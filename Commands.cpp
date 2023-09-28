#include <iostream>
#include "Players.hpp"
#include "List.hpp"
#include "Commands.hpp"
#include <cmath>


Commands::Commands()
{
    game = List();
    size = 0;
 
}

Commands::~Commands()
{
}


void Commands::spawn(double x, double y){
    // create a new node contining the coordinates entered (x,y) 
    if (x > 0 && y > 0){
    
        size++;
        Players *new_child {new Players(x, y)};
        
         if(game.getHead() == nullptr){
            game.setHead(new_child);
        } else{
            //adding the new node to the front of the list
            Players *temp_ptr {game.getHead()};
            game.setHead(new_child);
            new_child -> setNext(temp_ptr);
        }
        
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}

void Commands::time(double t){
    // if t is positive 
        //move children by the formula 
        //remove children outside of the quadrant
    // if t is negative, remove children that are closer than 1m
    Players *temp_ptr = game.getHead();
    Players *prev = game.getHead();

    if (t > 0){
        
        while (temp_ptr != nullptr){
            double x = temp_ptr->getX();
            double y = temp_ptr->getY();
            double x_new = x - (t * cos(atan2(y,x)));
            double y_new = y - (t * sin(atan2(y,x)));


            // check to see if child is out of bounds
            if (x_new > 0 && y_new > 0){
                temp_ptr->setX(x_new);
                temp_ptr->setY(y_new);
            } else {
                
                size--;

        

                if (temp_ptr == game.getHead()){ //if the node is the head
                    game.setHead(temp_ptr->getNext());
                    delete temp_ptr;
                    temp_ptr = game.getHead(); 

                } else {
                    prev->setNext(temp_ptr->getNext());
                    delete temp_ptr;    
                    temp_ptr = prev->getNext();
                }
            }
            prev = temp_ptr;

            if (temp_ptr != nullptr){
            temp_ptr = temp_ptr->getNext();
            }
        }    
        
    } else if (t < 0){
        double distance;

        while (temp_ptr != nullptr){
            double x = temp_ptr->getX();
            double y = temp_ptr->getY();
            distance = sqrt((x*x) + (y*y)); //checking distance from origin

            if (distance < 1){
                size--;
                
                if (temp_ptr == game.getHead()){ //if the node is the head
                    game.setHead(temp_ptr->getNext());
                    delete temp_ptr;
                    temp_ptr = game.getHead(); 

                } else {
                    prev->setNext(temp_ptr->getNext());
                    delete temp_ptr;
                    temp_ptr = prev->getNext();
                }
                
            }
            prev = temp_ptr;

            if (temp_ptr != nullptr){
            temp_ptr = temp_ptr->getNext();
            }
        }
    } 

    num();
    
}

void Commands::num(){
    //output number of nodes in the linkedlist
    unsigned int N = size;  
    std::cout << "number of children still playing: " << N << std::endl;
}

void Commands::prt(double D){
    //go through linked list and print all chidren coordinates within distance D
    unsigned int N = size;
    bool count = true;
    double distance;
    Players *temp_ptr = game.getHead();

    for (int i = 0; i < N; i++){
        double x = temp_ptr->getX();
        double y = temp_ptr->getY();
        distance = sqrt((x*x) + (y*y));
        
        if (distance < D){
            std::cout << x << " " << y << " ";
            count = false;
        }
        
    }

    if (count == true){
        std::cout << "no children within distance" << std::endl;
    } else {
        std::cout << std::endl; 
    }
}

void Commands::over(){
    // check if linked list is null 

   unsigned int inGame = size;
   if (inGame != 0){
        std::cout << "the players win" << std::endl;
    }else{
        std::cout << "the wolf wins" << std::endl;
    }
}
