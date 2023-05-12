#include "Game.h"
#include <string>
#include "Key.h"
#include "Player.h"
#include "Portal.h"
#include "Enemy.h"
#include <iostream>
#include "Map.h"
#include "Menu.h"
#include <iomanip>
#include <fstream>

using namespace std;

/** \brief Konstruktor przypisuj�cy do obiektu warto�ci pocz�tkowe
*
* @param nx nowy indeks rz�du
* @param ny nowy indeks kolumn

*/
Player::Player(int nx, int ny) {
    x = nx;
    y = ny;
    character = 'O';
}

/** \brief Metoda zwracaj�ca liczb� kluczy
*
* @return keys liczba kluczy
*/
int Player::getKeys() {
    return keys;
}

/** \brief Metoda zmieniaj�ca pozycj� gracza na now� - u�ycie teleportu
*
* @param nx nowy indeks rz�du
* @param ny nowy indeks kolumn
*/
void Player::teleport(int nx, int ny) {
    x = nx;
    y = ny;
}

/** \brief Metoda zmieniaj�ca pozycj� gracza na now� - u�ycie klawiszy
*
* @param direction kierunek ruchu gracza
* @param map mapa z labiryntem
*/
void Player::move(char direction, shared_ptr<Map> map) {

    int oldX = x;
    int oldY = y;

    if (direction == 'd')
    {
        if (!collides(x + 1, y, (*map)))
            x++;
    }
    if (direction == 'a')
    {
        if (!collides(x - 1, y, (*map)))
            x--;
    }
    if (direction == 's')
    {
        if (!collides(x, y + 1, (*map)))
            y++;
    }
    if (direction == 'w')
    {
        if (!collides(x, y - 1, (*map)))
            y--;
    }

    if ((*map).grid[x][y] == 2) { 
        if (keys > 0) {
            (*map).openDoor(x, y); 
            keys--;
        }
        else {
            x = oldX;
            y = oldY;
        }
    }
}


Player& Player::operator++(int) {
    Player copy(*this);
    keys += 1;
    return copy;
}

