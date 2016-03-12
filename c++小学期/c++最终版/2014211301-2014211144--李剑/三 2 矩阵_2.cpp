/*三 2矩阵二*/ 
#include<iostream>
#include<stdlib.h>
//假定矩阵大小为4×5
#define row 4
#define line 5
using namespace std;
//定义矩阵初始化函数，可以从cin中输入矩阵元素
void initialMax(int **matrix);
//定义矩阵输出函数，将矩阵格式化输出到cout
void disPlay(int **matrix);
//定义矩阵相加的函数，实现两个矩阵相加的功能,结果保存在另一个矩阵中
void addingMax(int **mat_1,int **mat_2,int **result);
//定义矩阵相减的函数，实现两个矩阵相减的功能,结果保存在另一个矩阵中
void distractMax(int **mat_1,int **mat_2,int **result);

int main(void)
{
	int **A1,**A2,**A3;//（2）	矩阵空间采用new动态申请，保存在指针中；
	int i;
	cout<<"We assume the size is 4*5"<<endl;
	//动态申请三个矩阵：A1、A2、A3；
	A1=new int*[row];
	for(i=0;i<row;i++)
		A1[i]=new int[line];
	A2=new int*[row];
	for(i=0;i<row;i++)
		A2[i]=new int[line];
	A3=new int*[row];
	for(i=0;i<row;i++)
		A3[i]=new int[line];	
	//初始化A1、A2； 
	initialMax(A1);
	initialMax(A2);

	//计算并输出A3 = A1加A2，A3 = A1减A2；
	addingMax(A1,A2,A3);
	cout<<"After adding,";
	disPlay(A3);
	distractMax(A1,A2,A3);
	cout<<"After distracting,";
	disPlay(A3);
	//释放内存 
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
