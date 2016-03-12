/*三.1矩阵1*/
#include<iostream>
#include<stdlib.h>
//假定矩阵大小为4×5
#define row 4
#define line 5

using namespace std;
//定义矩阵初始化函数，可以从cin中输入矩阵元素
void initialMax(int matrix[][line]);
//定义矩阵输出函数，将矩阵格式化输出到cout
void disPlay(int matrix[][line]);
//定义矩阵相加的函数，实现两个矩阵相加的功能,结果保存在另一个矩阵中
void addingMax(int mat_1[][line],int mat_2[][line],int result[][line]);
//定义矩阵相减的函数，实现两个矩阵相减的功能,结果保存在另一个矩阵中
void distractMax(int mat_1[][line],int mat_2[][line],int result[][line]);
 
int main(void)
{
	//定义三个矩阵：A1、A2、A3
	int A1[row][line],A2[row][line],A3[row][line];
	cout<<"We assume the size is 4*5"<<endl;
	//初始化A1、A2
	initialMax(A1);
	initialMax(A2);
	//计算并输出：A3 = A1加A2，A3 = A1减A2
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
