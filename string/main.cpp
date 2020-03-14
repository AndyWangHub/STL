/*
string ���ṩ�ĸ��ֲ����������·�Ϊ���ࣺ
������������������С��������Ԫ�ش�ȡ���� �����Ƚϡ��ַ����޸ġ��ַ����Ӻϡ�I/O �����Լ������Ͳ��ҡ�
*/
#include<iostream>
#include<string>
#include"display.h"

using namespace std;

int main()
{
	//������string�๹�캯�������¼�����ʽ��
#if 0
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

#endif // 0


//String ���Ͷ��������������ַ������ȵĺ�����size() �� length()�� maxsize() �� capacity()��
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
	//C++ string��ȡ�ַ���Ԫ�أ�[]��at()
#if 0
	//Ϊ�޸� string �ַ��������ݣ��±������ [] �ͺ��� at() �������ַ��ġ����á���
	//�����ַ������ڴ汻���·����Ժ󣬿��ܻᷢ��ִ�д���
	    const std::string cS ("c.biancheng.net");
    std::string s ("abode");
    char temp =0;
    char temp_1 = 0;
    char temp_2 = 0;
    char temp_3 = 0;
    char temp_4 = 0;
    char temp_5 = 0;
    temp = s [2]; //"��ȡ�ַ� 'c'
    temp_1 = s.at(2); //��ȡ�ַ� 'c'
    temp_2 = s [s.length()]; //δ������Ϊ�������ַ�'\0'����Visual C++ 2012ִ��ʱδ����
    temp_3 = cS[cS.length()]; //ָ���ַ� '\0'
    temp_4 = s.at (s.length ()); //�����쳣
    temp_5 = cS.at(cS.length ()); //�����쳣
    std::cout << temp <<temp_1 << temp_2 << temp_3 << temp_4 << temp_5 << std::endl;
#endif // 0

	//compare()����,�Ƚ��ַ���
#if 0
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
#endif // 0

	//�ַ������ݵ��޸�
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
    cout << "����: " << B << endl;
    A = "ello";
    B = "H";
    B.insert(1, A, 2, 2);
    cout << "����:" << B << endl;
    A = "ello";
    B = "H";
    B.insert(1, 5, 'C');
    cout << "����:" << B << endl;
    A = "ello";
    B = "H";
    string::iterator it = B.begin() + 1;
    const string::iterator itF = A.begin();
    const string::iterator itG = A.end();
    B.insert(it, itF, itG);
    cout << "���룺" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B = " << B << endl;
    B.append(A);
    cout << "׷�ӣ�" << B << endl;
    B = "H";
    cout << "A = " << A << ", B= " << B << endl;
    B.append("12345", 2);
    cout << "׷�ӣ�" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B= " << B << endl;
    B.append("12345", 2, 3);
    cout << "׷�ӣ�" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B = " << B << endl;
    B.append(10, 'a');
    cout << "׷��:" << B << endl;
    A = "ello";
    B = "H";
    cout << "A = " << A << ", B = " << B << endl;
    B.append(A.begin(), A.end());
    cout << "׷��:" << B << endl;
    cin.get();
#endif // 0

    //�ַ������ݵ��滻
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
    var.replace(3, 1, dest.c_str(), 4); //���ַ�ʽ���޶��ַ����滻����󳤶�
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