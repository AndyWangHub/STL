#pragma once
#include<iostream>
#include<string>
#include"display.h"

using namespace std;

void four()
{
	//compare()����,�Ƚ��ַ���

	string A("aBcdef");
	string B("AbcdEf");
	string C("123456");
	string D("123dfg");
	//�����Ǹ��ֱȽϷ���
	int m = A.compare(B); //������A��B�ıȽ�
	int n = A.compare(1, 5, B, 4, 2); //"Bcdef"��"AbcdEf"�Ƚ�
	int p = A.compare(1, 5, B, 4, 2); //"Bcdef"��"Ef"�Ƚ�
	int q = C.compare(0, 3, D, 0, 3); //"123"��"123"�Ƚ�
	cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;
	cin.get();
	
}