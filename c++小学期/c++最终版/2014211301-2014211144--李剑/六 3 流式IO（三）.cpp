/*六 3 流式IO（三）*/
#include<iostream>
#include<fstream>
#include<string.h>
#define SIZE 20 
using namespace std;

int main(void)
{
	char s1[SIZE],s2[SIZE],temp;
	ifstream file_1;
	ofstream file_2;
	int i=1,j;
	
	cout<<"请输入一个文本文件名:";//输入一个文本文件名
	cin>>s1;
	strcat(s1,".txt");
	file_1.open(s1,ios::binary);//打开文件
	if(file_1.fail())
		cout<<"文件打开失败。\n";
	cout<<"请输入一个目标文件名:";
	cin>>s2;
	strcat(s2,".txt");
	file_2.open(s2,ios::binary);
	//该文件的每一行前面加上一个行号，保存在另外一个文本文件中
	if(file_2.fail())
		cout<<"文件打开失败。\n"; 
	file_2<<i<<'.';
	i++;
	temp=file_1.get();
	while(temp!=EOF)
	{
		if(temp=='\n')
		{
			file_2<<temp;
			file_2<<i<<'.';
			i++;
		}
		else
			file_2<<temp;
		temp=file_1.get();
	}
	
	file_1.close();
	file_2.close();
	system("pause");
	return 0;
}
