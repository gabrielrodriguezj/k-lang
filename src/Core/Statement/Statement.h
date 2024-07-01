#ifndef K_LANG_STATEMENT_H
#define K_LANG_STATEMENT_H

#include "../../Environment.h"
#include "../../VisitorStatement.h"

class Statement {
public:
    virtual void accept(VisitorStatement *visitor) = 0;
};


#endif //K_LANG_STATEMENT_H
