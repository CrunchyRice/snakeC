#include <stdio.h>
#include <stdlib.h>
#include "snakeMov.h"
#include "movement.h"


/* function to make the snake move with wasd*/
void movement( char input, bodypart* snake,char** grid, int ROW, int COL, int* game){
    if (input == 'd'){
        /* check if the snake is pointing to the oposite way so it cannot move backwards */
        if (snake->shape == '<'){
            game[0] = 4;
        }
        else if (snake->y == COL - 2){
                game[0] = 3;
        }
        else{
        snake->shape = '>';
        shapeChange(snake,grid);
        snake->y++;}
    }

    else if (input == 's'){
        if (snake->shape ==  '^'){
            game[0] = 4;
        }
        else if (snake->x == ROW - 2){
                game[0] = 3;
            }else{
        snake->shape = 'v';
        shapeChange(snake,grid);
        snake->x++;}
    }

    else if (input == 'a'){
        if (snake->shape == '>'){
            game[0] = 4;
        }
            else if (snake->y == 1){
                game[0] = 3;
            }else{
        snake->shape = '<';
        shapeChange(snake,grid);
        snake->y--;}
    }

    else if (input == 'w'){
        if (snake->shape ==  'v'){
            game[0] = 4;
        }
            else if (snake->x == 1){
                game[0]= 3;
            }else{
        snake->shape = '^';
        shapeChange(snake,grid);
        snake->x--;}
    }
}


/*Make the rest of the body follow the head, and make the character change if it is going vertical*/
void shapeChange(bodypart* snake,char** grid){
int currentX;
int currentY;
int prevX;
int prevY;
bodypart* temp;
temp = snake;

/*make every part of the body take the coordinates of the previous one*/
    prevX = snake->y;
    prevY = snake->x;
    temp = temp->next;
    while (temp != NULL){
        currentX = temp->y;
        currentY = temp->x;
        if (temp->shape!='#'){
        if (prevY!=currentY){
                temp->shape = '|';
        }else{
            temp->shape = '-';
        }}
        temp->y = prevX;
        temp->x= prevY;
        prevX = currentX;
        prevY = currentY;
        temp = temp->next;
    }
    /* Erasing the trail of the snake*/
    grid[prevY][prevX] = ' ';

}