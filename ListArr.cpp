#include "ListArrADT.h"
#include "ListArr.h"

ListArr::ListArr(int b){
    Head = nullptr;
    Tail = nullptr;
    Tail->b = b;
    Head->b=b;
    Head->countNode = 0;
    count = 0;
    NodeSummary Summary;
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
    int n = Head->b;
    Node* NewNode = new Node(n);
    if(Head == nullptr){    //Primer nodo iniciado
        Head = NewNode;
        Tail = NewNode;
        for(int i = n; i>=0; i--){
            Head->array[i+1] = Head->array[i];
        }
        Head->array[0] = v;
        aux++;
    }else{
        if(n == aux){   //Primer arreglo lleno
            NewNode = Head->next;   //Nuevo nodo apunta al nodo que apuntaba la cabeza
            Head = NewNode; //La cabeza apunta al Nuevo nodo
            aux++;
            int OutValue = Head->array[n-1];
            for(int i = n; i>=0; i--){
                Head->array[i+1] = Head->array[i];
            }
            Head->array[0] = v;
            NewNode->array[0] = OutValue;
        }
    }
}

void ListArr::insert_right(int v){
    this->count++;
    int n = Head->b;
    int aux = 0;
    Node* NewNode = new Node(n);
    if(Head == nullptr){    //Primer nodo iniciado
        Head = NewNode;
        Tail = NewNode;
        for(int i = n; i>=0; i--){
            Head->array[i+1] = Head->array[i];
        }
        Head->array[0] = v;
        aux++;
    }else{
        if(n == aux){   //Ultimo arreglo lleno
            NewNode = Tail->next; //Ultimo nodo apunta a lo que apunta la cola
            Tail = NewNode; //Cola apunta al nuevo nodo
            aux++;
            int OutValue = Head->array[n-1];
            for(int i = n; i>=0; i--){
                Tail->array[i+1] = Tail->array[i];
            }
            Tail->array[0] = v;
            NewNode->array[0] = OutValue;
        }
    } 
}

int ListArr::size(){
    return this->count;
}

void ListArr::insert(int v, int i){
    this->count++;
    int aux = 0;        //Variable que permite encontrar el nodo del indice
    int index = 0;      //Indice dentro del arreglo
    int n = Head->b;    //tamaño del arreglo
    Node *current = Head;

    while(current != nullptr ){
        while(aux != i-1){
            for(int j = 0; j < n; j++){
                aux++;
                index++;
                if(aux == i) break;
            }
            if(aux==i) break;   //Obtengo el nodo current donde se almacena el indice i
            else{
                current = current->next;
                index = 0;      //Itero en 0 por cada nodo para obtener la posición de i
            }    
        }
        current->array[index] = v;
    }
}

bool ListArr::find(int v){
    bool b = false;
    int n = Head->b;
	Node *current = Head;

	while(current != nullptr){
		for(int i = 0; i < n; i++){
            if(current->array[i]==v){   //Compara dentro del arreglo del nodo
                return true;
            }
            current = current->next;    //Avanza al siguiente nodo
        }
	}
	return false;
}

void ListArr::print(){
    int n = Head->b;
    Node* current = Head;
    std::cout<<std::endl;

    while(current != nullptr){
        for(int i = 0; i < n; i++){
            std::cout<< current->array[i] << "";
        }
        current = current->next;
    }
}