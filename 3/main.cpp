/*************************************************************************
	> File Name: main.cpp
	> Brief: 位示图磁盘管理
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月25日 星期二 10时29分44秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#define DEBUG 1
using namespace std;

const int SIZE = 8;
int bitmap[SIZE][SIZE];

void disp_bitmap();
void call();
void call_back();
int main(void)
{	int choose;
	disp_bitmap();
	while(cout<<"------------------------------\n\t1:申请\n\t2:回收\n\t0:退出\n请输入: "<<endl,cin>>choose)
	{	switch(choose)
		{	case 1:
			{	call();								//申请新作业内存
			};break;
			case 2:
			{	call_back();						//释放作业
			};break;
			case 0:return 0;
			default:break;
		}/*endof switch*/
		disp_bitmap();
	}/*endof while*/
	return 0;
}

void call_back()   
{ 
	int cylinder,track,sector;   
	printf("柱面号:");   
	scanf("%d",&cylinder);   
	printf("磁道号:");   
	scanf("%d",&track);   
	printf("物理记录号:");   
	scanf("%d",&sector);   
	if(bitmap[cylinder][4*track+sector]==0)   
	{   
		printf("此块为未分配块！回收出错！");   
		getchar();   
	}  
	else   
	{  
		bitmap[cylinder][4*track+sector]=0;   
		printf("回收块对应的字节号:%4d\t位数:%4d\n",cylinder,4*track+sector);   
	}   
}  
void call()   
{   
	int i,j;   
	int flag=0;
	int cylinder,track,sector;
	for(i=0;i<8&& !flag;i++)
	{
		for(j=0;j<8&&!flag;j++)   
        	if(bitmap[i][j]==0) 
			{
				bitmap[i][j]=1;
				flag=1;
			}     
	}
	if(flag==1)
	{     
		cylinder=i;   
		track=j/4;   
		sector=j%4;  
		printf("分配到的柱面号、磁道号、物理记录数");   
		printf("%d\t%d\t%d",cylinder,track,sector);   
		printf("\n"); 
	} 
	else printf("空间不足，分配失败!");   
}   
void disp_bitmap()
{	for(int i=0;i<SIZE;++i)
	{	for(int j=0;j<SIZE;++j)
		{	printf("%2d",bitmap[i][j]);
		}
		printf("\n");
	}
}

