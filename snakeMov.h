#ifndef SNAKEMOV_H
#define SNAKEMOV_H


struct bodypart{
    char shape;
    int x;
    int y;
    struct bodypart *next;
};

typedef struct bodypart bodypart;
bodypart *newNode(char shape,int x, int y);
bodypart *insert(bodypart **head, bodypart *part);
void printList(bodypart *head);
bodypart *createSnake(char const* const fileName);
void changeSnake(bodypart* snake);
bodypart *find(bodypart* head, char shape);
void insertLast(bodypart* head);
void freeList(bodypart* head);
#endif