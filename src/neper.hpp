#ifndef __NEPER__
#define __NEPER__

#include "abstract/abstract.hpp"
#include "css/css.hpp"
#include "dom/dom.hpp"
#include "html/html.hpp"
#include "styles/styles.hpp"
#include "utils/utils.hpp"

abstract::Widget* buildAbstractFromHTML(const std::string& html);

#endif /* __NEPER__ */