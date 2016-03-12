/*五 1 运算符重载*/
#include<iostream>
#include<stdlib.h>

using namespace std;

//Point类的属性包括点的坐标（x，y）
class Point{
	public:
		void showPoint(void)
		{
			cout<<"("<<x<<' '<<y<<")"<<endl;
		}; 
		Point(int dx,int dy);
		~Point();
		//对Point类重载＋＋和――运算符
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
