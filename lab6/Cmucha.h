#pragma once
#include <string>
#include <iostream>
class Ogrod {
    std::string nazwa{ "Ogrod dla muszek" };
public:
    std::string get() const { return nazwa; }
};



class Cmucha {
private:
    size_t iq;
    std::string imie;
    std::string nazwisko;
    static Ogrod ogrod;
    
public:
    Cmucha() = default;
    Cmucha(size_t iq_, std::string imie_, std::string nazwisko_)
        : iq(iq_), imie(imie_), nazwisko(nazwisko_) {}

    virtual void print() const {
        std::cout << "IQ: " << getIq() << "\n";
        std::cout << "Imie: " << getImie() << "\n";
        std::cout << "Nazwisko: " << getNazwisko() << "\n";
    }

    static Ogrod& getOgrod() {
        return ogrod;
    }

    size_t getIq() const {
        return iq;
    }
    std::string getImie() const {
        return imie;
    }
    std::string getNazwisko() const {
        return nazwisko;
    }
   
    void setIq(size_t iq_) {
        iq = iq_;
    }
    void setImie(std::string imie_) {
        imie = imie_;
    }
    void setNazwisko(std::string nazwisko_) {
        nazwisko = nazwisko_;
    }

    ~Cmucha() {

    }

};




class Pajeczak : public Cmucha {
private:
    std::string gatunek;
public:
    Pajeczak() = default;
    Pajeczak(size_t iq_, std::string imie_, std::string nazwisko_, std::string gatunek_)
        : Cmucha(iq_, imie_, nazwisko_), gatunek(gatunek_) {}

    std::string getGatunek() const {
        return gatunek;
    }

    void setGatunek(std::string gatunek_) {
        gatunek = gatunek_;
    }

    virtual void print() const override {
        Cmucha::print();
        std::cout << "Gatunek: " << gatunek << std::endl;
    }

    ~Pajeczak() {}
};



class Mucholapka : public Cmucha  {
private:
    size_t rozmiar;
public:
    Mucholapka(size_t iq_, std::string imie_, std::string nazwisko_, size_t rozmiar_)
        : Cmucha(iq_, imie_, nazwisko_), rozmiar(rozmiar_) {}

    size_t getRozmiar() const {
        return rozmiar;
    }

    void setRozmiar(size_t rozmiar_) {
        rozmiar = rozmiar_;
    }
    virtual void print() const override final {
        Cmucha::print();
        std::cout << "Rozmiar: " << rozmiar << std::endl;
    }
    ~Mucholapka() {

    }
};
