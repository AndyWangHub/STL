#include<iostream>
#include<string>
#include<map>
#include<utility>
#include <iomanip>
#include"name.h"

using namespace std;

using Entry = std::pair<const Name, size_t>;

template<typename T1,typename T2>
void display(std::map<T1, T2> m)
{
	for (auto v : m)
	{
		std::cout << std::left << std::setw(30) << v.first
			<< std::right << std::setw(4) << v.second << std::endl;
	}
}


// Create a map entry from input
Entry get_entry()
{
	std::cout << "Enter first and second names followed by the age: ";
	Name name{};
	size_t age{};
	std::cout << name;
	return make_pair(name, age);
}

int main()
{
#if 0

	//创建一个空的关联容器
	//std::map<std::string, size_t> people;

	//创建一个关联的容器并初始化
	//std::map<std::string, size_t> people{ {"Ann", 25}, {"Bill", 46},{"Jack", 32},{"Jill", 32} };
	std::map<std::string, size_t> people{ std::make_pair("Ann",25),std::make_pair("Bill", 46),std::make_pair("Jack", 32),std::make_pair("Jill", 32) };
	//display(people);
	
	auto ret_pr = people.insert(std::make_pair("Bill", 48)); //已经存在，插入失败演示
	std::cout << ret_pr.first->first << " " << ret_pr.first->second << " " << std::boolalpha << ret_pr.second << "\n";
	display(people);

	//用现有的容器来初始化
	//std::map<std::string, size_t> personnel {people};
	std::map<std::string, size_t>personnel{ std::begin(people),std::end(people) }; //可选择现有容器的部分
#endif // 0






	cout << endl;
	system("pause");
	return 0;
}