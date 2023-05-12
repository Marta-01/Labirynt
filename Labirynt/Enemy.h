#pragma once
#include <memory>
#include "Object.h"
using namespace std;

/** \brief Klasa Enemy dziedzicz�ca po klasie Object zajmuje si� tworzeniem obiektu przeciwnika
*
* @param horizontal kierunek poruszania si� przeciwnika
* @param movement d�ugo�� kroku przeciwnika
*/
class Enemy : public Object {

    bool horizontal;
    int movement = -1;

public:
    Enemy(int nx, int ny, bool nhorizontal);
    void update(shared_ptr<Map> map);
};
