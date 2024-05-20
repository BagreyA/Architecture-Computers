#include <string>
#include <unordered_map>

class VariableTable
{
private:
  std::unordered_map<std::string, int> vars;

public:
  void define (std::string name, int address);
  int get_addr (std::string name);
  bool has (std::string name);
};
