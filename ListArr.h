#ifndef ListArr_H
#define ListArr_H
#include "ListArrADT.h"

class ListArr: public ListArrADT{
private:
    //Para nodos
    struct Node {
    int num_elements;
    int* array;
    Node* next;
    Node(int b) {
            this->b = b;
            num_elements = 0;
            array = new int[b];
            next = nullptr;
        }
    ~Node() {
        delete[] arr;
    }
};
    //Para nodos resumenes
    struct NodeSummary {        
    int total_capacity;
    int total_size;
    NodeSummary* left_child;
    NodeSummary* right_child;
};

Node* T;
int count;

public:
    ListArr();
    ~ListArr();
    int size()=0;   
    void insert_left(int v)=0;  
    void insert_right(int v)=0; 
    void insert(int v, int i)=0;
    void print()=0; 
    bool find(int v)=0; 

};

#endif