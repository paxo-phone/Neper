#ifndef __CSS_DEFAULT__
#define __CSS_DEFAULT__

#include <string>
#include <unordered_map>

namespace css
{
    extern std::unordered_map<std::string, std::unordered_map<std::string, std::string> > defaultStyles;
} // namespace css

#endif /* __CSS_DEFAULT__ */