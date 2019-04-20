#include <iostream>
#include "IntNum.h"

IntNum::IntNum ():
    number(0)
{
}

IntNum::IntNum ( int initNumber ):
    number(initNumber)
{

}

void IntNum::createObject ( const int newValue ){
    number = newValue;
}

void IntNum::loadValues ( int& numValue ){
    numValue = number;
}

bool IntNum::ifThisObject ( int value ){
    return value == number;
}

void IntNum::resetObject ( ){
    number = 0;
}

void IntNum::writeOutObject (){
    std::cout<<this->number<<std::endl;
}

IntNum IntNum::operator + ( const IntNum object2 ){
    return this->number + object2.number;
}

IntNum IntNum::operator = ( const IntNum object2 ){
    number = object2.number;
    return *(this);
}