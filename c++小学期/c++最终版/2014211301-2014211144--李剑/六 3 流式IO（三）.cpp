/*�� 3 ��ʽIO������*/
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
	
	cout<<"������һ���ı��ļ���:";//����һ���ı��ļ���
	cin>>s1;
	strcat(s1,".txt");
	file_1.open(s1,ios::binary);//���ļ�
	if(file_1.fail())
		cout<<"�ļ���ʧ�ܡ�\n";
	cout<<"������һ��Ŀ���ļ���:";
	cin>>s2;
	strcat(s2,".txt");
	file_2.open(s2,ios::binary);
	//���ļ���ÿһ��ǰ�����һ���кţ�����������һ���ı��ļ���
	if(file_2.fail())
		cout<<"�ļ���ʧ�ܡ�\n"; 
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
