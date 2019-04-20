#ifndef _Map_H_
#define _Map_H_

#include "../list/List.h"

//background colors
#define	BLACK 40
#define	RED 41
#define	GREEN 42
#define YELLOW 43
#define	BLUE 44
#define	MAGENTA 45
#define	CYAN 46
#define WHITE 47 //niepotrzeny ?

#define WIDTH 13
#define HEIGHT 26

class Map{
private:
    char tableMap[HEIGHT][2*WIDTH]; // tablica wysokosc x szerokosc (1 - wiersze, 2 - kolumny)
  //  List<Block> listBlocks(); 
public:
    Map();
    ~Map();
    void mapView();
    char randomColor();
    void refreshMap( );
    void reset();
};


#endif //