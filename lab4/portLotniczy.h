#include <iostream>
#include <cstdlib>
#include <locale>
#include <random>
#include <string>
#include <sstream>

size_t randomNumber(int min, int max);
extern std::string samolotki[10];

class portLotniczy {
private:
    size_t rozmiar;
    size_t id;
    class Samolot {
    private:
        friend class portLotniczy;
        std::string nazwa;
        int rokProdukcji;
    public:
        Samolot() = default;
        Samolot(std::string nazwa_, int rokProdukcji_)
            : nazwa(nazwa_), rokProdukcji(rokProdukcji_) {}
        std::string getNazwa() const {
            return nazwa;
        }
        int getRokProdukcji() const {
            return rokProdukcji;
        }
        void setNazwa(std::string nazwa_) {
            nazwa = nazwa_;
        }
        void setRokProdukcji(int rokProdukcji_) {
            rokProdukcji = rokProdukcji_;
        }

        ~Samolot() {}

    };
    Samolot** samoloty;
public:
    portLotniczy(size_t rozmiar_, size_t id_) : rozmiar(rozmiar_), id(id_), samoloty(new Samolot* [rozmiar]) {
        for (size_t i = 0; i < rozmiar; i++) {
            samoloty[i] = new Samolot();
        }
    }
    portLotniczy(const portLotniczy& other) : rozmiar(other.rozmiar), id(other.id), samoloty(new Samolot* [rozmiar]) {
        for (size_t i = 0; i < rozmiar; i++) {
            samoloty[i] = new Samolot(*(other.samoloty[i]));
        }
    }
    ~portLotniczy() {
        for (size_t i = 0; i < rozmiar; i++) {
            delete samoloty[i];
        }
        delete[] samoloty;
    }
    void usun(size_t index);
    void dodaj();
    void ini(Samolot* samolot);
    void stworz();
    void print();
    void print(const size_t rok);
    void ini();
    void wyswietlWybranySamolot(size_t index);


    size_t getRozmiar() const;
};




