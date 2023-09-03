#include <iostream>
#include <fstream>
#include <string>

#include "src/neper.hpp"

int main(void)
{
    std::string path = "/Users/raphaelgoutmann/Desktop/Neper/data/appollo.html";
    
    std::ifstream file (path);
    if( !file.is_open() ) {
        std::cerr << "Cannot open " << path << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::string html = "";
    
    std::string line;
    while( getline(file, line) ) {
        html.append(line);
    }

    abstract::Widget* tree = buildAbstractFromHTML(html);
    std::cout << (*tree) << std::endl;
    delete tree;

    return 0;
}