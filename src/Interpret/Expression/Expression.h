#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H

#include <variant>
#include <string>
#include <vector>
#include "../TData.h"
#include "../../Token/IdToken.h"
#include "../../Visitor.h"

class Expression {
public:
    virtual void accept(Visitor *visitor) const = 0;
};


#endif //K_LANG_EXPRESSION_H
