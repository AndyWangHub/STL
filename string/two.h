#pragma once
#include<iostream>
#include<string>
#include"display.h"

using namespace std;

void two()
{
	//String ���Ͷ��������������ַ������ȵĺ�����size() �� length()�� maxsize() �� capacity()��
	int size = 0;
	int length = 0;
	unsigned long maxsize = 0;
	int capacity = 0;
	std::string str("12345678");
	std::string str_custom;
	str_custom = str;
	str_custom.resize(5); //��������Ԫ��
	//str_custom.reserve(33); //��������

	size = str_custom.size();
	length = str_custom.length();
	maxsize = str_custom.max_size();
	capacity = str_custom.capacity(); //��ȡ������С
	cout << "size = " << size << endl;
	cout << "length = " << length << endl;
	cout << "maxsize = " << maxsize << endl;
	cout << "capacity = " << capacity << endl;
}