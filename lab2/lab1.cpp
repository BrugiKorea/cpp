//lab1.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

import <iostream>;
import<cstdlib>;
import <locale>;
import <random>;
import <string>;
import  <sstream>;
#include "Cmucha.h";
#include "Samolot.h";
#include "portLotniczy.h";
size_t randomNumber(int min, int max);
void ini(Cmucha*);
void stworz(portLotniczy*&);
void ini(portLotniczy*, int rozmiar, Samolot**);
void print(portLotniczy);
void modify(Cmucha* const, const size_t);
void ini(Cmucha* const, const size_t);
void stworz(Cmucha*&, const size_t);
void print(Cmucha*, const size_t);
void ini(Samolot* const* const, const size_t);
void stworz(Samolot**&, const size_t);
void print(Samolot**, const size_t);
void print(Samolot**, const size_t, const size_t);
void ini(Samolot*);
void usun(Samolot**&, size_t&);
void usun(Cmucha*&, const size_t);

std::string imiona[10] = {
    "Andrzej",
    "Michal",
    "Kacper",
    "Kamil",
    "Jakub",
    "Jan",
    "Jacek",
    "Wojtek",
    "Borys",
    "Remek"
};
std::string nazwiska[10] = {
    "Sier¿ant",
    "Porucznik",
    "Major ",
    "Chor¹¿y",
    "Kapitan",
    "Kapral",
    "Plutonowy",
    "Szeregowy",
    "Genera³",
    "Pu³kownik"
};

std::string samolotki[10] = {
     "Tupolew ",
     "Kalinin ",
     "Antonow",
     "Moskalew",
     "Tairow",
     "Ijuszyn",
     "I³  ",
     "Jakowlew",
     "MiG",
     "Szachrow"
};


void usun(Samolot**& kartoteka, size_t& size, size_t index) {
    if (index < size) {
        Samolot** temp = new Samolot * [size - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = kartoteka[i];
            }
        delete[] kartoteka;
        kartoteka = temp;
        --size;
    }
    else
        std::cout << "ERROR: Index jest nieprawid³owy ! " << std::endl;

}

void stworz(portLotniczy*& port) {
    port = new portLotniczy;
}

void ini(portLotniczy* port, int rozmiar, Samolot** samoloty) {
    port->size = rozmiar;
    port->samoloty = samoloty;

}
void print(portLotniczy* port, int rozmiar) {
    std::cout << port->size << std::endl;
}

void usun(Samolot**& samoloty, size_t& rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++)
        delete samoloty[ind];
    delete[] samoloty;
    samoloty = nullptr;
    rozmiar = 0;
}
void usun(Cmucha*& muchy, const size_t rozmiar) {
    delete[] muchy;
    muchy = nullptr;
}

void usun(Cmucha*& kartoteka, size_t& size, size_t index) {
    if (index < size) {
        Cmucha* temp = new Cmucha[size - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = kartoteka[i];
            }
        delete[] kartoteka;
        kartoteka = temp;
        --size;
    }
    else
        std::cout << "ERROR: Index jest nieprawid³owy ! " << std::endl;

}

void dodaj(Samolot**& kartoteka, size_t& size1) {
    Samolot** temp = new Samolot * [size1 + 1];
    if (size1 == 0) {
        temp[size1] = new Samolot;

    }
    else {
        for (size_t i = 0; i < size1; ++i)
            temp[i] = kartoteka[i];
        temp[size1] = new Samolot;
        ini(temp[size1]);
        delete[] kartoteka;
    }
    kartoteka = temp;
    ++size1;
}

void usun(portLotniczy* port) {
    delete port;
}

void dodaj(Cmucha*& kartoteka, size_t& size2) {
    Cmucha* temp = new Cmucha[size2 + 1];


    for (size_t i = 0; i < size2; ++i) {
        temp[i] = kartoteka[i];
    }
    ini(&temp[size2]);
    delete[] kartoteka;
    kartoteka = temp;
    ++size2;
}


size_t randomNumber(int min, int max) {
    std::random_device rd;
    std::default_random_engine dfe(rd());
    std::uniform_int_distribution<int> tab(min, max);
    return tab(dfe);
}


int main()
{
    portLotniczy* port{ nullptr };
    stworz(port);
    size_t rozmiar = randomNumber(1, 20);
    size_t rozmiar2 = randomNumber(1, 20);
    setlocale(LC_CTYPE, "Polish");
    Samolot** samoloty;
    stworz(samoloty, rozmiar);
    Cmucha* muchy{ nullptr };
    int wybor;
    int wybor2;
    int number;
    int wyborUsuniecia;
    int rok;


    do {
        system("cls");
        std::puts("1. Stworz tablice much");
        std::puts("2. Zainicjalizuj  atrybuty much");
        std::puts("3. Pokaz dane much ");
        std::puts("4. Dodaj muche");
        std::puts("5. Usun muche");
        std::puts("6. Stworz tablice wskaznikow samolotow");
        std::puts("7. Zainicjalizuj  atrybuty samolotow");
        std::puts("8. Pokaz dane samolotow ");
        std::puts("9. Dodaj samolot");
        std::puts("10. Usun samolot");
        std::puts("11. Zmodyfikuj wybrana muche");
        std::puts("12. Pokaz samoloty danego roku");
        std::puts("13. Stworz port i pokaz ilosc samolot");
        std::puts("0. Wyjdz");
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;
        switch (wybor) {
        case 1:
            do {
                system("cls");
                stworz(muchy, rozmiar);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 2:
            do {
                system("cls");
                ini(muchy, rozmiar);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 3:
            do {
                system("cls");
                print(muchy, rozmiar);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 4:
            do {
                system("cls");
                dodaj(muchy, rozmiar);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 5:
            do {
                system("cls");
                std::cout << "Jak¹ muche chcesz usunac:  ";
                std::cin >> wyborUsuniecia;
                usun(muchy, rozmiar, wyborUsuniecia);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 6:
            do {
                system("cls");
                stworz(samoloty, rozmiar2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 7:
            do {
                system("cls");
                ini(samoloty, rozmiar2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 8:
            do {
                system("cls");
                print(samoloty, rozmiar2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 9:
            do {
                system("cls");
                dodaj(samoloty, rozmiar2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 10:
            do {
                system("cls");
                std::cout << "Jaki samolot chcesz usunac:  ";
                std::cin >> wyborUsuniecia;
                usun(samoloty, rozmiar2, wyborUsuniecia);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 11:
            do {
                std::cout << "Jaka muche chcesz zmodyfikowac?";
                std::cin >> wybor2;
                modify(muchy, wybor2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 12:
            do {
                system("cls");
                std::cout << "Z jakiego roku samolot chcesz wyswietlic? ";
                std::cin >> rok;
                print(samoloty, rozmiar2, rok);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 13:
            do {
                system("cls");
                stworz(port);
                ini(port, rozmiar2, samoloty);
                print(port, rozmiar2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 0:
            do {
                usun(port);
                usun(samoloty, rozmiar2);
                usun(muchy, rozmiar);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;


        }




    } while (wybor != 0);
}

void stworz(Cmucha*& mucha, const size_t rozmiar) {
    mucha = new Cmucha[rozmiar];
    std::puts("Muchy zostaly stworzone!");
}


void modify(Cmucha* const muchy, const size_t id) {
    std::string name;
    std::cout << "Podaj dane do modyfikacji muchy: ";
    std::getline(std::cin.ignore(), name);
    size_t start = 0, end = 0;
    int i = 0;
    while (end != std::string::npos) {
        end = name.find(';', start);
        std::string word = name.substr(start, end - start);

        switch (i) {
        case 0:
            muchy[id].imie = word;
            break;
        case 1:
            muchy[id].nazwisko = word;
            break;
        case 2:
            muchy[id].iq = std::stoi(word);
            break;
        }
        i++;
        start = end + 1;
    }
}

void ini(Cmucha* mucha) {


    mucha->iq = randomNumber(150, 300);
    mucha->nazwisko = nazwiska[randomNumber(0, 9)];
    mucha->imie = imiona[randomNumber(0, 9)];




}
void ini(Samolot* samolot) {

    size_t number;

    number = randomNumber(1970, 2000);
    samolot->rokProdukcji = number;
    samolot->nazwa = samolotki[randomNumber(0, 9)];

}



void ini(Cmucha* const muchy, const size_t rozmiar) {


    for (size_t ind = 0; ind < rozmiar; ind++) {

        muchy[ind].iq = randomNumber(150, 300);
        muchy[ind].nazwisko = nazwiska[randomNumber(0, 9)];
        muchy[ind].imie = imiona[randomNumber(0, 9)];
    }
    std::puts("Muchy zostaly zainicjalizowane!");
}
void print(Cmucha* muchy, const size_t rozmiar) {
    std::cout << "<========= Muchy =========>" << std::endl;
    std::cout << "iq      imie    nazwisko     " << std::endl;
    printf("\n");
    for (size_t ind = 0; ind < rozmiar; ind++) {
        std::cout << muchy[ind].iq << "\t" << muchy[ind].imie
            << "\t" << muchy[ind].nazwisko << "  \t" << std::endl;
    }
}



void stworz(Samolot**& samoloty, const size_t rozmiar) {
    samoloty = new Samolot * [rozmiar];
    for (size_t ind = 0; ind < rozmiar; ind++)
        samoloty[ind] = new Samolot;
}


void print(Samolot** samoloty, const size_t rozmiar) {
    std::cout << "<========== Samoloty ==========>" << std::endl;
    std::cout << "Nazwa:          Rok produkcji" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        std::cout << samoloty[ind]->nazwa << "    \t" << samoloty[ind]->rokProdukcji << "\t" << std::endl;
    }
}

void print(Samolot** samoloty, const size_t rozmiar, const size_t rok) {
    std::cout << "<========== Samoloty ==========>" << std::endl;
    std::cout << "Nazwa:          Rok produkcji" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        if (samoloty[ind]->rokProdukcji == rok) {
            std::cout << samoloty[ind]->nazwa << "    \t" << samoloty[ind]->rokProdukcji << "\t" << std::endl;
        }
    }

}

void ini(Samolot* const* const samoloty, const size_t rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++) {
        size_t number;
        number = randomNumber(1970, 2000);
        samoloty[ind]->rokProdukcji = number;
        samoloty[ind]->nazwa = samolotki[randomNumber(0, 9)];
    }
}








// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotycz¹ce rozpoczynania pracy:
//   1. U¿yj okna Eksploratora rozwi¹zañ, aby dodaæ pliki i zarz¹dzaæ nimi
//   2. U¿yj okna programu Team Explorer, aby nawi¹zaæ po³¹czenie z kontrol¹ Ÿród³a
//   3. U¿yj okna Dane wyjœciowe, aby sprawdziæ dane wyjœciowe kompilacji i inne komunikaty
//   4. U¿yj okna Lista b³êdów, aby zobaczyæ b³êdy
//   5. Wybierz pozycjê Projekt > Dodaj nowy element, aby utworzyæ nowe pliki kodu, lub wybierz pozycjê Projekt > Dodaj istniej¹cy element, aby dodaæ istniej¹ce pliku kodu do projektu
//   6. Aby w przysz³oœci ponownie otworzyæ ten projekt, przejdŸ do pozycji Plik > Otwórz > Projekt i wybierz plik sln
