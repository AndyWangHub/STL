#include "name.h"

std::istream& operator>>(std::istream &in, Name& name)
{
	// TODO: 在此处插入 return 语句
	in >> name.first >> name.second;
	return in;
}

std::ostream& operator<<(std::ostream &out, Name& name)
{
	// TODO: 在此处插入 return 语句
	cout << name.first << " " << name.second << endl;
	return out;
}
