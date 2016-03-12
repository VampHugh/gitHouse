/*三 3 矩阵三*/
#include<iostream>
#include<cstdlib>
using namespace std;
/*	用类来实现矩阵，定义一个矩阵的类，属性包括：
 	矩阵大小，用 lines, rows（行、列来表示）；
 	存贮矩阵的数组指针，根据矩阵大小动态申请（new）。*/
class Matrix{
	public:
		Matrix(int _row,int _line);//构造函数 
		~Matrix();//析构函数 
		Matrix(Matrix &other);//拷贝构造函数
        void Input();//输入矩阵
        void Print();//输出
        void Add(Matrix &A,Matrix &B);//加法
        void Distract(Matrix &A,Matrix &B);//减法  
	private:
		int rows;
		int lines;
		int **matrix;
};
void Matrix::Add(Matrix &A,Matrix &B)//加法 
{
	int i,j;
     
    for(i=0;i<this->rows;i++)
		for(j=0;j<this->lines;j++)
            this->matrix[i][j]=A.matrix[i][j]+B.matrix[i][j];
}
void Matrix::Distract(Matrix &A,Matrix &B)
{
	int i,j;
     
    for(i=0;i<this->rows;i++)
		for(j=0;j<this->lines;j++)
            this->matrix[i][j]=A.matrix[i][j]-B.matrix[i][j];
}
void Matrix::Input()
{
     int i,j;
     
     for(i=0;i<this->rows;i++)
		for(j=0;j<this->lines;j++)
             cin>>this->matrix[i][j];
}
void Matrix::Print()
{
	int i,j;
	
	cout<<"the matrix is:\n";
	for(i=0;i<this->rows;i++)
	{
		for(j=0;j<this->lines;j++)
		 	cout<<this->matrix[i][j]<<" ";
		 cout<<endl;
	}
}
Matrix::Matrix(Matrix &other)//拷贝构造函数 
{
     int i,j;
     rows=other.rows;
     lines=other.lines;
     
     matrix=new int*[rows];
	 for(i=0;i<rows;i++)
		matrix[i]=new int[lines];
		
     for(i=0;i<rows;i++)
         for(j=0;j<lines;j++)
             matrix[i][j]=other.matrix[i][j];
}
Matrix::Matrix(int _row,int _line)//构造函数 
{
	int i;
	
	rows=_row;
	lines=_line;
	
	matrix=new int*[rows];
	for(i=0;i<rows;i++)
		matrix[i]=new int[lines];
}
//析构函数 
Matrix::~Matrix()
{
	for(int i=0;i<this->rows;i++)
		delete  [] this->matrix[i];
	delete [] this->matrix;
}
int main(void)
{
	int row,line;
	
	cout<<"Please input the row and line:"; 
	cin>>row>>line;
	//定义三个矩阵：A1、A2、A3
	Matrix A(row,line),B(row,line),C(row,line);
	cout<<"Please input matrix A:\n";
	A.Input();
	cout<<"Please input matrix B:\n";
	B.Input();
	//计算并输出A3 = A1加A2，A3=A1减A2
	C.Add(A,B);
	cout<<"After adding A and B,";
	C.Print();
	C.Distract(A,B);
	cout<<"After distracting A and B,";
	C.Print();
	
	//用new动态创建三个矩阵类的对象：pA1、pA1、pA3
	Matrix *pA1 = new Matrix(row,line);          
  	Matrix *pA2 = new Matrix(row,line);
  	Matrix *pA3 = new Matrix(row,line);   
	//初始化pA1、pA2
  	cout << "Please input matrix A1:" << endl;
  	(*pA1).Input();
  	cout << "Please input matrix A2:" << endl;
  	(*pA2).Input();
    //计算并输出pA3=pA1加pA2，pA3=pA1减pA2
  	cout << "After adding A1 and A2,";            
  	(*pA3).Add(*pA1, *pA2);               
  	(*pA3).Print();
  	cout << "After distracting A1 and A2,";
  	(*pA3).Distract(*pA1, *pA2);               
  	(*pA3).Print();

	//释放pA1、pA1、pA3
    delete pA1;                       
    delete pA2;
    delete pA3;
    
	system("pause");
	return 0;
}
