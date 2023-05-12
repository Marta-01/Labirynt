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

/** \brief Metoda ograniczaj¹ca dostêp do x
 *
 * @return x indeks rzêdu
 */
int Object::getX() {
    return x;
}

/** \brief Metoda ograniczaj¹ca dostêp do y
 *
 * @return y indeks kolumny
 */
int Object::getY() {
    return y;
}

/** \brief Metoda ograniczaj¹ca dostêp do character
 *
 * @return character znak elementu
 */
char Object::getCharacter() {
    return character;
}

/** \brief Metoda sprawdzaj¹ca czy nie trzeba zaktualizowaæ po³o¿enia obiektu
 *
 * @param map inteligentny wzkaŸnik na mapê labiryntu
 */
void Object::update(shared_ptr<Map> map) {

}

/** \brief Metoda sprawdzaj¹ca czy nie dosz³o do niemo¿liwego ruchu obiektu
 *
 * @param map mapa labiryntu
 */
bool Object::collides(int x, int y, Map map) {
    if (map.grid[x][y] == 1)
        return true;
    else return false;
}
