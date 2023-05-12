#pragma once
using namespace std;

/** \brief Klasa Menu wykorzystuje wzorzec projektowy Syngleton, kt�ry zapewnienia globalnege dost�p do stworzonego obiektu Menu
*
*/
class Menu {

private:
    Menu() {}

public:
    static Menu& getInstance();

    void showUsernameMenu();

    void showInfo();

    void showUsernameError();

    void askForUsername();

    void printScore(int score);

    template <typename T>    
    void printData(T value);
};
