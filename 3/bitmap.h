/*************************************************************************
	> File Name: disc.h
	> Breif:磁盘分配类定义
	> Author: 计科三班秦贤康
	> Mail:qinxiankang@gmail.com 
	> Created Time: 2015年11月25日 星期二 08时29分24秒
 ************************************************************************/

#ifndef _BITMAP_H
#define _BITMAP_H

#include<iostream>
#include<cstdio>

using namespace std;

//#define DEBUG 1									//测试输出标记
#define INFO 1										//提示信息输出标记
class BitMap{
	
public:
	BitMap(int size=8);								//构造一个位示图
	bool state;
	int ** bitmap;									//指向位示图的指针
	
	bool call();									//申请磁盘空间
	void show_block_info(int block_id);				//显示磁盘块信息，柱面号，等
	bool call_back(int block_id);					//回收磁盘块
	~BitMap();										//回收位示图空间
};


#endif
