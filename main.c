#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snakeMov.h"
#include "grid.h"
#include "food.h"

int main(int argc, char* argv[]){
    char **grid;
    int ROW;
    int COL;
    char* lines;
    int index;
    bodypart *snake;
    if (argc<3 || argc > 3){
        printf("Please input the correct number of arguments \n");
    }
    if(atoi(argv[2])<2){
        printf("Please input a bigger goal\n");
    }

    else{
    int goal = atoi(argv[2]);
    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[256];

    fgets(line, sizeof(line), file);
    lines = strtok(line," ");
    index = 0;
    while (lines != NULL){
        if (index == 0){
            ROW = atoi(lines);
        }
        else if (index ==1){
            COL = atoi(lines);
        }
        lines = strtok(NULL," ");
        index++;
    }
    fclose(file);

    snake = createSnake(fileName);
    grid =gridCreation(ROW,COL);
    gridDisplay(ROW,COL,grid,goal,snake);
    freeing(ROW,grid);
    freeList(snake);
    }
    return 0;

}
