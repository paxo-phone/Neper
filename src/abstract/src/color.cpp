#include <string>
#include <unordered_map>

#include "../include/color.hpp"

namespace abstract
{
    std::ostream& operator<<(std::ostream& os, color_t& color)
    {
        os << "(";
        
        os << color.r << ", ";
        os << color.g << ", ";
        os << color.b << ", ";
        os << color.a;

        os << ")";
        
        return os;
    }

    color_t TRANSPARENT{ 0, 0, 0, 0.0};

    color_t ALICEBLUE{ 240, 248, 255, 1.0 };
    color_t ANTIQUEWHITE{ 250, 235, 215, 1.0 };
    color_t AQUA{   0, 255, 255, 1.0 };
    color_t AQUAMARINE{ 127, 255, 212, 1.0 };
    color_t AZURE{ 240, 255, 255, 1.0 };
    color_t BEIGE{ 245, 245, 220, 1.0 };
    color_t BISQUE{ 255, 228, 196, 1.0 };
    color_t BLACK{0,   0,   0, 1.0 };
    color_t BLANCHEDALMOND{ 255, 235, 205, 1.0 };
    color_t BLUE{   0,   0, 255, 1.0 };
    color_t BLUEVIOLET{ 138,  43, 226, 1.0 };
    color_t BROWN{ 165,  42,  42, 1.0 };
    color_t BURLYWOOD{ 222, 184, 135, 1.0 };
    color_t CADETBLUE{  95, 158, 160, 1.0 };
    color_t CHARTREUSE{ 127, 255,   0, 1.0 };
    color_t CHOCOLATE{ 210, 105,  30, 1.0 };
    color_t CORAL{ 255, 127, 80, 1.0  };
    color_t CORNFLOWERBLUE{ 100, 149, 237, 1.0 };
    color_t CORNSILK{ 255, 248, 220, 1.0 };
    color_t CRIMSON{ 220,  20,  60, 1.0 };
    color_t CYAN{   0, 255, 255, 1.0 };
    color_t DARKBLUE{   0,   0, 139, 1.0 };
    color_t DARKCYAN{   0, 139, 139, 1.0 };
    color_t DARKGOLDENROD{ 184, 134,  11, 1.0 };
    color_t DARKGRAY{ 169, 169, 169, 1.0 };
    color_t DARKGREEN{   0, 100,   0, 1.0 };
    color_t DARKKHAKI{ 189, 183, 107, 1.0 };
    color_t DARKMAGENTA{ 139,   0, 139, 1.0 };
    color_t DARKOLIVEGREEN{  85, 107,  47, 1.0 };
    color_t DARKORANGE{ 255, 140,   0, 1.0 };
    color_t DARKORCHID{ 153,  50, 204, 1.0 };
    color_t DARKRED{ 139,   0,   0, 1.0 };
    color_t DARKSALMON{ 233, 150, 122, 1.0 };
    color_t DARKSEAGREEN{ 143, 188, 143, 1.0 };
    color_t DARKSLATEBLUE{  72,  61, 139, 1.0 };
    color_t DARKSLATEGRAY{  47,  79,  79, 1.0 };
    color_t DARKTURQUOISE{   0, 206, 209, 1.0 };
    color_t DARKVIOLET{ 148,   0, 211, 1.0 };
    color_t DEEPPINK{ 255,  20, 147, 1.0 };
    color_t DEEPSKYBLUE{   0, 191, 255, 1.0 };
    color_t DIMGRAY{ 105, 105, 105, 1.0 };
    color_t DODGERBLUE{  30, 144, 255, 1.0 };
    color_t FIREBRICK{ 178,  34,  34, 1.0 };
    color_t FLORALWHITE{ 255, 250, 240, 1.0 };
    color_t FORESTGREEN{  34, 139,  34, 1.0 };
    color_t FUCHSIA{ 255,   0, 255, 1.0 };
    color_t GAINSBORO{ 220, 220, 220, 1.0 };
    color_t GHOSTWHITE{ 248, 248, 255, 1.0 };
    color_t GOLD{ 255, 215,   0, 1.0 };
    color_t GOLDENROD{ 218, 165,  32, 1.0 };
    color_t GRAY{ 128, 128, 128, 1.0 };
    color_t GREEN{   0, 128,   0, 1.0 };
    color_t GREENYELLOW{ 173, 255,  47, 1.0 };
    color_t HONEYDEW{ 240, 255, 240, 1.0 };
    color_t HOTPINK{ 255, 105, 180, 1.0 };
    color_t INDIANRED{ 205,  92,  92, 1.0 };
    color_t INDIGO{  75,   0, 130, 1.0 };
    color_t IVORY{ 255, 255, 240, 1.0 };
    color_t KHAKI{ 240, 230, 140, 1.0 };
    color_t LAVENDER{ 230, 230, 250, 1.0 };
    color_t LAVENDERBLUSH{ 255, 240, 245, 1.0 };
    color_t LAWNGREEN{ 124, 252,   0, 1.0 };
    color_t LEMONCHIFFON{ 255, 250, 205, 1.0 };
    color_t LIGHTBLUE{ 173, 216, 230, 1.0 };
    color_t LIGHTCORAL{ 240, 128, 128, 1.0 };
    color_t LIGHTCYAN{ 224, 255, 255, 1.0 };
    color_t LIGHTGOLDENRODYELLOW{ 250, 250, 210, 1.0 };
    color_t LIGHTGREEN{ 144, 238, 144, 1.0 };
    color_t LIGHTGREY{ 211, 211, 211, 1.0 };
    color_t LIGHTPINK{ 255, 182, 193, 1.0 };
    color_t LIGHTSALMON{ 255, 160, 122, 1.0 };
    color_t LIGHTSEAGREEN{  32, 178, 170, 1.0 };
    color_t LIGHTSKYBLUE{ 135, 206, 250, 1.0 };
    color_t LIGHTSLATEGRAY{ 119, 136, 153, 1.0 };
    color_t LIGHTSTEELBLUE{ 176, 196, 222, 1.0 };
    color_t LIGHTYELLOW{ 255, 255, 224, 1.0 };
    color_t LIME{   0, 255,   0, 1.0 };
    color_t LIMEGREEN{  50, 205,  50, 1.0 };
    color_t LINEN{ 250, 240, 230, 1.0 };
    color_t MAGENTA{ 255,   0, 255, 1.0 };
    color_t MAROON{ 128,   0,   0, 1.0 };
    color_t MEDIUMAQUAMARINE{ 102, 205, 170, 1.0 };
    color_t MEDIUMBLUE{   0,   0, 205, 1.0 };
    color_t MEDIUMORCHID{ 186,  85, 211, 1.0 };
    color_t MEDIUMPURPLE{ 147, 112, 219, 1.0 };
    color_t MEDIUMSEAGREEN{  60, 179, 113, 1.0 };
    color_t MEDIUMSLATEBLUE{ 123, 104, 238, 1.0 };
    color_t MEDIUMSPRINGGREEN{   0, 250, 154, 1.0 };
    color_t MEDIUMTURQUOISE{  72, 209, 204, 1.0 };
    color_t MEDIUMVIOLETRED{ 199,  21, 133, 1.0 };
    color_t MIDNIGHTBLUE{  25,  25, 112, 1.0 };
    color_t MINTCREAM{ 245, 255, 250, 1.0 };
    color_t MISTYROSE{ 255, 228, 225, 1.0 };
    color_t MOCCASIN{ 255, 228, 181, 1.0 };
    color_t NAVAJOWHITE{ 255, 222, 173, 1.0 };
    color_t NAVY{   0,   0, 128, 1.0 };
    color_t OLDLACE{ 253, 245, 230, 1.0 };
    color_t OLIVE{ 128, 128,   0, 1.0 };
    color_t OLIVEDRAB{ 107, 142,  35, 1.0 };
    color_t ORANGE{ 255, 165,   0, 1.0 };
    color_t ORANGERED{ 255,  69,   0, 1.0 };
    color_t ORCHID{ 218, 112, 214, 1.0 };
    color_t PALEGOLDENROD{ 238, 232, 170, 1.0 };
    color_t PALEGREEN{ 152, 251, 152, 1.0 };
    color_t PALETURQUOISE{ 175, 238, 238, 1.0 };
    color_t PALEVIOLETRED{ 219, 112, 147, 1.0 };
    color_t PAPAYAWHIP{ 255, 239, 213, 1.0 };
    color_t PEACHPUFF{ 255, 218, 185, 1.0 };
    color_t PERU{ 205, 133,  63, 1.0 };
    color_t PINK{ 255, 192, 203, 1.0 };
    color_t PLUM{ 221, 160, 221, 1.0 };
    color_t POWDERBLUE{ 176, 224, 230, 1.0 };
    color_t PURPLE{ 128,   0, 128, 1.0 };
    color_t RED{ 255,   0,   0, 1.0 };
    color_t ROSYBROWN{ 188, 143, 143, 1.0 };
    color_t ROYALBLUE{  65, 105, 225, 1.0 };
    color_t SADDLEBROWN{ 139,  69,  19, 1.0 };
    color_t SALMON{ 250, 128, 114, 1.0 };
    color_t SANDYBROWN{ 244, 164,  96, 1.0 };
    color_t SEAGREEN{  46, 139,  87, 1.0 };
    color_t SEASHELL{ 255, 245, 238, 1.0 };
    color_t SIENNA{ 160,  82,  45, 1.0 };
    color_t SILVER{ 192, 192, 192, 1.0 };
    color_t SKYBLUE{ 135, 206, 235, 1.0 };
    color_t SLATEBLUE{ 106,  90, 205, 1.0 };
    color_t SLATEGRAY{ 112, 128, 144, 1.0 };
    color_t SNOW{ 255, 250, 250, 1.0 };
    color_t SPRINGGREEN{   0, 255, 127, 1.0 };
    color_t STEELBLUE{  70, 130, 180, 1.0 };
    color_t TAN{ 210, 180, 140, 1.0 };
    color_t TEAL{   0, 128, 128, 1.0 };
    color_t THISTLE{ 216, 191, 216, 1.0 };
    color_t TOMATO{ 255,  99,  71, 1.0 };
    color_t TURQUOISE{  64, 224, 208, 1.0 };
    color_t VIOLET{ 238, 130, 238, 1.0 };
    color_t WHEAT{ 245, 222, 179, 1.0 };
    color_t WHITE{ 255, 255, 255, 1.0 };
    color_t WHITESMOKE{ 245, 245, 245, 1.0 };
    color_t YELLOW{ 255, 255,   0, 1.0 };
    color_t YELLOWGREEN{ 154, 205,   5, 1.0};

    std::unordered_map<std::string, color_t> x11Colors = 
    {
        {"ALICEBLUE",            ALICEBLUE },
        {"ANTIQUEWHITE",         ANTIQUEWHITE },
        {"AQUA",                 AQUA },
        {"AQUAMARINE",           AQUAMARINE },
        {"AZURE",                AZURE },
        {"BEIGE",                BEIGE },
        {"BISQUE",               BISQUE },
        {"BLACK",                BLACK },
        {"BLANCHEDALMOND",       BLANCHEDALMOND },
        {"BLUE",                 BLUE },
        {"BLUEVIOLET",           BLUEVIOLET },
        {"BROWN",                BROWN },
        {"BURLYWOOD",            BURLYWOOD },
        {"CADETBLUE",            CADETBLUE },
        {"CHARTREUSE",           CHARTREUSE },
        {"CHOCOLATE",            CHOCOLATE },
        {"CORAL",                CORAL },
        {"CORNFLOWERBLUE",       CORNFLOWERBLUE },
        {"CORNSILK",             CORNSILK },
        {"CRIMSON",              CRIMSON },
        {"CYAN",                 CYAN },
        {"DARKBLUE",             DARKBLUE },
        {"DARKCYAN",             DARKCYAN },
        {"DARKGOLDENROD",        DARKGOLDENROD },
        {"DARKGRAY",             DARKGRAY },
        {"DARKGREEN",            DARKGREEN },
        {"DARKKHAKI",            DARKKHAKI },
        {"DARKMAGENTA",          DARKMAGENTA },
        {"DARKOLIVEGREEN",       DARKOLIVEGREEN },
        {"DARKORANGE",           DARKORANGE },
        {"DARKORCHID",           DARKORCHID },
        {"DARKRED",              DARKRED },
        {"DARKSALMON",           DARKSALMON },
        {"DARKSEAGREEN",         DARKSEAGREEN },
        {"DARKSLATEBLUE",        DARKSLATEBLUE },
        {"DARKSLATEGRAY",        DARKSLATEGRAY },
        {"DARKTURQUOISE",        DARKTURQUOISE },
        {"DARKVIOLET",           DARKVIOLET },
        {"DEEPPINK",             DEEPPINK },
        {"DEEPSKYBLUE",          DEEPSKYBLUE },
        {"DIMGRAY",              DIMGRAY },
        {"DODGERBLUE",           DODGERBLUE },
        {"FIREBRICK",            FIREBRICK },
        {"FLORALWHITE",          FLORALWHITE },
        {"FORESTGREEN",          FORESTGREEN },
        {"FUCHSIA",              FUCHSIA },
        {"GAINSBORO",            GAINSBORO },
        {"GHOSTWHITE",           GHOSTWHITE },
        {"GOLD",                 GOLD },
        {"GOLDENROD",            GOLDENROD },
        {"GRAY",                 GRAY },
        {"GREEN",                GREEN },
        {"GREENYELLOW",          GREENYELLOW },
        {"HONEYDEW",             HONEYDEW },
        {"HOTPINK",              HOTPINK },
        {"INDIANRED",            INDIANRED },
        {"INDIGO",               INDIGO },
        {"IVORY",                IVORY },
        {"KHAKI",                KHAKI },
        {"LAVENDER",             LAVENDER },
        {"LAVENDERBLUSH",        LAVENDERBLUSH },
        {"LAWNGREEN",            LAWNGREEN },
        {"LEMONCHIFFON",         LEMONCHIFFON },
        {"LIGHTBLUE",            LIGHTBLUE },
        {"LIGHTCORAL",           LIGHTCORAL },
        {"LIGHTCYAN",            LIGHTCYAN },
        {"LIGHTGOLDENRODYELLOW", LIGHTGOLDENRODYELLOW },
        {"LIGHTGREEN",           LIGHTGREEN },
        {"LIGHTGREY",            LIGHTGREY },
        {"LIGHTPINK",            LIGHTPINK },
        {"LIGHTSALMON",          LIGHTSALMON },
        {"LIGHTSEAGREEN",        LIGHTSEAGREEN },
        {"LIGHTSKYBLUE",         LIGHTSKYBLUE },
        {"LIGHTSLATEGRAY",       LIGHTSLATEGRAY },
        {"LIGHTSTEELBLUE",       LIGHTSTEELBLUE },
        {"LIGHTYELLOW",          LIGHTYELLOW },
        {"LIME",                 LIME },
        {"LIMEGREEN",            LIMEGREEN },
        {"LINEN",                LINEN },
        {"MAGENTA",              MAGENTA },
        {"MAROON",               MAROON },
        {"MEDIUMAQUAMARINE",     MEDIUMAQUAMARINE },
        {"MEDIUMBLUE",           MEDIUMBLUE },
        {"MEDIUMORCHID",         MEDIUMORCHID },
        {"MEDIUMPURPLE",         MEDIUMPURPLE },
        {"MEDIUMSEAGREEN",       MEDIUMSEAGREEN },
        {"MEDIUMSLATEBLUE",      MEDIUMSLATEBLUE },
        {"MEDIUMSPRINGGREEN",    MEDIUMSPRINGGREEN },
        {"MEDIUMTURQUOISE",      MEDIUMTURQUOISE },
        {"MEDIUMVIOLETRED",      MEDIUMVIOLETRED },
        {"MIDNIGHTBLUE",         MIDNIGHTBLUE },
        {"MINTCREAM",            MINTCREAM },
        {"MISTYROSE",            MISTYROSE },
        {"MOCCASIN",             MOCCASIN },
        {"NAVAJOWHITE",          NAVAJOWHITE },
        {"NAVY",                 NAVY },
        {"OLDLACE",              OLDLACE },
        {"OLIVE",                OLIVE },
        {"OLIVEDRAB",            OLIVEDRAB },
        {"ORANGE",               ORANGE },
        {"ORANGERED",            ORANGERED },
        {"ORCHID",               ORCHID },
        {"PALEGOLDENROD",        PALEGOLDENROD },
        {"PALEGREEN",            PALEGREEN },
        {"PALETURQUOISE",        PALETURQUOISE },
        {"PALEVIOLETRED",        PALEVIOLETRED },
        {"PAPAYAWHIP",           PAPAYAWHIP },
        {"PEACHPUFF",            PEACHPUFF },
        {"PERU",                 PERU },
        {"PINK",                 PINK },
        {"PLUM",                 PLUM },
        {"POWDERBLUE",           POWDERBLUE },
        {"PURPLE",               PURPLE },
        {"RED",                  RED },
        {"ROSYBROWN",            ROSYBROWN },
        {"ROYALBLUE",            ROYALBLUE },
        {"SADDLEBROWN",          SADDLEBROWN },
        {"SALMON",               SALMON },
        {"SANDYBROWN",           SANDYBROWN },
        {"SEAGREEN",             SEAGREEN },
        {"SEASHELL",             SEASHELL },
        {"SIENNA",               SIENNA },
        {"SILVER",               SILVER },
        {"SKYBLUE",              SKYBLUE },
        {"SLATEBLUE",            SLATEBLUE },
        {"SLATEGRAY",            SLATEGRAY },
        {"SNOW",                 SNOW },
        {"SPRINGGREEN",          SPRINGGREEN },
        {"STEELBLUE",            STEELBLUE },
        {"TAN",                  TAN },
        {"TEAL",                 TEAL },
        {"THISTLE",              THISTLE },
        {"TOMATO",               TOMATO },
        {"TURQUOISE",            TURQUOISE },
        {"VIOLET",               VIOLET },
        {"WHEAT",                WHEAT },
        {"WHITE",                WHITE },
        {"WHITESMOKE",           WHITESMOKE },
        {"YELLOW",               YELLOW },
        {"YELLOWGREEN",          YELLOWGREEN }
    };
}