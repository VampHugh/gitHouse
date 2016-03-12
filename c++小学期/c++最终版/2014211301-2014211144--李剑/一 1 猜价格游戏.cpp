/*猜价格游戏*/
#include<iostream>
#include<stdlib.h>
#include<ctime>
//#include<stdio.h>

using namespace std;

int main(void)
{
	char input[4]={0};//保存输入的 
	int price,hypos;
	int isleap=0,i=0;
	
	srand(time(NULL));
	price=(rand()%1000)+1;//随机生成一个价格（1-1000） 
	cout<<"方便测试，这是正确答案"<<price<<endl;
    //提示输入 
	cout << "Now there is a merchandise,it's price is between 1 and 1000.please guess the price of it." << endl;
	cout << "Price:";
	cin >> input;
	
	while(1)
	{
		isleap=0;
		while(input[i]!='\0')
		{
			//检查输入是否合法 
			if(input[i]<'0' || input[i]>'9' || atoi(input)>1000)
			{
				isleap=1;
				break;
			}
			i++;
		}
		i=0;
		if(isleap==0)//输入合法
		{
			hypos=atoi(input);
			//判断用户猜的是否正确 
			if(hypos==price)//猜对了 
			{
				cout << "God damn it,you are right now!"<<endl;
				break;
			}
			else
			{
				//当猜的不对的时候做出适当的提示 
				if(hypos<price)//猜的过小 
				{
					cout << "You should give a bigger number.\n";
					cout << "Price:";
					cin >> input;
				}
				else//猜的过大 
				{
					cout << "You should give a smaller number.\n";
					cout << "Price:";
					cin >> input;
				}
			}
		}
		else//输入不合法 
		{
			cout << "Please input from 1 to 1000.\nPlease input again:";
			cin >> input;
		}
	}
	system("pause");
	return 0;
}
