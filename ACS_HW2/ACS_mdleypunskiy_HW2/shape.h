#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <stdio.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
class Shape {
protected:
    static Random rnd250;
    static Random rnd3;
    double density;
public:
    virtual ~Shape() {};

    // Ввод обобщенной фигуры
    static Shape *StaticInShape(FILE *file);

    // Ввод обобщенной фигуры
    virtual void InShape(FILE *file) = 0;

    // Случайный ввод обобщенной фигуры
    static Shape *StaticInRndShape();

    // Виртуальный метод ввода случайной фигуры
    virtual void InRndShape() = 0;

    // Вывод обобщенной фигуры
    virtual void OutShape(FILE *file) = 0;

    // Вычисление площади поверхности обобщенной фигуры
    virtual double Square() = 0;
};

#endif
