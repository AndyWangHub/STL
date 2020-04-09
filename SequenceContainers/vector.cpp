#include<iostream>
#include<vector>
#include <iomanip> 
#include <algorithm>
#include<iterator>

using namespace std;

template<typename T>
void ShowSize(std::vector<T> & v)
{
	cout << "The size is : " << v.size() << endl; //��ʾʵ��Ԫ�ظ���
	cout << "The capacity is : " << v.capacity() << endl; //��ʾ����
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

	std::vector<size_t> primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 ,43 ,47 }; //��ʼ��15��Ԫ��
	/* ������С���� */
	ShowSize(primes);
	display(primes);
	//primes.resize(13); //�޸�ʵ��Ԫ�ظ���
	primes.resize(17,7); //�޸�ʵ��Ԫ�ظ���,�����ֵ
	ShowSize(primes);
	display(primes);
	primes.reserve(30); //�޸�����
	ShowSize(primes);
	display(primes);
	
	/* ����Ԫ�� */
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

	//vector β���������
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

	//vector �м��������
#if 0
	std::vector<std::string> words{ "first","second" };
	/*
	emplace() �ĵ�һ��������һ������������ȷ���˶������ɵ�λ�á�����ᱻ���뵽��������ָ��Ԫ�صĺ��档
	��һ��������Ĳ���������Ϊ����Ԫ�صĹ��캯���Ĳ�������
	emplace() �᷵��һ��ָ�����Ԫ�صĵ�����
	*/
	auto iter = words.emplace(++std::begin(words), 5, 'A');
	display(words);

	words.emplace(++iter, "$$$$"); //emplace ���뵥��Ԫ��
	display(words);

	std::string more[] = { "five","six","seven" };
	//����һ���ɵڶ����͵���������ָ����Ԫ������
	iter = words.insert(--std::end(words), std::begin(more), std::end(more));
	display(words);

	//���뵥��Ԫ��
	words.insert(iter, "two"); 
	display(words);

	// �ڲ�������������Ԫ�ء��ڶ��������ǵ�����������ָ������Ĳ������
	iter = words.insert(std::cend(words)-1, 2, "nine");
	display(words);

	//�ڲ���㣬�����ʼ���б�ָ����Ԫ�ء��ڶ����������Ǳ�����Ԫ�صĳ�ʼ���б�
	iter = words.insert(std::end(words), { std::string {"twelve"},std::string {"thirteen"} });
	display(words);

	/*
	fmd() �㷨����ͷ����������ָ����һ��Ԫ���У���������������ָ����Ԫ�أ����ص�һ���ҵ���Ԫ�أ�
	��˻��ҵ� String("one")�����᷵��һ�������������������������ָ��������Χ�ĵ���������ͬ�����ͣ�
	��һ��ָ��ƥ��Ԫ�صķ�������������û���ҵ�ƥ���Ԫ�أ���ô������ָ���һ��Ԫ��֮ǰλ�õĵ����� 
	rend(str)��ʹ�÷����������ζ�� fmd()���ҵ����ƥ���Ԫ�أ�ʹ�ñ�׼���������ҵ���һ��ƥ���Ԫ�أ�
	���û��ƥ���Ԫ�أ��᷵�� end(str)��
	*/
	std::vector<std::string> str{ "one", "two", "one", "three" };
	auto riter = std::find(std::rbegin(str), std::rend(str), "one");
	str.insert(riter.base(), "five"); //���� riter �ĳ�Ա���� base() ���Եõ�һ����׼������
	display(str);
#endif // 0

#if 0
	std::vector<int> data(10, 9);
	show(data);

	//ɾ������β����Ԫ��
	data.pop_back();
	show(data);

	//ȥ�������ж��������
	data.shrink_to_fit();
	show(data);

	//ɾ��ȫ��Ԫ��
	data.clear(); 
	show(data);
	if (data.empty())
		cout << "data.empty" << endl;
#endif // 0


	//��Ա���� erase() ��ɾ�������е�һ������Ԫ��
#if 0

	std::vector<size_t> v;
	v.reserve(10U);
	for (size_t i = 0; i < 10U; i++)
	{
		v.emplace_back(i);
	}
	show(v);

	v.erase(--std::end(v)); //ָ��ɾ������Ԫ��
	v.push_back(6U);
	show(v);

	v.erase(std::begin(v), std::begin(v)+5); //ָ��ɾ���������Ԫ��
	show(v);

	v.erase(std::remove(std::begin(v), std::end(v), 6), std::end(v)); //ɾ��ָ��Ԫ��
	show(v);

#endif // 0


#if 1
	/*
	��ͬ�����������������ܲ�ͬ����ȡ������������ vector �������㷨���ӵ�һ���������Կ�����
	����ʼʹ��һ���յ� vector ʱ����ҪƵ���ط��������ڴ棬��Ϊ����������С�����ڴ��һ��Ԫ�ؿ�ʼ���ӡ�
	�������������������������������Ĵ�С��ء�ÿ�η��䣬���������൱�ڵ�ǰԪ����Ŀ 50% ���ڴ档
	����ζ�����ܹ�ѡ��������ʼ��Сʱ����Ҫע��һЩ���顣

	����������һ����ʼ����Ϊ 1000 ��Ԫ�ص� vector����ʵ���ϴ洢�� 1001 ��Ԫ�ء�
	�����ͻ������� 499 ��Ԫ�صĶ������������Ԫ�����������������ռ��̫��ռ�Ķ����ⲻ�����κ����⡣
	�����������ǳ�������ÿ�� 10KB����ô������Ҫ���伸�� 5MB �Ķ����ڴ档���ԣ�
	��ÿ�����΢�߹� vector �ĳ�ʼ��С�������ܵ͹���
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