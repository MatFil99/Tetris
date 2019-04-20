#include <iostream>


#include "Block.h"
//#include "Point.h"

Block::Block():
    type('o')
{

}

Block::Block(Point P1, Point P2, Point P3, Point P4, char typeBlock):
    Point1(P1),
    Point2(P2),
    Point3(P3),
    Point4(P4),
    type(typeBlock)
{
    
}

Block::~Block(){
    std::cout<<"To jest destruktor!\n";
}

void Block::writeOutObject(){
    std::cout<<type;
    Point1.writeOutObject();
    Point2.writeOutObject();
    Point3.writeOutObject();
    Point4.writeOutObject();

}

void Block::createObject ( const Point P1, const Point P2, const Point P3, const Point P4){
    Point1 = P1;
    Point2 = P2;
    Point3 = P3;
    Point4 = P4;
}

void Block::loadValues ( Point table[] ){
    table[0] = Point1;
    table[1] = Point2;
    table[2] = Point3;
    table[3] = Point4;
}

bool Block::ifThisObject ( Point P1,Point P2, Point P3, Point P4){
    if( Point1 == P1 && Point2 == P2 && Point3 == P3 && Point4 == P4 ) return true;
    return false;
}

void Block::resetObject (){
    Point1.resetObject();
    Point2.resetObject();
    Point3.resetObject();
    Point4.resetObject();
}

void Block::sortPoints( char whichCoord){
    Point temp[4] = {Point1, Point2, Point3, Point4};
    Point helpPoint = Point1;
    for (int i=0; i<4;++i){
        for(int j=0;j<3-i;++j){
            if(!(temp[j].secondLowerOrRighter(temp[j+1], whichCoord))){
                helpPoint = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = helpPoint;
            }
        }
    }
    Point1 = temp[0];
    Point2 = temp[1];
    Point3 = temp[2];
    Point4 = temp[3];
}

void Block::turnBlock(){
    switch (type)
    {
    case 'I':
        turnI();
        break;
    case 'L':
        turnL();
        break;
    case 'S':
        turnS();
        break;
    case 'Z':
        turnZ();
        break;
    case 'R':
        turnR();
    case 'T':
        turnT();
        break;
    default:
        break;
    }
}

void Block::turnI(){
    if(Point1.compareCoordinate(Point2, 1)){
        this->sortPoints(1);
        Point2.increaseCoord(1,-1);
        Point3.increaseCoord(2,-2);
        Point4.increaseCoord(3,-3);
    }else{
        this->sortPoints(0);
        Point2.increaseCoord(-1,1);
        Point3.increaseCoord(-2,2);
        Point4.increaseCoord(-3,3);
    }
}

void Block::turnL(){
    this->sortPoints(1);
    if(Point1.compareCoordinate(Point2, 1) && (Point1.compareCoordinate(Point3, 1) || Point1.compareCoordinate(Point3, 1) )&& Point3.compareCoordinate(Point4, 0)){
        if(Point4.secondLowerOrRighter(Point3, 0)){
            Point temp = Point3;
            Point3= Point4;
            Point4 = temp;
        }
        Point1.increaseCoord(1,0);
        Point2.increaseCoord(2,-1);
        Point3.increaseCoord(0,-1);
        Point4.increaseCoord(-1,-2);
    }// gdy L nie jest odwrocone
    else if( (Point1.compareCoordinate(Point4,1) || Point2.compareCoordinate(Point4,1)) && Point3.compareCoordinate(Point4,1) ){
        if(Point2.secondLowerOrRighter(Point1, 0)){
            Point temp = Point1;
            Point1= Point2;
            Point2 = temp;
        }
        Point1.increaseCoord(2,1);
        Point2.increaseCoord(1,0);
        Point4.increaseCoord(-1,-1);
    }// gdy L do gory nogami
    else {
        sortPoints(0);
        if(Point1.compareCoordinate(Point2,1)){
            if(Point1.secondLowerOrRighter(Point2,1)){
                Point temp = Point1;
                Point1 = Point2;
                Point2 = temp;
            }
            Point1.increaseCoord(1,0);
            Point4.increaseCoord(-1,2);
        }else{
            Point1.increaseCoord(3,1);
            Point2.increaseCoord(1,1);
        }
    }

}

void Block::turnR(){
    this->sortPoints(1);
    if(Point1.compareCoordinate(Point2, 1) && (Point1.compareCoordinate(Point3, 1) || Point1.compareCoordinate(Point3, 1) )&& Point3.compareCoordinate(Point4, 0)){
        if( Point3.secondLowerOrRighter(Point4, 0) ){
            Point temp = Point3;
            Point3 = Point4;
            Point4 = temp;
        }
        Point1.increaseCoord(1,1);
        Point3.increaseCoord(-1,-1);
        Point4.increaseCoord(0,-2);
    }else if((Point1.compareCoordinate(Point4,1) || Point2.compareCoordinate(Point4,1)) && Point3.compareCoordinate(Point4,1) ){
        Point3.increaseCoord(-1,-1);
        Point4.increaseCoord(1,-1);
    }else {
        sortPoints(0);
        if(Point1.compareCoordinate(Point2,1)){
            Point3.increaseCoord(0,-1);
            Point4.increaseCoord(-2,1);
        }else{
            Point1.increaseCoord(1,2);
            Point2.increaseCoord(1,2);
        }
    }
}

void Block::turnT(){
    sortPoints(0);
    if((Point1.compareCoordinate(Point2, 0) || Point1.compareCoordinate(Point3,0)) && Point1.compareCoordinate(Point4,0) ){
        if(Point3.secondLowerOrRighter(Point2, 1)){
            Point temp = Point2;
            Point2 = Point3;
            Point3 = temp;
        }
        if(Point1.compareCoordinate(Point3, 0)){
            Point1.increaseCoord(0,1);
            Point2.increaseCoord(-1,0);
            Point3.increaseCoord(-1,0);
            Point4.increaseCoord(-1,0);
        }else{
            Point1.increaseCoord(1,1);
            Point2.increaseCoord(1,1);
            Point3.increaseCoord(1,1);
        }
    }else{
        sortPoints(1);
        if(Point3.secondLowerOrRighter(Point2, 0)){
            Point temp = Point2;
            Point2 = Point3;
            Point3 = temp;
        }
        if(Point1.compareCoordinate(Point3,1)){
            Point4.increaseCoord(1,-1);
        }else{
            Point1.increaseCoord(-1,0);
            Point2.increaseCoord(0,-1);
            Point3.increaseCoord(0,-1);
            Point4.increaseCoord(0,-1);
        }
    }
}

void Block::turnS(){
    sortPoints(1);
    if(!(Point1.compareCoordinate(Point2,1)) && !(Point1.compareCoordinate(Point4, 1))){
        Point1.increaseCoord(2,0);
        Point4.increaseCoord(0,-2);
    }else{
        sortPoints(0);
        Point1.increaseCoord(1,1);
        Point2.increaseCoord(-1,0);
        Point3.increaseCoord(-1,0);
        Point4.increaseCoord(-1,1);
    }
}

void Block::turnZ(){
    sortPoints(1);
    if(!(Point1.compareCoordinate(Point2,1))){
        Point1.increaseCoord(1,1);
        Point2.increaseCoord(0,-1);
        Point3.increaseCoord(0,-1);
        Point4.increaseCoord(1,-1);
    }else{
        sortPoints(0);
        Point1.increaseCoord(0,1);
        Point4.increaseCoord(-2,1);
    }
}