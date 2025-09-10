#include "logic_functions.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <assert.h>

bool is_zero(float number)
{
    assert(is_finite(number));

    const float epsilon = 1e-7f;
    return fabsf(number) < epsilon;
}

bool is_equal(float number_1, float number_2)
{
    return is_zero(number_1 - number_2);
}

bool is_nan(float number)
{
    return number != number;
}

bool is_inf(float number)
{
    return number < -FLT_MAX || number > FLT_MAX;
}

bool is_finite(float number)
{
    return !is_inf(number) && !is_nan(number);
}

bool is_digit(char ch)
{
    return (ch >= '0' && ch <= '9')? true : false;
}

bool is_symbol(int symbol)
{
    return (symbol >= 0 && symbol <= 255)? true : false;
}
