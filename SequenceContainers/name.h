#pragma once
#include<iostream>
#include<string>

using namespace std;

class Name
{
private:
	std::string first{};
	std::string second{};

public:
	Name() = default;
	Name(const std::string& name1, const std::string& name2)
		:first(name1), second(name2) {}

	bool operator<(const Name& name)const
	{
		return second < name.second || (second == name.second && first < name.first);
	}
	friend std::istream& operator>>(std::istream &in, Name& name);
	friend std::ostream& operator<<(std::ostream &out, Name& name);

};

