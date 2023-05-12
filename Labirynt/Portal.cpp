#include "Portal.h"

/** \brief Konstruktor przypisuj�cy do obiektu warto�ci pocz�tkowe
*
* @param nx indeks rz�du
* @param ny indeks kolumn
* @param ncharacter znak na wej�ciu
* @param nExitCharacter znak na wyj�ciu
* @param nTeleportX nowy adres x na wyj�ciu
* @param nTeleportY nowy adres y na wyj�ciu
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

/** \brief Metoda teleportacj�ca gracza
*
* @param map wzka�nik na map� labiryntu
* @param player wzka�nik na gracza
*/
void Portal::update(shared_ptr<Map> map, shared_ptr<Player> player) {
    if ((*player).getX() == x && (*player).getY() == y) { //je�li gracz nadepnie na portal
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