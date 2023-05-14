#include "game_of_life.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


game_of_life::game_of_life() {
    srand(time(nullptr));
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

bool game_of_life::slucajna_vrijednost() {
        return rand() < RAND_MAX * 0.25;
}

bool game_of_life::celija_zauzeta(int i, int j) {
    if (i < 0 || i >= REDAKA || j < 0 || j >= STUPACA) {
        return false;
    }
    return _generacija[i][j];
}

void game_of_life::sljedeca_generacija() {
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            int broj_zivih_susjeda = 0;
            broj_zivih_susjeda += celija_zauzeta(i - 1, j - 1) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i - 1, j) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i - 1, j + 1) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i, j - 1) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i, j + 1) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i + 1, j - 1) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i + 1, j) ? 1 : 0;
            broj_zivih_susjeda += celija_zauzeta(i + 1, j + 1) ? 1 : 0;

            // Primjenjujemo pravila igre
            if (_generacija[i][j]) {
                if (broj_zivih_susjeda < 2 || broj_zivih_susjeda > 3) {
                    _sljedeca_generacija[i][j] = false;
                }
                else {
                    _sljedeca_generacija[i][j] = true;
                }
            }
            else {
                if (broj_zivih_susjeda == 3) {
                    _sljedeca_generacija[i][j] = true;
                }
                else {
                    _sljedeca_generacija[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

// Funkcija koja iscrtava trenutnu generaciju
void game_of_life::iscrtaj() {
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            if (_generacija[i][j]) {
                cout << "*";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}