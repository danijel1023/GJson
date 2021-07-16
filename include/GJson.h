#pragma once
#include <string>
#include "Json_Node.h"

class GJson {
public:
    GJson(const std::string& File_Name);

private:
    bool m_Loaded = false;
};
