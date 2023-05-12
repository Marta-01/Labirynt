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

/** \brief Metoda wy�wietlaj�ca menu u�ytkownika
*
*/
void Menu::showUsernameMenu() {
    system("cls");
    cout << "Czy chcesz podac pseudonim?" << endl;
    cout << "1. Tak" << endl;
    cout << "2. Nie" << endl;
}


Menu& Menu::getInstance() { //zmienna statyczna (nale�y do klasy) jest taka sama dla ka�dego obiektu w twj klasie, tworzenie obiektu na chwile
    static Menu theInstance;
    return theInstance; //zwraca obiekt do wykorzystania w danej chwili
}


/** \brief Metoda wy�wietlaj�ca instrukcj�
*
*/
void Menu::showInfo() {
    cout << "Witaj w grze labirynt." << endl;
    cout << "1-9 - Portale. Portal o numerze 1 przenosi do wyjscia o numerze 2, portal 3 do wyjscia 4 itd. Portale dzialaja w jedna strone." << endl;
    cout << "K - Klucze potrzebne do otworzenia drzwi. Liczba posiadanych kluczy znajduje sie w dolnej czesci ekranu." << endl;
    cout << "% - Drzwi do ktorych otwarcia potrzebny jest klucz" << endl;
    cout << "E - Przeciwnik. Porusza sie od sciany do sciany. Jezeli wejdziesz na te samo pole co przeciwnik przegrywasz." << endl;
    system("pause");
}

/** \brief Metoda wy�wietlaj�ca b��d
*
*/
void Menu::showUsernameError() {
    cout << "Wybrano zla opcje. Prosze wybrac jeszcze raz." << endl;
    system("pause");
}

/** \brief Metoda wy�wietlaj�ca pro�b� o podanie pseudonimu
*
*/
void Menu::askForUsername() {
    cout << "Podaj pseudonim: ";
}

/** \brief Metoda wydrukowuj�ca wynik na konsol�
*
* @param score wynik
*/
void Menu::printScore(int score) {                              
    printData<const char[28]>("Koniec gry, twoj wynik to: ");  
    printData<int>(score);
    printData<char>('\n');
    system("pause");
}

template <typename T> 
void Menu::printData(T data) { 
    cout << data;
}
