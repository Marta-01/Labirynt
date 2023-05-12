#pragma once
#include <memory>
#include "Object.h"
using namespace std;

/** \brief Klasa Enemy dziedzicz¹ca po klasie Object zajmuje siê tworzeniem obiektu przeciwnika
*
* @param horizontal kierunek poruszania siê przeciwnika
* @param movement d³ugoœæ kroku przeciwnika
*/
class Enemy : public Object {

    bool horizontal;
    int movement = -1;

public:
    Enemy(int nx, int ny, bool nhorizontal);
    void update(shared_ptr<Map> map);
};
