#include "Expression.h"

Constant::Constant(float _v) : value(_v)
{}

float Constant::Eval()
{
    return value;
}
