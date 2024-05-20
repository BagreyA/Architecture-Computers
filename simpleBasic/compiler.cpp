//получает поток ввода и передаёт его под управление классу TokenStream, далее работает с токенами и обрабатывает все выражения языка программирования Simple Basic
#include "compiler.h"
using namespace std;

Compiler::Compiler(std::istream &input_st, std::ostream &output_st) : in_stream(input_st),
                                                                      out_stream(output_st),
                                                                      ts(input_st),
                                                                      used_memory(mem_size, false),
                                                                      tags(mem_size, 0),
                                                                      last_variable(""),
                                                                      command_count(0),
                                                                      current_address(0),
                                                                      variables_address(mem_size - 1)
{
}

void Compiler::parse_expression()
{
    Token t = Token(Token::EXPRESSION_END_FLAG);
    std::stack<Token> operator_stack;
    std::vector<Token> output_queue;

    while ((t = ts.get_token()).type != Token::Types::EXPRESSION_END_FLAG &&
           t.type != Token::Types::EXIT_FLAG)
    {
        if (t.type == Token::Types::VAR_NAME)
        {
            output_queue.push_back(t);
        }
        else if (t.is_operator())
        {
            while (!operator_stack.empty() &&
                   operator_stack.top().precedence() > t.precedence())
            {
                output_queue.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(t);
        }
        else if (t.type == Token::Types::OPEN_BRACKET)
        {
            operator_stack.push(t);
        }
        else if (t.type == Token::Types::CLOSING_BRACKET)
        {
            while (!operator_stack.empty() && operator_stack.top().type != Token::Types::OPEN_BRACKET)
            {
                output_queue.push_back(operator_stack.top());
                operator_stack.pop();
            }
            if (!operator_stack.empty() && operator_stack.top().type == Token::Types::OPEN_BRACKET)
            {
                operator_stack.pop();
            }
            else
            {
                throw std::runtime_error("Mismatched parentheses");
            }
        }
        else
        {
            throw std::runtime_error("Unexpected token in expression");
        }
    }

    while (!operator_stack.empty())
    {
        output_queue.push_back(operator_stack.top());
        operator_stack.pop();
    }

    stack<Token> ans = stack<Token>();
    for (const auto &token : output_queue)
    {
        if (token.is_operator())
        {
            auto op2 = ans.top();
            ans.pop();
            auto op1 = ans.top();
            ans.pop();

            load_variable(op1.str_val);
            if (token.type == Token::OP_PLUS)
            {
                write_command("ADD", var_table.get_addr(op2.str_val));
            }
            if (token.type == Token::OP_MINUS)
            {
                write_command("SUB", var_table.get_addr(op2.str_val));
            }
            if (token.type == Token::OP_MULT)
            {
                write_command("MUL", var_table.get_addr(op2.str_val));
            }
            if (token.type == Token::OP_DIVIDE)
            {
                write_command("DIV", var_table.get_addr(op2.str_val));
            }

            int addr = variables_address - 1;
            string name = "tmp" + to_string(addr);
            var_table.define(name, addr);
            ans.push(Token(Token::VAR_NAME, name));

            write_command("STORE", addr);
            variables_address--;
        }
        else
        {
            ans.push(token);
        }
    }
}
int Compiler::var_declaration()
{
    Token t = ts.get_token();
    if (t.type != Token::Types::VAR_NAME)
        throw std::runtime_error("Variable name expected in declaration");

    std::string var_name = t.str_val;

    t = ts.get_token();
    if (t.type != Token::Types::OP_EQUAL)
        throw std::runtime_error("Expected '=' after variable name");

    t = ts.get_token();
    if (t == Token::NUMBER)
    {
        create_const_variable(var_name, t.value);
    }
    else
    {
        ts.put_back(t);
        parse_expression();
        if (var_table.has(var_name))
        {
            int addr = var_table.get_addr(var_name);
            write_command("STORE", addr);
        }
        else
        {
            var_table.define(var_name, variables_address);
        }
    }

    return 0;
}

int Compiler::if_statement()
{
    Token var = ts.get_token();
    if (var.type != Token::VAR_NAME)
        throw std::runtime_error("Variable name expected in declaration");
    Token cmp = ts.get_token();
    if (cmp.type != Token::OP_GT && cmp.type != Token::OP_LESS)
        throw std::runtime_error("Expected > or < operator");
    Token zero = ts.get_token();
    if (zero.type != Token::NUMBER)
        throw std::runtime_error("0 expected after comparsion operator");
    Token go = ts.get_token();
    if (go.type != Token::GOTO)
        throw std::runtime_error("GOTO expected after compare expresson");
    Token addr = ts.get_token();
    if (addr.type != Token::NUMBER)
        throw std::runtime_error("address should be number");

    load_variable(var.str_val);

    if (cmp.type == Token::OP_GT)
    {
        write_command("JNS", -1, addr.value);
    }
    else if (cmp.type == Token::OP_LESS)
    {
        write_command("JNEG", -1, addr.value);
    }

    return 0;
}

int Compiler::global_statement()
{
    Token t = ts.get_token();
    if (t.type != Token::NUMBER)
        throw std::runtime_error("Memory address expected");

    current_address = t.value;
    tags[current_address] = command_count;
    return statement();
}

int Compiler::rem()
{
    ts.ignore();
    return 0;
}

int Compiler::input()
{
    Token t = ts.get_token();
    if (t.type != Token::Types::VAR_NAME)
        throw std::runtime_error("Variable name expected in input command");

    create_variable(t.str_val);
    return 0;
}

int Compiler::output()
{
    Token var = ts.get_token();
    if (var.type != Token::Types::VAR_NAME)
        throw std::runtime_error("Variable name expected in output command");

    if (var_table.has(var.str_val) == false)
        throw std::runtime_error("Variable to output not found...");

    write_command("WRITE", var_table.get_addr(var.str_val));
    return 0;
}

int Compiler::go()
{
    Token t = ts.get_token();
    if (t.type != Token::NUMBER)
        throw runtime_error("expected number after goto");

    write_command("JUMP", -1, t.value);
    return 0;
}

int Compiler::end()
{
    write_command("HALT", 0);
    return 0;
}

int Compiler::statement()
{
    Token t = ts.get_token();
    switch (t.type)
    {
    case Token::LET:
        return var_declaration();
    case Token::REM:
        return rem();
    case Token::INPUT:
        return input();
    case Token::IF:
        return if_statement();
    case Token::OUTPUT:
        return output();
    case Token::GOTO:
        return go();
    case Token::END:
        return end();
    default:
        ts.put_back(t);
        throw runtime_error("Unknown statement!");
    }
}

void Compiler::write_command(std::string command, int operand, int tag)
{
    AsmCommand cmd;
    cmd.command = command;
    cmd.mem_addr = command_count;
    cmd.operand = operand;
    cmd.tag = tag;
    if (command == "JUMP" || command == "JNEG" || command == "JNS")
    {
        cmd.is_resloved = false;
        cmd.tag = tag;
    }
    commands.push_back(cmd);
    // out_stream << command_count << " " << command << " " << operand << endl;
    command_count++;
}

void Compiler::update_mem_addr()
{
    while (used_memory[variables_address])
        variables_address--;
}

void Compiler::create_const_variable(std::string name, int value)
{
    AsmCommand cmd;
    cmd.mem_addr = command_count;
    cmd.command = "=";
    cmd.operand = value;
    cmd.tag = -1;

    commands.push_back(cmd);
    used_memory[command_count] = true;
    var_table.define(name, command_count);
    command_count++;
}

void Compiler::create_variable(std::string name)
{
    update_mem_addr();

    AsmCommand cmd;
    cmd.command = "READ";
    cmd.mem_addr = command_count;
    cmd.operand = variables_address;
    cmd.tag = -1;

    commands.push_back(cmd);
    // out_stream << command_count << " READ " << variables_address << endl;
    used_memory[variables_address] = true;
    var_table.define(name, variables_address);
    command_count++;
}

void Compiler::load_variable(std::string name)
{
    if (!var_table.has(name))
    {
        throw std::runtime_error("Variable not defined: " + name);
    }
    int addr = var_table.get_addr(name);
    AsmCommand cmd;
    cmd.command = "LOAD";
    cmd.mem_addr = command_count;
    cmd.operand = addr;
    cmd.tag = -1;

    commands.push_back(cmd);
    // out_stream << command_count << " LOAD " << addr << endl;
    command_count++;
}

int Compiler::compile()
{
    int line = 0;
    try
    {
        while (in_stream)
        {
            line++;

            Token t = ts.get_token();
            while (t.type == Token::Types::EXPRESSION_END_FLAG)
                t = ts.get_token();

            if (t.type == Token::Types::EXIT_FLAG)
            {
                for (auto &cmd : commands)
                {
                    if (cmd.is_resloved)
                    {
                        out_stream << cmd.mem_addr << " " << cmd.command << " " << cmd.operand << endl;
                    }
                    else
                    {
                        out_stream << cmd.mem_addr << " " << cmd.command << " " << tags[cmd.tag] << endl;
                    }
                }
                return 0;
            }

            ts.put_back(t);
            global_statement();
        }
    }
    catch (exception &e)
    {
        std::cout << "Line #" << line << "\nCalculation error: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        std::cout << "Line #" << line << "\nUnknown error!" << endl;
        return 2;
    }

    return 0;
}
