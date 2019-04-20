#ifndef POINT_H
#define POINT_H

class Point{
    private:
    char color;
    int x;
    int y;

    public:
    Point (); //kontruktor przypisujacy 0 do wspolrzednych
    Point (int , int ); // konstruktor przypisujacy konkretne wartosci
    void createObject ( const int, const int );  //przypisuje wartosci do punktu
    void loadValues ( int table[] ); //pobiera wartosci wspolrzednych
    bool ifThisObject ( int, int );
    void resetObject ( );
    void writeOutObject ();
    void increaseCoord( int dX, int dY );
    Point operator + ( const Point );
    Point operator = ( const Point );
    bool compareCoordinate ( const Point, char whichCoord);
    bool secondLowerOrRighter ( const Point, char ); //
    bool operator == ( const Point );
};

#endif //