/*
string 类提供的各种操作函数大致分为八类：
构造器和析构器、大小和容量、元素存取、字 符串比较、字符串修改、字符串接合、I/O 操作以及搜索和查找。
*/
#include<iostream>
#include<string>
#include"display.h"

using namespace std;

int main()
{
	//常见的string类构造函数有以下几种形式：
#if 0
	std::string str("12345678");
	char ch[] = "abcdefgh";
	std::string a; //定义一个空字符串
	std::string str_1(str); //构造函数，全部复制
	std::string str_2(str, 2, 5); //构造函数，从字符串str的第二个元素开始，复制5个元素，赋值给str_2;
	std::string str_3(ch, 5); //将字符串的前5个元素赋值给str_3
	std::string str_4(5, 'X'); //将5个"X"组成的字符串并赋值给str_4
	std::string str_5(str.begin(), str.end()); //复制str所有元素，并复制给str_5

	display(str);
	display(ch);
	display(str_1);
	display(str_2);
	display(str_3);
	display(str_4);
	display(str_5);

#endif // 0


//String 类型对象包括三种求解字符串长度的函数：size() 和 length()、 maxsize() 和 capacity()：
#if 0
	int size = 0;
	int length = 0;
	unsigned long maxsize = 0;
	int capacity = 0;
	std::string str("12345678");
	std::string str_custom;
	str_custom = str;
	str_custom.resize(5);
	//str_custom.reserve(5);
	size = str_custom.size();
	length = str_custom.length();
	maxsize = str_custom.max_size();
	capacity = str_custom.capacity();
	cout << "size = " << size << endl;
	cout << "length = " << length << endl;
	cout << "maxsize = " << maxsize << endl;
	cout << "capacity = " << capacity << endl;
	
#endif
	//C++ string获取字符串元素：[]和at()
#if 0
	//为修改 string 字符串的内容，下标操作符 [] 和函数 at() 均返回字符的“引用”。
	//但当字符串的内存被重新分配以后，可能会发生执行错误
	    const std::string cS ("c.biancheng.net");
    std::string s ("abode");
    char temp =0;
    char temp_1 = 0;
    char temp_2 = 0;
    char temp_3 = 0;
    char temp_4 = 0;
    char temp_5 = 0;
    temp = s [2]; //"获取字符 'c'
    temp_1 = s.at(2); //获取字符 'c'
    temp_2 = s [s.length()]; //未定义行为，返回字符'\0'，但Visual C++ 2012执行时未报错
    temp_3 = cS[cS.length()]; //指向字符 '\0'
    temp_4 = s.at (s.length ()); //程序异常
    temp_5 = cS.at(cS.length ()); //程序异常
    std::cout << temp <<temp_1 << temp_2 << temp_3 << temp_4 << temp_5 << std::endl;
#endif // 0

	//compare()函数,比较字符串
#if 0
	string A("aBcdef");
	string B("AbcdEf");
	string C("123456");
	string D("123dfg");
	//下面是各种比较方法
	int m = A.compare(B); //完整的A和B的比较
	int n = A.compare(1, 5, B, 4, 2); //"Bcdef"和"AbcdEf"比较
	int p = A.compare(1, 5, B, 4, 2); //"Bcdef"和"Ef"比较
	int q = C.compare(0, 3, D, 0, 3); //"123"和"123"比较
	cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;
	cin.get();
#endif // 0

	//字符串内容的修改
#if 0
    string str1("123456");
    string str2("abcdefghijklmn");
    string str;
    str.assign(str1);
    cout << str << endl;
    str.assign(str1, 3, 3);
    cout << str << endl;
    str.assign(str1, 2, str1.npos);
    cout << str << endl;
    str.assign(5, 'X');
    cout << str << endl;
    string::iterator itB;
    string::iterator itE;
    itB = str1.begin();
    itE = str1.end();
    str.assign(itB, (--itE));
    cout << str << endl;
    str = str1;
    cout << str << endl;
    str.erase(3);
    cout << str << endl;
    str.erase(str.begin(), str.end());
    cout << ":" << str << ":" << endl;
    str.swap(str2);
    cout << str << endl;
    string A("ello");
    string B("H");
    B.insert(1, A);
    cout << B << endl;
    A = "ello";
    B = 'H';
    B.insert(1, "yanchy ", 3);
    cout << "插入: " << B << endl;
    A = "ello";
    B = "H";
    B.insert(1, A, 2, 2);
    cout << "插入:" << B << endl;
    A = "ello";
    B = "H";
    B.insert(1, 5, 'C');
    cout << "插入:" << B << endl;
    A = "ello";
    B = "H";
    string::iterator it = B.begin() + 1;
    const string::iterator itF = A.begin();
    const string::iterator itG = A.end();
    B.insert(it, itF, itG);
    cout << "插入：" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B = " << B << endl;
    B.append(A);
    cout << "追加：" << B << endl;
    B = "H";
    cout << "A = " << A << ", B= " << B << endl;
    B.append("12345", 2);
    cout << "追加：" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B= " << B << endl;
    B.append("12345", 2, 3);
    cout << "追加：" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B = " << B << endl;
    B.append(10, 'a');
    cout << "追加:" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B = " << B << endl;
    B.append(A.begin(), A.end());
    cout << "追加:" << B << endl;
    cin.get();
#endif // 0

    //字符串内容的替换
#if 0
    string var("abcdefghijklmn");
    const string dest("1234");
    string dest2("567891234");
    var.replace(3, 3, dest);
    cout << "1: " << var << endl;
    var = "abcdefghijklmn";
    var.replace(3, 1, dest.c_str(), 1, 3);
    cout << "2: " << var << endl;
    var = "abcdefghijklmn";
    var.replace(3, 1, 5, 'x');
    cout << "3: " << var << endl;
    string::iterator itA, itB;
    string::iterator itC, itD;
    itA = var.begin();
    itB = var.end();
    var = "abcdefghijklmn";
    var.replace(itA, itB, dest);
    cout << "4: " << var << endl;
    itA = var.begin();
    itB = var.end();
    itC = dest2.begin() + 1;
    itD = dest2.end();
    var = "abodefghijklmn";
    var.replace(itA, itB, itC, itD);
    cout << "5: " << var << endl;
    var = "abcdefghijklmn";
    var.replace(3, 1, dest.c_str(), 4); //这种方式会限定字符串替换的最大长度
    cout << "6: " << var << endl;
#endif // 1

    char ch[100] = { 0x11,0x22,0x00,0x33,'\0' };
    string str("12345678");
    str.assign(ch,6);
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
	system("pause");
	return 0;
}