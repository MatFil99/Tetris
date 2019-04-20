#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "./list/List.h"
#include "./engine/Map.h"

using namespace std;

int main (){
    srand(time(NULL));
  
    Map mapa;
    mapa.mapView();
    mapa.refreshMap();  

    Point P1(1,1), P2(2,1), P3(3,3), P4(7,1);

    List<Block> lista1("lista1");
    lista1.addNewObject(P1, P2, P3, P4);
    lista1.addNewObject(P1+P2, P1+P1, P3, P1+P4);
    lista1.addNewObject(P2, P1, P4, P2+P3);
    lista1.writeOut();
    return 0;

}


//Komentarze
/*

 //List<Block> lista1("lista");

    Point P1( 1, 3), P2( 1, 1), P3( 1, 2), P4( 2, 3);
    //lista1.addNewObject(P1,P2,P3,P4);

    Block B1(P1,P2,P3,P4,'L');
   // B1.writeOutObject();

   // getchar();
    B1.sortPoints(1);

    B1.writeOutObject();
    B1.turnBlock();
    B1.writeOutObject();
    B1.turnBlock();

    B1.writeOutObject();
    B1.turnBlock();

    B1.writeOutObject();




List<IntNum> lista1("napis");
   // cout<<lista1.nameList<<endl;
    lista1.addNewObject( 2);
    lista1.addNewObject( 3);
    lista1.addNewObject( 1112);

    lista1.writeOut();

    List<IntNum> lista2( lista1 );

    cout<<endl<<"Kopia listy :D\n";

    lista2.writeOut();

    Node<IntNum>* point1 = lista2.findObject( 3 );
  //  cout<<point1->point.x<<" __ "<<point1->point.y<<" __ "<<point1->point.z<<" __ \n";
    lista2.removeObjectFromList( lista2.findObject( 2) );
    lista2.removeObjectFromList( lista2.findObject( 1112) );
    lista2.removeObjectFromList( lista2.findObject( 3) );
    lista2.removeObjectFromList( lista2.findObject( 3) );
    lista2.writeOut();


List<Point> lista1("napis");
   // cout<<lista1.nameList<<endl;
    lista1.addNewObject( 2, 2, 2);
    lista1.addNewObject( 3, 1, 2 );
    lista1.addNewObject( 1.2, 4.2, 0);

    lista1.writeOut();

    List<Point> lista2( lista1 );

    cout<<endl<<"Kopia listy :D\n";

    lista2.writeOut();

    Node<Point>* point1 = lista2.findObject( 1.2, 4.2, 0 );
  //  cout<<point1->point.x<<" __ "<<point1->point.y<<" __ "<<point1->point.z<<" __ \n";
    lista2.removeObjectFromList( lista2.findObject( 2, 2, 2) );
    lista2.removeObjectFromList( lista2.findObject( 1.2, 4.2, 0) );
    lista2.removeObjectFromList( lista2.findObject( 3, 1, 2) );
    lista2.removeObjectFromList( lista2.findObject( 3, 1, 2) );
    lista2.writeOut();
*/