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

/** \brief Konstruktor przypisuj¹cy do obiektu wartoœci pocz¹tkowe
*
* @param nx nowy indeks rzêdu
* @param ny nowy indeks kolumn
*/
Key::Key(int nx, int ny) {
    x = nx;
    y = ny;
    character = 'K';
}
