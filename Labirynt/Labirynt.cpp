#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include "Menu.h"
#include "Map.h"
#include "Object.h"
#include "Enemy.h"
#include "Key.h"
#include "Player.h"
#include "Portal.h"
#include "Game.h"
#include "Windows.h"
using namespace std;


int main()
{
    string playerName = "";
    int enterUsername;

    while (playerName == "") {
        Menu::getInstance().showUsernameMenu();
        

            cin >> enterUsername;
            cin.clear();
            cin.ignore(10000, '\n');  

            if (enterUsername != 1 && enterUsername != 2) 
                Menu::getInstance().showUsernameError();
            
            if (enterUsername == 1) {
                Menu::getInstance().askForUsername();
                getline(cin, playerName);
            }
            else if (enterUsername == 2) {

                ifstream is("score.txt");
                string line;
                int linesCount = 0;
                while (getline(is, line))
                {
                    linesCount++;
                }
                playerName = to_string(linesCount + 1); 
            
        }
        
           
      
    }

    Game g(playerName);
    Menu::getInstance().showInfo();
    g.draw();
    
    while (!g.getGameEnded()) {
        
        Sleep(500);
        while (_kbhit()) 
            _getch(); 
        char c = _getch();
        

        if (c == 'w' || c == 's' || c == 'a' || c == 'd')
            g.movePlayer(c);

        g.update();
        g.draw();

    }
}
