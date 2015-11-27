#include "pcb.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <list>
using namespace std;
//#define DEBUG 1
#define MIN -32767									//标记运行结束的任务的优先级
/**
* @brief 构造函数
*
* @param tn 运行需要时间
* @param pri 优先级
*/
PCB::PCB(int tn, int pri)
{	this->name = ++size;
	this->time_needed = tn;
	this->priority_number = pri;
	state = 'R';
	pcb_list.push_back(this);						//把进程添加到队列
}
/**
* @brief 优先级比较函数
*
* @param f	
* @param s
*
* @return 
*/
bool PCB::compare_pcb(const PCB* f, const PCB* s)	  
{	//if(f->time_needed<=0)return false;
	//if(s->time_needed<=0)return true;	
	return f->priority_number > s->priority_number; //以优先级进行调度
}
/**
* @brief 运行当前进程
*/
bool PCB::prun()
{	if(this->time_needed <=0 || this->state == 'E'){
		size--;
		this->state='E';
		this->priority_number = MIN;
		return false;
	}	
	this->priority_number--;
	this->time_needed--;
	
	if(this->time_needed<=0)						//当一个进程运行完毕			
	{	this->state = 'E';							//更改状态为E
		//size--;									//队列中进程数减一
	}
	return true;
}
/**
* @brief 运行进程队列
*/
void PCB::run()
{	disp_list();									//显示初始化队列
	int i=0;
	while(size >0)									//当队列不为空（不用实际删除list中数据，因为还要显示）
	{	
		#ifdef DEBUG
		getchar();
		#endif
		pcb_list.sort(PCB::compare_pcb);			//按优先级进行排序
		
		PCB * pcb;									//获取首进程
		pcb = *pcb_list.begin();

		if(!pcb->prun())continue;					//如果该进程无效，跳过
		cout<<"task_num:"<<size
			<<" run:Q"<<pcb->name<<" step:"<<++i<<endl;			//输出当前进程数，当前运行进程
		disp_list();
	}
	
}
/**
* @brief 显示所有队列信息
*/
void PCB::disp_list()
{	cout <<"-------------------------------------------------------------"<<endl;	
	cout << "|name\t\t"<<"|time_needed\t"<<"|pri_num\t"<<"|state      |"<<endl;
	cout <<"-------------------------------------------------------------"<<endl;
	list <PCB*>::iterator plist;
	for(plist = pcb_list.begin(); plist != pcb_list.end(); plist++)
	{	PCB * pcb;
		pcb = *plist;
		printf("|Q%d\t\t%2d\t\t %2d\t\t %c\n",pcb->name,pcb->time_needed,(pcb->time_needed<=0?0:pcb->priority_number),pcb->state);
	}
	cout<<endl;
}
/**
* @brief 显示当前进程信息
*/
void PCB::disp()
{	cout<<"Q"<<name<<" "<<time_needed<<" "<<state<<endl;
}
