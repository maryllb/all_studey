#pragma once
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
extern int getch(void);

/* reads from keypress, echoes */
extern int getche(void);
