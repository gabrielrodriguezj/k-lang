#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H

#include <variant>
#include <string>
#include <vector>
#include "../KData.h"
#include "../../Core/Token/IdToken.h"
#include "VisitorExpression.h"

class Expression {
public:
    virtual KData accept(VisitorExpression *visitor) = 0;
};


#endif //K_LANG_EXPRESSION_H
