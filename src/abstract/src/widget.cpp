#ifdef DEBUG
    #include <sstream>
#endif

#include "../include/widget.hpp"

namespace abstract
{
    Widget::Widget()
    {
        this->m_displayType = DISPLAY_BLOCK;
        this->m_widgetType =  WIDGET_WIDGET;

        this->m_fullWidth  = false;
        this->m_fullHeight = false;

        this->m_contentHeight = false;
        this->m_contentWidth  = false;

        // position

        this->m_x = 0;
        this->m_y = 0;

        // dimensions

        this->m_width =  0;
        this->m_height = 0;

        // padding

        this->m_paddingLeft   = 0;
        this->m_paddingRight  = 0;
        this->m_paddingTop    = 0;
        this->m_paddingBottom = 0;

        // margin

        this->m_marginLeft   = 0;
        this->m_marginRight  = 0;
        this->m_marginTop    = 0;
        this->m_marginBottom = 0;

        // border size

        this->m_borderLeftWidth   = 0;
        this->m_borderRightWidth  = 0;
        this->m_borderTopWidth    = 0;
        this->m_borderBottomWidth = 0;

        // border color

        this->m_borderLeftColor   = BLACK;
        this->m_borderRightColor  = BLACK;
        this->m_borderTopColor    = BLACK;
        this->m_borderBottomColor = BLACK;

        // border style

        this->m_borderLeftStyle   = LINE_SOLID;
        this->m_borderRightStyle  = LINE_SOLID;
        this->m_borderTopStyle    = LINE_SOLID;
        this->m_borderBottomStyle = LINE_SOLID;

        // radius

        this->m_radiusTopLeft     = 0;
        this->m_radiusTopRight    = 0;
        this->m_radiusBottomLeft  = 0;
        this->m_radiusBottomRight = 0;

        // background color
        this->m_backgroundColor = WHITE;

        // text
        this->m_text          = "";
        this->m_fontFamily    = "";
        this->m_fontSize      = 0;
        this->m_textColor     = BLACK;
        this->m_lineHeight    = 0;
        this->m_letterSpacing = 0;
        this->m_fontWeight    = 0;

        // children

        this->m_parent = nullptr;
    }

    Widget::Widget(Widget* parent) : Widget()
    {
        if(parent == nullptr)
            return;

        parent->addChild(this);
    }

    Widget::Widget(Widget* parent, 
                   double x, 
                   double y) : Widget(parent)
    {
        this->m_x = x;
        this->m_y = y;
    }

    Widget::Widget(Widget* parent, 
                   double x, 
                   double y, 
                   double width, 
                   double height) : Widget(parent, x, y)
    {
        this->m_width  = width;
        this->m_height = height;
    }



    Widget::~Widget()
    {
        for(size_t i = 0; i < this->m_children.size(); i++)
        {
            if(m_children[i] != nullptr)
                delete m_children[i];
        }
    }

    // display type

    DisplayType Widget::displayType(void)
    {
        return this->m_displayType;
    }

    void Widget::setDisplayType(DisplayType displayType)
    {
        this->m_displayType = displayType;
    }

    // widget type

    WidgetType Widget::type(void)
    {
        return this->m_widgetType;
    }

    void Widget::setType(WidgetType widgetType)
    {
        this->m_widgetType = widgetType;
    }

    // position
    
    double Widget::x(void)
    {
        return this->m_x;
    }

    void Widget::setX(double x)
    {
        this->m_x = x;
    }

    double Widget::y(void)
    {
        return this->m_y;
    }

    void Widget::setY(double y)
    {
        this->m_y = y;
    }

    // absolute positions

    double Widget::absoluteY()
    {
        if( this->hasParent() )
        {
            return 
            (
                m_parent->absoluteY() + 
                m_parent->m_borderTopWidth +
                m_parent->m_paddingTop +
                m_marginTop +
                m_y
            );
        }
        else
        {
            return m_y + m_marginTop;
        }
    }

    double Widget::absoluteX()
    {
        if( this->hasParent() )
        {
            return 
            (
                m_parent->absoluteX() + 
                m_parent->m_borderLeftWidth +
                m_parent->m_paddingLeft +
                m_marginLeft +
                m_x
            );
        }
        else
        {
            return m_x + m_marginLeft;
        }
    }


    // automatic dimensions

    double Widget::width(void)
    {
        return this->m_width;
    }

    void Widget::setWidth(double width)
    {
        this->m_width = width;
    }

    double Widget::height(void)
    {
        return this->m_height;
    }

    void Widget::setHeight(double height)
    {
        this->m_height = height;
    }

    void Widget::setFullHeight(bool state)
    {
        this->m_fullHeight = state;
    }

    bool Widget::fullHeight(void)
    {
        return this->m_fullHeight;
    }

    void Widget::setFullWidth(bool state)
    {
        this->m_fullWidth = state;
    }

    bool Widget::fullWidth(void)
    {
        return this->m_fullWidth;
    }

    void Widget::setContentWidth(bool state)
    {
        this->m_contentWidth = state;
    }

    bool Widget::contentWidth(void)
    {
        return this->m_contentWidth;
    }

    void Widget::setContentHeight(bool state)
    {
        this->m_contentHeight = state;
    }

    bool Widget::contentHeight(void)
    {
        return this->m_contentHeight;
    }

    // padding

    double Widget::paddingLeft(void)
    {
        return this->m_paddingLeft;
    }

    void Widget::setPaddingLeft(double paddingLeft)
    {
        this->m_paddingLeft = paddingLeft;
    }

    double Widget::paddingRight(void)
    {
        return this->m_paddingRight;
    }

    void Widget::setPaddingRight(double paddingRight)
    {
        this->m_paddingRight = paddingRight;
    }

    double Widget::paddingTop(void)
    {
        return this->m_paddingTop;
    }

    void Widget::setPaddingTop(double paddingTop)
    {
        this->m_paddingTop = paddingTop;
    }

    double Widget::paddingBottom(void)
    {
        return this->m_paddingBottom;
    }

    void Widget::setPaddingBottom(double paddingBottom)
    {
        this->m_paddingBottom = paddingBottom;
    }

    void Widget::setPadding(double padding)
    {
        this->m_paddingLeft   = padding;
        this->m_paddingRight  = padding;
        this->m_paddingTop    = padding;
        this->m_paddingBottom = padding;

    }

    // margin

    double Widget::marginLeft(void)
    {
        return this->m_marginLeft;
    }

    void Widget::setMarginLeft(double marginLeft)
    {
        this->m_marginLeft = marginLeft;
    }

    double Widget::marginRight(void)
    {
        return this->m_marginRight;
    }

    void Widget::setMarginRight(double marginRight)
    {
        this->m_marginRight = marginRight;
    }

    double Widget::marginTop(void)
    {
        return this->m_marginTop;
    }

    void Widget::setMarginTop(double marginTop)
    {
        this->m_marginTop = marginTop;
    }

    double Widget::marginBottom(void)
    {
        return this->m_marginBottom;
    }

    void Widget::setMarginBottom(double marginBottom)
    {
        this->m_marginBottom = marginBottom;
    }

    void Widget::setMargin(double margin)
    {
        this->m_marginLeft   = margin;
        this->m_marginRight  = margin;
        this->m_marginTop    = margin;
        this->m_marginBottom = margin;
    }

    // outline color

    color_t Widget::outlineColor(void)
    {
        return this->m_outlineColor;
    }

    void Widget::setOutlineColor(color_t outlineColor)
    {
        this->m_outlineColor = outlineColor;
    }


    // outline offset

    double Widget::outlineOffset(void)
    {
        return this->m_outlineOffset;
    }

    void Widget::setOutlineOffset(double outlineOffset)
    {
        this->m_outlineOffset = outlineOffset;
    }

    // outline width

    double Widget::outlineWidth(void)
    {
        return this->m_outlineWidth;
    }

    void Widget::setOutlineWidth(double outlineWidth)
    {
        this->m_outlineWidth = outlineWidth;
    }

    // outline style

    void Widget::setOutlineStyle(LineStyle outlineStyle)
    {
        this->m_outlineStyle = outlineStyle;
    }

    LineStyle Widget::outlineStyle(void)
    {
        return this->m_outlineStyle;
    }

    // border width

    double Widget::borderLeftWidth(void)
    {
        return this->m_borderLeftWidth;
    }

    void Widget::setBorderLeftWidth(double borderLeftWidth)
    {
        this->m_borderLeftWidth = borderLeftWidth;
    }

    double Widget::borderRightWidth(void)
    {
        return this->m_borderRightWidth;
    }

    void Widget::setBorderRightWidth(double borderRightWidth)
    {
        this->m_borderRightWidth = borderRightWidth;

    }

    double Widget::borderTopWidth(void)
    {
        return this->m_borderTopWidth;
    }

    void Widget::setBorderTopWidth(double borderTopWidth)
    {
        this->m_borderTopWidth = borderTopWidth;
    }

    double Widget::borderBottomWidth(void)
    {
        return this->m_borderBottomWidth;
    }

    void Widget::setBorderBottomWidth(double borderRightWidth)
    {
        this->m_borderRightWidth = borderRightWidth;
    }

    void Widget::setBorderWidth(double borderWidth)
    {
        this->m_borderLeftWidth   = borderWidth;
        this->m_borderRightWidth  = borderWidth;
        this->m_borderTopWidth    = borderWidth;
        this->m_borderBottomWidth = borderWidth;
    }

    // border color

    color_t Widget::borderLeftColor(void)
    {
        return this->m_borderLeftColor;
    }

    void Widget::setBorderLeftColor(color_t borderLeftColor)
    {
        this->m_borderLeftColor = borderLeftColor;
    }

    color_t Widget::borderRightColor(void)
    {
        return this->m_borderRightColor;
    }

    void Widget::setBorderRightColor(color_t borderRightColor)
    {
        this->m_borderRightColor = borderRightColor;
    }

    color_t Widget::borderTopColor(void)
    {
        return this->m_borderTopColor;
    }

    void Widget::setBorderTopColor(color_t borderTopColor)
    {
        this->m_borderTopColor = borderTopColor;
    }

    color_t Widget::borderBottomColor(void)
    {
        return this->m_borderBottomColor;
    }

    void Widget::setBorderBottomColor(color_t borderRightColor)
    {
        this->m_borderRightColor = borderRightColor;
    }

    void Widget::setBorderColor(color_t borderColor)
    {
        this->m_borderTopColor    = borderColor;
        this->m_borderBottomColor = borderColor;
        this->m_borderLeftColor   = borderColor;
        this->m_borderRightColor  = borderColor;
    }

    // border style

    LineStyle Widget::borderLeftStyle(void)
    {
        return this->m_borderLeftStyle;
    }

    void Widget::setBorderLeftStyle(LineStyle borderStyle)
    {
        this->m_borderLeftStyle = borderStyle;
    }

    LineStyle Widget::borderRightStyle(void)
    {
        return this->m_borderRightStyle;
    }

    void Widget::setBorderRightStyle(LineStyle borderStyle)
    {
        this->m_borderRightStyle = borderStyle;
    }

    LineStyle Widget::borderTopStyle(void)
    {
        return this->m_borderTopStyle;
    }

    void Widget::setBorderTopStyle(LineStyle borderStyle)
    {
        this->m_borderTopStyle = borderStyle;
    }

    LineStyle Widget::borderBottomStyle(void)
    {
        return this->m_borderBottomStyle;
    }

    void Widget::setBorderBottomStyle(LineStyle borderStyle)
    {
        this->m_borderBottomStyle = borderStyle;
    }

    void Widget::setLineStyle(LineStyle borderStyle)
    {
        this->m_borderLeftStyle   = borderStyle;
        this->m_borderRightStyle  = borderStyle;
        this->m_borderTopStyle    = borderStyle;
        this->m_borderBottomStyle = borderStyle;
    }

    // radius

    double Widget::radiusTopLeft(void)
    {
        return this->m_radiusTopLeft;
    }

    void Widget::setRadiusTopLeft(double radiusTopLeft)
    {
        this->m_radiusTopLeft = radiusTopLeft;
    }

    double Widget::radiusTopRight(void)
    {
        return this->m_radiusTopRight;
    }

    void Widget::setRadiusTopRight(double radiusTopRight)
    {
        this->m_radiusTopRight = radiusTopRight;
    }

    double Widget::radiusBottomLeft(void)
    {
        return this->m_radiusBottomLeft;
    }

    void Widget::setRadiusBottomLeft(double radiusBottomLeft)
    {
        this->m_radiusBottomLeft = radiusBottomLeft;
    }

    double Widget::radiusBottomRight(void)
    {
        return this->m_radiusBottomRight;
    }

    void Widget::setRadiusBottomRight(double radiusBottomRight)
    {
        this->m_radiusBottomRight = radiusBottomRight;
    }

    void Widget::setRadius(double radius)
    {
        this->m_radiusTopLeft     = radius;
        this->m_radiusTopRight    = radius;
        this->m_radiusBottomLeft  = radius;
        this->m_radiusBottomRight = radius;
    }

    // background color

    void Widget::setBackgroundColor(color_t backgroundColor)
    {
        this->m_backgroundColor = backgroundColor;
    }

    color_t Widget::backgroundColor(void)
    {
        return this->m_backgroundColor;
    }

    // text

    std::string Widget::text(void)
    {
        return this->m_text;
    }

    void Widget::setText(const std::string& text)
    {
        this->m_text = text;
    }

    // font family
    FontFamily Widget::fontFamily(void)
    {
        return this->m_fontFamily;
    }

    void Widget::setFontFamily(FontFamily fontFamily)
    {
        this->m_fontFamily = fontFamily;
    }

    // font size
    double Widget::fontSize(void)
    {
        return this->m_fontSize;
    }

    void Widget::setFontSize(double fontSize)
    {
        this->m_fontSize = fontSize;
    }

    // text color
    color_t Widget::textColor(void)
    {
        return this->m_textColor;
    }

    void Widget::setTextColor(color_t textColor)
    {
        this->m_textColor = textColor;
    }

    // line height
    double Widget::lineHeight()
    {
        return this->m_lineHeight;
    }

    void Widget::setLineHeight(double lineHeight)
    {
        this->m_lineHeight = lineHeight;
    }

    // letter spacing

    double Widget::letterSpacing(void)
    {
        return this->m_letterSpacing;
    }

    void Widget::setLetterSpacing(double letterSpacing)
    {
        this->m_letterSpacing = letterSpacing;
    }

    // font weight

    double Widget::fontWeight(void)
    {
        return this->m_fontWeight;
    }

    void Widget::setFontWeight(double fontWeight)
    {
        this->m_fontWeight = fontWeight;
    }


    // children

    Widget* Widget::child(size_t i) 
    { 
        return this->m_children[i]; 
    }

    size_t Widget::children(void)
    {
        return this->m_children.size();
    }

    void Widget::addChild(Widget* widget) 
    { 
        if(widget == nullptr)
            return;

        m_children.push_back(widget);
        widget->m_parent = this;
    }

    // parent

    Widget* Widget::parent(void) 
    { 
        return this->m_parent;
    }

    Widget* Widget::root(void)
    {
        if(this->m_parent == nullptr)
            return this;
        else
            return this->m_parent->root();
    }

    bool Widget::hasParent(void)
    {
        return ( this->m_parent != nullptr );
    }

    size_t Widget::depth(void)
    {
        if( this->parent() == nullptr )
            return 0;
        else
            return (1 + parent()->depth());
    }

    Widget* Widget::previousSibling(void)
    {
        if( hasParent() )
        {
            for(size_t i = 0; i < parent()->children(); i++)
            {
                if( parent()->child(i) == this )
                {
                    if( i == 0 )
                        return nullptr;
                    else
                        return parent()->child(i-1);
                }
            }
        }

        return nullptr;
    }

    Widget* Widget::nextSibling(void)
    {
        if( hasParent() )
        {
            for(size_t i = 0; i < parent()->children(); i++)
            {
                if( parent()->child(i) == this )
                {
                    if( i == parent()->children() - 1 )
                        return nullptr;
                    else
                        return parent()->child(i+1);
                }
            }
        }

        return nullptr;
    }

    #ifdef DEBUG

        std::string WidgetTypeString (WidgetType type)
        {
            if (type == WIDGET_TEXT )  { return "Text"; }
            if (type == WIDGET_BOX )   { return "Box"; }
            if (type == WIDGET_TEXT )  { return "Text"; }
            if (type == WIDGET_WIDGET) { return "Widget"; }
            return "";
        }

        std::string Widget::asJSON(void)
        {
            std::stringstream jsontext;

            jsontext << "{" << std::endl;

            jsontext << "\"widgetType\" : \"" << WidgetTypeString(this->type()) << "\"," << std::endl;
            jsontext << "\"displayType\" : \"" << m_displayType << "\"," << std::endl;

            jsontext << "\"fullWidth\" : \""  << std::boolalpha << m_fullWidth << "\"," << std::endl;
            jsontext << "\"fullHeight\" : \"" << std::boolalpha << m_fullHeight << "\"," << std::endl;

            jsontext << "\"contentWidth\" : \""  << std::boolalpha << m_contentWidth << "\"," << std::endl;
            jsontext << "\"contentHeight\" : \"" << std::boolalpha << m_contentHeight << "\"," << std::endl;

            jsontext << "\"x\" : \"" << m_x << "\"," << std::endl;
            jsontext << "\"y\" : \"" << m_y << "\"," << std::endl;

            jsontext << "\"width\" : \"" << m_width << "\"," << std::endl;
            jsontext << "\"height\" : \"" << m_height << "\"," << std::endl;

            jsontext << "\"paddingLeft\" : \"" << m_paddingLeft << "\"," << std::endl;
            jsontext << "\"paddingRight\" : \"" << m_paddingRight << "\"," << std::endl;
            jsontext << "\"paddingTop\" : \"" << m_paddingTop << "\"," << std::endl;
            jsontext << "\"paddingBottom\" : \"" << m_paddingBottom << "\"," << std::endl;

            jsontext << "\"marginLeft\" : \"" << m_marginLeft << "\"," << std::endl;
            jsontext << "\"marginRight\" : \"" << m_marginRight << "\"," << std::endl;
            jsontext << "\"marginTop\" : \"" << m_marginTop << "\"," << std::endl;
            jsontext << "\"marginBottom\" : \"" << m_marginBottom << "\"," << std::endl;

            jsontext << "\"borderLeftWidth\" : \"" << m_borderLeftWidth << "\"," << std::endl;
            jsontext << "\"borderRightWidth\" : \"" << m_borderRightWidth << "\"," << std::endl;
            jsontext << "\"borderTopWidth\" : \"" << m_borderTopWidth << "\"," << std::endl;
            jsontext << "\"borderBottomWidth\" : \"" << m_borderBottomWidth << "\"," << std::endl;

            jsontext << "\"borderLeftColor\" : \"" << m_borderLeftColor << "\"," << std::endl;
            jsontext << "\"borderRightColor\" : \"" << m_borderRightColor << "\"," << std::endl;
            jsontext << "\"borderTopColor\" : \"" << m_borderTopColor << "\"," << std::endl;
            jsontext << "\"borderBottomColor\" : \"" << m_borderBottomColor << "\"," << std::endl;

            jsontext << "\"borderLeftStyle\" : \"" << m_borderLeftStyle << "\"," << std::endl;
            jsontext << "\"borderRightStyle\" : \"" << m_borderRightStyle << "\"," << std::endl;
            jsontext << "\"borderTopStyle\" : \"" << m_borderTopStyle << "\"," << std::endl;
            jsontext << "\"borderBottomStyle\" : \"" << m_borderBottomStyle << "\"," << std::endl;

            jsontext << "\"radiusTopLeft\" : \"" << m_radiusTopLeft << "\"," << std::endl;
            jsontext << "\"radiusTopRight\" : \"" << m_radiusTopRight << "\"," << std::endl;
            jsontext << "\"radiusBottomLeft\" : \"" << m_radiusBottomLeft << "\"," << std::endl;
            jsontext << "\"radiusBottomRight\" : \"" << m_radiusBottomRight << "\"," << std::endl;
            
            jsontext << "\"backgroundColor\" : \"" << m_backgroundColor << "\"," << std::endl;

            jsontext << "\"text\" : \""          << m_text          << "\"," << std::endl;
            jsontext << "\"fontFamily\" : \""    << m_fontFamily    << "\"," << std::endl;
            jsontext << "\"fontSize\" : \""      << m_fontSize      << "\"," << std::endl;
            jsontext << "\"textColor\" : \""     << m_textColor     << "\"," << std::endl;
            jsontext << "\"lineHeight\" : \""    << m_lineHeight    << "\"," << std::endl;
            jsontext << "\"letterSpacing\" : \"" << m_letterSpacing << "\"," << std::endl;
            jsontext << "\"fontWeight\" : \""    << m_fontWeight    << "\"," << std::endl;


            jsontext << "\"children\": ";
            jsontext << "[" << std::endl;
            for(size_t i = 0; i < m_children.size(); i++)
            {
                jsontext << m_children[i]->asJSON() << std::endl;
                jsontext << "," << std::endl;
            }

            jsontext << "]" << std::endl;
            jsontext << "}" << std::endl;

            return jsontext.str();
        }

        std::ostream& operator<<(std::ostream& os, Widget& widget)
        {
            os << widget.asJSON() << std::endl;
            return os;
        }
    #endif

} // namespace abstract