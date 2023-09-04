#include <cctype>

#include "../include/inline_parser.hpp"

#include "../../dom/dom.hpp"
#include "../../utils/utils.hpp"

namespace css
{
    bool ispropchar(const char& c)
    {
        return (isalpha(c) || c == '-');
    }

    dom::StyleList parseInlineCSS(const std::string& str)
    {
        dom::StyleList styles;

        std::string key, value;

        size_t i = 0;
        while(i < str.size())
        {
            key = value = "";

            ignorewhitespaces(i, str);

            while( ispropchar(str[i]) )
                key += tolower(str[i++]);
            
            ignorewhitespaces(i, str);
            
            if (str[i] != ':')
                continue;
            i++;
            
            ignorewhitespaces(i, str);

            while(str[i] != ';' && i < str.size())
                value += str[i++];

            styles[key] = value;
            i++;
        }

        return styles;
    }

} // namespace css