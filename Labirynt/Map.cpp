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

/** \brief Metoda usuwaj¹ca drzwi
*
* @param x indeks rzêdu
* @param y indeks kolumny
*/
void Map::openDoor(int x, int y) { 
    grid[x][y] = 0;
}
