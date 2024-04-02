#include "TString.h"

TString::TString(std::string  value): value(value){}

std::string  TString::get() {
    return value;
}