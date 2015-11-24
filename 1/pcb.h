/**
* @file pcb.h
* @brief PCB类定义
* @author 秦贤康
* @version 1.0
* @date 2015-11-24
*/
#ifndef _PCB_H_
#define _PCB_H

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <list>

using namespace std;

class PCB{
private:
	int name;										//进程id
	int time_needed;								//需要运行时间
	char state;										//进程状态
	int priority_number;							//优先级
public:
    PCB(int tn, int pri);							//构造函数
	static int size;								//队列中进程数
	static list <PCB*> pcb_list;					//进程队列	
    
    void disp();									//显示当前进程信息
	static void run(); 								//运行进程队列
	void prun();									//运行当前进程
	static bool compare_pcb(const PCB* f, 
			const PCB* s);							//优先级比较函数
	static void disp_list();						//显示所有队列信息
};
#endif


