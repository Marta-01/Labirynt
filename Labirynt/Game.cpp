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

Game::Game(string _playerName) : playerName{ _playerName } { 
    shared_ptr<Player> p(new Player(6, 1));
    shared_ptr<Map> m(new Map);
    shared_ptr<Key> k1(new Key(14, 2));
    shared_ptr<Key> k2(new Key(9, 11));
    shared_ptr<Key> k3(new Key(33, 3));
    shared_ptr<Key> k4(new Key(32, 16));
    shared_ptr<Key> k5(new Key(1, 17));


    shared_ptr<Portal> por1(new Portal(9, 3, '1', '2', 6, 5));
    shared_ptr<Portal> por2(new Portal(12, 3, '3', '4', 6, 2));
    shared_ptr<Portal> por3(new Portal(5, 10, '5', '6', 6, 3));
    shared_ptr<Portal> por4(new Portal(34, 14, '7', '8', 14, 15));
    shared_ptr<Portal> por5(new Portal(18, 15, '9', '0', 33, 11));

    shared_ptr<Enemy> e1(new Enemy(11, 5, false));
    shared_ptr<Enemy> e2(new Enemy(11, 7, true));
    shared_ptr<Enemy> e3(new Enemy(2, 14, true));
    shared_ptr<Enemy> e4(new Enemy(6, 15, false));
    shared_ptr<Enemy> e5(new Enemy(24, 6, true));
    shared_ptr<Enemy> e6(new Enemy(22, 17, true));
    shared_ptr<Enemy> e7(new Enemy(26, 15, true));
    shared_ptr<Enemy> e8(new Enemy(26, 14, false));
    shared_ptr<Enemy> e9(new Enemy(35, 10, false));
    shared_ptr<Enemy> e10(new Enemy(36, 18, false));


    map = m; 
    player = p; 
    objects.push_back(e1); 
    objects.push_back(e2);
    objects.push_back(e3);
    objects.push_back(e4);
    objects.push_back(e5);
    objects.push_back(e6);
    objects.push_back(e7);
    objects.push_back(e8);
    objects.push_back(e9);
    objects.push_back(e10);
    portals.push_back(por1);
    portals.push_back(por2);
    portals.push_back(por3);
    portals.push_back(por4);
    portals.push_back(por5);
    objects.push_back(k1);
    objects.push_back(k2);
    objects.push_back(k3);
    objects.push_back(k4);
    objects.push_back(k5);
}

/** \brief Metoda informuj¹ca o zakoñczeniu gry
*
* @return gameEnded
*/
bool Game::getGameEnded() {
    return gameEnded;
}

/** \brief Metoda zapisuj¹ca wynki do pliku
*
* @return 0
*/
bool Game::saveScore() {
    ofstream leaderboard; //

    leaderboard.open("score.txt", std::ios_base::app);
    leaderboard << playerName << " - " << score << " points" << endl;
    return 0;
}

/** \brief Metoda wyœwietlaj¹ca wynik
*
*/
void Game::endGame() {
    Menu::getInstance().printScore(score); 
    saveScore();
}

/** \brief Metoda sprawdzj¹ca, czy nie zasz³a sytacja niew³aœciwa
*
*/
void Game::update() {

    if ((*map).grid[(*player).getX()][(*player).getY()] == 3) {
        gameEnded = true;
        endGame();
    }

    for (int i = 0; i < objects.size(); i++) { 
        (*objects[i]).update(map); 
    }

    for (int i = 0; i < portals.size(); i++) { 
        (*portals[i]).update(map, player); 
    }

    for (int o = 0; o < objects.size(); o++) { 
        if ((*objects[o]).getX() == (*player).getX() && (*objects[o]).getY() == (*player).getY()) 
        {
            if ((*objects[o]).getCharacter() == 'E') {
                gameEnded = true;
                score = 0;
                endGame();
            }
            else if ((*objects[o]).getCharacter() == 'K') {

                (*player)++; //konstrukcja przeci¹zenia operatora, klucze siê zwiêkszaj¹
                objects.erase(std::remove(objects.begin(), objects.end(), objects[o]), objects.end()); //kostrukcja usuwania 
            }

        }
    }
}

/** \brief Metoda rysuj¹ca labirynt
*
*/
void Game::draw() {
    system("cls");
    for (int y = 0; y < Map::grid_y; y++) {
        for (int x = 0; x < Map::grid_x; x++) {
            char character = ' ';

            for (int o = 0; o < portals.size(); o++) {  
                if ((*portals[o]).getX() == x && (*portals[o]).getY() == y) 
                    character = (*portals[o]).getCharacter();
                if ((*portals[o]).getTeleportX() == x && (*portals[o]).getTeleportY() == y) { 
                    character = (*portals[o]).getExitCharacter();
                }
            }

            if ((*player).getX() == x && (*player).getY() == y) { 
                character = (*player).getCharacter();
            }


            for (int o = 0; o < objects.size(); o++) {
                if ((*objects[o]).getX() == x && (*objects[o]).getY() == y)
                    character = (*objects[o]).getCharacter();   
            }




            if ((*map).grid[x][y] == 1) {
                character = '#';
            }

            if ((*map).grid[x][y] == 2) {
                character = '%';
            }

            cout << setw(2) << character; //formatowanie
        }
        cout << endl; 
    }

    cout << "Keys: " << (*player).getKeys() << endl;
    cout << "Score: " << score << endl;
}

/** \brief Metoda zmieniaj¹ca po³o¿enie gracza na mapie
*
* @param direction
*/
void Game::movePlayer(char direction) {
    (*player).move(direction, map);
    score--;
}