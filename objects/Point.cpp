#include <iostream>
#include "Point.h"

Point::Point ()
    : x(0),
    y(0),
    color(0)
{
}

Point::Point (int coorX, int coorY )
    : x (coorX),
      y (coorY)
{
    std::cout<<"Wywolano konstruktor punkt\n";
}

void Point::createObject ( int coorX, int coorY ){
    x = coorX;
    y = coorY;
}

void Point::loadValues ( int table[] ){
    table[0] = x;
    table[1] = y;
}

bool Point::ifThisObject ( int x1, int x2 ){
    if( x1 == x && x2 == y) return true;
    else return false;
}

void Point::resetObject ( ){
    x = 0;
    y = 0;
}

void Point::writeOutObject (){
    std::cout<<"x = "<<x<<"\t y = "<<y<<std::endl;
}

void Point::increaseCoord( int dX, int dY ){
    x += dX;
    y += dY;
}

Point Point::operator+ ( Point point2 ){
    Point pointSum;
    pointSum.x = this->x + point2.x;
    pointSum.y = this->y + point2.y;
    return pointSum;
}

Point Point::operator = ( const Point pCopy){
    x = pCopy.x;
    y = pCopy.y;
    color = pCopy.color;
    return *this;
}

bool Point::secondLowerOrRighter ( const Point P2, char whichCoord){
    if ( whichCoord == 1){
        if( y < P2.y ) return true;
        else return false;
    }
    if( whichCoord == 0){
        if( x < P2.x ) return true;
        else return false;
    }
}

bool Point::compareCoordinate ( const Point compareP, char whichCoord){ // whichCoord == 1 oznacza porownanie 
    if(whichCoord == 1){
        if( x == compareP.x ) return true; // punkt jeden jest nad drugim
    }
    if(whichCoord == 0){
        if( y == compareP.y ) return true; // punkt jeden jest obok drugiego (na tej samej wysokosci)
    }
    return false;
}

bool Point::operator == (const Point comparePoint ){
    if( x != comparePoint.x || y!=comparePoint.y ) return false;
    else return true;
}