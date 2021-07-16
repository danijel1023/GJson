#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "GJson.h"

struct Parsed_Json_Struct {
    std::string Build_Instructions;
    std::vector<std::string> String_List;
    std::vector<double> Number_List;
};


static bool Parse(const std::string& File);


GJson::GJson(const std::string& File_Name) {
    std::ifstream File(File_Name);
    if (!File.is_open()) {
        std::cout << "Could not open file: " << File_Name << std::endl;
        m_Loaded = false;
        return;
    }
    
    std::stringstream buffer;
    buffer << File.rdbuf();
    
    Parse(buffer.str());
}


static bool Whitespace (int ch) {
    switch(ch) {
        case ' ':  return true;
        case '\t': return true;
        case '\n': return true;
        default:   return false;
    }
}

static bool Escape_Char = false;
static bool String = false;
static bool Number = false;
static bool Decimal = false;
static bool Parse(const std::string& File) {
    std::string Build_Instruction;
    for (size_t i = 0; i < File.size(); i++) {
        if (Escape_Char) {
            Escape_Char = false;
            continue;
        }

        const int& ch = File.at(i);
        if (ch == '\\') {
            Escape_Char = true;
            continue;
        }

        else if (ch == '"') {
            if (!String) String = true;
            else {
                String = false;
                Build_Instruction.push_back('S');
            }
        }
        else if (String) continue;


        else if (ch >= 48 && ch <= 57) {
            if (!Number) {
                Number = true;
                Build_Instruction.push_back('N');
            }
        }

        else if (ch == '.' && Number) {
            if (!Decimal) Decimal = true;
            else {
                std::cout << "Error parsing number: found 2 '.'" << std::endl;
                break;
            }
        }

        else if (Whitespace(ch)) {
            Number = false;
            continue;
        }

        else {
            Number = false;
            Build_Instruction.push_back(ch);
        }
    }

    return true;
}
