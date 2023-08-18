#include <math.h>
#include "ExtremeC_examples_chapter3_2_geometry.h"

double	to_radian(double deg)
{
	return ((PI * deg) / 180);
}

double to_degree(double rad)
{
	return ((PI * rad) / PI);
}

double cos_deg(double deg)
{
	return (cos(to_radian(deg)));
}

double acos_deg(double deg)
{
	return (acos(to_radian(deg)));
}

double sin_deg(double deg)
{
	return (sin(to_radian(deg)));
}

double asin_deg(double deg)
{
	return (asin(to_radian(deg)));
}
