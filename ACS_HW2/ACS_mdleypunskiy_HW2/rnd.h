#ifndef __rnd__
#define __rnd__

#include <stdlib.h>
#include <time.h>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация случайного числа в заданном диапазоне
    int Get() {
        return rand() % (last - first + 1) + first;
    }

    // Генерация случайной плотности
    static double GetDensity() {
        const double min = 0.1;
        const double max = 10;
        double f = (double)rand() / RAND_MAX;
        return min + f * (max - min);
    }
private:
    int first;
    int last;
};

#endif