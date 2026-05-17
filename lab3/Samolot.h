#pragma once
import<string>;

class Samolot {
private:
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
    ~Samolot() {

    }
};

