/*�� 1 ���������*/
#include<iostream>
#include<stdlib.h>

using namespace std;

//Point������԰���������꣨x��y��
class Point{
	public:
		void showPoint(void)
		{
			cout<<"("<<x<<' '<<y<<")"<<endl;
		}; 
		Point(int dx,int dy);
		~Point();
		//��Point�����أ����ͨD�D�����
		void operator++()
		{
			x++;	y++;
		}
		void operator--()
		{
			x--;	y--;
		}
		void operator++(int)
		{
			x++; 	y++;
		}
		void operator--(int)
		{
			x--;	y--;
		}
	private:
		int x;
		int y;				
};
Point::Point(int dx,int dy)
{
	x=dx;
	y=dy;
}
Point::~Point(){
}
int main(void)
{
	int n,m;
	
	cout<<"Please input the coordinate a(* *):";
	cin>>n>>m;
	Point yu(n,m);
	--yu;
	cout<<"--a=";
	yu.showPoint();
	yu++;
	cout<<"a++=";
	yu.showPoint();
	yu--;
	cout<<"a--=";
	yu.showPoint();
	++yu;
	cout<<"++a=";
	yu.showPoint();
	
	system("pause");
	return 0;
}
