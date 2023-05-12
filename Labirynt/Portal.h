#include <memory>
#include "Object.h"
#include "Map.h"
#include "Player.h"
#pragma once

using namespace std;

/** \brief Klasa Portal zajmuje siê teleportowaniem gracza na nowe miejsce
*
*/
class Portal : public Object {
    int teleportX;
    int teleportY;
    char exitCharacter;

public:
    Portal(int nx, int ny, char ncharacter, char nExitCharacter, int nTeleportX, int nTeleportY);
    void update(shared_ptr<Map> map, shared_ptr<Player> player);
    int getTeleportX();
    int getTeleportY();
    int getExitCharacter();

};
