/*************************************************************************
	> File Name: mem.h
	> Breif:作业类定义
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月24日 星期二 18时00分27秒
 ************************************************************************/

#ifndef _MEM_H
#define _MEM_H

#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

class Task{
private:
	int start;
	int task_size;
	int end;
	int id;
	bool state;
public:
	static int taskNum;
	static int size;
	static list<Task*> task_list;

	Task(int st, int ed);
	Task(int t_size);
	static void showMem();							//显示内存分配状况
	bool call();									//申请作业内存
	static bool callback(int id);					//释放作业
	void disp();									//显示当前作业信息
	static bool compare_task(const Task* f, const Task* s);//内存块排序
	static void setSize(int s);
};


#endif
