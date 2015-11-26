/*************************************************************************
	> File Name: mem.cpp
	> Breif:作业类实现
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月24日 星期二 18时00分19秒
 ************************************************************************/

#include"mem.h"
using namespace std;

int Task::taskNum=0;
int Task::size=128;
list<Task*> Task::task_list;

/**
* @brief 比较函数
*
* @param f
* @param s
*
* @return 
*/
bool Task::compare_task(const Task* f, const Task* s)
{	return f->start < s->start;
}
/**
* @brief 设置内存大小
*
* @param s 内存大小
*
* @return 
*/
void Task::setSize(int s)
{	size = s;
}

/**
* @brief 用于测试的方法
*
* @param st
* @param st
*/
Task::Task(int st, int ed):start(st),end(ed)		//直接指定起始位置
{								
	state = false;									//初始未分配
	this->id = taskNum++;							//id一直递增，唯一
	task_list.push_back(this);
}
/**
* @brief 构造函数
*
* @param t_size 作业内存大小
*/
Task::Task(int t_size):task_size(t_size)			//只指定分配大小
{	
	state = false;									//初始未分配
	this->id = taskNum++;							//id一直递增，唯一
	
}
/**
* @brief 显示内存分配状况
*/
void Task::showMem()
{
	printf("\n   0|----------\n");
	list <Task*>::iterator plist;
	int temp_pos=0,pos=0;							//temp_pos保存上一个作业的结束位置,pos保存下一个作业的起始位置
	
	for(plist = task_list.begin(); plist != task_list.end(); plist++)
	{	Task * task;
		task = *plist;								//获取列表中的一个作业
		#ifdef DEBUG								//测试输出
		task->disp();
		#endif
		pos=task->start;							//下一个作业起始内存
		if(pos!=temp_pos)							//如果在内存中作业连续
		{	printf("    |\tEmpty\n");
			printf("%4d|----------\n",pos);
		}
		printf("    |\tTask:%d\n",task->id);				
		printf("%4d|----------\n",task->end);
		temp_pos = task->end;						//temp_pos保存上一个作业的结束位置
	}
	if(temp_pos< Task::size)						//显示最后一块内存
	{	printf("    |\tEmpty\n");
		printf("%4d|----------\n",Task::size);
	}
	printf("\n");
}

/**
* @brief 作业申请内存
*
* @return 
*/
bool Task::call()
{	int temp_size=0,temp_pos=0,pos=0;
	list <Task*>::iterator plist;
	if(task_list.empty())							//如果作业为空
	{	/*暂留,为以后的情况考虑*/
	}
	for(plist = task_list.begin(); plist != task_list.end(); plist++)
	{	Task * task;
		task = *plist;
		pos = task->start;
		#ifdef DEBUG
		task->disp();
		cout<<pos<<temp_pos<<task_size<<endl;
		#endif
		if(pos - temp_pos >= task_size)				//如果找到第一个合适的空间大小
		{	this->state = true; 
			this->start = temp_pos;
			this->end = temp_pos+this->task_size;
			task_list.push_back(this);				//把作业存入列表
			task_list.sort(compare_task);			//按地址顺序进行排序
			return true;
		}
		temp_pos = task->end;
	}
	if(Task::size - temp_pos >= task_size)			//处理最后一个空作业
	{	this->state = true; 
		this->start = temp_pos;
		this->end = temp_pos+this->task_size;
		task_list.push_back(this);
		task_list.sort(compare_task);
		return true;
	}
	#ifdef INFO
	cout<<"内存申请失败:找不到大小为"<<task_size<<"的空闲块"<<endl;
	#endif
	return false;	
}

/**
* @brief 释放作业
*
* @param id 作业id
*
* @return 是否释放成功
*/
bool Task::callback(int id)
{	list <Task*>::iterator plist;
	if(task_list.empty())
	{
		#ifdef INFO	
		cout<<"内存空间为空"<<endl;	
		#endif
		return false;
	}
	for(plist = task_list.begin(); plist != task_list.end(); plist++)
	{	Task * task;
		task = *plist;
		if(id == task->id)
		{	task_list.remove(task);
			return true;
		}
	}
	#ifdef INFO
	cout<<"内存释放失败:找到不进程"<<id<<endl;
	#endif
	return false;
}

/**
* @brief 显示作业信息
*/
void Task::disp()
{	cout<<"task_id:"<<id<<" start:"<<start<<" end:"<<end<<endl;
}

