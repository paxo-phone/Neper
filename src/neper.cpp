#include "neper.hpp"

abstract::Widget* buildAbstractFromHTML(const std::string& html)
{
    dom::Node* root = html::parseHTML(html);
    styles::readStyles(root);

    abstract::Widget* tree = styles::abstractTree(root);

    delete root;

    return tree;
}