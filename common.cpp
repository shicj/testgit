/* 常用函数的定义 */

#include"common.h"


/* 使当前进程成为守护进程 */
void daemon()
{
	pid_t pid;
	if((pid = fork())<0)  
	{  
		perror("fork");  
		exit(1);  
	}  
	else if(pid > 0)  
	{  
		exit(0);  /* 父进程退出 */
	}  
	  
	setsid();//create new session in son process.  
	chdir("/");//change work directory to root.  
	umask(0);//reset mask  
	//close file descriptor extend from parent process.  
	int fd_size = getdtablesize();  
	for(int i=0;i<fd_size;i++)  
	{  
		close(i);  
	}
}

/* 生成格式化的时间并返回 */
string getFormatedTime()  
{  
    time_t now;  
    struct tm *timenow;
	char str[50]={0};
	string res="";
    time(&now);  
    timenow = localtime(&now);  
    sprintf(str,"%d-%02d-%02d %02d:%02d:%02d",1900+timenow->tm_year,1+timenow->tm_mon,
		timenow->tm_mday,timenow->tm_hour,timenow->tm_min,timenow->tm_sec);
	res=str;
	return res;
}


/* 解析配置文件 */
void parseConfFile(char *confFile)
{
	if(confFile == NULL)
		return ;
	FILE *fp = fopen(confFile,"r");
	if(fp == NULL)
	{
		perror("fopen");
		exit(1);
	}
	char line[255]={0};
	int len=0;
	while(fgets(line,sizeof(line),fp) != NULL)
	{
		printf("%s",line);
	}
	
	fclose(fp);
}

void trim(char *str)
{
	int i=0,j=0;
	int len=strlen(str);
	if(len==0)
	{
		return;
	}
	for(i=0;i<len;i++)
	{
		if(str[i]=='\t' || str[i]=='\r' || str[i]=='\n' || str[i]==' ')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
	for(j=len-1;j>=0;j--)
	{
		if(str[j]=='\t' || str[j]=='\r' || str[j]=='\n' || str[j]==' ')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if(j>=i)
	{
		strncpy(str,str+i,j-i+1);
		str[j-i+1]='\0';
	}
}


/* 设置Socket为非阻塞模式 */
bool setNonBlocking(int sock)
{
    int opts;
    opts=fcntl(sock,F_GETFL);
    if(opts<0)
    {
        perror("fcntl");
        return false;
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(sock,F_SETFL,opts)<0)
    {
        perror("fcntl");
        return false;
    }
	return true;
}
