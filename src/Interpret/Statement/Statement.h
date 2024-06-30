#ifndef K_LANG_STATEMENT_H
#define K_LANG_STATEMENT_H

#include "../Environment.h"
#include "../../Visitor.h"

class Statement {
public:
    virtual void accept(Visitor *visitor) const = 0;
};


#endif //K_LANG_STATEMENT_H
