#ifndef __ABSTRACT_WIDGET__
#define __ABSTRACT_WIDGET__

#ifdef DEBUG
    #include <iostream>
#endif 

#include <vector>

#include "color.hpp"

namespace abstract
{
    
    class Widget;

    typedef std::string FontFamily;

    typedef std::vector<Widget*> WidgetList;

    enum WidgetType
    {
        WIDGET_WIDGET,      // 0
        WIDGET_TEXT,        // 1
        WIDGET_BOX,         // 2
        WIDGET_BUTTON,      // 3
    };

    enum DisplayType
    {
        DISPLAY_BLOCK,           // 0
        DISPLAY_INLINE,          // 1
        DISPLAY_INLINE_BLOCK,    // 2
        DISPLAY_NONE             // 3
    };

    enum LineStyle
    {
        LINE_NONE,       // 0
        LINE_HIDDEN,     // 1
        LINE_DOTTED,     // 2
        LINE_DASHED,     // 3
        LINE_SOLID,      // 4
        LINE_DOUBLE,     // 5
        LINE_GROOVE,     // 6
        LINE_RIDGE,      // 7
        LINE_INSET,      // 8
        LINE_OUTSET      // 9
    };
    

    class Widget
    {
        public:

            /* constructors */

            Widget();
            Widget(Widget* parent);
            Widget(Widget* parent, double x, double y);
            Widget(Widget* parent, double x, double y, double width, double height);


            virtual ~Widget();


            // type 

            WidgetType type(void);
            void setType(WidgetType widgetType);

            // display type

            DisplayType displayType(void);
            void setDisplayType(DisplayType displayType);

            // position

            /*
                get the x position of the widget
            */

            double x(void);

            /*
                set the x position of the widget
            */
            void setX(double x);

            /*
                get the y position of the widget
            */
            double y(void);

            /*
                set the y position of the widget
            */
            void setY(double y);

            // absolute positions

            /*
                get the absolute y position of the widget
            */
            double absoluteY();

            /*
                get the absolute x position of the widget
            */
            double absoluteX();

            // dimensions

            /*
                get the width of the widget
            */
            double width(void);

            /*
                set the width of the widget
            */
            void setWidth(double width);

            /*
                get the height of the widget
            */
            double height(void);

            /*
                Set the height of the widget
            */
            void setHeight(double height);

            /*
                Set the state of the attribute "fullHeight"
            */
           void setFullHeight(bool state);

            /*
                Get the state of the attribute "fullHeight"
            */
           bool fullHeight(void);

            /*
                Set the state of the attribute "fullWidth"
            */
           void setFullWidth(bool state);

            /*
                Get the state of the attribute "fullWidth"
            */
           bool fullWidth(void);

            /*
                Set the state of the attribute "contentWidth"
            */
           void setContentWidth(bool state);

            /*
                Get the state of the attribute "contentWidth"
            */
           bool contentWidth(void);

            /*
                Set the state of the attribute "contentHeight"
            */
           void setContentHeight(bool state);

           /*
                Get the state of the attribute "contentHeight"
           */
           bool contentHeight(void);

            // padding

            /*
                Get the left padding of the widget
            */
            double paddingLeft(void);

            /*
                Set the left padding of the widget
            */
            void setPaddingLeft(double paddingLeft);

            /*
                get the right padding of the widget
            */
            double paddingRight(void);

            /*
                Set the right padding of the widget
            */
            void setPaddingRight(double paddingRight);

            /*
                Get the top padding of the widget
            */
            double paddingTop(void);

            /*
                Set the top padding of the widget
            */
            void setPaddingTop(double paddingTop);

            /*
                Get the bottom padding of the widget
            */
            double paddingBottom(void);

            /*
                Set the bottom padding of the widget
            */
            void setPaddingBottom(double paddingBottom);

            /*
                Set the global padding of the widget
            */
            void setPadding(double padding);

            // margin

            /*
                Get the left margin of the widget
            */
            double marginLeft(void);
            
            /*
                Set the left margin of the widget
            */
            void setMarginLeft(double marginLeft);

            /*
                Get the right margin of the widget
            */
            double marginRight(void);

            /*
                Set the right margin of the widget
            */
            void setMarginRight(double marginRight);

            /*
                Get the margin top of the widget
            */
            double marginTop(void);

            /*
                Set the top margin of the widget
            */
            void setMarginTop(double marginTop);

            /*
                Get the bottom margin of the widget
            */
            double marginBottom(void);

            /*
                Set the bottom margin of the widget
            */
            void setMarginBottom(double marginBottom);

            /*
                Set the global margin of the widget
            */
            void setMargin(double margin);

            // outline color

            /*
                Get outline color
            */
            color_t outlineColor(void);

            /*
                Set outline color
            */
            void setOutlineColor(color_t outlineColor);


            // outline offset

            /*
                Get outline offset
            */
            double outlineOffset(void);

            /*
                Set outline offset
            */
            void setOutlineOffset(double outlineOffset);

            // outline width

            /*
                Get outline width
            */
            double outlineWidth(void);

            /*
                Set outline width
            */
            void setOutlineWidth(double outlineWidth);

            // outline style

            /*
                Set outline style
            */
           void setOutlineStyle(LineStyle outlineStyle);

           /*
                Get outline style
           */
           LineStyle outlineStyle(void);


            // border size

            /*
                Get the width of the left border of the element
            */
            double borderLeftWidth(void);
            
            /*
                Set the width of the left border of the element
            */
            void setBorderLeftWidth(double borderLeftWidth);

            /*
                Get the width of the right border of the element
            */
            double borderRightWidth(void);

            /*
                Set the width of the right border of the element
            */
            void setBorderRightWidth(double borderRightWidth);

            /*
                Get the width of the top border of the element
            */
            double borderTopWidth(void);

            /*
                Set the width of the top border of the element
            */
            void setBorderTopWidth(double borderTopWidth);

            /*
                Get the width of the bottom border of the element
            */
            double borderBottomWidth(void);

            /*
                Set the width of the bottom border of the element
            */
            void setBorderBottomWidth(double borderRightWidth);

            /*
                Set the global border width of the element
            */
            void setBorderWidth(double borderWidth);

            // border color

            /*
                Get the color of the left border of the widget
            */
            color_t borderLeftColor(void);

            /*
                Set the color of the left border of the widget
            */
            void setBorderLeftColor(color_t borderLeftColor);

            /*
                Get the color of the right border of the widget
            */
            color_t borderRightColor(void);

            /*
                Set the color of the right border of the widget
            */
            void setBorderRightColor(color_t borderRightColor);

            /*
                Get the color of the top border of the widget
            */
            color_t borderTopColor(void);
            
            /*
                Set the color of the top border of the widget
            */
            void setBorderTopColor(color_t borderTopColor);

            /*
                Get the color of the bottom border of the widget
            */
            color_t borderBottomColor(void);

            /*
                Set the color of the bottom border of the widget
            */
            void setBorderBottomColor(color_t borderRightColor);

            /*
                Set the global color of the borders of the widget
            */
            void setBorderColor(color_t borderColor);

            // border style

            /*
                Get the border left style
            */
            LineStyle borderLeftStyle(void);

            /*
                Set the border left style
            */
            void setBorderLeftStyle(LineStyle borderStyle);

            /*
                Get the border left right
            */
            LineStyle borderRightStyle(void);

            /*
                Set the border right style
            */
            void setBorderRightStyle(LineStyle borderStyle);

            /*
                Get the border top style
            */
            LineStyle borderTopStyle(void);

            /*
                Set the border top style
            */
            void setBorderTopStyle(LineStyle borderStyle);

            /*
                Get the border bottom style
            */
            LineStyle borderBottomStyle(void);

            /*
                Set the border bottom style
            */
            void setBorderBottomStyle(LineStyle borderStyle);

            /*
                Set the global border style
            */
            void setLineStyle(LineStyle borderStyle);


            // radius

            /*
                Get the radius of the top left corner of the widget
            */
            double radiusTopLeft(void);

            /*
                Set the radius of the top left corner of the widget
            */
            void setRadiusTopLeft(double radiusTopLeft);

            /*
                Get the radius of the top right corner of the widget
            */
            double radiusTopRight(void);

            /*
                Set the radius of the top right corner of the widget
            */
            void setRadiusTopRight(double radiusTopRight);

            /*
                Get the radius of the bottom left corner of the widget
            */
            double radiusBottomLeft(void);

            /*
                Set the radius of the bottom left corner of the widget
            */
            void setRadiusBottomLeft(double radiusBottomLeft);

            /*
                Get the radius of the bottom right corner of the widget
            */
            double radiusBottomRight(void);

            /*
                Get the radius of the bottom right corner of the widget
            */
            void setRadiusBottomRight(double radiusBottomRight);

            /*
                Set the global radius of the widget
            */
            void setRadius(double radius);

            // background color

            void setBackgroundColor(color_t backgroundColor);
            color_t backgroundColor(void);

            // text

            std::string text(void);
            void setText(const std::string& text);

            // font family
            FontFamily fontFamily(void);
            void setFontFamily(FontFamily fontFamily);

            // font size
            double fontSize(void);
            void setFontSize(double fontSize);

            // text color
            color_t textColor(void);
            void setTextColor(color_t textColor);

            // line height
            double lineHeight();
            void setLineHeight(double lineHeight);

            // letter spacing

            double letterSpacing(void);
            void setLetterSpacing(double letterSpacing);

            // font weight

            double fontWeight(void);
            void setFontWeight(double fontWeight);

            // children

            /*
                Get the ith child of the widget
            */
            Widget* child(size_t i);

            /*
                Get the number if children
            */
           size_t children(void);

            /*
                Add child to the widget
            */
            void addChild(Widget* widget);

            // parent

            /*
                Get the parent of the widget
            */
            Widget* parent(void);

            /*
                Get the root of the widget
            */
            Widget* root(void);


            /*
                Return true if the widget has a prent
            */
           bool hasParent(void);

           size_t depth(void);


            Widget* previousSibling(void);
            Widget* nextSibling(void);

            #ifdef DEBUG

                std::string asJSON(void);

                friend std::ostream& operator<<(std::ostream& os, Widget& widget);
            #endif

            

        private:

            DisplayType m_displayType;
            WidgetType m_widgetType;

            // position

            double m_x;
            double m_y;

            // dimensions

            double m_width;
            double m_height;

            bool m_contentWidth;
            bool m_contentHeight;

            bool m_fullWidth;
            bool m_fullHeight;

            // padding

            double m_paddingLeft;
            double m_paddingRight;
            double m_paddingTop;
            double m_paddingBottom;

            // margin

            double m_marginLeft;
            double m_marginRight;
            double m_marginTop;
            double m_marginBottom;

            // outline
            
            color_t m_outlineColor;
            double  m_outlineOffset;
            double  m_outlineWidth;
            LineStyle m_outlineStyle;

            // border size

            double m_borderLeftWidth;
            double m_borderRightWidth;
            double m_borderTopWidth;
            double m_borderBottomWidth;

            // border color

            color_t m_borderLeftColor;
            color_t m_borderRightColor;
            color_t m_borderTopColor;
            color_t m_borderBottomColor;

            // border style

            LineStyle m_borderLeftStyle;
            LineStyle m_borderRightStyle;
            LineStyle m_borderTopStyle;
            LineStyle m_borderBottomStyle;

            // radius

            double m_radiusTopLeft;
            double m_radiusTopRight;
            double m_radiusBottomLeft;
            double m_radiusBottomRight;

            // background color
            color_t m_backgroundColor;

            // text

            std::string m_text;
            FontFamily m_fontFamily;
            double m_fontSize;
            color_t m_textColor;
            double m_lineHeight;
            double m_letterSpacing;
            double m_fontWeight;

            // children

            Widget*    m_parent;
            WidgetList m_children;
    };

} // namespace abstract



#endif /* __ABSTRACT_WIDGET__ */