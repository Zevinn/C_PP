#include "Utilities.h"

double & ama::operator+=(double & total_s, const iProduct & src)
{
	return total_s += src.total_cost();
}

std::ostream & ama::operator<<(std::ostream & out, const iProduct & src)
{
	return src.write(out, 2);
}

std::istream & ama::operator>>(std::istream & in, iProduct & src)
{
	return src.read(in, true);
}

ama::iProduct* ama::createInstance(char tag)
{
	iProduct* p = nullptr;
	if (tag == 'N' || tag == 'n') {
		p = new Product();
	}
	return p;
}
