/*************************************************************************
	> File Name: disc.cpp
	> Breif:磁盘分配类实现
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月24日 星期二 22时28分39秒
 ************************************************************************/

#include"bitmap.h"
using namespace std;

BitMap::BitMap(int size=8)
{
	bitmap = new int*[10]; 			//第一维，

	for( int i=0; i<10; i++)
	{
		bitmap[i] = new int[10];  	//分配第二维，每一行的空间。
	}
	
	
}

void BitMap::show_block_info(int block_id)
{
	cout<<""<<""<<""<<""<<endl;
}

bool BitMap::call_back(int block_id)
{
	return false;
}

bool call()
{
	return false;
}

BitMap::~BitMap()
{
	delete();
}
