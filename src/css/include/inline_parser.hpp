#ifndef __CSS_INLINE_PARSER__
#define __CSS_INLINE_PARSER__

#include "../../dom/dom.hpp"

namespace css
{
    dom::StyleList parseInlineCSS(const std::string& str);
    
} // namespace css

#endif /* __CSS_INLINE_PARSER__ */