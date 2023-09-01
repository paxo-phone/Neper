#include <iostream>
#include <fstream>
#include <string>

#include "src/abstract/abstract.hpp"
#include "src/css/css.hpp"
#include "src/dom/dom.hpp"
#include "src/html/html.hpp"
#include "src/styles/styles.hpp"
#include "src/utils/utils.hpp"

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

    dom::Node* root = html::parseHTML(html);
    styles::readStyles(root);

    abstract::Widget* tree = styles::abstractTree(root);
    std::cout << (*tree) << std::endl;

    delete root;
    delete tree;

    return 0;
}