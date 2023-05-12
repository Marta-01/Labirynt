#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Object.h"
#include "Portal.h"
#include "Map.h"
#include "Player.h"

/** \brief Klasa Game zajmuje si� tworzeniem nowych obiket�w; kluczy portali i przeciwnic�w, obiekt mapy i obiekt playera. P�niej 
*
*/
using namespace std;
class Game {
    vector<shared_ptr<Object>> objects;
    vector<shared_ptr<Portal>> portals;
    shared_ptr<Player> player;
    shared_ptr<Map> map;

    string playerName;
    int score = 200;
    bool gameEnded = false;

public:

    Game(string _playerName);

    bool getGameEnded();

    bool saveScore();
    void endGame();

    void update();

    void draw();

    void movePlayer(char direction);
};
