#include "name.h"

std::istream& operator>>(std::istream &in, Name& name)
{
	// TODO: �ڴ˴����� return ���
	in >> name.first >> name.second;
	return in;
}

std::ostream& operator<<(std::ostream &out, Name& name)
{
	// TODO: �ڴ˴����� return ���
	cout << name.first << " " << name.second << endl;
	return out;
}
