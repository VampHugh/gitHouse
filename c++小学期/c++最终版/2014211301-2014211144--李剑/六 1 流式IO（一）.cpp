/*�� 1 ��ʽIO��һ��*/
#include<stdlib.h>
#include<iomanip> 
#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ofstream MyFile;
	int a=-225;//����
	unsigned int b=324;//�޷�������
	char c[]="Hello world!";//�ַ���
	long int d=124342212;//������
	float e=993.34;//������
	
	MyFile.open("1.txt");//ʹ��ofstream ��һ���ı��ļ�������������͵����� 
	if(MyFile.fail())
		cout<<"�ļ���ʧ�ܡ�\n"; 
	MyFile<<"����"<<setw(10)<<a<<endl; 
	MyFile<<"�޷�������"<<setw(10)<<b<<endl;
	MyFile<<"�ַ���"<<setw(10)<<c<<endl;
	MyFile<<"������"<<setw(10)<<d<<endl;
	MyFile<<"������"<<setw(10)<<e<<endl;
	MyFile<<"ʮ���� ��"<<dec<<b<<endl;
	MyFile<<"�˽��� ��"<<oct<<b<<endl;
	MyFile<<"ʮ�����ƣ�"<<hex<<b<<endl;
	MyFile<<e<<"������λ��Ч����"<<setprecision(4)<<e;//���ƾ��� 
	MyFile.close();
	
	system("pause");
	return 0;
}
