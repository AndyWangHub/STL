#include<iostream>
#include<vector>
#include <iomanip> 
#include <algorithm>
#include<iterator>

using namespace std;

template<typename T>
void ShowSize(std::vector<T> & v)
{
	cout << "The size is : " << v.size() << endl; //显示实际元素个数
	cout << "The capacity is : " << v.capacity() << endl; //显示容量
}

template<typename T>
void display(std::vector<T>& v)
{
	for (auto& value : v)
	{
		cout << std::setw(4) << value;
	}
	cout << endl;
	for (size_t i = 0; i < v.size(); i++)
		cout << "-----";
	cout << endl;
}

int main()
{
	std::vector<size_t> primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 ,43 ,47 }; //初始化15个元素
	/* 向量大小问题 */
	ShowSize(primes);
	display(primes);
	//primes.resize(13); //修改实际元素个数
	primes.resize(17,7); //修改实际元素个数,并填充值
	ShowSize(primes);
	display(primes);
	primes.reserve(30); //修改容量
	ShowSize(primes);
	display(primes);
	
	/* 访问元素 */
	cout << "front: " << primes.front() << endl;
	cout << "back: " << primes.back() << endl;
	for (size_t i = 0; i < primes.size(); i++)
	{
		cout << std::setw(5) << primes[i];
	}
	cout << endl;

/*
	std::vector<double> data{ 32.5, 30.1, 36.3, 40.0, 39.2 };
	std::cout << "Enter additional data values separated by spaces or Ctrl+Z to end:" << std::endl;
	std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), std::back_inserter(data));
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "));
*/

	std::vector<std::string> words{};
	words.reserve(10);

	std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(words));
	
	display(words);

	std::cout << "Starting sort." << std::endl;
	bool out_of_order{ false };
	while (true)
	{
		for (auto first = words.begin() + 1; first != words.end(); ++first)
		{
			if (*(first - 1) > * first)
			{ // Out of order so swap them
				std::swap(*first, *(first - 1));
				out_of_order = true;
			}
		}
		if (!out_of_order)                      // If they are in order (no swaps necessary)...
			break;                                // ...we are done...
		out_of_order = false;                   // ...otherwise, go round again.
	}

	display(words);

	cout << endl;
	system("pause");
	return 0;
}