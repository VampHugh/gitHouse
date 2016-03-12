/*�� 3 ������*/
#include<iostream>
#include<cstdlib>
using namespace std;
/*	������ʵ�־��󣬶���һ��������࣬���԰�����
 	�����С���� lines, rows���С�������ʾ����
 	�������������ָ�룬���ݾ����С��̬���루new����*/
class Matrix{
	public:
		Matrix(int _row,int _line);//���캯�� 
		~Matrix();//�������� 
		Matrix(Matrix &other);//�������캯��
        void Input();//�������
        void Print();//���
        void Add(Matrix &A,Matrix &B);//�ӷ�
        void Distract(Matrix &A,Matrix &B);//����  
	private:
		int rows;
		int lines;
		int **matrix;
};
void Matrix::Add(Matrix &A,Matrix &B)//�ӷ� 
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
Matrix::Matrix(Matrix &other)//�������캯�� 
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
Matrix::Matrix(int _row,int _line)//���캯�� 
{
	int i;
	
	rows=_row;
	lines=_line;
	
	matrix=new int*[rows];
	for(i=0;i<rows;i++)
		matrix[i]=new int[lines];
}
//�������� 
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
	//������������A1��A2��A3
	Matrix A(row,line),B(row,line),C(row,line);
	cout<<"Please input matrix A:\n";
	A.Input();
	cout<<"Please input matrix B:\n";
	B.Input();
	//���㲢���A3 = A1��A2��A3=A1��A2
	C.Add(A,B);
	cout<<"After adding A and B,";
	C.Print();
	C.Distract(A,B);
	cout<<"After distracting A and B,";
	C.Print();
	
	//��new��̬��������������Ķ���pA1��pA1��pA3
	Matrix *pA1 = new Matrix(row,line);          
  	Matrix *pA2 = new Matrix(row,line);
  	Matrix *pA3 = new Matrix(row,line);   
	//��ʼ��pA1��pA2
  	cout << "Please input matrix A1:" << endl;
  	(*pA1).Input();
  	cout << "Please input matrix A2:" << endl;
  	(*pA2).Input();
    //���㲢���pA3=pA1��pA2��pA3=pA1��pA2
  	cout << "After adding A1 and A2,";            
  	(*pA3).Add(*pA1, *pA2);               
  	(*pA3).Print();
  	cout << "After distracting A1 and A2,";
  	(*pA3).Distract(*pA1, *pA2);               
  	(*pA3).Print();

	//�ͷ�pA1��pA1��pA3
    delete pA1;                       
    delete pA2;
    delete pA3;
    
	system("pause");
	return 0;
}
