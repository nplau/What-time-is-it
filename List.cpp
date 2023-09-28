#include <iostream> 
#include <cmath>
#include "List.hpp"
#include "Players.hpp"

// Linked list constructor
List::List(){
    head = nullptr;

}

// Linked list destructor
List::~List(){

    Players* temp = head;
    while(temp != nullptr){
        Players *temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }
}


Players *List::getHead(){
    return this->head;
}

void List::setHead(Players *new_head){
    this->head = new_head;
}





