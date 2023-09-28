#include <iostream> 
#include <cmath>
#include "Players.hpp"

// Node constructor
Players::Players(double new_x, double new_y): 
x(new_x), 
y(new_y), 
p_next(nullptr){}

// Node destructor
Players::~Players(){
    
}

void Players::setNext(Players *next){
    this->p_next = next;
}

Players *Players::getNext(){
    return this->p_next;
}

double Players::getX(){
   return this->x;
}

double Players::getY(){
    return this->y;
}

void Players::setX(double new_x){
    this->x = new_x;
}

void Players::setY(double new_y){
    this->y = new_y;
}