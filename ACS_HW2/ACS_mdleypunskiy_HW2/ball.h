#ifndef __ball__
#define __ball__

//------------------------------------------------------------------------------
// ball.h - содержит описание шара
//------------------------------------------------------------------------------

#include <stdio.h>
#include "shape.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// Шар

class Ball : public Shape {
private:
    int radius;
    const double PI = 3.141592;
public:
    virtual ~Ball() {};

    // Ввод параметров шара из файла
    virtual void InShape(FILE *file);

    // Случайный ввод параметров шара
    virtual void InRndShape();

    // Вывод параметров шара в файловый поток
    virtual void OutShape(FILE *file);

    // Получение площади поверхности шара
    virtual double Square();
};

#endif