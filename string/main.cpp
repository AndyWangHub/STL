/*
string ���ṩ�ĸ��ֲ����������·�Ϊ���ࣺ
������������������С��������Ԫ�ش�ȡ���� �����Ƚϡ��ַ����޸ġ��ַ����Ӻϡ�I/O �����Լ������Ͳ��ҡ�
*/
#include<iostream>
#include<string>
#include"display.h"

int main()
{
	//������string�๹�캯�������¼�����ʽ��
	std::string str("12345678");
	char ch[] = "abcdefgh";
	std::string a; //����һ�����ַ���
	std::string str_1(str); //���캯����ȫ������
	std::string str_2(str, 2, 5); //���캯�������ַ���str�ĵڶ���Ԫ�ؿ�ʼ������5��Ԫ�أ���ֵ��str_2;
	std::string str_3(ch, 5); //���ַ�����ǰ5��Ԫ�ظ�ֵ��str_3
	std::string str_4(5, 'X'); //��5��"X"��ɵ��ַ�������ֵ��str_4
	std::string str_5(str.begin(), str.end()); //����str����Ԫ�أ������Ƹ�str_5

	display(str);
	display(ch);
	display(str_1);
	display(str_2);
	display(str_3);
	display(str_4);
	display(str_5);

	system("pause");
	return 0;
}