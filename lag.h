#ifndef LAG_H_
#define LAG_H_

struct ertzPisuPos{
    int pisua;
    int posizioa;
};
typedef ertzPisuPos ertzPisuPos;

struct Node {
    int data;
    float weight;
    struct Node* next;
};
typedef Node Node;

int searchElement(struct Node* head, int item);

void insert(struct Node** head, int data);

void display(struct Node* node);

#endif