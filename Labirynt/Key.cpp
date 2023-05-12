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

/** \brief Konstruktor przypisuj�cy do obiektu warto�ci pocz�tkowe
*
* @param nx nowy indeks rz�du
* @param ny nowy indeks kolumn
*/
Key::Key(int nx, int ny) {
    x = nx;
    y = ny;
    character = 'K';
}
