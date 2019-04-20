#ifndef IntNum_H
#define IntNum_H

class IntNum{
    private:
    int number;
    
    public:
    IntNum (); //kontruktor przypisujacy 0 do wspolrzednych
    IntNum ( int  ); // konstruktor przypisujacy konkretne wartosci
    void createObject ( const int );  //przypisuje wartosci do punktu

   // void createObject ( double, double, double ){};
    
    void loadValues ( int& ); //pobiera wartosci wspolrzednych
    bool ifThisObject ( int );
    void resetObject ( );
    void writeOutObject ();
    IntNum operator + ( const IntNum );
    IntNum operator = ( const IntNum );

};

#endif //