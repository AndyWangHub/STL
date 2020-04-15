#pragma once
#include<iostream>
#include<string>
#include"display.h"

using namespace std;

void two()
{
	//String 类型对象包括三种求解字符串长度的函数：size() 和 length()、 maxsize() 和 capacity()：
	int size = 0;
	int length = 0;
	unsigned long maxsize = 0;
	int capacity = 0;
	std::string str("12345678");
	std::string str_custom;
	str_custom = str;
	str_custom.resize(5); //设置有限元素
	//str_custom.reserve(33); //设置容量

	size = str_custom.size();
	length = str_custom.length();
	maxsize = str_custom.max_size();
	capacity = str_custom.capacity(); //获取容量大小
	cout << "size = " << size << endl;
	cout << "length = " << length << endl;
	cout << "maxsize = " << maxsize << endl;
	cout << "capacity = " << capacity << endl;
}