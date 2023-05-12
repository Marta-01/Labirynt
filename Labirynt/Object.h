#pragma once
#include <memory>
#include "Map.h"
using namespace std;

/** \brief Klasa Object, z kt�rej dziedzicz� inne elementy labiryntu.
*
* @param x indeks rz�du
* @param y indeks kolumny
* @param character znak elementu
*/
class Object {
protected:
    int x;
    int y;
    char character;

public:
    int getX(); 
    int getY();
    char getCharacter();

    virtual void update(shared_ptr<Map> map); 

    bool collides(int x, int y, Map map);
};
