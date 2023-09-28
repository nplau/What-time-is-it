#include <iostream> 
#include "Commands.hpp"

using namespace std;

int main(){

    string input;
    Commands play;

    double x;
    double y;
    double t;
    double D;
    

    while (cin >> input){

        if (input == "SPAWN"){ 
            cin >> x;
            cin >> y;
            play.spawn(x, y);    

        } else if (input == "TIME"){
           cin >> t;
            play.time(t);

        } else if (input == "NUM"){
            play.num();

        } else if (input == "PRT"){
            cin >> D;
            play.prt(D);

        } else if (input == "OVER") {
            play.over();
            break;
        }
    }
}

