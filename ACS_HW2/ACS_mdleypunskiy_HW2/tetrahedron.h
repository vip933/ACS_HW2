#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра
//------------------------------------------------------------------------------

#include <stdio.h>
#include "shape.h"
#include "rnd.h"

//------------------------------------------------------------------------------
// тетраэдр

class Tetrahedron: public Shape {
private:
    int edge;
    const double SQUARE_ROOT_OF_3 = 1.73205;
public:
    virtual ~Tetrahedron() {};

    // Ввод параметров тетраэдра из файла
    virtual void InShape(FILE *file);

    // Случайный ввод параметров тетраэдра
    virtual void InRndShape();

    // Вывод параметров тетраэдра в форматируемый поток
    virtual void OutShape(FILE *file);

    // Вычисление площади поверхности тетраэдра
    virtual double Square();
};

#endif
