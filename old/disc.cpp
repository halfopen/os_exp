#include <stdio.h>    
       
void Initbitmap(int map[8][8])   
{  
	int cylinder,track,sector;
	char choice='Y';
	printf("初始化位视图...\n");
	while(choice=='y'||choice=='Y')
	{
		printf("柱面号:");
		scanf("%d",&cylinder);
		printf("磁道号:");
		scanf("%d",&track);
		printf("物理记录号:");
		scanf("%d",&sector);
		map[cylinder][4*track+sector]=1;
		printf("contiune?");
		getchar();
		scanf("%c",&choice);
	}   
}      
void allocate(int map[8][8])   
{   
	int i,j;   
  
	int flag=0;
	int cylinder,track,sector;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)   
        if(map[i][j]==0) {map[i][j]=1;flag=1;break;}    
        if(flag==1) break;   
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
   
void reclaim(int map[8][8])   
{ 
	int cylinder,track,sector;   
	printf("柱面号:");   
	scanf("%d",&cylinder);   
	printf("磁道号:");   
	scanf("%d",&track);   
	printf("物理记录号:");   
	scanf("%d",&sector);   
	if(map[cylinder][4*track+sector]==0)   
	{   
		printf("此块为未分配块！回收出错！");   
		getchar();   
	}  
	else   
	{  
		map[cylinder][4*track+sector]=0;   
		printf("回收块对应的字节号:%4d\t位数:%4d\n",cylinder,4*track+sector);   
	}   
}      
int main()   
{   
	int bitmap[8][8];   
	int i,j;   
	int choice;   
	for(i=0;i<8;i++)   
		for(j=0;j<8;j++)   
			bitmap[i][j]=0;   
    Initbitmap(bitmap);   
	while(1)   
	{   
		printf("\n请输入选择:");   
		printf("1--分配，2---回收，3--显示位示图，0--退出\n");   
		scanf("%d",&choice);     
		switch(choice)   
		{   
		case 1:allocate(bitmap);break;   
		case 2:reclaim(bitmap);break;   
		case 3:for(i=0;i<8;i++)   
                 {
				   for(j=0;j<8;j++)   
                   printf("%8d",bitmap[i][j]);   
                   printf("\n");   
                 }   
			break;   
		case 0:return 0;
		default:printf("错误选择！");
			break;
		}   
	}  
	return 0; 
}
