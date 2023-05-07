#include "ListArr.h"

ListArr::ListArr(int b){
    Head = nullptr;
    Head->b=b;
    Head->countNode = 0;
    count = 0;
}

ListArr::~ListArr(){
    Node* current = Head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    Head = nullptr;
    count = 0;
}

void ListArr::insert_left(int v){   //Inserta un elemento al inicio i = 0;
    int aux;
    while( Head != nullptr ){
        if(Head->b-1 != Head->countNode){
            for(int i = 0; i < Head->array[Head->countNode]; i++){
                aux = Head->array[i];
                Head->array[i] = v;
            }
        }
    }
}

void ListArr::insert_right(int v){
    
}