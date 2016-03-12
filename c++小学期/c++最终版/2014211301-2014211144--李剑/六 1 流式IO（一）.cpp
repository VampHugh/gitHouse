/*六 1 流式IO（一）*/
#include<stdlib.h>
#include<iomanip> 
#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ofstream MyFile;
	int a=-225;//整数
	unsigned int b=324;//无符号整型
	char c[]="Hello world!";//字符串
	long int d=124342212;//长整型
	float e=993.34;//浮点型
	
	MyFile.open("1.txt");//使用ofstream 向一个文本文件中输出各种类型的数据 
	if(MyFile.fail())
		cout<<"文件打开失败。\n"; 
	MyFile<<"整数"<<setw(10)<<a<<endl; 
	MyFile<<"无符号整型"<<setw(10)<<b<<endl;
	MyFile<<"字符串"<<setw(10)<<c<<endl;
	MyFile<<"长整型"<<setw(10)<<d<<endl;
	MyFile<<"浮点型"<<setw(10)<<e<<endl;
	MyFile<<"十进制 ："<<dec<<b<<endl;
	MyFile<<"八进制 ："<<oct<<b<<endl;
	MyFile<<"十六进制："<<hex<<b<<endl;
	MyFile<<e<<"保留四位有效数字"<<setprecision(4)<<e;//控制精度 
	MyFile.close();
	
	system("pause");
	return 0;
}
