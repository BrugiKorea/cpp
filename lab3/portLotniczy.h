#include <iostream>
import<cstdlib>;
import <locale>;
import <random>;
import <string>;
import  <sstream>;
#include "Samolot.h";
size_t randomNumber(int min, int max);
extern std::string samolotki[10];



class portLotniczy
{
private:
	size_t rozmiar;
	Samolot** samoloty;
    size_t id_portu;

public:
	portLotniczy(size_t rozmiar_) : rozmiar(rozmiar_), samoloty(new Samolot* [rozmiar]) {}
    ~portLotniczy() {
        for (size_t i = 0; i < rozmiar; i++) {
            delete samoloty[i];
        }
        delete[] samoloty;
    }
    void usun(size_t index) {
        if (index < rozmiar) {
            Samolot** temp = new Samolot * [rozmiar - 1];
            short int j{ -1 };
            for (size_t i = 0; i < rozmiar; ++i)
                if (i != index) {
                    ++j;
                    temp[j] = samoloty[i];
                }
            delete[] samoloty;
            samoloty = temp;
            --rozmiar;
        }
        else
            std::cout << "ERROR: Index jest nieprawid³owy ! " << std::endl;

    }
    void dodaj() {
        Samolot** temp = new Samolot * [rozmiar + 1];
        if (rozmiar == 0) {
            temp[rozmiar] = new Samolot;

        }
        else {
            for (size_t i = 0; i < rozmiar; ++i)
                temp[i] = samoloty[i];
            temp[rozmiar] = new Samolot;
            ini(temp[rozmiar]);
            delete[] samoloty;
        }
        samoloty = temp;
        ++rozmiar;
    }
    void ini(Samolot* samolot) {

        *samolot = Samolot(samolotki[randomNumber(0, 9)], randomNumber(1970, 2002));


    }
    void stworz() {
        samoloty = new Samolot * [rozmiar];
        for (size_t ind = 0; ind < rozmiar; ind++)
            samoloty[ind] = new Samolot();
    }


    void print(){
        std::cout << "<========== Samoloty ==========>" << std::endl;
        std::cout << "Nazwa: Rok produkcji" << std::endl;
        for (size_t ind = 0; ind < rozmiar; ind++) {
            std::cout << samoloty[ind]->getNazwa() << " \t" << samoloty[ind]->getRokProdukcji() << "\t" << std::endl;
        }
    }

    void print(const size_t rok) {
        std::cout << "<========== Samoloty ==========>" << std::endl;
        std::cout << "Nazwa: Rok produkcji" << std::endl;
        for (size_t ind = 0; ind < rozmiar; ind++) {
            if (samoloty[ind]->getRokProdukcji() == rok) {
                std::cout << samoloty[ind]->getNazwa() << " \t" << samoloty[ind]->getRokProdukcji() << "\t" << std::endl;
            }
        }
    }

    void ini() {
        for (size_t ind = 0; ind < rozmiar; ind++) {
            size_t number;
            number = randomNumber(1970, 2000);
            samoloty[ind]->setRokProdukcji(number);
            samoloty[ind]->setNazwa(samolotki[randomNumber(0, 9)]);
        }
    }
    void wyswietlWybranySamolot(size_t index) {
        std::cout << samoloty[index]->getNazwa() << " \t" << samoloty[index]->getRokProdukcji() << "\t" << std::endl;
    }
    size_t getRozmiar() const {
        return rozmiar;
    }
};
