#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// syntax
string print = "print";
string condition = "if";
string jump = "jump";
string label = "label";
string input = "input";

// Function to check if a vector contains a specific value
bool Contains(const vector<string> &vec, const string &value) {
  return find(vec.begin(), vec.end(), value) != vec.end();
}

// Function to print error messages based on an error code
void Error(int code, string param) {
  switch (code) {
  case 1:
    cout << "Lexer error: missing closing quote" << endl;
    break;
  case 2:
    cout << "Unexpected token: " << param << endl;
    break;
  }
}

// Function to check if all characters in a string belong to a given set of
// characters
bool CheckContents(string strToCheck, string characters) {
  bool found = false;
  for (char c : strToCheck) {
    found = false;
    for (char d : characters) {
      if (c == d) {
        found = true;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }
  return true;
}

// Function to split a string by a given character, handling quotes
vector<string> Split(string str, char delimiter) {
  vector<string> result = {};
  string tempStr = "";
  int quotes = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str.at(i) == '"') {
      quotes += 1;
    }
    if (str.at(i) == delimiter && quotes % 2 == 0) {
      result.push_back(tempStr);
      tempStr = "";
    } else {
      tempStr += str.at(i);
    }
  }
  if (!tempStr.empty()) {
    result.push_back(tempStr);
  }
  if (quotes % 2 != 0) {
    Error(1, "");
    return {};
  }
  return result;
}

// Function to print the contents of a nested vector structure
// debug
/*void PrintVector(const vector<vector<vector<string>>> &data) {
  for (size_t i = 0; i < data.size(); ++i) {
    cout << "Line " << i << ": ";
    for (size_t j = 0; j < data[i].size(); ++j) {
      cout << "[" << j << "]: ";
      for (size_t k = 0; k < data[i][j].size(); ++k) {
        cout << data[i][j][k] << " ";
      }
      cout << " | ";
    }
    cout << endl;
  }
}*/

// Lexer function to tokenize a code string into nested vectors
vector<vector<vector<string>>> Lexer(string code) {
  vector<string> lines = Split(code, '\n');
  vector<vector<vector<string>>> result = {};

  for (string line : lines) {
    if (line.empty())
      continue;

    vector<string> tokens = Split(line, ' ');
    vector<vector<string>> items = {};

    for (string token : tokens) {
      vector<string> item = {};

      if (token[0] == '"' && token[token.size() - 1] == '"') {
        item.push_back("string");
        token = token.substr(1, token.size() - 2);
      } else if (CheckContents(
                     token,
                     "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        item.push_back("symbol");
      } else if (CheckContents(token, "+-*/%=><!=<>=")) {
        item.push_back("expression");
      } else if (CheckContents(token, "0123456789")) {
        item.push_back("number");
      } else {
        Error(2, token);
        continue;
      }

      item.push_back(token);
      items.push_back(item);
    }
    result.push_back(items);
  }
  return result;
}

// Define some global variables: known symbols, label map, and variable map
vector<string> symbols = {print, label, jump, condition, input};
map<string, int> labels;     // stores labels with line indices
map<string, int> vars;       // stores integer variables with their values
map<string, string> strVars; // stores string variables

// Function to evaluate conditions for if statements
bool EvaluateCondition(int lhs, string op, int rhs) {
  if (op == "==")
    return lhs == rhs;
  else if (op == "!=")
    return lhs != rhs;
  else if (op == ">=")
    return lhs >= rhs;
  else if (op == "<=")
    return lhs <= rhs;
  else if (op == ">")
    return lhs > rhs;
  else if (op == "<")
    return lhs < rhs;
  return false;
}

// Function to get a string value from a token
string GetStr(vector<string> token) {
  if (token.at(0) == "string") {
    return token.at(1);
  } else if (token.at(0) == "symbol") {
    return strVars[token.at(1)];
  }
  throw invalid_argument("Invalid token type for string");
}

// Helper function to get the value of a token (whether it's a number or a
// variable)
int GetValue(vector<string> token) {
  if (token.at(0) == "number") {
    return stoi(token.at(1));
  } else if (token.at(0) == "symbol") {
    return vars[token.at(1)];
  }
  throw invalid_argument("Invalid token type for comparison");
}

// Parse function to process the file and execute code based on parsed tokens
void Parse(string file) {
  // Open file and read its content into the 'code' string
  ifstream inputCode(file);
  string code;
  getline(inputCode, code, '\0');
  inputCode.close();

  // Tokenize the code using the lexer
  vector<vector<vector<string>>> lines = Lexer(code);

  // First pass: find and store label definitions
  for (int i = 0; i < lines.size(); i++) {
    vector<vector<string>> line = lines.at(i);
    // If a line defines a label, store it in the label map
    if (line.at(0).at(0) == "symbol" && line.at(0).at(1) == label) {
      if (line.at(1).at(0) == "string") {
        labels[line.at(1).at(1)] = i; // associate label name with line number
      }
    }
  }

  // Second pass: execute the code line by line
  int i = 0;
  while (i < lines.size()) {
    vector<vector<string>> line = lines.at(i);

    // Handle symbol-based commands (print, jump, if, etc.)
    if (line.at(0).at(0) == "symbol") {
      string command = line.at(0).at(1);

      // 'print' command: prints either a string or a variable value
      if (command == print) {
        if (line.at(1).at(0) == "string") {
          cout << line.at(1).at(1) << endl;
        } else if (line.at(1).at(0) == "symbol") {
          if (vars.find(line.at(1).at(1)) != vars.end()) {
            cout << vars[line.at(1).at(1)] << endl;
          } else if (strVars.find(line.at(1).at(1)) != strVars.end()) {
            cout << strVars[line.at(1).at(1)] << endl;
          }
        }
      }
      // 'jump' command: jumps to the label specified
      else if (command == jump) {
        if (line.at(1).at(0) == "string") {
          i = labels[line.at(1).at(
              1)]; // set the execution pointer to the label's line
          continue;
        }
      }
      // 'if' command: conditional execution based on a variable's value and a
      // comparison operator
      else if (command == condition) {
        // Get the left-hand side (lhs) and right-hand side (rhs) values
        int lhs = GetValue(line.at(1)); // lhs can be a variable or number
        string op = line.at(2).at(1);   // comparison operator
        int rhs = GetValue(line.at(3)); // rhs can be a variable or number

        // Check the condition and execute the jump if it's true
        if (EvaluateCondition(lhs, op, rhs) && line.at(4).at(1) == jump) {
          i = labels[line.at(5).at(1)]; // jump if condition is true
          continue;
        }
      }
      // Variable assignment and expression handling
      else {
        string varName = line.at(0).at(1);
        if (line.at(1).at(1) == "=") {
          // Handle string assignment and concatenation
          if (strVars.find(line.at(0).at(1)) != strVars.end() ||
              line.at(2).at(0) == "string") {
            string val = GetStr(line.at(2));
            if (line.size() > 3 && line.at(3).at(1) == "+") {
              val += GetStr(line.at(4)); // concatenate strings
            }
            strVars[varName] = val; // assign string value
          } else {
            int value = 0;
            if (line.size() > 3) {
              string op = line.at(3).at(1);
              int var1 = GetValue(line.at(2));
              int num = GetValue(line.at(4));
              // Handle arithmetic based on the operator
              if (op == "+") {
                value = var1 + num;
              } else if (op == "-") {
                value = var1 - num;
              } else if (op == "*") {
                value = var1 * num;
              } else if (op == "/") {
                value = var1 / num;
              } else if (op == "%") {
                value = var1 % num;
              }
            } else {
              value = GetValue(line.at(2));
            }
            // Assign the final calculated value to the variable
            vars[varName] = value;
          }
        }
      }
    }
    i++;
  }
}

int main(int argc, char* argv[]) {
  //search parameters for a file ending in .fc
  //it is done this way because different compilers pass a different number of arguments before your argument
  bool found = false;
  for (int i = 0; i < argc; i++) {
    std::string arg = argv[i];  // Convert C-style string to std::string
    // Check if the last three characters are ".fc"
    if (arg.length() >= 3 && arg.substr(arg.length() - 3) == ".fc") {
      Parse(arg);
      found = true;
      break;
    }
  }
  // If no file ending in ".fc" was found, use the default "test.fc"
  if (!found) {
    Parse("test.fc");
  }
  return 0;
}
