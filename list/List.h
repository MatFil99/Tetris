#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>


#include "../engine/Map.h"
#include "../objects/Point.h"
#include "../objects/IntNum.h"
#include "../objects/Block.h"
#include "Node.h"



template <class type> class List{
    private:
    std::string nameList;
    Node<type> nodeHead, nodeTail; //struktury przechowujace punkt oraz wskazniki na poprzednie i nastepne elementy

    public:
    List( std::string ); //konstruktor zwykly
    List ( const List& ); //konstruktor kopiujacy
    ~List ();//destruktor - zwalnia pamiec (struktur) 
    void copyValue( Node<Point>* listTwoNode, const List& listWhichCopy ); // funkcja pomocnicza do kopiowania objektu Point
    void copyValue ( Node<IntNum>* listTwoNode, const List& listWhichCopy ); // - || - do kopiowania objektu IntNum
    void writeOut ();//wypisuje liste
    void addNewObject ( const int, const int );//dodaje nowy punkt (alokuje strukture)
    void addNewObject ( const int );
    void addNewObject ( const Point, const Point , const Point ,const Point );
    void removeObjectFromList ( Node<type>* );
    void loadToMap (  );
    Node<type>* findObject ( int, int ); //znajduje punkt o podanych wspolrzednych
    Node<type>* findObject ( int ); // znajduje liczbe w liscie
    List<type> operator + ( const List<type> );
    List<type> operator = ( const List<type> );

};

//DEFINICJA FUNKCJI SZABLONOW



template <class type>
List<type>::List( std::string name )
    : nameList(name)
{
    std::cout<<"Wywolano konstruktor listy\n";
    nodeHead.next = nullptr;
    nodeHead.previous = nullptr;
    nodeTail.next = nullptr;
    nodeTail.previous = nullptr;
    Point point(0,0);
}


template <class type>
List<type>::List ( const List& listWhichCopy )
    : nameList (listWhichCopy.nameList)
{
    nodeHead.next = nullptr;
    nodeHead.previous = nullptr;
    nodeTail.next = nullptr;
    nodeTail.previous = nullptr;
    Point point(0,0);

    Node<type>* listTwoNode = listWhichCopy.nodeTail.previous;
    if( listTwoNode != nullptr){
        while ( listTwoNode!=&(listWhichCopy.nodeHead) ){
            //double tableCoor[3];
            //listTwoNode->object.loadValues (tableCoor);
            //this->addNewObject ( tableCoor[0], tableCoor[1], tableCoor[2]);
            
            this->copyValue ( listTwoNode, listWhichCopy );
            listTwoNode = listTwoNode->previous;
        }
    }
}

template <class type>
List<type>::~List (){
    Node<type>* actualNode = nodeHead.next;
    Node<type>* temp = nodeHead.next;
    if ( actualNode != nullptr ){
        while ( actualNode != &nodeTail ){
            actualNode = actualNode->next;
            temp->resetNode(); // zwalnianie pamieci
            temp = actualNode;
        }
    }
}

template <class type>
void List<type>::copyValue( Node<Point>* listTwoNode, const List& listWhichCopy ){
    int tableCoor[2];
    listTwoNode->object.loadValues (tableCoor);
    this->addNewObject ( tableCoor[0], tableCoor[1]);
    //listTwoNode = listTwoNode->previous;
}

template <class type>
void List<type>::copyValue( Node<IntNum>* listTwoNode, const List& listWhichCopy ){
    int numValue;
    listTwoNode->object.loadValues (numValue);
    this->addNewObject ( numValue );
    //listTwoNode = listTwoNode->previous;
}

template <class type>
void List<type>::addNewObject ( const int x, const int y ){ // dodawanie punktu
    Node<Point>* nodeMid = new Node<Point>;
    Node<Point>* temp = nodeHead.next;
    if ( temp == nullptr ){
        nodeHead.next = nodeMid;
        nodeTail.previous = nodeMid;
        nodeMid->previous = &nodeHead;
        nodeMid->next = &nodeTail;
    }else{
        nodeHead.next = nodeMid;
        temp->previous = nodeMid;
        nodeMid->previous = &nodeHead;
        nodeMid->next = temp;
    }
    nodeMid->object.createObject ( x, y );
}

template <class type>
void List<type>::addNewObject ( const int number ){ // dodawanie inta
    Node<IntNum>* nodeMid = new Node<IntNum>;
    Node<IntNum>* temp = nodeHead.next;
    if ( temp == nullptr ){
        nodeHead.next = nodeMid;
        nodeTail.previous = nodeMid;
        nodeMid->previous = &nodeHead;
        nodeMid->next = &nodeTail;
    }else{
        nodeHead.next = nodeMid;
        temp->previous = nodeMid;
        nodeMid->previous = &nodeHead;
        nodeMid->next = temp;
    }
    nodeMid->object.createObject ( number );
}

template <class type>
void List<type>::addNewObject ( const Point P1, const Point P2, const Point P3, const Point P4 ){
    Node<Block>* nodeMid = new Node<Block>;
    Node<Block>* temp = nodeHead.next;
    if ( temp == nullptr ){
        nodeHead.next = nodeMid;
        nodeTail.previous = nodeMid;
        nodeMid->previous = &nodeHead;
        nodeMid->next = &nodeTail;
    }else{
        nodeHead.next = nodeMid;
        temp->previous = nodeMid;
        nodeMid->previous = &nodeHead;
        nodeMid->next = temp;
    }
    nodeMid->object.createObject ( P1, P2, P3, P4 );
}
// dodatkowe funkcje dodajace np. int, double, char, string

template <class type>
void List<type>::writeOut (){
    Node<type>* temp = nodeHead.next;
    if( temp != nullptr ){
        while ( temp != &nodeTail ){
            temp->object.writeOutObject();
            temp = temp->next;
        }
    }
}

template <class type>
void List<type>::removeObjectFromList ( Node<type>* node){
    if(node == &nodeTail || node == nullptr ) return; // nie zwalniaj pamieci ogona!
    if ( node->next==&nodeTail && node->previous == &nodeHead ){
        node->resetNode ( );
        nodeHead.next = nullptr;
        nodeTail.previous = nullptr;
    }else{
        Node<type>* nodePrev = node->previous;
        Node<type>* nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->previous = nodePrev;
        node->resetNode ( );
    }
}

template <class type>
void List<type>::loadToMap(  ){



    Map mapa;



}

template <class type>
Node<type>* List<type>::findObject ( int x, int y ){
    Node<Point>* temp = nodeHead.next;
    while ( temp != &nodeTail && temp != nullptr && !(temp->object.ifThisObject( x, y))){
        temp = temp->next;
        std::cout<<"krok\n";
    }
    return temp;
}

template <class type>
Node<type>* List<type>::findObject ( int x ){
    Node<IntNum>* temp = nodeHead.next;
    while ( temp != &nodeTail && temp != nullptr && !(temp->object.ifThisObject( x))){
        temp = temp->next;
        std::cout<<"krok\n";
    }
    return temp;
}

template <class type>
List<type> List<type>::operator + ( const List<type> list2 ){
    List<type> sumList1 (*this);
    List<type> sumList2 (list2);
    sumList1.nodeTail.previous->next = sumList2.nodeHead.next;
    sumList2.nodeHead.next->previous = sumList1.nodeTail.previous;
    sumList2.nodeTail.previous->next = &(sumList1.nodeTail);
    sumList1.nodeTail.previous = sumList2.nodeTail.previous;
    
    sumList2.nodeHead.next = &(sumList2.nodeTail);// wyzerowanie sumList2
    sumList2.nodeTail.previous = &(sumList2.nodeHead);

    return sumList1;
}

template <class type>
List<type> List<type>::operator = ( const List<type> list2 ){
    List<type> copyList (list2);
    this->~List();
    nodeHead.next = copyList.nodeHead.next;
    nodeTail.previous = copyList.nodeTail.previous;
    copyList.nodeHead.next->previous = &(nodeHead);
    copyList.nodeTail.previous->next = &(nodeTail);

    copyList.nodeHead.next = &(copyList.nodeTail);
    copyList.nodeTail.previous = &(copyList.nodeHead);

    

    return *this;
}

#endif //