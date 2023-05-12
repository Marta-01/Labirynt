#include "Portal.h"

/** \brief Konstruktor przypisuj¹cy do obiektu wartoœci pocz¹tkowe
*
* @param nx indeks rzêdu
* @param ny indeks kolumn
* @param ncharacter znak na wejœciu
* @param nExitCharacter znak na wyjœciu
* @param nTeleportX nowy adres x na wyjœciu
* @param nTeleportY nowy adres y na wyjœciu
* 
*/
Portal::Portal(int nx, int ny, char ncharacter, char nExitCharacter, int nTeleportX, int nTeleportY) { 
    x = nx;
    y = ny;
    character = ncharacter; 
    teleportX = nTeleportX; 
    teleportY = nTeleportY; 
    exitCharacter = nExitCharacter; 
}

/** \brief Metoda teleportacj¹ca gracza
*
* @param map wzkaŸnik na mapê labiryntu
* @param player wzkaŸnik na gracza
*/
void Portal::update(shared_ptr<Map> map, shared_ptr<Player> player) {
    if ((*player).getX() == x && (*player).getY() == y) { //jeœli gracz nadepnie na portal
        (*player).teleport(teleportX, teleportY); //to przteleportuj go w miejsce x i y
    }
}


int Portal::getTeleportX() {
    return teleportX;
}

int Portal::getTeleportY() {
    return teleportY;
}

int Portal::getExitCharacter() {
    return exitCharacter;
}