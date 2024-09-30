#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Function to check if a vector contains a specific value
bool Contains(const vector<string> &vec, const string &value) {
  return find(vec.begin(), vec.end(), value) != vec.end();
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
      } else if (CheckContents(token, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
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

int main(int argc, char* argv[]) {
  //search parameters for a file ending in .fc
  //it is done this way because different compilers pass a different number of arguments before your argument
  bool found = false;
  for (int i = 0; i < argc; i++) {
    std::string arg = argv[i];  // Convert C-style string to std::string
    // Check if the last three characters are ".fc"
    if (arg.length() >= 3 && arg.substr(arg.length() - 3) == ".fc") {
      //Parse(arg);
      found = true;
      break;
    }
  }
  // If no file ending in ".fc" was found, use the default "test.fc"
  if (!found) {
    cout << "Error: no .fc file found" << endl;
  }
  return 0;
}