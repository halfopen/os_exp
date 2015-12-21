#include<iostream>
#include<cstdlib>
#include<string>
#include<time.h>
using namespace std;
#define N 50
typedef struct PageTable
{
	int page_num;
	int pic_num;
}PageTable;
PageTable PT[N];
typedef struct LogicalAdd
{
	int page_num;
	int page_add;
}LogicalAdd;
LogicalAdd LA;

int Page_length;//页长
int Page_num;//页数
int Process;//进程大小
int Address;//逻辑地址

void Input()
{
	cout << "输入进程长度：";
	cin >> Process;
	cout<< "输入页长:";
	cin >> Page_length;
	cout<< "请输入逻辑地址:";
	cin >> Address;
}

int Init()
{

	srand(time(0));
	int i,temp;
	int sum=1;
	Page_num=Process/Page_length+1;
	//cout<< "num=" << Page_num<< endl;
	PT[0].pic_num=1;
	for(i=0;i<Page_num;i++)
	{
		PT[i].page_num=i;
		temp=rand()%3+1;
		sum+=temp;
		PT[i].pic_num+=sum;
		//cout<< PT[i].pic_num <<endl;
	}
	LA.page_num=Address/Page_length;
	if(LA.page_num>=Page_num){
		cout << "所查逻辑地址不在该页内，初始化失败！"<<endl;
		return -1;
	}
	LA.page_add=Address%Page_length;
}


int Translate()
{
	int i=0;
	int res;
	while(i<Page_num)
	{
		if(PT[i].page_num==LA.page_num){
			res=PT[i].pic_num;
			break;
		}
		else i++;
	}
	if(i>=N)
		return -1;
	return res*Page_length+LA.page_add;
}

void Output(int res)
{
	if(res==0)
	{
		cout<< "构造的页表如下："<<endl;
		cout<< "页号\t块号"<<endl;
		for(int i=0;i<Page_num;i++)
		{
			cout << PT[i].page_num << "\t";
			cout<< PT[i].pic_num<<endl;
		}
	}
	else
		cout << "物理地址为:"<< res<<endl;
}
int main()
{
	int k;
	cout<< "\t*************欢迎使用页式地址重定位模拟系统*****************\n";
	for(;;)
	{
		cout << "\t---请输入以下选项---"<<endl;
		cout<< "1.输入信息;"<<endl << "2.查看页表;"<<endl<<"3.查看物理地址;"<<endl<<"4. 退出;"<<endl;
		cin>> k;
		switch(k)
		{
		case 1:
			Input();
			if(Init()==-1)return -1;
			break;
		case 2:
			Output(0);
			break;
		case 3:
			
			Output(Translate());
			break;
		case 4:
			cout << "O(∩_∩)O谢谢使用，再见！"<<endl;
			exit(0);
			break;
		}
	}
	return 1;
}
