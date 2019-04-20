#include <iostream>
//#include "List.h"

template <class type> class Node{
        public:
        type object;
        Node* next;
        Node* previous;


        void resetNode ( );
       // Node<type>* goNext(){ return next;}
        //void resetNodePoint ( Node<Point>& node ){};
      //  void resetNodePoint ( Node<type>& ); // zwalnia pamiec struktury i zeruje wskaznik
};


template <class type>
void Node<type>::resetNode ( ){
    object.resetObject();
    next = nullptr;
    previous = nullptr;
    delete this;
}