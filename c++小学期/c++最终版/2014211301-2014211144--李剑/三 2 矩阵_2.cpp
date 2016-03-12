/*�� 2�����*/ 
#include<iostream>
#include<stdlib.h>
//�ٶ������СΪ4��5
#define row 4
#define line 5
using namespace std;
//��������ʼ�����������Դ�cin���������Ԫ��
void initialMax(int **matrix);
//�����������������������ʽ�������cout
void disPlay(int **matrix);
//���������ӵĺ�����ʵ������������ӵĹ���,�����������һ��������
void addingMax(int **mat_1,int **mat_2,int **result);
//�����������ĺ�����ʵ��������������Ĺ���,�����������һ��������
void distractMax(int **mat_1,int **mat_2,int **result);

int main(void)
{
	int **A1,**A2,**A3;//��2��	����ռ����new��̬���룬������ָ���У�
	int i;
	cout<<"We assume the size is 4*5"<<endl;
	//��̬������������A1��A2��A3��
	A1=new int*[row];
	for(i=0;i<row;i++)
		A1[i]=new int[line];
	A2=new int*[row];
	for(i=0;i<row;i++)
		A2[i]=new int[line];
	A3=new int*[row];
	for(i=0;i<row;i++)
		A3[i]=new int[line];	
	//��ʼ��A1��A2�� 
	initialMax(A1);
	initialMax(A2);

	//���㲢���A3 = A1��A2��A3 = A1��A2��
	addingMax(A1,A2,A3);
	cout<<"After adding,";
	disPlay(A3);
	distractMax(A1,A2,A3);
	cout<<"After distracting,";
	disPlay(A3);
	//�ͷ��ڴ� 
	for(i=0;i<row;i++)
		delete  [] A1[i];
	delete [] A1;
	A1=NULL;
	for(i=0;i<row;i++)
		delete [] A2[i];
	delete [] A2;
	A2=NULL;
	for(i=0;i<row;i++)
		delete [] A3[i];
	delete [] A3;
	A3=NULL;
	system("pause");
	return 0;
}

void distractMax(int **mat_1,int **mat_2,int **result)
{
	int i,j;
	
	for(i=0;i<row;i++)
	 for(j=0;j<line;j++)
	 	result[i][j]=mat_1[i][j]-mat_2[i][j];
}
void addingMax(int **mat_1,int **mat_2,int **result)
{
	int i,j;
	
	for(i=0;i<row;i++)
	 for(j=0;j<line;j++)
	 	result[i][j]=mat_1[i][j]+mat_2[i][j];
}
void initialMax(int **matrix)
{
	int i,j;
	int t;
	cout<<"Please input a matrix:\n"; 
	for(i=0;i<row;i++)
	 for(j=0;j<line;j++)
	 	cin>>matrix[i][j];
}
void disPlay(int **matrix)
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
