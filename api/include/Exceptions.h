#pragma once
#include <stdexcept>
#include <sstream>

#define DECLARE_NEW_EXCEPTION_CLASS(classname) \
class classname : public std::runtime_error\
{\
public:\
    classname();\
};

#define IMPLEMENT_NEW_EXCEPTION_CLASS(classname, message) \
classname::classname()\
    : std::runtime_error(message)\


DECLARE_NEW_EXCEPTION_CLASS(EmptyList);
DECLARE_NEW_EXCEPTION_CLASS(InvalidNumberOfOperandInstruction);
DECLARE_NEW_EXCEPTION_CLASS(InvalidOperandException);



IMPLEMENT_NEW_EXCEPTION_CLASS(EmptyList, "the list is empty") {}
IMPLEMENT_NEW_EXCEPTION_CLASS(InvalidNumberOfOperandInstruction, "Invalid number of operand.") {}
IMPLEMENT_NEW_EXCEPTION_CLASS(InvalidOperandException, "Operand is invalid.") {}