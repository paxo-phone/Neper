#include <vector>

#include "../../css/css.hpp"
#include "../include/inherit.hpp"

namespace styles
{
    std::vector<std::string> inheritedProperties = 
    {
        "color",
    };

    std::vector<std::string> nonInheritedProperties = 
    {
        "border-bottom-color",
        "border-bottom-style",
        "border-bottom-width",

        "border-top-color",
        "border-top-style",
        "border-top-width",

        "border-left-color",
        "border-left-style",
        "border-left-width",

        "border-right-color",
        "border-right-style",
        "border-right-width",

        "padding-top",
        "padding-bottom",
        "padding-right",
        "padding-left",

        "margin-top",
        "margin-left",
        "margin-bottom",
        "margin-right"

        "width",
        "height",

        "display",

        "outline-color",
        "outline-offset",
        "outline-style",
        "outline-width"
    };

    void inheriteStyles(dom::Node* node)
    {
        if( node->hasParent() )
        {
            // non inherited properties

            for(size_t i = 0; i < nonInheritedProperties.size(); i++)
            {
                std::string key = nonInheritedProperties[i];

                if ( node->styles[key].empty() )
                {
                    node->styles[key] = css::initialStyles[key];
                }
            }


            // inherited properties
            
            for(size_t i = 0; i < inheritedProperties.size(); i++)
            {
                std::string key = inheritedProperties[i];
                if ( node->styles[key].empty() )
                {
                    node->styles[key] = node->parent()->styles[key];
                }
            }

            // initial and inherit keywords

            dom::StyleList::iterator ite = node->styles.begin();
            
            for(; ite != node->styles.end(); ite++)
            {
                if((*ite).second == "initial")
                {
                    (*ite).second = css::initialStyles[(*ite).first];
                    continue;
                }

                if((*ite).second == "inherit")
                {
                    (*ite).second = node->parent()->styles[(*ite).first];
                    continue;
                }

            }
        }

        for(size_t i = 0; i < node->children(); i++)
        {
            inheriteStyles(node->child(i));
        }

        return;
    }
}