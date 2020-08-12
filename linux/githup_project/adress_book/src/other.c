#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/other.h"
/*
 *	@access StringInput		提示用户输入数据或者命令
 *	@param	t				目标字符串
 *	@param	lens			指定输入字符串的最长的长度
 *	@param  notice			显示提示信息
 *	@return 无
 */
extern void StringInput(char* t, int lens, char* notice)
{
    char n[50];
    do {
        printf(notice); /*显示提示信息*/
        scanf("%s", n); /*输入字符串*/
        if (strlen(n) > lens)printf("\t Exceed the required length! \n"); /*超过lens值重新输入*/

    } while (strlen(n) > lens);
    strcpy(t, n); /*将输入的字符串拷贝到字符串t中*/

}
/*
 *	@access DisPlay			显示某条信息
 *	@param	p				目标节点
 *	@return 无
 */
extern void DisPlay(Node* p)
{
    printf("\tName:     %s\n", p->data.name);
    printf("\tSex:      %s\n", p->data.sex);
    printf("\tQQ:       %s\n", p->data.tecent);
    printf("\tTelphone: %s\n", p->data.tel);
    printf("\tEmial:    %s\n", p->data.email);
    printf("\tCity:     %s\n", p->data.city);
    printf("\t******************************** \n");
}

/*
 *	@access SearchName		查找某条信息是否存在
 *	@param	l				目标字符串
 *	@param	name			需要查找的名字
 *	@return 1 , 0	 		存在返回1 ，不存在返回0
 */
extern int SearchName(mylink l, char* name)
{
    int flag = 0;
    Node* p;
    p = l;
    while (p) {
        /*查找与输入的名字相匹配的记录*/
        if (strcmp(p->data.name, name) == 0) {
            //display(p);/*调用函数显示信息*/
            //getch();
            flag = 1;
            break;
        }
        else {
            p = p->next;
        }

    }
    if (p == NULL) {
        //printf("\tNot found\n");
        //getch();
        flag = 0;
    }
    //printf("flag = %d\n", flag);
    return flag;
}







