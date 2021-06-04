#include "Utilities.h"

double & ama::operator+=(double & total_s, const Product & src)
{
	return total_s += src.total_cost();
}

std::ostream & ama::operator<<(std::ostream & out, const Product & src)
{
	return src.write(out, 2);
}

std::istream & ama::operator>>(std::istream & in, Product & src)
{
	return src.read(in, true);
}
