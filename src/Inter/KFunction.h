#ifndef K_LANG_KFUNCTION_H
#define K_LANG_KFUNCTION_H


#include "Statement/StmtFunction.h"

class KFunction: public KCallable{
private:
    StmtFunction* declaration;
    Environment closure;
    bool isInitializer;
public:
    KFunction(StmtFunction *declaration, const Environment &closure, bool isInitializer);
    KFunction* bind();

    int arity() override;

    TData call(Environment *environment, std::list<TData> arguments) override;
};


#endif //K_LANG_KFUNCTION_H
