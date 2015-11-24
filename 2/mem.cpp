/*************************************************************************
	> File Name: mem.cpp
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月24日 星期二 18时00分19秒
 ************************************************************************/

#include"mem.h"
using namespace std;

int Task::taskNum=0;
int Task::size=128;
list<Task*> Task::task_list;

bool Task::compare_task(const Task* f, const Task* s)
{	return f->start < s->start;
}

void Task::setSize(int s)
{	size = s;
}

Task::Task(int st, int ed):start(st),end(ed)//直接指定起始位置
{								
	state = false;									//初始未分配
	this->id = taskNum++;							//id一直递增，唯一
	task_list.push_back(this);
}
Task::Task(int t_size):task_size(t_size)				//只指定分配大小
{	
	state = false;									//初始未分配
	this->id = taskNum++;							//id一直递增，唯一
	
}
void Task::showMem()
{
	printf("   0|----------\n");
	list <Task*>::iterator plist;
	
	if(task_list.empty())
	{	printf("    |\tEmpty\n");
		printf("%4d|----------\n\n",size);
		return;
	}
	int temp_pos=0,pos=0;
	for(plist = task_list.begin(); plist != task_list.end(); plist++)
	{	Task * task;
		task = *plist;
		//task->disp();
		pos=task->start;
		if(pos!=temp_pos)
		{	printf("    |\tEmpty\n");
			printf("%4d|----------\n",pos);
		}
		printf("    |\t%d\n",task->id);
		printf("%4d|----------\n",task->end);
		temp_pos = task->end;
	}
	if(temp_pos< Task::size)
	{	printf("    |\tEmpty\n");
		printf("%4d|----------\n",Task::size);
	}
	printf("\n");
}

bool Task::call()
{	int temp_size=0,temp_pos=0,pos=0;
	list <Task*>::iterator plist;
	if(task_list.empty())
	{	
	}
	for(plist = task_list.begin(); plist != task_list.end(); plist++)
	{	Task * task;
		task = *plist;
		pos = task->start;
		//task->disp();
		//cout<<pos<<temp_pos<<task_size<<endl;
		if(pos - temp_pos >= task_size)
		{	this->state = true; 
			this->start = temp_pos;
			this->end = temp_pos+this->task_size;
			task_list.push_back(this);
			task_list.sort(compare_task);
			return true;
		}
		temp_pos = task->end;
	}
	if(Task::size - temp_pos >= task_size)
	{	this->state = true; 
			this->start = temp_pos;
			this->end = temp_pos+this->task_size;
			task_list.push_back(this);
			task_list.sort(compare_task);
			return true;
	}
	cout<<"内存申请失败:找不到大小为"<<task_size<<"的空闲块"<<endl;
	return false;	
}

bool Task::callback(int id)
{	list <Task*>::iterator plist;
	if(task_list.empty())
	{	cout<<"内存空间为空"<<endl;	
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
	cout<<"内存释放失败:找到不进程"<<id<<endl;
	return false;
}

void Task::disp()
{	cout<<"task_id:"<<id<<" start:"<<start<<" end:"<<end<<endl;
}

