#ifndef __ABSTRACT_COLOR__
#define __ABSTRACT_COLOR__

#include <iostream>
#include <string>
#include <unordered_map>

namespace abstract
{
    struct color_t
    {
        unsigned r; // uint8_t doesn't work __(°-°)__
        unsigned g;
        unsigned b;
        float   a;
    };

    #ifdef DEBUG
        std::ostream& operator<<(std::ostream& os, color_t& color);
    #endif

    extern color_t TRANSPARENT;
    extern color_t BLACK;
    extern color_t WHITE;

    extern std::unordered_map<std::string, color_t> x11Colors ;


} // namespace abstract

#endif /* __ABSTRACT_COLOR__ */