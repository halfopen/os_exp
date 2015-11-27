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

//#define DEBUG 1									//测试输出标记
#define INFO 1										//提示信息输出标记
class Task{
private:
	int start;										//起始位置
	int task_size;									//作业内存大小
	int end;										//结束位置
	int id;											//作业id
	bool state;										//作业状态
public:							
	static int size;								//内存大小
	static list<Task*> task_list;					//作业列表
	static int taskNum;								//分配作业id,保证id唯一
	Task(int st, int ed);							//用于测试的方法
	Task(int t_size);								//构造函数
	static void showMem();							//显示内存分配状况
	bool call();									//申请作业内存
	static bool callback(int id);					//释放作业
	void disp();									//显示当前作业信息
	static bool compare_task(const Task* f, const Task* s);//内存块排序
	static void setSize(int s);						//设置内存大小
};


#endif
