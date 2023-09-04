#include "../../dom/dom.hpp"
#include "../../css/css.hpp"

#include "../include/inline.hpp"


namespace styles
{
    void readInlineStyles( dom::Node* node  )
    {
        std::string inlineStyles = node->attributes["style"];
        
        if( ! inlineStyles.empty() )
        {
            dom::StyleList inlineStylesList = css::parseInlineCSS(inlineStyles);
            for(auto& ite : inlineStylesList) {
                node->styles[ite.first] = ite.second;
            }
        }

    }
}
