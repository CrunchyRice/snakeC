#include <stdio.h>
#include <stdlib.h>
#include "snakeMov.h"
#include "grid.h"
#include "terminal.h"
#include "movement.h"
#include "food.h"
#include "messages.h"
#include "winLoseCondition.h"




/*Function that creates the grid*/
char** gridCreation(int ROW, int COL){
    int i,j;
    char **grid;
    
    
    grid = (char**)malloc(ROW * sizeof(char*));
    for (i = 0; i < ROW; i++){
        grid[i] = (char*)malloc(COL * sizeof(char));}

    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
            if (i==0 || j==0 || i == ROW-1 || j == COL-1){
            grid[i][j] = '*';}
            else{
                grid[i][j] = ' ';
            }}}

    return grid;
}
/*Puts the food on the grid with its coordinates*/
void foodOnGrid(int ROW,int COL,char **grid, int* food){
    grid[food[0]][food[1]] = '@';

    
}
/*Puts the snake on the grid with its coordinates*/
void snakeOnGrid(char **grid,bodypart *snake){
    bodypart *temp;
    temp = snake;
    while (temp != NULL){
        grid[temp->x][temp->y] = temp->shape;
        temp = temp->next;
    }
}
/* Display the grid and runs the game*/
void gridDisplay(int ROW,int COL,char **grid, int goal,bodypart *snake){
    char input;
    int* count;
    int* game;
    int i,j;
    int* food;
    count = (int*)malloc(sizeof(int));;
    food = foodPos(ROW,COL,snake);
    snakeOnGrid(grid,snake);
    foodOnGrid(ROW,COL,grid,food);
    /* Game is a pointer that will make the game stop or display the messages*/
    game = (int*)malloc(sizeof(int));
    game[0] = 0;
    count[0] = 0;
    for (i = 0; i < ROW; i++){
            for (j = 0; j < COL; j++){
                printf("%c ", grid[i][j]);
                }
            printf("\n");}

    while (input!='q' && game[0] < 5 ){
        game[0] = 0;
        disableBuffer();
        scanf("%c",&input);
        enableBuffer();

        movement(input,snake,grid,ROW,COL,game);
        snakeOnGrid(grid,snake);
        system("clear");

        for (i = 0; i < ROW; i++){
            for (j = 0; j < COL; j++){
                printf("%c ", grid[i][j]);
                }
            printf("\n");}
        /*Checks if the game is lost or won, and displays a message if applicable*/
        winLoseCondition(food,snake,game,count,goal);
        message(input,COL,ROW,game,count , goal);
        if (game[0] == 2){
            free(food);
            food = foodPos(ROW,COL,snake);
            foodOnGrid(ROW,COL,grid,food);
        }
}
free(count);
free(game);
free(food);
}
/*Frees the grid*/
void freeing(int ROW,char **grid){
    int i;
    for (i = 0; i < ROW; i++){
        free(grid[i]);}
free(grid);



}

