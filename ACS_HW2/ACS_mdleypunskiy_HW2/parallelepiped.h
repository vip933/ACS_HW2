#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда
//------------------------------------------------------------------------------

#include <stdio.h>
#include "shape.h"
#include "rnd.h"


//------------------------------------------------------------------------------
// параллелепипед
class Parallelepiped: public Shape {
private:
    int edge_a, edge_b, edge_c;
public:
    virtual ~Parallelepiped() {};

    // Ввод параметров треугольника из файла
    virtual void InShape(FILE *file);

    // Случайный ввод параметров параллелепипеда
    virtual void InRndShape();

    // Вывод параметров параллелепипеда в файловый поток
    virtual void OutShape(FILE *file);

    // Получение площади поверхности параллелепипеда
    double Square();
};

struct parallelepiped {
    // ребра
    int edge_a, edge_b, edge_c;
    double density;
};

#endif