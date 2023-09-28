#include <iostream>
#include "List.hpp"
#include "Players.hpp"

class Commands
{
private:

    List game;
    int size;

public:
    Commands(/* args */);
    ~Commands();

    void spawn(double x, double y);
    void time(double t);
    void num();
    void prt(double D);
    void over();
};
