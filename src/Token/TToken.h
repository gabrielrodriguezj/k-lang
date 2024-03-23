#ifndef K_LANG_TTOKEN_H
#define K_LANG_TTOKEN_H

#include "TokenName.h"

class TToken{
private:
    TokenName name;
public:
    TToken(TokenName name){
        this->name = name;
    }

    TokenName getName(){
        return name;
    }
    virtual std::string toString(){return "";}
};
#endif //K_LANG_TTOKEN_H
