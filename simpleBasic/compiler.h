#pragma once
#include <iostream>
#include <sstream>

#include <cmath>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <vector>

#include "token.h"
#include "token_stream.h"
#include "var_table.h"

struct AsmCommand
{
  int mem_addr;
  std::string command;
  int operand;
  int tag;
  bool is_resloved = true;
};

class Compiler
{
private:
  static const int mem_size = 128;

  std::istream &in_stream;
  std::ostream &out_stream;
  VariableTable var_table;
  TokenStream ts;

  int statement ();         // handle functions REM, INPUT
  int var_declaration ();   // LET HANDLE
  int if_statement ();      // IF
  void parse_expression (); // X [>, <] 0
  int global_statement ();  // mem addr -> statement

  int rem ();
  int input ();
  int output ();
  int go ();
  int end ();

  void create_variable (std::string name);
  void create_const_variable (std::string name, int value);
  void load_variable (std::string name);
  void write_command (std::string command, int operand, int tag = -1);

  void update_mem_addr ();

  int command_count = 0;
  int current_address = 0;
  int variables_address = mem_size - 1;

  std::vector<bool> used_memory;
  std::vector<int> tags;
  std::vector<AsmCommand> commands;

  std::string last_variable = "";

public:
  Compiler (std::istream &input_st, std::ostream &output_st);

  // Returns error code (0 - Ok, 1 - expected error, 2 - unexpected)
  int compile ();
};
