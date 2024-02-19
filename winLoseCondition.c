#include <stdio.h>
#include <stdlib.h>
#include "snakeMov.h"
#include "winLoseCondition.h"

/*Function the checks if the same coordinates appear twice in the array of coordinates for the lose condition*/
int checkDuplicate(bodypart* snake){
int currx;
int curry;
bodypart* temp;
temp = snake;
currx = temp->x;
curry = temp->y;
temp = temp->next;
    while (temp != NULL){
        if (currx == temp->x && curry == temp->y){
            return 1;
        }
        temp = temp->next;
        
    }
    return 0;
}

/*If the head is on the apple, the game is won, and if unbeatable if off and the snake eats himself, the game is lost*/
void winLoseCondition(int* food, bodypart* snake, int * game, int* count, int goal){
    if (food[0] == snake->x && food[1] == snake->y){
        count[0]= count[0] + 1;
        insertLast(snake);
        game[0] = 2;
    }
    if (count[0] == goal){
        game[0] = 5;
}
    #ifndef UNBEATABLE
        if(checkDuplicate(snake) == 1){
            game[0] = 6;
    }
    #endif
}

