#ifndef K_LANG_STMTPRINT_H
#define K_LANG_STMTPRINT_H


#include "Statement.h"
#include "../Expression/Expression.h"

class StmtPrint: public Statement{
private:
    Expression* expression;
public:
    explicit StmtPrint(Expression *expression);

    void accept(Visitor *visitor) override;
};


#endif //K_LANG_STMTPRINT_H
