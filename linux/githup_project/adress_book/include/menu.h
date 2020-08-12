#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAIN_MENU      1
#define CHANGE_MENU    2


/*
*	@access Menu_select		菜单
*	@param	mode			主菜单MAIN_MENU，子菜单 CHANGE_MENU
*	@return int	 			用户的选择
*/
int Menu_select(int mode);
