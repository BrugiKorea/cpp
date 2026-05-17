#include "portLotniczy.h"

void portLotniczy::usun(size_t index) {
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
