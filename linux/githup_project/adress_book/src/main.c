#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/options.h"
#include "../include/menu.h"
#include "../include/other.h"
#include <ncurses.h>
int main()
{
    //initscr();
	mylink l;
	l = (Node*)malloc(sizeof(Node));
	if (!l){
		printf("\n allocate memory failure "); /*如没有申请到，输出提示信息*/
		return 0;
	}
	l->next = NULL;
	system("clear");
	while (1){
		system("clear");
		//主窗口菜单
		switch (Menu_select(MAIN_MENU)){
		case 1:
			//录入信息
			Enter(l);break;
		case 2:
			//删除信息
			Del(l);break;
		case 3:
			//显示所有信息
			ShowAll(l);break;
		case 4:
			//查询某条信息
			SearchShow(l);break;
		case 5:
			//变更某条信息
			Change(l);break;
		case 6:
			//保存到文件
			SaveToFile(l);break;
		case 7:
			LoadToFile(l);break;
		case 0:
            //endwin();
			exit(0);
		}
	}
}
