#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int MAX_COFNIJ = 5;

struct gra {
    struct gracz {
        int x, y; // pozycja kursora
        int poprzedniSymbol;

    } gracz;
    int atomy = 3;
    int atomySredni = 5;
    int atomyTrudny = 8;
    bool** oznaczenia;
    int** oddzialywanie;
    int wynik = 0;

    // 1,2,3,4 - symbole naroznikow 5 - sciana pionowa 6- sciana pozioma 7 - pole gry 8 - puste pole 9 - atom

    int** generujTablice() {
        const int rozmiar = 16;
        int** tablica = new int* [rozmiar];
        oznaczenia = new bool* [rozmiar];
        oddzialywanie = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = new int[rozmiar];
            oznaczenia[i] = new bool[rozmiar];
            oddzialywanie[i] = new int[rozmiar];
        }

        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                if ((i == 2 and j == 2) or (i == 4 and j == 4)) {
                    tablica[i][j] = 1;
                }
                else if ((i == 2 and j == 12) or (i == 4 and j == 10)) {
                    tablica[i][j] = 2;
                }
                else if ((i == 12 and j == 2) or (i == 10 and j == 4)) {
                    tablica[i][j] = 3;
                }
                else if ((i == 12 and j == 12) or (i == 10 and j == 10)) {
                    tablica[i][j] = 4;
                }
                else if ((j == 4 and i > 4 and i <= 9) or (j == 10 and i > 4 and i <= 9) or
                    (i > 2 and i <= 11 and j == 2) or (i > 2 and i <= 11 and j == 12)) {
                    tablica[i][j] = 5;
                }
                else if ((i == 2 and j > 2 and j <= 11) or (i == 4 and j > 4 and j <= 9) or
                    (i == 12 and j > 2 and j <= 11) or (i == 10 and j > 4 and j <= 9)) {
                    tablica[i][j] = 6;
                }
                else if (i > 4 and i <= 9 and j > 4 and j <= 9) {
                    tablica[i][j] = 7;
                }
                else {
                    tablica[i][j] = 8;
                }
            }
        }

        return tablica;
    }

    int** generujSrednia() {
        const int rozmiar = 16;
        int** tablica = new int* [rozmiar];
        oznaczenia = new bool* [rozmiar];
        oddzialywanie = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = new int[rozmiar];
            oznaczenia[i] = new bool[rozmiar];
            oddzialywanie[i] = new int[rozmiar];
        }

        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                if ((i == 3 and j == 3) or (i == 0 and j == 0)) {
                    tablica[i][j] = 1;
                }
                else if ((i == 0 and j == 15) or (i == 3 and j == 12)) {
                    tablica[i][j] = 2;
                }
                else if ((i == 15 and j == 0) or (i == 12 and j == 3)) {
                    tablica[i][j] = 3;
                }
                else if ((i == 15 and j == 15) or (i == 12 and j == 12)) {
                    tablica[i][j] = 4;
                }
                else if ((j == 0 and i > 0 and i <= 14) or (j == 15 and i > 0 and i <= 14) or
                    (i > 3 and i <= 11 and j == 3) or (i > 3 and i <= 11 and j == 12)) {
                    tablica[i][j] = 5;
                }
                else if ((i == 0 and j > 1 and j <= 14) or (i == 15 and j > 1 and j <= 14) or
                    (i == 3 and j > 3 and j <= 11) or (i == 12 and j > 3 and j <= 11)) {
                    tablica[i][j] = 6;
                }
                else if (i > 3 and i <= 11 and j > 3 and j <= 11) {
                    tablica[i][j] = 7;
                }
                else {
                    tablica[i][j] = 8;
                }
            }
        }
        return tablica;
    }

    int** generujTrudna() {
        const int rozmiar = 16;
        int** tablica = new int* [rozmiar];
        oznaczenia = new bool* [rozmiar];
        oddzialywanie = new int* [rozmiar];
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = new int[rozmiar];
            oznaczenia[i] = new bool[rozmiar];
            oddzialywanie[i] = new int[rozmiar];
        }

        for (int i = 0; i < rozmiar; ++i) {
            for (int j = 0; j < rozmiar; ++j) {
                if ((i == 2 and j == 2) or (i == 0 and j == 0)) {
                    tablica[i][j] = 1;
                }
                else if ((i == 0 and j == 15) or (i == 2 and j == 13)) {
                    tablica[i][j] = 2;
                }
                else if ((i == 15 and j == 0) or (i == 13 and j == 2)) {
                    tablica[i][j] = 3;
                }
                else if ((i == 15 and j == 15) or (i == 13 and j == 13)) {
                    tablica[i][j] = 4;
                }
                else if ((j == 0 and i > 0 and i <= 14) or (j == 15 and i > 0 and i <= 14) or
                    (i > 2 and i <= 12 and j == 2) or (i > 2 and i <= 12 and j == 13)) {
                    tablica[i][j] = 5;
                }
                else if ((i == 0 and j > 1 and j <= 14) or (i == 15 and j > 1 and j <= 14) or
                    (i == 2 and j > 2 and j <= 12) or (i == 13 and j > 2 and j <= 12)) {
                    tablica[i][j] = 6;
                }
                else if (i > 2 and i <= 12 and j > 2 and j <= 12) {
                    tablica[i][j] = 7;
                }
                else {
                    tablica[i][j] = 8;
                }
            }
        }
        return tablica;
    }
};

void menu(gra& gra, int** plansza);


void inicjalizujOddzialywanie(gra& gra) {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            gra.oddzialywanie[i][j] = 0;
        }
    }
}

void inicjalizujOznaczenia(gra& gra) {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            gra.oznaczenia[i][j] = false;
        }
    }
}

void piszRozwiazanie(gra& gra, int** plansza) {
    system("cls");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (plansza[i][j] == 1) {
                cout << setw(3) << char(218);
            }
            else if (plansza[i][j] == 2) {
                cout << setw(3) << char(191);
            }
            else if (plansza[i][j] == 3) {
                cout << setw(3) << char(192);
            }
            else if (plansza[i][j] == 4) {
                cout << setw(3) << char(217);
            }
            else if (plansza[i][j] == 5) {
                cout << setw(3) << '|';
            }
            else if (plansza[i][j] == 6) {
                cout << setw(3) << '-';
            }
            else if (plansza[i][j] == 7) {
                cout << setw(3) << '*';
            }
            else if (plansza[i][j] == 9) {
                cout << setw(3) << 'O';
            }
            else if (plansza[i][j] == 13) {
                cout << setw(3) << 'O';
            }
            else if (plansza[i][j] == 14) {
                cout << setw(3) << 'X';
            }
            else {
                cout << setw(3) << ' ';
            }
        }
        cout << endl;
    }
}

void piszPlansze(gra& gra, int** plansza, int atomy) {
    system("cls");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (gra.oznaczenia[i][j]) {
                cout << setw(3) << 'o';
            }
            else if (plansza[i][j] == 1) {
                cout << setw(3) << char(218);
            }
            else if (plansza[i][j] == 2) {
                cout << setw(3) << char(191);
            }
            else if (plansza[i][j] == 3) {
                cout << setw(3) << char(192);
            }
            else if (plansza[i][j] == 4) {
                cout << setw(3) << char(217);
            }
            else if (plansza[i][j] == 5) {
                cout << setw(3) << '|';
            }
            else if (plansza[i][j] == 6) {
                cout << setw(3) << '-';
            }
            else if (plansza[i][j] == 7) {

                cout << setw(3) << '*';

            }
            else if (plansza[i][j] == 9) {
                cout << setw(3) << '*';
            }
            else if (plansza[i][j] == 10) {
                cout << setw(3) << 'x';
            }
            else if (plansza[i][j] == 11) {
                cout << setw(3) << 'H';
            }
            else if (plansza[i][j] == 12) {
                cout << setw(3) << 'R';
            }
            else if (plansza[i][j] == -1) {
                cout << setw(3) << char(254);
            }
            else {
                cout << setw(3) << ' ';
            }
        }
        cout << endl;
    } cout << "\nUkrytych atomow: " << atomy << endl;
}


// 1 - atom, 2 - naroznik, 3 - krawedz
void oznaczAtom(gra& gra, int** plansza) {

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (plansza[i][j] == 9) {
                gra.oddzialywanie[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (gra.oddzialywanie[i][j] == 1) {
                if (gra.oddzialywanie[i - 1][j - 1] == 0) {
                    gra.oddzialywanie[i - 1][j - 1] = 2;
                };
                if (gra.oddzialywanie[i - 1][j + 1] == 0) {
                    gra.oddzialywanie[i - 1][j + 1] = 2;
                };
                if (gra.oddzialywanie[i + 1][j + 1] == 0) {
                    gra.oddzialywanie[i + 1][j + 1] = 2;
                };
                if (gra.oddzialywanie[i + 1][j - 1] == 0) {
                    gra.oddzialywanie[i + 1][j - 1] = 2;
                };
                if (gra.oddzialywanie[i][j + 1] == 0) {
                    gra.oddzialywanie[i][j + 1] = 3;
                };
                if (gra.oddzialywanie[i][j - 1] == 0) {
                    gra.oddzialywanie[i][j - 1] = 3;
                };
                if (gra.oddzialywanie[i + 1][j] == 0) {
                    gra.oddzialywanie[i + 1][j] = 3;
                };
                if (gra.oddzialywanie[i - 1][j] == 0) {
                    gra.oddzialywanie[i - 1][j] = 3;
                };
            }
        }
    }

}

void losujAtom(gra& gra, int** plansza, int atomy) {
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (plansza[i][j] == 9)plansza[i][j] = 7;
        }
    }
    int zamiany = 0;
    while (zamiany < atomy) {
        int i = rand() % 16;
        int j = rand() % 16;
        if (plansza[i][j] == 7) {
            plansza[i][j] = 9;
            zamiany++;
        }
    }
}

void odbijPromien(gra& gra, int& kierunekX, int& kierunekY, int& x, int& y) {
    if (kierunekY == 1) {
        if (gra.oddzialywanie[y][x + 1] == 3) {
            kierunekX = -1;
            kierunekY = 0;
        }
        else {
            kierunekX = 1;
            kierunekY = 0;
        }
    }
    else if (kierunekY == -1) {
        if (gra.oddzialywanie[y][x + 1] == 3) {
            kierunekX = -1;
            kierunekY = 0;
        }
        else {
            kierunekX = 1;
            kierunekY = 0;
        }
    }
    else if (kierunekX == -1) {
        if (gra.oddzialywanie[y + 1][x] == 3) {
            kierunekX = 0;
            kierunekY = -1;
        }
        else {
            kierunekX = 0;
            kierunekY = 1;
        }
    }
    else if (kierunekX == 1) {
        if (gra.oddzialywanie[y + 1][x] == 3) {
            kierunekX = 0;
            kierunekY = -1;
        }
        else {
            kierunekX = 0;
            kierunekY = 1;
        }
    }
}

void wystrzelPromien(gra& gra, int** plansza) {
    char kierunek;
    int kierunekX = 0, kierunekY = 0;

    cout << "Podaj kierunek strzalu: ";
    cin >> kierunek;

    if (kierunek == 'w' or kierunek == 'W') {
        kierunekY = -1;
        kierunekX = 0;
    }
    else if (kierunek == 's' or kierunek == 'S') {
        kierunekY = 1;
        kierunekX = 0;
    }
    else if (kierunek == 'a' or kierunek == 'A') {
        kierunekX = -1;
        kierunekY = 0;
    }
    else if (kierunek == 'd' or kierunek == 'D') {
        kierunekX = 1;
        kierunekY = 0;
    }

    int x = gra.gracz.x + kierunekX;
    int y = gra.gracz.y + kierunekY;

    // Dopóki promień nie opuści planszy
    while (x >= 0 && x < 16 && y >= 0 && y < 16) {
        // Jeśli trafi na element = 1, wypisz H na przedłużeniu toru lotu
        if (plansza[y][x] == 9) {
            if (kierunekX == 1) {
                plansza[y - kierunekY][15 - kierunekX] = 11;
                break;
            }
            else if (kierunekX == -1) {
                plansza[y - kierunekY][0 - kierunekX] = 11;
                break;
            }
            else if (kierunekY == 1) {
                plansza[15 - kierunekY][x - kierunekX] = 11;
                break;
            }
            else if (kierunekY == -1) {
                plansza[0 - kierunekY][x - kierunekX] = 11;
                break;
            }
        }

        // Jeśli trafi na element = 2, odbij promień
        if (gra.oddzialywanie[y][x] == 2) {
            odbijPromien(gra, kierunekX, kierunekY, x, y);
            if (kierunekX == 1) {
                plansza[y][15 - kierunekX] = 12;
                break;
            }
            else if (kierunekX == -1) {
                plansza[y][0 - kierunekX] = 12;
                break;
            }
            else if (kierunekY == 1) {
                plansza[15 - kierunekY][x] = 12;
                break;
            }
            else if (kierunekY == -1) {
                plansza[0 - kierunekY][x] = 12;
                break;
            }

        }
        x += kierunekX;
        y += kierunekY;
    }
}




void oznaczPole(gra& gra, int** plansza) {
    gra.oznaczenia[gra.gracz.y][gra.gracz.x] = !gra.oznaczenia[gra.gracz.y][gra.gracz.x];
}

void przesunAwatara(gra& gra, int** plansza, char kierunek, int atomy) {


    int poprzedniePole = gra.gracz.poprzedniSymbol;

    int noweX = gra.gracz.x;
    int noweY = gra.gracz.y;

    if ((kierunek == 'w' or kierunek == 'W') && gra.gracz.y > 0 && plansza[gra.gracz.y - 1][gra.gracz.x] != -1) {
        noweY--;

    }
    else if ((kierunek == 's' or kierunek == 'S') && gra.gracz.y < 15 && plansza[gra.gracz.y + 1][gra.gracz.x] != -1) {
        noweY++;

    }
    else if ((kierunek == 'a' or kierunek == 'A') && gra.gracz.x > 0 && plansza[gra.gracz.y][gra.gracz.x - 1] != -1) {
        noweX--;

    }
    else if ((kierunek == 'd' or kierunek == 'D') && gra.gracz.x < 15 && plansza[gra.gracz.y][gra.gracz.x + 1] != -1) {
        noweX++;

    }

    plansza[gra.gracz.y][gra.gracz.x] = poprzedniePole;
    gra.gracz.x = noweX;
    gra.gracz.y = noweY;
    gra.gracz.poprzedniSymbol = plansza[gra.gracz.y][gra.gracz.x];
    plansza[gra.gracz.y][gra.gracz.x] = -1;
    piszPlansze(gra, plansza, atomy);
}


void start() {
    int wybor;
    cout << R"(
     ____    _                  _           ____                 
    | __ )  | |   __ _    ___  | | __      | __ )    ___   __  __
    |  _ \  | |  / _` |  / __| | |/ /      |  _ \   / _ \  \ \/ /
    | |_) | | | | (_| | | (__  |   <       | |_) | | (_) |  >  < 
    |____/  |_|  \__,_|  \___| |_|\_\      |____/   \___/  /_/\_\
                                                        
     
       _       _            _           
      /_\  _ _| |_ ___ _ _ (_)          
     / _ \| ' \  _/ _ \ ' \| |          
    /_/_\_\_||_\__\___/_||_|_|    _   _ 
    | _ \_  _ _ __  _____ __ ____| |_(_)
    |   / || | '  \/ _ \ V  V (_-< / / |
    |_|_\\_,_|_|_|_\___/\_/\_//__/_\_\_|
     _ ___ ____ __  ___ ____            
    / / _ \__ //  \( _ )__  |           
    | \_, /|_ \ () / _ \ / /            
    |_|/_/|___/\__/\___//_/             
                                     
   
     _                         _     _                           
    / |          ___ _____   _| |__ | | ____ _    __ _ _ __ __ _ 
    | |  _____  / __|_  / | | | '_ \| |/ / _` |  / _` | '__/ _` |
    | | |_____| \__ \/ /| |_| | |_) |   < (_| | | (_| | | | (_| |
    |_|         |___/___|\__, |_.__/|_|\_\__,_|  \__, |_|  \__,_|
                         |___/                   |___/                                                                                             
  
     _                                             _     _                              
    (_)_ __  _ __  _   _          __      ___   _ (_) __| |____  ____   __ _ _ __ _   _ 
    | | '_ \| '_ \| | | |  _____  \ \ /\ / / | | || |/ _` |_  / |_  /  / _` | '__| | | |
    | | | | | | | | |_| | |_____|  \ V  V /| |_| || | (_| |/ /   / /  | (_| | |  | |_| |
    |_|_| |_|_| |_|\__, |           \_/\_/  \__, |/ |\__,_/___| /___|  \__, |_|   \__, |
                   |___/                    |___/__/                   |___/      |___/ 
)";

    cin >> wybor;
    if (wybor != 1)  exit(0);

}

void sprawdzWygrana(gra& gra, int** plansza) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (gra.oznaczenia[i][j] == true && plansza[i][j] == 9) {
                plansza[i][j] = 13;
                gra.wynik = gra.wynik + 1;
            }
            else if (gra.oznaczenia[i][j] == true && plansza[i][j] != 9)
            {
                plansza[i][j] = 14;
            }
        }
    }
}

void grajTrudny(gra& gra, int** plansza) {
    char ruch;
    gra.gracz.x = 1;
    gra.gracz.y = 1;
    gra.gracz.poprzedniSymbol = plansza[gra.gracz.y][gra.gracz.x];
    plansza[gra.gracz.y][gra.gracz.x] = -1;
    losujAtom(gra, plansza, gra.atomyTrudny);
    oznaczAtom(gra, plansza);
    do {
        piszPlansze(gra, plansza, gra.atomyTrudny);
        cin.get(ruch);
        if (ruch == 'w' or ruch == 'W' or ruch == 's' or ruch == 'S' or ruch == 'a' or ruch == 'A' or ruch == 'd' or ruch == 'D') {
            przesunAwatara(gra, plansza, ruch, gra.atomyTrudny);
        }
        else if (ruch == 'o' or ruch == 'O') {
            oznaczPole(gra, plansza);
            piszPlansze(gra, plansza, gra.atomyTrudny);
        }
        else if (ruch == ' ') {
            wystrzelPromien(gra, plansza);
        }
        else if (ruch == 'h' or ruch == 'H') {
            piszRozwiazanie(gra, plansza);
            Sleep(500);
        }
        else if (ruch == 'm' or ruch == 'M') {
            menu(gra, plansza);
        }
    } while (ruch != 'q' && ruch != 'Q' && ruch != 'k' && ruch != 'K' && ruch != 'p' && ruch != 'P' or gra.wynik == gra.atomyTrudny);
    if (ruch == 'k' or ruch == 'K') {
        sprawdzWygrana(gra, plansza);
        piszRozwiazanie(gra, plansza);
        {
            if (gra.wynik == gra.atomyTrudny) {
                cout << "\nGratulacje wygrales! Twoj wynik to: " << gra.wynik << "atomow" << endl;
                system("pause");
            }
            else {
                cout << "\nWynik to: " << gra.wynik << " punktow." << endl;
                system("pause");
            }
        }
    }
    else if (ruch == 'p' or ruch == 'P') {
        piszRozwiazanie(gra, plansza);
        system("pause");
    }
    else if (gra.wynik == gra.atomyTrudny) {
        piszRozwiazanie(gra, plansza);
        cout << "\nGratulacje wygrales! Twoj wynik to: " << gra.wynik << "atomow" << endl;
        system("pause");
    }
    else exit(0);
}

void grajSredni(gra& gra, int** plansza) {
    char ruch;
    gra.gracz.x = 1;
    gra.gracz.y = 1;
    gra.gracz.poprzedniSymbol = plansza[gra.gracz.y][gra.gracz.x];
    plansza[gra.gracz.y][gra.gracz.x] = -1;
    losujAtom(gra, plansza, gra.atomySredni);
    oznaczAtom(gra, plansza);

    do {
        piszPlansze(gra, plansza, gra.atomySredni);
        cin.get(ruch);
        if (ruch == 'w' or ruch == 'W' or ruch == 's' or ruch == 'S' or ruch == 'a' or ruch == 'A' or ruch == 'd' or ruch == 'D') {
            przesunAwatara(gra, plansza, ruch, gra.atomySredni);
        }
        else if (ruch == 'o' or ruch == 'O') {
            oznaczPole(gra, plansza);
            piszPlansze(gra, plansza, gra.atomySredni);
        }
        else if (ruch == ' ') {
            wystrzelPromien(gra, plansza);
        }
        else if (ruch == 'h' or ruch == 'H') {
            piszRozwiazanie(gra, plansza);
            Sleep(500);
        }
        else if (ruch == 'm' or ruch == 'M') {
            menu(gra, plansza);
        }
    } while (ruch != 'q' && ruch != 'Q' && ruch != 'k' && ruch != 'K' && ruch != 'p' && ruch != 'P' or gra.wynik == gra.atomySredni);
    if (ruch == 'k' or ruch == 'K') {
        sprawdzWygrana(gra, plansza);
        piszRozwiazanie(gra, plansza);
        {
            if (gra.wynik == gra.atomySredni) {
                cout << "\nGratulacje wygrales! Twoj wynik to: " << gra.wynik << "atomow" << endl;
                system("pause");
            }
            else {
                cout << "\nWynik to: " << gra.wynik << " punktow." << endl;
                system("pause");
            }
        }
    }
    else if (ruch == 'p' or ruch == 'P') {
        piszRozwiazanie(gra, plansza);
        system("pause");
    }
    else if (gra.wynik == gra.atomySredni) {
        piszRozwiazanie(gra, plansza);
        cout << "\nGratulacje wygrales! Twoj wynik to: " << gra.wynik << "atomow" << endl;
        system("pause");
    }
    else exit(0);
}

void graj(gra& gra, int** plansza) {
    char ruch;
    gra.gracz.x = 3;
    gra.gracz.y = 3;
    gra.gracz.poprzedniSymbol = plansza[gra.gracz.y][gra.gracz.x];
    plansza[gra.gracz.y][gra.gracz.x] = -1;
    losujAtom(gra, plansza, gra.atomy);
    oznaczAtom(gra, plansza);

    do {
        piszPlansze(gra, plansza, gra.atomy);
        cin.get(ruch);
        if (ruch == 'w' or ruch == 'W' or ruch == 's' or ruch == 'S' or ruch == 'a' or ruch == 'A' or ruch == 'd' or ruch == 'D') {
            przesunAwatara(gra, plansza, ruch, gra.atomy);
        }
        else if (ruch == 'o' or ruch == 'O') {
            oznaczPole(gra, plansza);
            piszPlansze(gra, plansza, gra.atomy);
        }
        else if (ruch == ' ') {
            wystrzelPromien(gra, plansza);
        }
        else if (ruch == 'h' or ruch == 'H') {
            piszRozwiazanie(gra, plansza);
            Sleep(500);
        }
        else if (ruch == 'm' or ruch == 'M') {
            menu(gra, plansza);
        }
    } while (ruch != 'q' && ruch != 'Q' && ruch != 'k' && ruch != 'K' && ruch != 'p' && ruch != 'P' or gra.wynik == gra.atomy);
    if (ruch == 'k' or ruch == 'K') {
        sprawdzWygrana(gra, plansza);
        piszRozwiazanie(gra, plansza);
        {
            if (gra.wynik == gra.atomy) {
                cout << "\nGratulacje wygrales! Twoj wynik to: " << gra.wynik << "atomow" << endl;
                system("pause");
            }
            else {
                cout << "\nWynik to: " << gra.wynik << " punktow." << endl;
                system("pause");
            }
        }
    }
    else if (ruch == 'p' or ruch == 'P') {
        piszRozwiazanie(gra, plansza);
        system("pause");
    }
    else if (gra.wynik == gra.atomy) {
        piszRozwiazanie(gra, plansza);
        cout << "\nGratulacje wygrales! Twoj wynik to: " << gra.wynik << "atomow" << endl;
        system("pause");
    }
    else exit(0);

}



int main() {
    start();

    gra gra;
    int** plansza = gra.generujTablice();
    inicjalizujOznaczenia(gra);
    inicjalizujOddzialywanie(gra);

    graj(gra, plansza);
    menu(gra, plansza);

    return 0;
}

void menu(gra& gra, int** plansza) {
    int wybor;
    system("cls");
    cout << "1. Nowa gra" << endl;
    cout << "2. Powrot" << endl;
    cout << "3. Wyjdz z gry" << endl;
    cout << "Podaj wybor: "; cin >> wybor;

    if (wybor == 1) {
        int trudnosc;
        cout << "\nWybierz poziom trudnosci: 1. Latwy, 2. Sredni, 3. Trudny" << endl;
        cin >> trudnosc;
        if (trudnosc == 1) {
            for (int i = 0; i < 16; ++i) {
                delete[] plansza[i];
                delete[] gra.oznaczenia[i];
                delete[] gra.oddzialywanie[i];
            }
            delete[] plansza;
            delete[] gra.oznaczenia;
            delete[] gra.oddzialywanie;
            gra.wynik = 0;
            int** plansza = gra.generujTablice();
            inicjalizujOznaczenia(gra);
            inicjalizujOddzialywanie(gra);
            losujAtom(gra, plansza, gra.atomy);
            graj(gra, plansza);

        }
        else if (trudnosc == 2) {
            for (int i = 0; i < 16; ++i) {
                delete[] plansza[i];
                delete[] gra.oznaczenia[i];
                delete[] gra.oddzialywanie[i];
            }
            delete[] plansza;
            delete[] gra.oznaczenia;
            delete[] gra.oddzialywanie;
            gra.wynik = 0;
            int** plansza = gra.generujSrednia();
            inicjalizujOznaczenia(gra);
            inicjalizujOddzialywanie(gra);
            grajSredni(gra, plansza);
        }
        else if (trudnosc == 3) {
            for (int i = 0; i < 16; ++i) {
                delete[] plansza[i];
                delete[] gra.oznaczenia[i];
                delete[] gra.oddzialywanie[i];
            }
            delete[] plansza;
            delete[] gra.oznaczenia;
            delete[] gra.oddzialywanie;
            gra.wynik = 0;
            int** plansza = gra.generujTrudna();
            inicjalizujOznaczenia(gra);
            inicjalizujOddzialywanie(gra);
            grajTrudny(gra, plansza);
        }
        else {
            return;
        }

    }
    else if (wybor == 2) {
        return;
    }
    else if (wybor == 3) {
        for (int i = 0; i < 16; ++i) {
            delete[] plansza[i];
            delete[] gra.oznaczenia[i];
            delete[] gra.oddzialywanie[i];
        }
        delete[] plansza;
        delete[] gra.oznaczenia;
        delete[] gra.oddzialywanie;
        exit(0);
    }
    else menu(gra, plansza);

}