#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/options.h"
#include "../include/other.h"
//#include "../include/mygetch.h"
#include<ncurses.h>

/*
*	@access Enter			录入信息
*	@param	l				目标链表
*	@return 无
*/
void Enter(mylink l)/*输入信息*/
{
	Node* p, * q;
	q = l;
	while (1) {
		p = (Node*)malloc(sizeof(Node));/*申请结点空间*/
		if (!p)/*未申请成功输出提示信息*/ {
			printf("\tMemory malloc fail\n");
			return;
		}
		while (1) {
			StringInput(p->data.name, 15, "\tEnter name:");/*输入姓名*/

			if (SearchName(l, p->data.name) == 1) {
				printf("\tThe Name exist\n");
				free(p);
				getch();
				return;
			}
			break;
		}
		StringInput(p->data.sex, 5, "\tEnter sex:");/*输入性别*/
		StringInput(p->data.tel, 11, "\tEnter telephone:");/*输入电话*/
		StringInput(p->data.tecent, 15, "\tEnter QQ:");/*输入QQ*/
		StringInput(p->data.email, 20, "\tEnter email:");/*输入邮箱*/
		StringInput(p->data.city, 10, "\tEnter city:");/*输入城市*/
		p->next = NULL;
		while (q->next) q = q->next;
		q->next = p;
		q = p;
		printf("\tEnter successful\n");
		getch();
		break;
	}
}

/*
*	@access Del				删除信息
*	@param	l				目标链表
*	@return 无
*/
void Del(mylink l)
{
	Node* p = NULL;
	Node* q = NULL;
	char s[20];
	q = l;
	p = q->next;
	if (!p) {
		printf("\tNot Info\n");
		getch();
		return;
	}
	printf("\tEnter name:");
	scanf("%s", s);/*输入要删除的姓名*/
	while (p) {
		if (strcmp(s, p->data.name) == 0)/*查找记录中与输入名字匹配的记录*/ {
			q->next = p->next;/*删除p结点*/
			free(p);/*将p结点空间释放*/
			printf("\tDelete successfully!");
			break;
		}
		else {
			q = p;
			p = q->next;
		}
	}
	if (p == NULL) {
		printf("\tThe name not found\n");
		printf("\tDelete fail\n");
	}
	getch();
}

/*
*	@access Del				查找并显示信息
*	@param	l				目标链表
*	@return 1，0			查找成功:1 查找失败:0
*/
int SearchShow(mylink l)
{
	char name[20];
	Node* p;
	p = l;
	int flag;
	printf("\tEnter name:");
	scanf("%s", name);/*输入要查找的名字*/
	while (p) {
		/*查找与输入的名字相匹配的记录*/
		if (strcmp(p->data.name, name) == 0) {
			DisPlay(p);/*调用函数显示信息*/
			getch();
			flag = 1;
			break;

		}
		else {
			p = p->next;
		}

	}
	if (!p) {
		printf("\tNot found\n");
		getch();
		flag = -1;
	}
	return flag;
}

/*
*	@access ShowAll			显示所有信息
*	@param	l				目标链表
*	@return 无
*/
void ShowAll(mylink l) 
{
	Node* p;
	p = l->next;
	if (!p) {
		printf("\tNot Info\n");
		getch();
		return;
	}
	/*从首节点一直遍历到链表最后*/
	while (p != NULL) {
		DisPlay(p);
		p = p->next;
	}
	printf("\n");
	getch();
}

/*
*	@access SaveSaveToFile	保存信息到文件(非追加保存）
*	@param	l				目标链表
*	@return 无
*/
void SaveToFile(mylink l)
{
	Node* p;
	FILE* fp;
	p = l->next;
	if (p == NULL) {
		printf("\tNot info\n");
		getch();
		return;
	}
	if ((fp = fopen("../adresslist", "wb")) == NULL) {
		printf("\tCan not open file\n");
		getch();
		exit(1);
	}
	printf("\tSaving file successful\n");
	while (p)/*将节点内容逐个写入磁盘文件中*/ {
		fwrite(p, sizeof(Node), 1, fp);
		p = p->next;
	}
	fclose(fp);
	getch();
}

/*
*	@access LoadToFile		读取文件
*	@param	l				目标链表
*	@return 无
*/
void LoadToFile(mylink l)
{
	Node* p = NULL;
	Node* r = NULL;
	FILE* fp;
	l->next = NULL;
	r = l;
	if ((fp = fopen("../adresslist", "rb")) == NULL)
	{
		printf("\tCan not open file\n");
		getch();
		exit(1);
	}
	printf("\tLoading file successful\n");
	while (!feof(fp))
	{
		p = (Node*)malloc(sizeof(Node));/*申请节点空间*/
		if (!p) {
			printf("\tMemory malloc fail!");
			getch();
			return;
		}
		if (fread(p, sizeof(Node), 1, fp) != 1)/*读记录到节点p中*/
			break;
		else {
			p->next = NULL;
			r->next = p;/*插入链表中*/
			r = p;
		}
	}
	fclose(fp);
	getch();
}

/*
*	@access Change		改变某个数据中的某条信息
*	@param	l				目标链表
*	@return 无
*/
void Change(mylink l)
{
	int i;
	Node* p;
	p = l->next;
	char name[20] = { 0 };
	printf("\tEnter name:");
	scanf("%s", name);
	if (SearchName(l, name) == -1) {
		printf("\tNot the Info\n");
		getch();
		return;
	}
	while (1) {
		system("clear");
		i = Menu_select(CHANGE_MENU);
		switch (i)
		{
		case CHANGE_NAME:
			StringInput(p->data.name, 20, "\tEnter name:");
			printf("\tChange Name successful\n");
			getch();
			break;
		case CHANGE_SEX:
			StringInput(p->data.sex, 5, "\tEnter sex:");/*输入性别*/
			printf("\tChange Sex successful\n");
			getch();
			break;
		case CHANGE_TEL:
			StringInput(p->data.tel, 11, "\tEnter tel:");/*输入电话*/
			printf("\tChange Tel successful\n");
			getch();
			break;
		case CHANGE_QQ:
			StringInput(p->data.tecent, 15, "\tEnter QQ:");/*输入qq*/
			printf("\tChange QQ successful\n");
			getch();
			break;
		case CHANGE_EMAIL:
			StringInput(p->data.email, 20, "\tEnter email:");/*输入邮箱*/
			printf("\tChange Email successful\n");
			getch();
			break;
		case CHANGE_CITY:
			StringInput(p->data.city, 10, "\tEnter city:");/*输入城市*/
			printf("\tChange City successful\n");
			getch();
			break;
		default:
			return;
		}
	}
}
