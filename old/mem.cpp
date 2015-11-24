#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 10000
int n1;//空闲分区的个数
int n2;//作业区的个数
struct kongxian
{
	int start;  //起址
	int end;    //结束
	int length;  //长度
}kongxian[N];
struct zuoye
{
	int start;  //起址
	int end;   //结束
	int length;  //长度
}zuoye[N];
int cmp1(const void *a,const void *b)
{
	return (*(struct kongxian *)a).start-(*(struct kongxian *)b).start;
}
int cmp2(const void *a,const void *b)
{
	return (*(struct zuoye *)a).start-(*(struct zuoye *)b).start;
}
void init()
{
	n1=1;  //初始时只有一个空闲区
	n2=0;  //初始没有作业
	kongxian[0].start=0;
	kongxian[0].end=1023;
	kongxian[0].length=1024;
}
void print1() //打印空闲分区
{
	int i;
	for(i=0;i<n1;i++)
	printf("空闲分区ID:%d 起止:%d 结束:%d 长度:%d\n",i,kongxian[i].start,kongxian[i].end,kongxian[i].length);
}
void print2() //打印作业分区
{
	int i;
	for(i=0;i<n2;i++)
	printf("作业分区ID：%d 起止:%d 结束:%d 长度:%d\n",i,zuoye[i].start,zuoye[i].end,zuoye[i].length);
}
int main()
{
	int i,j,k,t,len,flag,id;
	int front,middle, behind;
	int t1,t2;
	init();
	print1();
	printf("输入1装入新作业，输入0回收作业，输入-1结束\n");
	while(scanf("%d",&t)!=EOF)
	{
		if(t==1)  //装入新作业
		{
			printf("请输入作业的占用空间的长度 ");
			scanf("%d",&len);
			flag=0;
			for(i=0;i<n1;i++)
			{
				if(kongxian[i].length>=len)  //首次适应算法
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				printf("内存分配失败\n");
			}
			else
			{
				//将该作业加入作业区里
				zuoye[n2].start=kongxian[i].start;
				zuoye[n2].end=zuoye[n2].start+len;
				zuoye[n2].length=len;
				n2++;  //作业数加1
				if(kongxian[i].length==len) //该分区全部用于分配，删除该空闲分区
				{
					for(j=i;j<n1-1;j++)
					{
						kongxian[j].start=kongxian[j+1].start;
						kongxian[j].end=kongxian[j+1].end;
						kongxian[j].length=kongxian[j+1].length;
					}
					n1--;
				}
				else  //该空闲分区部分用于分配，剩余的留在空闲分区中
				{
					kongxian[i].start+=len;
					kongxian[i].length-=len;
				}
			}
		}
		else if(t==0)
		{
			printf("输入要回收的作业ID ");
            scanf("%d",&id);
			front=middle=behind=0;
			for(i=0;i<n1;i++)
			{
				if(kongxian[i].start>zuoye[id].end)
				break;
				if(kongxian[i].end==zuoye[id].start)  //待回收的作业上面有空闲分区
				{
					front=1;
					t1=i;
				}
				if(kongxian[i].start==zuoye[id].end)  //待回收的作业下面有空闲分区
				{
					behind=1;
					t2=i;
				}
			}
			if(!front&&!behind)  //待回收的作业上下均没有空闲分区
			{ 
				kongxian[n1].start=zuoye[id].start;
				kongxian[n1].end=zuoye[id].end;
				kongxian[n1].length=zuoye[id].length;
				n1++;  //空闲分区增加一个
				qsort(kongxian,n1,sizeof(struct kongxian),cmp1); //插入空闲分区后排序
				for(j=id;j<n2-1;j++)  //在作业分区中删除该作业
				{
					zuoye[j].start=zuoye[j+1].start;
					zuoye[j].end=zuoye[j+1].end;
					zuoye[j].length=zuoye[j+1].length;
			    }
				n2--;
			}
			if(front &&behind)  //待回收的作业上下均有空闲分区
			middle=1;
			if(front&&!middle)  //合并待回收的作业和上面的空闲分区
			{
				kongxian[t1].end+=zuoye[id].length;
				kongxian[t1].length+=zuoye[id].length;
				for(j=id;j<n2-1;j++)  //在作业分区中删除该作业
				{
					zuoye[j].start=zuoye[j+1].start;
					zuoye[j].end=zuoye[j+1].end;
					zuoye[j].length=zuoye[j+1].length;
			    }
				n2--;
			}
			if(middle)  //合并待回收的作业和上下的空闲分区
			{
				kongxian[t1].end=kongxian[t2].end;
				kongxian[t1].length+=(zuoye[id].length+kongxian[t2].length);
				//删除空闲分区t2
				for(j=t2;j<n1-1;j++)
				{
					kongxian[j].start=kongxian[j+1].start;
					kongxian[j].end=kongxian[j+1].end;
					kongxian[j].length=kongxian[j+1].length;
				}
				n1--;
				for(j=id;j<n2-1;j++)  //在作业分区中删除该作业
				{
					zuoye[j].start=zuoye[j+1].start;
					zuoye[j].end=zuoye[j+1].end;
					zuoye[j].length=zuoye[j+1].length;
			    }
				n2--;
			}
		    if(behind &&!middle) //合并待回收的作业和下面的分区
			{
				kongxian[t2].start-=zuoye[id].length;
				kongxian[t2].length+=zuoye[id].length;
				for(j=id;j<n2-1;j++)  //在作业分区中删除该作业
				{
					zuoye[j].start=zuoye[j+1].start;
					zuoye[j].end=zuoye[j+1].end;
					zuoye[j].length=zuoye[j+1].length;
			    }
				n2--;
			}
        }
		else
		{
			 printf("操作结束\n");
			 break;
		}
		print1();
		print2();
	}
	return 0;
}

