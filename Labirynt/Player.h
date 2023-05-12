#pragma once
#include "Object.h"
using namespace std;

/** \brief Klasa Player obs³ug¹ gracza; zajmuje siê kluczami i przemieszczaniem siê
*
* @param keys liczba kluczy gracza
*/
class Player : public Object {
    int keys = 0;
public:
    Player(int nx, int ny);
    int getKeys();
    void teleport(int nx, int ny);
    void move(char direction, shared_ptr<Map> map);
    Player& operator++(int); 

};