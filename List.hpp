#ifndef LIST_HPP
#define LIST_HPP

#include <iostream> 
#include "Players.hpp"

class List
{
private:
    Players* head; 


public:
    List(); //constructor
    ~List();          //destructor

    //void add(Players* new_child);     //add a node to the linked list
    Players *getHead();     //get the head of the linked list
    void setHead(Players *new_head); //set the head of the linked list
};

#endif

