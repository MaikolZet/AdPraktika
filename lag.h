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

#endif