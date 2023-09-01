#ifndef __STYLES_TREE__
#define __STYLES_TREE__

#include "../../dom/dom.hpp"
#include "../../abstract/abstract.hpp"

namespace styles
{
    abstract::Widget* abstractTree( dom::Node* domNode );

} // namespace styles

#endif /* __STYLES_TREE__ */