#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h> 

#define SERVER_PORT (7778)
#define EPOLL_MAX_NUM (2048)
#define BUFFER_MAX_LEN (4096) 


/*
*    int epoll_create(int size);
* @param size 告诉内核监听的数目 
* @returns 返回一个epoll句柄（即一个文件描述符）
*    int epfd = epoll_create(1000);
*/ 

/*
*	int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
* @param epfd 用epoll_create所创建的epoll句柄 
* @param op 表示对epoll监控描述符控制的动作 
*
* EPOLL_CTL_ADD(注册新的fd到epfd)
* EPOLL_CTL_MOD(修改已经注册的fd的监听事件)
* EPOLL_CTL_DEL(epfd删除一个fd) 
*
* @param fd 需要监听的文件描述符 
* @param event 告诉内核需要监听的事件 
*
* @returns 成功返回0，失败返回-1, errno查看错误信息 
*/


/*
struct epoll_event {
	__uint32_t events; // epoll 事件 
	epoll_data_t data; // 用户传递的数据 
	}

* events : {EPOLLIN, EPOLLOUT, EPOLLPRI, EPOLLHUP, EPOLLET, EPOLLONESHOT}

typedef union epoll_data 
{
	void *ptr;
	int fd;
	uint32_t u32;
	uint64_t u64;
} epoll_data_t;
*/

/**
*int epoll_wait(int epfd, struct epoll_event *event, 
*				int maxevents, int timeout);
* @param epfd 用epoll_create所创建的epoll句柄
* @param event 从内核得到的事件集合 
* @param maxevents 告知内核这个events有多大, 
* 注意: 值 不能大于创建epoll_create()时的size. 
* @param timeout 超时时间 
* -1: 永久阻塞 
* 0: 立即返回，非阻塞 
* >0: 指定微秒 
*
* @returns 成功: 有多少文件描述符就绪,时间到时返回0 
* 失败: -1, errno 查看错误 
*/






char buffer[BUFFER_MAX_LEN]; 
void str_toupper(char *str) 
{ 
	int i;
	for (i = 0; i < strlen(str); i ++){
		str[i] = toupper(str[i]);
	}
}

int main(int argc, char **argv)
{
	int listen_fd = 0;
	int client_fd = 0;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_len;
	int epfd = 0;
	struct epoll_event event, *my_events;
	
	// socket
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	// bind
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(SERVER_PORT);
	bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	
	// listen
	listen(listen_fd, 10);
	
	// epoll create
	epfd = epoll_create(EPOLL_MAX_NUM);
	if (epfd < 0) {
		perror("epoll cre ate");
		goto END;
	}
	
	// epol create
	epfd = epoll_create(EPOLL_MAX_NUM);
	if (epfd < 0){
		perror("epoll create"); 
		goto END;
	}
	// listen_fd -> epoll
	event.events = EPOLLIN;
	event.data.fd = listen_fd;
	if (epoll_ctl(epfd, EPOLL_CTL_ADD, listen_fd, &event) < 0){
		perror("epoll ctl add listen_fd ");
		goto END;
		
	}
	my_events = malloc(sizeof(struct epoll_event) * EPOLL_MAX_NUM);
	
	while(1){ 
		// epoll wait
		int active_fds_cnt = epoll_wait(epfd, my_events, EPOLL_MAX_NUM, -1);
		int i = 0;
		for (i = 0; i < active_fds_cnt; i++) {
			// if fd == listen_fd
			if (my_events[i].data.fd == listen_fd) {
				//accept
				client_fd = accept(listen_fd, (struct sockaddr*) &client_addr, &client_len);
				if (client_fd < 0){
					perror("accept");
					continue;
				}
				char ip[20];
				printf("new connection[%s:%d]\n",
				inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip)), ntohs(client_addr.sin_port));
				
				event.events = EPOLLIN | EPOLLET;
				event.data.fd = client_fd;
				epoll_ctl(epfd, EPOLL_CTL_ADD, client_fd, &event );
			}
			else if (my_events[i].events & EPOLLIN){
				printf("EPOLLIN\n");
				client_fd = my_events[i].data.fd;
				
				// do read
				buffer[0] = '\0';
				int n = read(client_fd, buffer, 5);
				if (n < 0){
					perror("read");
					continue;
				}
				else if (n == 0) {
					epoll_ctl(epfd,
					EPOLL_CTL_DEL,
					client_fd, &event);
					close(client_fd);
				}
				else {
					printf("[read]: %s\n", buffer);
					buffer[n] = '\0';
					#if 1
					str_toupper(buffer);
					write(client_fd, buffer, strlen(buffer));
					printf("[write]: %s\n", buffer);
					memset(buffer, 0, BUFFER_MAX_LEN);
					#endif
					/*
					event.events = EPOLLOUT;
					event.data.fd = client_fd;
					epoll_ctl(epfd, EPOLL_CTL_MOD, client_fd, &e vent);
					*/
				}
			}
			else if(my_events[i].events & EPOLLOUT){
				printf("EPOLLOUT\n");
				
				/*
				client_fd = my_events[i].data.fd;
				str_toupper(buffer);
				write(client_fd, buffer, strlen(buffer));
				printf("[write]: %s\n", buffer);
				memset(buffer, 0, BUFFER_MAX_LEN);
				event.events = EPOLLIN;
				event.data.fd = client_fd;
				epoll_ctl(epfd, EPOLL_CTL_MOD, client_fd, &event );
				*/
				
			}
		}	
	}
END:
	close(epfd);
	close(listen_fd);
	return 0;
}














