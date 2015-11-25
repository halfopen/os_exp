/*************************************************************************
	> File Name: main.cpp
	> Brief: 用位示图管理磁盘源程序
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月25日 星期三 17时59分54秒
 ************************************************************************/
#include"mem.h"
#include<iostream>
using namespace std;

int main(void)
{
	int MemSize;
	cout<<"请输入内存块大小"<<endl;
	cin>>MemSize;
	Task::setSize(MemSize);							//初始化内存大小
	Task::showMem();
	int choose,t;
	while(cout<<"------------------------------\n"
				<<"\t1:申请作业内存\n"
				<<"\t2:回收作业\n"
				<<"\t0:退出\n请输入: "<<endl,
		cin>>choose)
	{	switch(choose)
		{	case 1:
			{	cout<<"输入作业大小:";
				cin>>t;
				Task* task = new Task(t);
				task->call();						//申请新作业内存
			};break;
			case 2:
			{	cout<<"输入回收作业ID:";
				cin>>t;
				Task::callback(t);					//释放作业
			};break;
			case 0:return 0;
			default:break;
		}/*endof switch*/
		Task::showMem();
	}/*endof while*/
	return 0;
}
