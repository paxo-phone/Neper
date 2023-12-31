#include <string>

#include "../include/default.hpp"

#include "../../dom/dom.hpp"
#include "../../css/css.hpp"
#include "../../utils/utils.hpp"

namespace styles
{
    void readDefaultStyles( dom::Node* node )
    {
        if(node == nullptr)
            return;

        const std::string tag = toupper(node->tag());
        node->styles = css::defaultStyles[tag];

    }
    
} // namespace styles