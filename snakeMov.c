#include <stdio.h>
#include <stdlib.h>
#include "snakeMov.h"
#include <string.h>


bodypart *newNode(char shape,int x, int y){
    bodypart *node = malloc(sizeof(bodypart));
    node->x = x;
    node->y = y;
    node->shape = shape;
    node->next = NULL;
    return node;
}

bodypart *insert(bodypart **head, bodypart *part){
    part->next = *head;
    *head = part;
    return part;
}

void printList(bodypart *head){
    bodypart *temp = head;

    while (temp != NULL){
        printf("%d %d %c\n",temp->x,temp->y,temp->shape);
        temp = temp->next;
    }
    printf("\n");

}

bodypart *createSnake(char const* const fileName){
    bodypart *head;
    bodypart *temp;
    int count;
    int index;
    int x;
    int y;
    char* lines;
    FILE* file = fopen(fileName, "r");
    char line[256];

    head = NULL;
    count = 0;
    while(!feof(file)){
        index = 0;
        fgets(line, sizeof(line), file);
        lines = strtok(line," ");
        if (count > 0){
            while (lines != NULL){
                if (index == 0){
                    x = atoi(lines)+1;
                }
                if (index == 1){
                    y = atoi(lines)+1;
                }
                if (index == 2){
                    temp = newNode(*lines,x,y);
                    insert(&head, temp);
                }
                lines = strtok(NULL," ");
                index++;
                
            }
        }
        count++;
    }
    fclose(file);
    return head;

}

bodypart *find(bodypart* head, char shape){
    bodypart* temp;
    temp = head;
    while (temp != NULL){
        if (temp->next->shape == shape){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertLast(bodypart* head){
    bodypart* temp;
    bodypart* Node;
    char shape;
    temp = head;
    temp = find(head, '#');
    shape = temp->shape;
    temp->next->shape = shape;
    Node = newNode('#',temp->x,temp->y);
    temp->next->next = Node;
}

void freeList(bodypart* head){
   bodypart* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

