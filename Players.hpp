#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <iostream> 

class Players
{
private:
    double x;
    double y;
    Players* p_next; 
  

public:
    Players(double x, double y); //constructor
    ~Players();                  //destructor

    void setNext(Players *p_next); 
    Players *getNext();
    double getX();
    double getY();
    void setX(double new_x);
    void setY(double new_y);


};


#endif
