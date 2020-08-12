#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/menu.h"

/*
*	@access Menu_select		菜单
*	@param	mode			主菜单MAIN_MENU，子菜单 CHANGE_MENU
*	@return int	 			用户的选择
*/
int Menu_select(int mode)
{
	int i;
	if (mode == MAIN_MENU)
	{
		printf("\n\n\t ***********************ADDRESS LIST***************************\n");
		printf("\t|*			1.Input record			      *|\n");	//输入信息
		printf("\t|*			2.Delete record			      *|\n");	//删除整条信息
		printf("\t|*			3.List record			      *|\n");	//显示所有信息
		printf("\t|*			4.Search record			      *|\n");	//查找某条信息
		printf("\t|*			5 Change record			      *|\n");	//改变某条信息
		printf("\t|*			6.Save record			      *|\n");
		printf("\t|*			7.Load record			      *|\n");
		printf("\t|*			0.Quit                                *|\n");
		printf("\t **************************************************************\n");
	}
	else if (mode == CHANGE_MENU)
	{
		printf("\n\n\t *************************CAHAGE MESSAGE*******************\n");
		printf("\t|*			1.Change name                   *|\n");
		printf("\t|*			2.Change sex                    *|\n");
		printf("\t|*			3.Change tel                    *|\n");
		printf("\t|*			4.Change QQ                     *|\n");
		printf("\t|*			5.Change email                  *|\n");
		printf("\t|*			6.Change city                   *|\n");
		printf("\t|*			0.Quit                          *|\n");
		printf("\t **************************************************************\n");
	}
	int flag = 0;
	do
	{
		printf("\n\tEnter your choice:");
		scanf("%d", &i);
		if (mode == MAIN_MENU) {
			flag = 8;
		}
		else if (mode == CHANGE_MENU) {
			flag = 7;
		}
	} while (i<0 || i>flag);
	return i;
}
