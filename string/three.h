#pragma once
#include<iostream>
#include<string>
#include<exception>
#include"display.h"

using namespace std;

void three()
{
    //C++ string��ȡ�ַ���Ԫ�أ�[]��at()

    //Ϊ�޸� string �ַ��������ݣ��±������ [] �ͺ��� at() �������ַ��ġ����á���
    //�����ַ������ڴ汻���·����Ժ󣬿��ܻᷢ��ִ�д���
    const std::string cS("c.biancheng.net");
    std::string s("abcde");
    char temp = 'X';
    char temp_1 = 'X';
    char temp_2 = 'X';
    char temp_3 = 'X';
    char temp_4 = 'X';
    char temp_5 = 'X';
    try
    {
        temp = s[2]; //"��ȡ�ַ� 'c'
        temp_1 = s.at(2); //��ȡ�ַ� 'c'
        temp_2 = s[s.length()]; //δ������Ϊ�������ַ�'\0'����Visual C++ 2012ִ��ʱδ����
        temp_3 = cS[cS.length()]; //ָ���ַ� '\0'
//        temp_4 = s.at(s.length()); //�����쳣
        temp_5 = cS.at(cS.length()); //�����쳣
    }
    catch (const std::exception& e)
    {
       cout << e.what() << endl;
    }
   catch (...)
    {
       cout << "extremely" << endl;
    }

    std::cout << temp << ", " << temp_1 << ", " << temp_2 << ", " << temp_3 << ", " << temp_4 << ", " << temp_5 << ", " << std::endl;

}