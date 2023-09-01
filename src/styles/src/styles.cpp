#include <string>

#include "../include/styles.hpp"

#include "../../dom/dom.hpp"
#include "../../css/css.hpp"
#include "../../utils/utils.hpp"

#include "../include/default.hpp"
#include "../include/inline.hpp"
#include "../include/tag.hpp"
#include "../include/inherit.hpp"

namespace styles
{
    void readStyles( dom::Node* node )
    {
        if( ! node->hasParent() )
        {
            node->styles = css::initialStyles;
        }
        
        readDefaultStyles( node );
        // ...
        inheriteStyles(node);
    }

} // namespace styles