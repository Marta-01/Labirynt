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

/** \brief Konstruktor przypisuj¹cy do obiektu wartoœci pocz¹tkowe
*
* @param nx nowy indeks rzêdu
* @param ny nowy indeks kolumn
* @param nhorizontal nowy kierunek poruszania siê przeciwnika
*/
Enemy::Enemy(int nx, int ny, bool nhorizontal) {
    x = nx;
    y = ny;
    horizontal = nhorizontal;
    character = 'E';
}

/** \brief Metoda aktualizuj¹ca po³o¿enie przeciwnika
*
* @param map mapa z labiryntem
*/
void Enemy::update(shared_ptr<Map> map) {
    if (horizontal) {

        if (!collides(x + movement, y, *map)) {
            x += movement;
        }
        else {
            movement *= -1;
        }
    }
    if (!horizontal) {

        if (!collides(x, y + movement, *map)) {
            y += movement;
        }
        else {
            movement *= -1;
        }
    }

}