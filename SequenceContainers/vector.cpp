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
		cout << std::setw(7) << value << " ";
	}
//	cout << endl;
//	for (size_t i = 0; i < v.size(); i++)
//		cout << "-----";
	cout << endl;
}

template<class T>
void show(std::vector<T> & v)
{
	ShowSize(v);
	display(v);
	cout << "------------------------" << endl;
}

int main()
{
#if 0

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

	std::cout << "your words in ascending sequence:" << std::endl;
	std::copy(std::begin(words), std::end(words), std::ostream_iterator < string > {std::cout, " "});
	std::cout << std::endl;
	// Create a new vector by moving elements from words vector
	vector<string> words_copy{ std::make_move_iterator(std::begin(words)),std::make_move_iterator(std::end(words)) };
	std::cout << "\nAfter moving elements from words, words_copy contains:" << std::endl;
	std::copy(std::begin(words_copy), std::end(words_copy), std::ostream_iterator < string > {std::cout, " "});
	std::cout << std::endl;
	// See what's happened to elements in words vector...
	std::cout << "\nwords vector has " << words.size() << " elements\n";
	if (words.front().empty())
		std::cout << "First element is empty string object." << std::endl;
	std::cout << "First element is \"" << words.front() << "\"" << std::endl;

#endif // 0

	//vector 尾部添加数据
#if 0
	std::vector<std::string> words{};
	ShowSize(words);
	
	words.push_back(string("one"));
	words.emplace_back("two");
	std::string str{ "alleged" };
	words.emplace_back(str, 2, 3);
	ShowSize(words);
	display(words);
#endif // 0

	//vector 中间插入数据
#if 0
	std::vector<std::string> words{ "first","second" };
	/*
	emplace() 的第一个参数是一个迭代器，它确定了对象生成的位置。对象会被插入到迭代器所指定元素的后面。
	第一个参数后的参数，都作为插入元素的构造函数的参数传入
	emplace() 会返回一个指向横入元素的迭代器
	*/
	auto iter = words.emplace(++std::begin(words), 5, 'A');
	display(words);

	words.emplace(++iter, "$$$$"); //emplace 插入单个元素
	display(words);

	std::string more[] = { "five","six","seven" };
	//插入一个由第二个和第三个参数指定的元素序列
	iter = words.insert(--std::end(words), std::begin(more), std::end(more));
	display(words);

	//插入单个元素
	words.insert(iter, "two"); 
	display(words);

	// 在插入点插入多个单个元素。第二个参数是第三个参数所指定对象的插入次数
	iter = words.insert(std::cend(words)-1, 2, "nine");
	display(words);

	//在插入点，插入初始化列表指定的元素。第二个参数就是被插入元素的初始化列表
	iter = words.insert(std::end(words), { std::string {"twelve"},std::string {"thirteen"} });
	display(words);

	/*
	fmd() 算法会在头两个参数所指定的一段元素中，搜索第三个参数指定的元素，返回第一个找到的元素，
	因此会找到 String("one")。它会返回一个迭代器，这个迭代器和用来指定搜索范围的迭代器有相同的类型，
	是一个指向匹配元素的反向迭代器。如果没有找到匹配的元素，那么它就是指向第一个元素之前位置的迭代器 
	rend(str)。使用反向迭代器意味着 fmd()会找到最后匹配的元素；使用标准迭代器会找到第一个匹配的元素，
	如果没有匹配的元素，会返回 end(str)。
	*/
	std::vector<std::string> str{ "one", "two", "one", "three" };
	auto riter = std::find(std::rbegin(str), std::rend(str), "one");
	str.insert(riter.base(), "five"); //调用 riter 的成员函数 base() 可以得到一个标准迭代器
	display(str);
#endif // 0

#if 0
	std::vector<int> data(10, 9);
	show(data);

	//删除容器尾部的元素
	data.pop_back();
	show(data);

	//去掉容器中多余的容量
	data.shrink_to_fit();
	show(data);

	//删除全部元素
	data.clear(); 
	show(data);
	if (data.empty())
		cout << "data.empty" << endl;
#endif // 0


	//成员函数 erase() 来删除容器中的一个或多个元素
#if 0

	std::vector<size_t> v;
	v.reserve(10U);
	for (size_t i = 0; i < 10U; i++)
	{
		v.emplace_back(i);
	}
	show(v);

	v.erase(--std::end(v)); //指定删除单个元素
	v.push_back(6U);
	show(v);

	v.erase(std::begin(v), std::begin(v)+5); //指定删除多个相连元素
	show(v);

	v.erase(std::remove(std::begin(v), std::end(v), 6), std::end(v)); //删除指定元素
	show(v);

#endif // 0


#if 1
	/*
	不同编译器的输出结果可能不同，这取决于用来增加 vector 容量的算法。从第一组的输出可以看出，
	当开始使用一个空的 vector 时，需要频繁地分配更多的内存，因为容量增量很小——内存从一个元素开始增加。
	其他组的输出表明，容量增量和容器的大小相关。每次分配，会额外分配相当于当前元素数目 50% 的内存。
	这意味着在能够选择容器初始大小时，需要注意一些事情。

	假设生成了一个初始容量为 1000 个元素的 vector，但实际上存储了 1001 个元素。
	这样就会有用于 499 个元素的多余容量。如果元素是数组或其他不会占用太多空间的对象，这不会有任何问题。
	但是如果对象非常大，例如每个 10KB，那么程序需要分配几乎 5MB 的多余内存。所以，
	最好可以稍微高估 vector 的初始大小，而不能低估。
	*/
	std::vector <size_t> sizes;                    // Record numbers of elements
	std::vector <size_t> capacities;               // and corresponding capacities
	size_t el_incr{ 10 };                           // Increment to initial element count
	size_t incr_count{ 4 * el_incr };               // Number of increments to element count
	for (size_t n_elements{}; n_elements < incr_count; n_elements += el_incr)
	{
		std::vector<int> values(n_elements);
		std::cout << "\nAppending to a vector with " << n_elements << " initial elements:\n";
		sizes.push_back(values.size());
		size_t space{ values.capacity() };
		capacities.push_back(space);
		// Append elements to obtain capacity increases
		size_t count{};                             // Counts capacity increases
		size_t n_increases{ 10 };
		while (count < n_increases)
		{
			values.push_back(22);                      // Append a new element
			if (space < values.capacity())             // Capacity increased...
			{                                            // ...so record size and capacity
				space = values.capacity();
				capacities.push_back(space);
				sizes.push_back(values.size());
				++count;
			}
		}
		// Show sizes & capacities when increments occur
		std::cout << "Size/Capacity: ";
		for (size_t i{}; i < sizes.size(); ++i)
			std::cout << sizes.at(i) << "/" << capacities.at(i) << "  ";
		std::cout << std::endl;
		sizes.clear();                               // Remove all elements
		capacities.clear();                          // Remove all elements
	}
#endif // 0

	cout << endl;
	system("pause");
	return 0;
}