#include <iostream>
#include <cstdlib>

#include "Map.h"
//#include "../list/List.h"


Map::Map(){
    for ( int i=0; i<HEIGHT; ++i){
        for (int j=0; j<WIDTH; ++j){
            tableMap[i][j] = 40;
            tableMap[i][j+1] = 40;
        }
    }
}

Map::~Map(){
    for ( int i=0; i<HEIGHT; ++i){
        for (int j=0; j<WIDTH; ++j){
            tableMap[i][j] = 0;
            tableMap[i][j+1] = 0;
        }
    }
}


void Map::mapView(){
    for ( int i=0; i<HEIGHT; ++i){
        for (int j=0; j<WIDTH; ++j){
            printf( "%c[%dm  ",0x1B, tableMap[i][j]);
        }
        reset();
        std::cout<<std::endl;
    }
}

void Map::refreshMap(  ){
    List<Block> lP("j");


}

char Map::randomColor(){
    return rand()%7 +41;
}

void Map::reset()
{
  printf("%c[%dm",0x1B,0);//przywrocenie naturalnych kolorow konsoli
}