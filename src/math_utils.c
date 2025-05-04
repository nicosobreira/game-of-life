#include "math_utils.h"

bool minFloat(float a, float b)
{
	return (a < b);
}

bool maxFloat(float a, float b)
{
	return (a > b);
}

bool isDivisibleBy(int a, int divisor)
{
	return (a % divisor == 0);
}
