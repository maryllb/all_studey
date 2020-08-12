#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/other.h"
#include "../include/menu.h"


extern void Enter(mylink l);/*输入信息*/
extern void Del(mylink l);

extern int SearchShow(mylink l);//查询某条信息
extern void ShowAll(mylink l);//遍历所有信息


extern void SaveToFile(mylink l) ;//保存到文件
extern void LoadToFile(mylink l);//读取文件


extern void Change(mylink l); //改变某个数据中的某条信息

