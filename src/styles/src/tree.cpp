#include <regex>
#include <stack>

#include "../../abstract/abstract.hpp"
#include "../include/tree.hpp"
#include "../../utils/utils.hpp"

/*
    todo:
    - fix the *parent font size* arg
*/

namespace styles
{
    enum BoxSizing
    {
        CONTENT_BOX,    // 0
        BORDER_BOX      // 1
    };

    #define LINE_THIN   1
    #define LINE_MEDIUM 2
    #define LINE_THICK  3

    abstract::LineStyle parseLineStyle( const std::string& str )
    {
        if(str == "none")
        { return abstract::LINE_NONE; }

        if(str == "hidden")
        { return abstract::LINE_HIDDEN; }

        if(str == "dotted")
        { return abstract::LINE_DOTTED; }

        if(str == "dashed")
        { return abstract::LINE_DASHED; }

        if(str == "solid")
        { return abstract::LINE_SOLID; }

        if(str == "double")
        { return abstract::LINE_DOUBLE; }

        if(str == "groove")
        { return abstract::LINE_GROOVE; }

        if(str == "ridge")
        { return abstract::LINE_RIDGE; }

        if(str == "inset")
        { return abstract::LINE_INSET; }

        if(str == "oustset")
        { return abstract::LINE_OUTSET; }

        throw "Invalid linestyle";
        return abstract::LINE_NONE;
    }

    double parseLength( const std::string& str, double parentFontSize)
    {
        std::regex pxpattern ( "[0-9\\.]+px" );
        std::regex percentpattern ( "[0-9\\.]+%" );
        std::regex empattern ( "[0-9\\.]+em" );
        // std::regex hex24pattern 

        if (str == "0")
        {
            return 0;
        }

        else if( std::regex_match(str, empattern) )
        {
            double nem = std::stod( str.substr(0, str.size() - 2) );
            return nem * parentFontSize;
        }

        else if( std::regex_match(str, percentpattern) )
        {
            return std::stod( str.substr(1, str.size() - 2) );
        }

        else if( std::regex_match(str, pxpattern) )
        {
            return std::stod( str.substr(0, str.size() - 2) );
        }

        else
        {
            throw "Invalid unit";
            return 0;
        }
    }

    double parseLineWidth( const std::string& str, double parentFontSize )
    {
        if(str == "thin")
        { return LINE_THIN; }
        
        if(str == "medium")
        { return LINE_MEDIUM; }

        if(str == "thick")
        { return LINE_THICK; }

        return parseLength(str, parentFontSize);
    }

    abstract::color_t parseColor( const std::string& str )
    {

        std::regex rgbpattern("rgb\\([0-9]+,[0-9]+,[0-9]+\\)");
        std::regex rgbapattern("rgba\\([0-9]+,[0-9]+,[0-9]+,[01]\\.[0-9]+\\)");

        if( contains(toupper(str), abstract::x11Colors) )
        {
            return abstract::x11Colors[ toupper(str) ];
        }

        if(std::regex_match(str, rgbapattern))
        {
            std::vector<std::string> colors = split( str.substr(5, str.size() - 6), ',');

            uint8_t  r = std::stoi(colors[0]);
            uint8_t  g = std::stoi(colors[1]);
            uint8_t  b = std::stoi(colors[2]);
            float    a = std::stoi(colors[3]);

            return { r, g, b, a };

        }
        
        if( std::regex_match(str, rgbpattern) )
        {
            std::vector<std::string> colors = split( str.substr(4, str.size() - 5), ',');
            
            uint8_t   r = std::stoi(colors[0]);
            uint8_t   g = std::stoi(colors[1]);
            uint8_t   b = std::stoi(colors[2]);
            return { r, g, b, 1.0 };
        }
        
        throw "Invalid color";

        return abstract::BLACK;
    }

    /*
        Cette fonction créé un widget primitif
        (dépourvu de style) à partir d'un dom::node.

        Ce widget sera par la suite stylisé par la fonction
        abstractTree qui en fait usage.
    */
   
    abstract::Widget* createWidget( dom::Node* domNode )
    {
        std::string tag = toupper( domNode->tag() );
        
        abstract::Widget* widget = new abstract::Widget();

        if ( tag == "TEXT" )
        {
            widget->setType( abstract::WIDGET_TEXT );
            widget->setText( domNode->value() );
        }

        else if (tag == "BUTTON" )
        { widget->setType(abstract::WIDGET_BUTTON); }

        else if ( tag == "DIV" )
        { widget->setType(abstract::WIDGET_BOX); }

        else
        { /* default */ }

        return widget;

    }

    /*
        Cette fonction a pour but de construire récusivement 
        un abstract::tree à partir d'un dom::node en
        suivant à la lettre les styles du noeud
    */

    abstract::Widget* abstractExplicitValues( dom::Node* domNode )
    {
        abstract::Widget* root;

        BoxSizing boxSizing;

        if( domNode->styles["box-sizing"] == "border-box")
        { boxSizing = BORDER_BOX; }
        else
        { boxSizing = CONTENT_BOX; }

        root = createWidget( domNode );

        // analyse styles


        // accent-color
        // align-content
        // align-items
        // align-self
        // all
        // animation-delay
        // animation-direction
        // animation-duration
        // animation-fill-mode
        // animation-iteration-count
        // animation-name
        // animation-play-state
        // animation-timeline
        // animation-timing-function
        // appearance
        // aspect-ratio
        // backdrop-filter
        // backface-visibility
        // background-attachment
        // background-blend-mode
        // background-clip
        // background-color
        // background-image
        // background-origin
        // background-position
        // background-position-x
        // background-position-y
        // background-repeat
        // background-size
        // block-size
        // border-block
        // border-block-color
        // border-block-end
        // border-block-end-color
        // border-block-end-style
        // border-block-end-width
        // border-block-start
        // border-block-start-color
        // border-block-start-style
        // border-block-start-width
        // border-block-style
        // border-block-width
        // border-bottom-color

        if( !domNode->styles["border-bottom-color"].empty() )
        {
            /* <color> */

            try
            {
                abstract::color_t color = parseColor(domNode->styles["border-bottom-color"]);
                root->setBorderRightColor(color);
            }
            catch( const char* e ) { /* invalid color */ }
        }

        // border-bottom-left-radius
        // border-bottom-right-radius
        // border-bottom-style

        if( !domNode->styles["border-bottom-style"].empty() )
        {
            /* <line-style> */

            try
            {
                abstract::LineStyle linestyle = parseLineStyle(domNode->styles["border-bottom-style"]);
                root->setBorderBottomStyle(linestyle);
            }
            catch( const char* e ) { /* invalid line-style */ }
        }

        // border-bottom-width

        if( !domNode->styles["border-bottom-width"].empty() )
        {
            /* <line-width> */

            try
            {
                double linewidth = parseLineWidth(domNode->styles["border-bottom-width"], 16.0);
                root->setBorderBottomWidth(linewidth);

                if(boxSizing == BORDER_BOX)
                { root->setHeight( max(0, root->height() - linewidth) ); }
                else
                {}

            }
            catch( const char* e ) { /* invalid line width */ }
        }

        // border-collapse
        // border-end-end-radius
        // border-end-start-radius
        // border-image
        // border-image-outset
        // border-image-repeat
        // border-image-slice
        // border-image-source
        // border-image-width
        // border-inline
        // border-inline-color
        // border-inline-end
        // border-inline-end-color
        // border-inline-end-style
        // border-inline-end-width
        // border-inline-start
        // border-inline-start-color
        // border-inline-start-style
        // border-inline-start-width
        // border-inline-style
        // border-inline-width
        // border-left-color

        if( !domNode->styles["border-left-color"].empty() )
        {
            /* <color> */

            try
            {
                abstract::color_t color = parseColor(domNode->styles["border-left-color"]);
                root->setBorderLeftColor(color);
            }
            catch( const char* e ) { /* invalid color */ }
        }

        // border-left-style

        if( !domNode->styles["border-left-style"].empty() )
        {
            /* <line-style> */

            try
            {
                abstract::LineStyle linestyle = parseLineStyle(domNode->styles["border-left-style"]);
                root->setBorderLeftStyle(linestyle);
            }
            catch( const char* e ) { /* invalid line-style */ }
        }

        // border-left-width

        if( !domNode->styles["border-left-width"].empty() )
        {
            /* <line-width> */

            try
            {
                double linewidth = parseLineWidth(domNode->styles["border-left-width"], 16.0);
                root->setBorderLeftWidth(linewidth);

                if(boxSizing == BORDER_BOX)
                { root->setWidth( max(0, root->width() - linewidth) ); }
                else
                {}

            }
            catch( const char* e ) { /* invalid line width */ }
        }


        // border-right-color

        if( !domNode->styles["border-right-color"].empty() )
        {
            /* <color> */

            try
            {
                abstract::color_t color = parseColor(domNode->styles["border-right-color"]);
                root->setBorderRightColor(color);
            }
            catch( const char* e ) { /* invalid color */ }
        }

        // border-right-style
        
        if( !domNode->styles["border-right-style"].empty() )
        {
            /* <line-style> */

            try
            {
                abstract::LineStyle linestyle = parseLineStyle(domNode->styles["border-right-style"]);
                root->setBorderRightStyle(linestyle);
            }
            catch( const char* e ) { /* invalid line-style */ }
        }

        // border-right-width

        if( !domNode->styles["border-right-width"].empty() )
        {
            /* <line-width> */

            try
            {
                double linewidth = parseLineWidth(domNode->styles["border-right-width"], 16.0);
                root->setBorderRightWidth(linewidth);

                if(boxSizing == BORDER_BOX)
                { root->setWidth( max(0, root->width() - linewidth) ); }
                else
                {}
            }
            catch( const char* e ) { /* invalid line width */ }
        }

        // border-spacing
        // border-start-end-radius
        // border-start-start-radius
        // border-top-color

        if( !domNode->styles["border-top-color"].empty() )
        {
            /* <color> */

            try
            {
                abstract::color_t color = parseColor(domNode->styles["border-top-color"]);
                root->setBorderTopColor(color);
            }
            catch( const char* e ) { /* invalid color */ }
        }

        // border-top-left-radius
        // border-top-right-radius
        // border-top-style

        if( !domNode->styles["border-top-style"].empty() )
        {
            /* <line-style> */

            try
            {
                abstract::LineStyle linestyle = parseLineStyle(domNode->styles["border-top-style"]);
                root->setBorderTopStyle(linestyle);
            }
            catch( const char* e ) { /* invalid line-style */ }
        }

        // border-top-width

        if( !domNode->styles["border-top-width"].empty() )
        {
            /* <line-width> */

            try
            {
                double linewidth = parseLineWidth(domNode->styles["border-top-width"], 16.0);
                root->setBorderTopWidth(linewidth);
                
                if(boxSizing == BORDER_BOX)
                { root->setHeight( max(0, root->height() - linewidth) ); }
                else
                {}

            }
            catch( const char* e ) { /* invalid line width */ }
        }

        // bottom
        // box-decoration-break
        // box-shadow
        // break-after
        // break-before
        // break-inside
        // caption-side
        // caret-color
        // clear
        // clip
        // clip-path
        // color

        if( !domNode->styles["color"].empty() )
        {
            // <color>

            try
            {
                abstract::color_t color = parseColor(domNode->styles["color"]);

                if( domNode->tag() == "text" )
                {
                    root->setTextColor(color);
                }
            }
            catch(const char* e) { /* invalid color */ }
            
        }

        // color-scheme
        // column-count
        // column-fill
        // column-gap (grid-column-gap)
        // column-rule-color
        // column-rule-style
        // column-rule-width
        // column-span
        // column-width
        // contain
        // content
        // content-visibility
        // counter-increment
        // counter-reset
        // counter-set
        // cursor
        // direction
        // display

        if( !domNode->styles["display"].empty() )
        {
            const std::string value = domNode->styles["display"];

            if ( value == "block" )
            { root->setDisplayType(abstract::DISPLAY_BLOCK); }
            
            else if ( value == "inline" )
            { root->setDisplayType(abstract::DISPLAY_INLINE); }

            else if ( value == "inline-block" )
            { root->setDisplayType(abstract::DISPLAY_INLINE_BLOCK); }

            else if ( value == "none" )
            { root->setDisplayType(abstract::DISPLAY_NONE); }

            else
            {
                // unknow display type
                root->setDisplayType(abstract::DISPLAY_BLOCK);
            }

        }

        // empty-cells
        // filter
        // flex-basis
        // flex-direction
        // flex-grow
        // flex-shrink
        // flex-wrap
        // float
        // font-family
        // font-feature-settings
        // font-kerning
        // font-language-override
        // font-optical-sizing
        
        // font-size
        if( !domNode->styles["font-size"].empty() )
        {
            /* <length> | <percentage> */

            try
            {
                
                double length = parseLength(domNode->styles["font-size"], 16.0);
                root->setFontSize(length);
            }
            catch(const char* e) { /* invalid length */ }
        }

        // font-size-adjust
        // font-stretch
        // font-style
        // font-synthesis
        // font-variant
        // font-variant-alternates
        // font-variant-caps
        // font-variant-east-asian
        // font-variant-ligatures
        // font-variant-numeric
        // font-variant-position
        // font-variation-settings
        // font-weight
        // forced-color-adjust
        // gap (grid-gap)
        // grid-auto-columns
        // grid-auto-flow
        // grid-auto-rows
        // grid-column-end
        // grid-column-start
        // grid-row-end
        // grid-row-start
        // grid-template-areas
        // grid-template-columns
        // grid-template-rows
        // hanging-punctuation
        // height

        if( !domNode->styles["height"].empty() )
        {
            try
            {
                std::string value = domNode->styles["height"];

                if(value == "auto")
                {
                    root->setContentHeight(true);
                }
            }
            catch(const char* e) { /* invalid value */ }
            
            // auto | <length> | <percentage> | min-content | max-content | fit-content | fit-content(<length-percentage>)
            
        }

        // hyphenate-character
        // hyphens
        // image-rendering
        // image-resolution
        // ime-mode
        // initial-letter
        // initial-letter-align
        // inline-size
        // inset
        // inset-block
        // inset-block-end
        // inset-block-start
        // inset-inline
        // inset-inline-end
        // inset-inline-start
        // isolation
        // justify-content
        // justify-items
        // justify-self
        // left
        // letter-spacing
        // line-break
        // line-height
        // line-height-step
        // list-style-image
        // list-style-position
        // list-style-type
        // margin-block
        // margin-block-end
        // margin-block-start
        // margin-bottom

        if( !domNode->styles["margin-bottom"].empty() )
        {
            /* <length> | <percentage> | auto */
            try
            {
                double length = parseLength(domNode->styles["margin-bottom"], 16.0);
                root->setMarginBottom(length);
            }
            catch(const char* e) { /* invalid length */ }
        }

        // margin-inline
        // margin-inline-end
        // margin-inline-start
        // margin-left

        if( !domNode->styles["margin-left"].empty() )
        {
            /* <length> | <percentage> | auto */
            try
            {
                double length = parseLength(domNode->styles["margin-left"], 16.0);
                root->setMarginLeft(length);
            }
            catch(const char* e) { /* invalid length */ }
        }
        
        // margin-right

        if( !domNode->styles["margin-right"].empty() )
        {
            /* <length> | <percentage> | auto */
            try
            {
                double length = parseLength(domNode->styles["margin-right"], 16.0);
                root->setMarginRight(length);
            }
            catch(const char* e) { /* invalid length */ }
        }
        
        // margin-top
        if( !domNode->styles["margin-top"].empty() )
        {
            /* <length> | <percentage> | auto */
            try
            {
                double length = parseLength(domNode->styles["margin-top"], 16.0);
                root->setMarginTop(length);
            }
            catch(const char* e) { /* invalid length */ }
        }

        // margin-trim
        // mask
        // mask-border
        // mask-border-mode
        // mask-border-outset
        // mask-border-repeat
        // mask-border-slice
        // mask-border-source
        // mask-border-width
        // mask-clip
        // mask-composite
        // mask-image
        // mask-mode
        // mask-origin
        // mask-position
        // mask-repeat
        // mask-size
        // mask-type
        // max-block-size
        // max-height
        // max-inline-size
        // max-width
        // min-block-size
        // min-height
        // min-inline-size
        // min-width
        // mix-blend-mode
        // object-fit
        // object-position
        // offset-anchor
        // offset-distance
        // offset-path
        // offset-position
        // offset-rotate
        // opacity
        // order
        // orphans
        // outline-color

        if( !domNode->styles["outline-color"].empty() )
        {
            /* <color> | invert */

            try
            {
                abstract::color_t color = parseColor(domNode->styles["outline-color"]);
                root->setOutlineColor(color);
            }
            catch(const char* e) { /* invalid color */ }
            
        }

        // outline-offset

        if( !domNode->styles["outline-offset"].empty() )
        {
            /* <length> */

            try
            {   
                double length = parseLength(domNode->styles["outline-offset"], 16.0);
                root->setOutlineOffset(length);
            }
            catch(const char* e){ /* invalid value */}
        }

        // outline-style

        if( !domNode->styles["outline-style"].empty() )
        {
            /* auto | <'border-style'> */

            try
            {
                abstract::LineStyle linestyle = parseLineStyle(domNode->styles["outline-style"]);
                root->setLineStyle(linestyle);
            }
            catch(const char* e) { /* invalid value */ }
            
        }

        // outline-width

        if( !domNode->styles["outline-width"].empty() )
        {
            /* <line-width> */

            try
            {   
                double length = parseLineWidth(domNode->styles["outline-width"], 16.0);
                root->setOutlineWidth(length);
            }
            catch(const char* e){ /* invalid value */}
        }

        // overflow-anchor
        // overflow-block
        // overflow-clip-margin
        // overflow-inline
        // overflow-wrap
        // overflow-x
        // overflow-y
        // overscroll-behavior
        // overscroll-behavior-block
        // overscroll-behavior-inline
        // overscroll-behavior-x
        // overscroll-behavior-y
        // padding-block-end
        // padding-block-start
        // padding-bottom

        if( !domNode->styles["padding-bottom"].empty() )
        {
            /* <length> | <percentage> */

            try
            {
                double length = parseLength(domNode->styles["padding-bottom"], 16.0);
                root->setPaddingBottom(length);

                if(boxSizing == BORDER_BOX)
                { root->setHeight( max(0, root->height() - length) ); }                
                else
                {}
            }
            catch(const char* e) { /* invalid length */ }
        }

        // padding-inline-end
        // padding-inline-start
        // padding-left

        if( !domNode->styles["padding-left"].empty() )
        {
            /* <length> | <percentage> */

            try
            {
                double length = parseLength(domNode->styles["padding-left"], 16.0);
                root->setPaddingLeft(length);

                if(boxSizing == BORDER_BOX)
                { root->setWidth( max(0, root->width() - length) ); }                
                else
                {}
            }
            catch(const char* e) { /* invalid length */ }
        }

        // padding-right

        if( !domNode->styles["padding-right"].empty() )
        {
            /* <length> | <percentage> */

            try
            {
                double length = parseLength(domNode->styles["padding-right"], 16.0);
                root->setPaddingRight(length);

                if(boxSizing == BORDER_BOX)
                { root->setWidth( max(0, root->width() - length) ); }                
                else
                {}
            }
            catch(const char* e) { /* invalid length */ }
        }

        // padding-top
        
        if( !domNode->styles["padding-top"].empty() )
        {
            /* <length> | <percentage> */

            try
            {
                double length = parseLength(domNode->styles["padding-top"], 16.0);
                root->setPaddingTop(length);

                if(boxSizing == BORDER_BOX)
                { root->setHeight( max(0, root->height() - length) ); }                
                else
                {}
            }
            catch(const char* e) { /* invalid length */ }
        }

        // page-break-after
        // page-break-before
        // page-break-inside
        // perspective
        // perspective-origin
        // pointer-events
        // position
        // print-color-adjust
        // quotes
        // resize
        // right
        // rotate
        // row-gap (grid-row-gap)
        // ruby-align
        // ruby-position
        // scale
        // scroll-behavior
        // scroll-margin
        // scroll-margin-block
        // scroll-margin-block-end
        // scroll-margin-block-start
        // scroll-margin-bottom
        // scroll-margin-inline
        // scroll-margin-inline-end
        // scroll-margin-inline-start
        // scroll-margin-left
        // scroll-margin-right
        // scroll-margin-top
        // scroll-padding
        // scroll-padding-block-end
        // scroll-padding-block-start
        // scroll-padding-bottom
        // scroll-padding-inline
        // scroll-padding-inline-end
        // scroll-padding-inline-start
        // scroll-padding-left
        // scroll-padding-right
        // scroll-padding-top
        // scroll-snap-coordinate
        // scroll-snap-destination
        // scroll-snap-points-x
        // scroll-snap-points-y
        // scroll-snap-type
        // scrollbar-color
        // scrollbar-width
        // shape-image-threshold
        // shape-margin
        // shape-outside
        // tab-size
        // table-layout
        // text-align
        // text-align-last
        // text-combine-upright
        // text-decoration-color
        // text-decoration-line
        // text-decoration-skip
        // text-decoration-skip-ink
        // text-decoration-style
        // text-emphasis
        // text-emphasis-color
        // text-emphasis-position
        // text-emphasis-style
        // text-indent
        // text-justify
        // text-orientation
        // text-overflow
        // text-rendering
        // text-shadow
        // text-size-adjust
        // text-transform
        // text-underline-position
        // top
        // touch-action
        // transform
        // transform-box
        // transform-origin
        // transform-style
        // transition-delay
        // transition-duration
        // transition-property
        // transition-timing-function
        // translate
        // unicode-bidi
        // user-select
        // vertical-align
        // visibility
        // white-space
        // widows
        // width

        if( !domNode->styles["width"].empty() )
        {
            try
            {
                std::string value = domNode->styles["width"];

                if(value == "auto")
                {
                    root->setWidth(0);

                    int displayType = root->displayType();

                    if( displayType == abstract::DISPLAY_INLINE  ) {
                        root->setContentWidth(true);
                    }
                    else if( displayType == abstract::DISPLAY_BLOCK ) {
                        root->setFullWidth(true);
                    }
                    else
                    {
                        // unsupported for the moment
                    }

                }
                else
                {
                    // unsupported for the moment
                }
            }
            catch(const char* e) { /* invalid value */ }
            
            // auto | <length> | <percentage> | min-content | max-content | fit-content | fit-content(<length-percentage>)
            
        }

        // will-change
        // word-break
        // word-spacing
        // writing-mode
        // z-index


        /* récursivité */

        for(size_t i = 0; i < domNode->children(); i++)
        {
            root->addChild( abstractExplicitValues(domNode->child(i)) );
        }

        return root;
    }

    abstract::Widget* abstractTree( dom::Node* domNode )
    {
        abstract::Widget* root;
        
        root = abstractExplicitValues(domNode);

        return root;
    }



} // namespace styles