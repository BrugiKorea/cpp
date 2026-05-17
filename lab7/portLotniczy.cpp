#include "portLotniczy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

void portLotniczy::pobierzDaneZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik) {
        std::cout << "B³¹d: Nie mo¿na otworzyæ pliku " << nazwaPliku << std::endl;
        return;
    }

    std::string linia;
    size_t indeks = 0;

    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);

        std::string nazwa;
        int rokProdukcji;

        if (iss >> nazwa >> rokProdukcji) {
            if (indeks < rozmiar) {
                samoloty[indeks]->setNazwa(nazwa);
                samoloty[indeks]->setRokProdukcji(rokProdukcji);
                indeks++;
            }
            else {
                break;
            }
        }
        else {
            std::cout << "B³¹d: Nieprawid³owy format danych w pliku" << std::endl;
            break;
        }
    }

    plik.close();
}

void portLotniczy::zapiszDoPliku(const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);
    if (!plik) {
        std::cout << "B³¹d: Nie mo¿na otworzyæ pliku " << nazwaPliku << std::endl;
        return;
    }

    plik << "<========== Samoloty ==========>" << std::endl;
    plik << "Nazwa: Rok produkcji" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        plik << samoloty[ind]->getNazwa() << " \t" << samoloty[ind]->getRokProdukcji() << std::endl;
    }
    plik.close();
}

void portLotniczy::usun(size_t index) {
    if (index < rozmiar) {
        delete samoloty[index];
        samoloty.erase(samoloty.begin() + index);
        --rozmiar;
    }
    else {
        std::cout << "ERROR: Index jest nieprawid³owy!" << std::endl;
    }
}

void portLotniczy::dodaj() {
    Samolot* samolot = new Samolot();
    ini(samolot);
    samoloty.push_back(samolot);
    ++rozmiar;
}

void portLotniczy::ini(Samolot* samolot) {
    *samolot = Samolot(samolotki[randomNumber(0, 9)], randomNumber(1970, 2002));
}

void portLotniczy::stworz() {
    for (size_t ind = 0; ind < rozmiar; ind++) {
        samoloty[ind] = new Samolot();
    }
}

void portLotniczy::print() {
    std::cout << "<========== Samoloty ==========>" << std::endl;
    std::cout << "Nazwa: Rok produkcji" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        std::cout << samoloty[ind]->getNazwa() << " \t" << samoloty[ind]->getRokProdukcji() << std::endl;
    }
}

void portLotniczy::print(const size_t rok) {
    std::cout << "<========== Samoloty ==========>" << std::endl;
    std::cout << "Nazwa: Rok produkcji" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        if (samoloty[ind]->getRokProdukcji() == rok) {
            std::cout << samoloty[ind]->getNazwa() << " \t" << samoloty[ind]->getRokProdukcji() << std::endl;
        }
    }
}

void portLotniczy::ini() {
    for (size_t ind = 0; ind < rozmiar; ind++) {
        size_t number = randomNumber(1970, 2000);
        samoloty[ind]->setRokProdukcji(number);
        samoloty[ind]->setNazwa(samolotki[randomNumber(0, 9)]);
    }
}

void portLotniczy::wyswietlWybranySamolot(size_t index) {
    if (index < rozmiar) {
        std::cout << samoloty[index]->getNazwa() << " \t" << samoloty[index]->getRokProdukcji() << std::endl;
    }
    else {
        std::cout << "ERROR: Index jest nieprawid³owy!" << std::endl;
    }
}

size_t portLotniczy::getRozmiar() const {
    return rozmiar;
}