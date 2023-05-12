#include "Object.h"
#include "Map.h"
#include <algorithm>
#include <memory>
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

/** \brief Metoda ograniczaj�ca dost�p do x
 *
 * @return x indeks rz�du
 */
int Object::getX() {
    return x;
}

/** \brief Metoda ograniczaj�ca dost�p do y
 *
 * @return y indeks kolumny
 */
int Object::getY() {
    return y;
}

/** \brief Metoda ograniczaj�ca dost�p do character
 *
 * @return character znak elementu
 */
char Object::getCharacter() {
    return character;
}

/** \brief Metoda sprawdzaj�ca czy nie trzeba zaktualizowa� po�o�enia obiektu
 *
 * @param map inteligentny wzka�nik na map� labiryntu
 */
void Object::update(shared_ptr<Map> map) {

}

/** \brief Metoda sprawdzaj�ca czy nie dosz�o do niemo�liwego ruchu obiektu
 *
 * @param map mapa labiryntu
 */
bool Object::collides(int x, int y, Map map) {
    if (map.grid[x][y] == 1)
        return true;
    else return false;
}
