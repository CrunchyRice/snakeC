#include <stdio.h>
#include <stdlib.h>
#include "messages.h"

/*Messages printed of all the scenarios*/
void message(char input, int COL, int ROW,int* game, int* count, int goal){
    printf("Food eaten %d/%d\n",count[0],goal);

    if (input != 'w' && input !='a' && input !='s' && input !='d' && input !='q'){
        printf("invalid input");
    }
    if (game[0] == 5){
        printf("You won! \n");
    }
    if (game[0] == 6){
        printf("You lost! \n");
    }
    if (game[0] == 3){
        printf("Can't go out of the boundaries!");
        game[0] = 0;
    }
    if (game[0] == 4){
        printf("Can't go backwards!");
        game[0] = 0;
    }
}