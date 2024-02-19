#include <stdio.h>
#include <stdlib.h>
#include "snakeMov.h"
#include "random.h"

/* Function that return a array containing the coordinates of the food on the grid*/

int* foodPos(int ROW, int COL, bodypart* snake){
bodypart* temp;
int *food = (int*)malloc(2 * sizeof(int)); 
temp = snake;
initRandom();
/* Randomly generates a x and a y for the food*/
food[0] = random(1,ROW-2);
food[1] = random(1,COL-2);

while (temp!= NULL){
    /* Loops through the linked list, if the x and the y of the part of the snake is equal to the coordinates of the food, regenerates the coordinates*/
    if (food[0] == temp->x && food[1]== temp->y){
        food[0] = random(1,ROW-2);
        food[1] = random(1,COL-2);
        temp = temp->next;
    }
    else{
        temp = temp->next;
    }
}



return food;
}



