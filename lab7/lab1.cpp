
#include <iostream>
import<cstdlib>;
import <locale>;
import <random>;
import <string>;
import  <sstream>;
#include "Cmucha.h";
#include "portLotniczy.h";
size_t randomNumber(int min, int max);
void ini(Cmucha*);
void stworz(portLotniczy*&);
void print(portLotniczy);
void modify(Cmucha* const, const size_t);
void ini(Cmucha* const, const size_t);
void stworz(Cmucha*&, const size_t);
void print(Cmucha*, const size_t);
//void ini(Samolot* const* const, const size_t);
//void stworz(Samolot**&, const size_t);
//void print(Samolot**, const size_t);
//void print(Samolot**, const size_t, const size_t);
//void ini(Samolot*);
//void usun(Samolot**&, size_t&);



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
     "Antonow ",
     "Moskalew",
     "Tairow  ",
     "Ijuszyn ",
     "I³      ",
     "Jakowlew",
     "MiG     ",
     "Szachrow"
};

std::string podMuchy[10] = {

};




void usun(Cmucha*& muchy, const size_t rozmiar) {
    for (size_t i = 0; i < rozmiar; i++) {
        muchy[i].~Cmucha();
    }
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


void dodaj(Cmucha*& kartoteka, size_t& size2) {
    Cmucha* temp = new Cmucha[size2 + 1]();


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

    size_t rozmiar = randomNumber(1, 16);
    size_t rozmiar2 = randomNumber(1, 16);
    portLotniczy p1(rozmiar2, randomNumber(1, 10000));
    portLotniczy p2(rozmiar2, randomNumber(1, 10000));
    setlocale(LC_CTYPE, "Polish");
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
        std::puts("13. Pokaz dany samolot z portu");
        std::puts("14. Pokaz ilosc samolotow w porcie");
        std::puts("15. Skopiuj port");
        std::puts("16. Pobierz dane do pliku");
        std::puts("17. U¿yj operatora []");
        std::puts("18. U¿yj operatora przypisania");
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
                p1.stworz();
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 7:
            do {
                system("cls");
                p1.ini();
                p1.zapiszDoPliku("samoloty2.txt");
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 8:
            do {
                system("cls");
                p1.print();
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 9:
            do {
                system("cls");
                p1.dodaj();
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
                p1.usun(wyborUsuniecia);
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
                p1.print(rok);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 13:
            do {
                system("cls");
                std::cout << "Jaki samolot chcesz wyswietlic?";
                std::cin >> wybor2;
                p1.wyswietlWybranySamolot(wybor2);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 14:
            do {
                system("cls");
                std::cout << p1.getRozmiar() << std::endl;
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 15:
            do {
                system("cls");
                portLotniczy p2(p1);
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 16:
            do {

                system("cls");
                p1.pobierzDaneZPliku("samoloty.txt");
                p1.print();

                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
        case 17:
            do {

                p1[0].setNazwa("Boeing 747");
                p1[0].setRokProdukcji(2000);
                std::cout << "Nazwa samolotu: " << p1[0].getNazwa() << std::endl;
                std::cout << "Rok produkcji: " << p1[0].getRokProdukcji() << std::endl;

                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;
            } while (wybor2 != 0);
            break;
        case 18:
            do {
                std::puts("zawartosc portu 2 przed przypisaniem");
                p2.print();
                p2 = p1;
                std::puts("zawartosc portu 2 po przypisaniu");
                p2.print();
                std::puts("0. EXIT");
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor2;

            } while (wybor2 != 0);
            break;
        case 0:
            do {
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
    mucha = new Cmucha[rozmiar]();
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
            muchy[id].setImie(word);
            break;
        case 1:
            muchy[id].setNazwisko(word);
            break;
        case 2:
            muchy[id].setIq(std::stoi(word));
            break;
        }
        i++;
        start = end + 1;
    }
}




void ini(Cmucha* mucha) {
    *mucha = Cmucha(randomNumber(150, 300), imiona[randomNumber(0, 9)], nazwiska[randomNumber(0, 9)]);
}
/*void ini(Samolot* samolot) {

    *samolot = Samolot(samolotki[randomNumber(0, 9)], randomNumber(1970, 2002));


}
*/




void ini(Cmucha* const muchy, const size_t rozmiar) {


    for (size_t ind = 0; ind < rozmiar; ind++) {
        muchy[ind].setIq(randomNumber(150, 300));
        muchy[ind].setNazwisko(nazwiska[randomNumber(0, 9)]);
        muchy[ind].setImie(imiona[randomNumber(0, 9)]);
    }
    std::puts("Muchy zostaly zainicjalizowane!");
}



void print(Cmucha* muchy, const size_t rozmiar) {
    std::cout << "<========= Muchy =========>" << std::endl;
    std::cout << "iq      imie    nazwisko     " << std::endl;
    printf("\n");
    for (size_t ind = 0; ind < rozmiar; ind++) {
        std::cout << muchy[ind].getIq() << "\t" << muchy[ind].getImie()
            << "\t" << muchy[ind].getNazwisko() << "  \t" << std::endl;
    }
}


