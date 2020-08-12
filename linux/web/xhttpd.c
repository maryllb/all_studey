#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define N 4096

#define log(filename,line,str)\
	do{\
		fprintf(tmp, "%s %d:%s", filename,line,str);\
		fflush(tmp);\
	}while(0)


void send_headers(char *type, off_t length)//发送不同内容给浏览器时，协议头类型不同
{
	printf("%s %d %s \r\n","HTTP/1.1", 200, "Ok");
	printf("Content-Type: %s\r\n",type);
	printf("Content-Length: %ld\r\n",(int64_t)length);
	printf("Connection: close\r\n");
	printf("\r\n");

	//HTTP/1.1 200 OK
	//Content-Type:text/plain; charset=utf-8
	//Content-Length:32
	//Connection: close
	//\r\n
}
//html中换行使用\n，http中换行使用\r\n

void send_err(int status/*错误号*/, char *title/*错误名称*/, char *text/*错误描述*/)
{
	send_headers("text/html", -1);//http协议头

	printf("<html><head><title>%d %s</title> </head>\n",status, title);
	printf("<body bgcolor=\"#cc99cc\"><h4>%d %s</h4>\n",status, title);
	printf("%s\n",text);
	printf("<hr>\n</body>\n</html>\n");

	fflush(stdout);//刷新
	/*
	 * <html><head><title>错误号 错误名</title></head>
	 * <body bgcolor = "#cc99cc"><h4>错误号 错误名</h4>
	 * 错误原因描述
	 * <hr>
	 * </body>
	 * </html>
	 */
	exit(1);
}


void write_log(char *filename,int line, char* str)
{
	FILE *tmp = fopen("/home/huoz/dir/tmp.txt", "a");
	if(tmp == NULL)
	{
		perror("fopen tmp.txt error.");
		exit(1);
	} 
	log(filename,line,str);
	fclose(tmp);
}
//xinetd  --> ./myhttpd  /home/huoz/dir == '/'
int main(int argc,char *argv[])
{
	char line[N];
	char method[N], path[N], protocol[N];

	char *file;
	struct stat sbuf;
	FILE *fp;
	int ich;
	char *type;

	if(argc != 2) // ./myhttpd  /home/huoz/dir
		send_err(500,"Internal Error", "Config error - no dir specified.");

	if(chdir(argv[1]) == -1)//切换工作目录到/home/huoz/dir,方便以后查找用户请求的文件是否存在
		send_err(500, "Internal Error", "Config error - couldn't chdir().");

	if(fgets(line,N,stdin) != NULL) //读出的一定是http协议的首行：GET /hello.c HTTP/1.1
		send_err(400, "Bad Request", "No request found.");

	if(sscanf(line,"%[^ ] %[^ ] %[^ ]",method, path, protocol) != 3)//拆分并提取line的非空格部分
		send_err(400, "Bad request", "Can't parse request.");

	while(fgets(line, N, stdin) != NULL)//读取请求信息到结束符
		if(strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0)
			break;

	if(strcasecmp(method, "GET") != 0)
		send_err(501, "Not Implemented", "That method is not implemented.");

	if(path[0] != '/')
		send_err(400, "Bad Request", "Bad filename.");
	file = path + 1;


	if(stat(file,&sbuf) < 0)//stat函数以获取数据长度
		send_err(404,"Not Found", "File not found.");

	fp = fopen(file, "r");
	if(fp == NULL)
		send_err(403, "Forbidden", "File is protected.");

	char *dot = strrchr(file, '.');//strrchr()在字符串中自右向左找出一个字符

	if(dot == NULL){
		type = "text/lain; charset=utf-8";
	}else if(strcmp(dot, ".html") == 0){
		type = "text/html;charset=utf-8";
	}else if(strcmp(dot, ".jpg") == 0){
		type = "image/jpeg";
	}else if(strcmp(dot, ".gif") == 0){
		type = "image/gif";
	}else if(strcmp(dot, ".png") == 0){
		type = "image/png";
	}else if(strcmp(dot, ".mp3") == 0){
		type = "audio/mpeg";
	}else if(strcmp(dot, ".wav") == 0){
		type = "audio/wav";
	}else if(strcmp(dot, ".avi") == 0){
		type = "video/x_msvideo";
	}else if(strcmp(dot, ".mov") == 0){
		type = "video/quicktime";
	}else{
		type = "text/plain;charset=iso-8859-1";
	}

	send_headers(type,sbuf.st_size);

	while((ich = getc(fp)) != EOF)
		putchar(ich);

	fflush(stdout);

	fclose(fp);

	return 0;
}
