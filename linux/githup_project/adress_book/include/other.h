#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CHANGE_NAME    1
#define CHANGE_SEX     2
#define CHANGE_TEL     3
#define CHANGE_QQ      4
#define CHANGE_EMAIL   5
#define CHANGE_CITY    6

#define QUIT 0

typedef struct Info
{
	char name[15];   //姓名
	char sex[5];	 //性别
	char tel[20];    //手机
	char tecent[15]; //qq号码
	char email[20];  //邮箱
	char city[10];   //城市
}Info;//通讯录结构体
typedef struct node/*定义通讯录链表的结点结构*/
{
	struct Info data;
	struct node* next;
}Node, *mylink;

/*
*	@access StringInput		提示用户输入数据或者命令
*	@param	t				目标字符串
*	@param	lens			指定输入字符串的最长的长度
*	@param  notice			显示提示信息
*	@return 无
*/
extern void StringInput(char* t, int lens, char* notice);

/*
*	@access DisPlay			显示某条信息
*	@param	p				目标节点
*	@return 无
*/
extern void DisPlay(Node* p);
/*
*	@access SearchName		查找某条信息是否存在
*	@param	l				目标字符串
*	@param	name			需要查找的名字
*	@return 1 , 0	 		存在返回1 ，不存在返回0
*/
extern int SearchName(mylink l, char* name);






