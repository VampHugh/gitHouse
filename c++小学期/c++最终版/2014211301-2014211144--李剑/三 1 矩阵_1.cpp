/*��.1����1*/
#include<iostream>
#include<stdlib.h>
//�ٶ������СΪ4��5
#define row 4
#define line 5

using namespace std;
//��������ʼ�����������Դ�cin���������Ԫ��
void initialMax(int matrix[][line]);
//�����������������������ʽ�������cout
void disPlay(int matrix[][line]);
//���������ӵĺ�����ʵ������������ӵĹ���,�����������һ��������
void addingMax(int mat_1[][line],int mat_2[][line],int result[][line]);
//�����������ĺ�����ʵ��������������Ĺ���,�����������һ��������
void distractMax(int mat_1[][line],int mat_2[][line],int result[][line]);
 
int main(void)
{
	//������������A1��A2��A3
	int A1[row][line],A2[row][line],A3[row][line];
	cout<<"We assume the size is 4*5"<<endl;
	//��ʼ��A1��A2
	initialMax(A1);
	initialMax(A2);
	//���㲢�����A3 = A1��A2��A3 = A1��A2
	addingMax(A1,A2,A3);
	cout<<"After adding,";
	disPlay(A3);
	distractMax(A1,A2,A3);
	cout<<"After distracting,";
	disPlay(A3);
	
	system("pause");
	return 0;
}
void distractMax(int mat_1[][line],int mat_2[][line],int result[][line])
{
	int i,j;
	
	for(i=0;i<row;i++)
	 for(j=0;j<line;j++)
	 	result[i][j]=mat_1[i][j]-mat_2[i][j];
}
void addingMax(int mat_1[][line],int mat_2[][line],int result[][line])
{
	int i,j;
	
	for(i=0;i<row;i++)
	 for(j=0;j<line;j++)
	 	result[i][j]=mat_1[i][j]+mat_2[i][j];
}
void initialMax(int matrix[][line])
{
	int i,j;
	
	cout<<"Please input a matrix:\n"; 
	for(i=0;i<row;i++)
	 for(j=0;j<line;j++)
	 	cin>>matrix[i][j];
}
void disPlay(int matrix[][line])
{
	int i,j;
	
	cout<<"the matrix is:\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<line;j++)
		 	cout<<matrix[i][j]<<" ";
		 cout<<endl;
	} 	
}
