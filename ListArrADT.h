#ifndef ListArrADT_H
#define ListArrADT_H

#include <iostream>

class ListArrADT{

    public:
        virtual int size()=0;   //Retorna la cantidad de elementos almacenados en el ListArr
        virtual void insert_left(int v)=0;  //Inserta un nuevo valor v al inicio del ListArr: i=0 
        virtual void insert_right(int v)=0; //Inserta un nuevo valor v a la derecha del ListArr: i=size()-1
        virtual void insert(int v, int i)=0;    //Inserta un nuevo valor v en el indice i del ListArr
        virtual void print()=0; //Imprime todos los valores del ListArr
        virtual bool find(int v)=0; //Busca en el ListArr si el valor v está almacenado

};



#endif 