#pragma once
#include <string>
#include <iostream>



class Cmucha {
private:
    size_t iq;
    std::string imie;
    std::string nazwisko;
public:
    Cmucha() = default;
    Cmucha(size_t iq_, std::string imie_, std::string nazwisko_)
        : iq(iq_), imie(imie_), nazwisko(nazwisko_) {}

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


