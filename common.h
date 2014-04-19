/* 常用数据结构定义，函数申明 */

#ifndef COMMON_H
#define COMMON_H

#include<cstdio>  
#include<cstdlib>  
#include<string>  
#include<unistd.h>  
#include<sys/wait.h>  
#include<sys/types.h>  
#include<fcntl.h>  
#include<time.h>
#include<map>

using namespace std;

/* 使当前进程成为守护进程 */
void daemon();

/* 生成格式化的时间并返回 */
string getFormatedTime();

/* 解析配置文件 */
void parseConfFile(char* confFile);

/* 设置Socket为非阻塞模式 */
bool setNonBlocking(int sock);

#endif









