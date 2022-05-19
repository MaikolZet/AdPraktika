#ifndef LAG_H_
#define LAG_H_

#define OUR_FLT_MAX 3.402823466e+38F

struct ertzPisuPos{
    int A;
    int B;
    float weight;
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
    float weight;
    struct Node2* next;    
};
typedef Node2 Node2;

struct ertz {
    int A;
    int B;
    float weight;  
};
typedef ertz ertz;

//PRIM-ekin Ibiltzeko NODE erabilita
int searchElement(struct Node* head, int item);
float mysearchElement(int item1, int item2);
void insert(struct Node** head, int data);
void display(struct Node* node);


//KRUSKAL-en Ibiltzeko NODE2 erabilita
void MergeSort(struct Node2** headRef);
struct Node2* SortedMerge(struct Node2* a, struct Node2* b);
void FrontBackSplit(struct Node2* source, struct Node2** frontRef, struct Node2** backRef);
void push(struct Node2** head_ref, int A, int B, float weight);
void display2();


#endif