#ifndef LAG_H_
#define LAG_H_

struct ertzPisuPos{
    int pisua;
    int posizioa;
};
typedef ertzPisuPos ertzPisuPos;

//PRIM-en Erabiltzeko
struct Node {
    int data;
    float weight;
    struct Node* next;
};
typedef Node Node;
 
//KRUSKAL-en Erailtzeko
struct Node2 {
    int A;
    int B;
    int weight;
    struct Node2* next;    
};
typedef Node2 Node2;

//PRIM-ekin Ibiltzeko NODE erabilita
int searchElement(struct Node* head, int item);
void insert(struct Node** head, int data);
void display(struct Node* node);


//KRUSKAL-en Ibiltzeko NODE2 erabilita
void MergeSort(struct Node2** headRef);
struct Node2* SortedMerge(struct Node2* a, struct Node2* b);
void FrontBackSplit(struct Node2* source, struct Node2** frontRef, struct Node2** backRef);


#endif