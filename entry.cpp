/* http服务器入口程序 */

#include<iostream>
#include"common.h"
#include"threadpool.h"

using namespace std;


int main(int argc,char *argv[])
{
	char file[]="http.conf";
	map<string,string> config;
	parseConfFile(file);
	return 0;
}

















