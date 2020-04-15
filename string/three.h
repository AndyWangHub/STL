#pragma once
#include<iostream>
#include<string>
#include<exception>
#include"display.h"

using namespace std;

void three()
{
    //C++ string获取字符串元素：[]和at()

    //为修改 string 字符串的内容，下标操作符 [] 和函数 at() 均返回字符的“引用”。
    //但当字符串的内存被重新分配以后，可能会发生执行错误
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
        temp = s[2]; //"获取字符 'c'
        temp_1 = s.at(2); //获取字符 'c'
        temp_2 = s[s.length()]; //未定义行为，返回字符'\0'，但Visual C++ 2012执行时未报错
        temp_3 = cS[cS.length()]; //指向字符 '\0'
//        temp_4 = s.at(s.length()); //程序异常
        temp_5 = cS.at(cS.length()); //程序异常
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