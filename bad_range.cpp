#include "bad_range.h"

const char* bad_range::what() const noexcept { return "!!!Выход за пределы массива!!!"; }
bad_range::bad_range() {}
bad_range::~bad_range() {}
