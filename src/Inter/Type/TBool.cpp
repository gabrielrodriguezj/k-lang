#include "TBool.h"

TBool::TBool(bool value): value(value){}

bool TBool::get() {
    return value;
}