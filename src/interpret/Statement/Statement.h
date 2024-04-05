#ifndef K_LANG_STATEMENT_H
#define K_LANG_STATEMENT_H

#include "../Environment.h"

class Statement {
public:
    virtual void execute(Environment*) = 0;
};


#endif //K_LANG_STATEMENT_H
