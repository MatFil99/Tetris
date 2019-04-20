#ifndef Block_H
#define Block_H

#include "Point.h"

class Block{
    private:
    Point Point1;
    Point Point2;
    Point Point3;
    Point Point4;
    char type;

    public:
    Block ();
    Block ( Point, Point, Point, Point, char);
    ~Block ();
    void writeOutObject();
    void createObject ( const Point, const Point, const Point, const Point );
    void loadValues ( Point table[] ); //pobiera wartosci punktow
    bool ifThisObject ( Point, Point, Point, Point );
    void resetObject ( );
    void sortPoints( char whichCoord);
    void turnBlock();
    void turnI();
    void turnL();
    void turnR();
    void turnT();
    void turnS();
    void turnZ();
    Point operator + ( const Block );
};

#endif //