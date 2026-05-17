#include <iostream>
#include <cstdlib>
#include <locale>
#include <random>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>

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
        friend std::ostream& operator<<(std::ostream& os, const Samolot& samolot) {
            os << std::setw(3) << std::right << samolot.nazwa << "   " << samolot.rokProdukcji;
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Samolot& samolot) {
            is >> samolot.nazwa >> samolot.rokProdukcji;
            return is;
        }

        ~Samolot() {}

    };
    std::vector<Samolot*> samoloty;
public:
    Samolot& operator[](int index) {
        if (index < rozmiar) {
            return *samoloty[index];
        }
        else {
            throw std::out_of_range("Indeks poza zakresem");
        }
    }
    portLotniczy& operator=(const portLotniczy& other) {
        if (this == &other) {
            return *this;
        }
        for (size_t i = 0; i < rozmiar; i++) {
            delete samoloty[i];
        }
        rozmiar = other.rozmiar;
        id = other.id;
        samoloty.clear();
        samoloty.reserve(rozmiar);
        for (size_t i = 0; i < rozmiar; i++) {
            samoloty.push_back(new Samolot(*(other.samoloty[i])));
        }

        return *this;
    }


    portLotniczy(size_t rozmiar_, size_t id_) : rozmiar(rozmiar_), id(id_) {
        samoloty.reserve(rozmiar);
        for (size_t i = 0; i < rozmiar; i++) {
            samoloty.push_back(new Samolot());
        }
    }
    portLotniczy(const portLotniczy& other) : rozmiar(other.rozmiar), id(other.id) {
        samoloty.reserve(rozmiar);
        for (size_t i = 0; i < rozmiar; i++) {
            samoloty.push_back(new Samolot(*(other.samoloty[i])));
        }
    }
    ~portLotniczy() {
        for (size_t i = 0; i < rozmiar; i++) {
            delete samoloty[i];
        }
    }
    void usun(size_t index);
    void dodaj();
    void ini(Samolot* samolot);
    void stworz();
    void print();
    void print(const size_t rok);
    void ini();
    void wyswietlWybranySamolot(size_t index);
    void pobierzDaneZPliku(const std::string& nazwaPliku);
    void zapiszDoPliku(const std::string& nazwaPliku);


    size_t getRozmiar() const;
};