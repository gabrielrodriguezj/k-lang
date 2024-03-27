#ifndef K_LANG_TTOKEN_H
#define K_LANG_TTOKEN_H

#include "TokenName.h"

class TToken{
private:
    TokenName name;
    int line;
public:
    TToken(TokenName name, int line){
        this->name = name;
        this->line = line;
    }

    TokenName getName(){
        return name;
    }

    int getLine(){
        return line;
    }

    virtual std::string toString(){return "";}
};
#endif //K_LANG_TTOKEN_H
