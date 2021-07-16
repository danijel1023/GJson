#include <iostream>
#include "GJson.h"

int main() {
    std::cout << "Hello world!" << std::endl;

    std::string File_Path = "C:/Users/Danijel/Desktop/Programming/Cross-Platform/GJson/test files/";
    std::string File_Name = "basic.json";
    std::cout << "Path: " << File_Path << std::endl << "Looking for file: " << File_Name << std::endl;

    GJson JBasic_Structure(File_Path + File_Name);

    return 0;
}
