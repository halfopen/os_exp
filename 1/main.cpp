/*************************************************************************
	> File Name: pcb.cpp
	> Brief: 按优先数调度算法
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月24日 星期二 12时58分58秒
 ************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <list>
#include "pcb.h"

#define DEBUG 1

using namespace std;


int PCB::size = 0;
list<PCB*> PCB::pcb_list;
/**
* @brief 主函数
*
* @return 0
*/
int main(void) 
{
	int num, tn,pri;
	//cout<<"请输入任务数:";
	cin>>num;
	PCB* pcb[num];
	while(num--)
	{	//cout<<"\n任务"<<num+1<<endl;
		//cout<<"请输入所需运行时间:"<<endl;	
		cin>>tn;
		//cout<<"请输入优先级:"<<endl;
		cin>>pri;
		pcb[num] = new PCB(tn,pri);
	}
	PCB::run();
    return 0;
}

