#ifndef K_LANG_STMTRETURN_H
#define K_LANG_STMTRETURN_H


#include "Statement.h"
#include "../Expression/Expression.h"

class StmtReturn: public Statement{
private:
    Token* keyword;
    Expression* value;
public:
    explicit StmtReturn(Token*, Expression*);

    void accept(VisitorStatement *visitor) override;

    Token *getKeyword() const;

    Expression *getValue() const;
};


#endif //K_LANG_STMTRETURN_H
