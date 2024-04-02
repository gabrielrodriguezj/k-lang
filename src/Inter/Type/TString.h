#ifndef K_LANG_TSTRING_H
#define K_LANG_TSTRING_H


#include <string>
#include "TType.h"

class TString: public TType{
private:
    std::string value;
public:
    TString(std::string);
    std::string get();
};


#endif //K_LANG_TSTRING_H
