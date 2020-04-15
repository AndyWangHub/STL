#pragma once

#include<iostream>
#include<string>
#include"display.h"

using namespace std;

void seven()
{
    char ch[100] = { 0x11,0x22,0x00,0x33,'\0' };
    string str("12345678");
    str.assign(ch, 6);
    std::cout << str.length() << endl;
    str.assign(ch, 5);
    std::cout << str.length() << endl;
    str = ch;
    std::cout << str.length() << endl;

    str.assign(ch, 5);
    str.resize(10);
    for (int i = 0; i < str.size(); i++)
    {
        printf("str[%d] = %0X\n", i, str[i]);
    }
    str.copy(ch, 1, 2);

}