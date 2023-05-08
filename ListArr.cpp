#include "ListArr.h"

ListArr::ListArr(int b){
    Head = nullptr;
    Tail = nullptr;
    Tail->b = b;
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
    this->count++;
    int aux=0;
    int aux1= 0;
    int n = Head->b;
    Node* NewNode = new Node(n);
    if(Head == nullptr){
        Head = NewNode;
        Tail = NewNode;
        delete NewNode;
        for(int i = n; i>=0; i--){
            Head->array[i+1] = Head->array[i];
        }
        Head->array[0] = v;
    }else{
        Tail->next = NewNode;
        Tail = NewNode;
        delete  NewNode;
        if(aux == n-1 ){
            if( Head->next!=nullptr){
                aux++;
                int OutValue = Head->array[n-1];
                for(int i = n; i>=0; i--){
                    Head->array[i+1] = Head->array[i];
                }
                Head->array[0] = v;
                Head->next->array[aux1] = OutValue;
                aux1++; 
            }   
        }
    }
}

void ListArr::insert_right(int v){
    this->count++;
    int n = Head->b;
    int aux = 0;
    int aux1 = 0;
    if(aux == n-1){
        Node* Newnode = new Node(n);
        Tail->next = Newnode;
        delete Newnode;
        if(Tail!=nullptr){
                aux++;
                int OutValue = Head->array[n-1];
                for(int i = n; i>=0; i--){
                    Head->array[i+1] = Head->array[i];
                }
                Head->array[0] = v;
                Head->next->array[aux1] = OutValue;
                aux1++; 
            }  
    }else{
        for(int i = n; i>=0; i--){
            Head->array[i+1] = Head->array[i];
        }
            Head->array[0] = v;
    }
}

int ListArr::size(){
    return this->count;
}