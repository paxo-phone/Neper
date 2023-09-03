#include <unordered_map>
#include <string> 

#include "../../dom/dom.hpp"
#include "../include/initial.hpp"

namespace css
{
    dom::StyleList initialStyles =
    {
        {"border-bottom-color", "currentcolor"},
        {"border-bottom-style", "none"},
        {"border-bottom-width", "medium"},

        {"border-top-color", "currentcolor"},
        {"border-top-style", "none"},
        {"border-top-width", "medium"},
        
        {"border-left-color", "currentcolor"},
        {"border-left-style", "none"},
        {"border-left-width", "medium"},

        {"border-right-color", "currentcolor"},
        {"border-right-style", "none"},
        {"border-right-width", "medium"},

        {"padding-top",    "0"},
        {"padding-bottom", "0"},
        {"padding-right",  "0"},
        {"padding-left",   "0"},

        { "margin-top",    "0"},
        { "margin-left",   "0"},
        { "margin-bottom", "0"},
        { "margin-right",  "0"},

        {"color", "canvastext"},

        {"width", "auto"},
        {"height", "auto"},

        {"display", "inline"},

        {"outline-color", "invert"},
        {"outline-offset", "0"},
        {"outline-style", "none"},
        {"outline-width", "medium"},

        {"font-size", "16px"}

    };
} // namespace css