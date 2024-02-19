#ifndef GRID_H
#define GRID_H

char** gridCreation(int ROW, int COL);
void foodOnGrid(int ROW,int COL,char **grid,int* food);
void snakeOnGrid(char **grid,bodypart *snake);
void gridDisplay(int ROW,int COL,char **grid, int goal,bodypart *snake);
void freeing(int ROW,char **grid);

#endif