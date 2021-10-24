//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "shape.h"
#include "tetrahedron.h"
#include "parallelepiped.h"
#include "ball.h"

Random Shape::rnd250(1, 250);
Random Shape::rnd3(1,3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Shape *Shape::StaticInShape(FILE *file) {
    int k;
    fscanf(file, "%d", &k);
    Shape *sp = nullptr;
    switch (k) {
        case 1:
            sp = new Ball;
            break;
        case 2:
            sp = new Parallelepiped;
            break;
        case 3:
            sp = new Tetrahedron;
            break;
    }
    sp->InShape(file);
    return sp;
}

//------------------------------------------------------------------------------
// Случайный генерация обобщенной фигуры
Shape *Shape::StaticInRndShape() {
    int random_figure_index = Shape::rnd3.Get();
    int random_figure = rand() % 3 + 1;
    Shape *sp = nullptr;
    switch (random_figure) {
        case 1:
            sp = new Ball;
            break;
        case 2:
            sp = new Parallelepiped;
            break;
        case 3:
            sp = new Tetrahedron;
            break;
    }
    sp->InRndShape();
    return sp;
}