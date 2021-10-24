#include "tetrahedron.h"

//------------------------------------------------------------------------------
// Ввод параметров тетраэдра из файла
void Tetrahedron::InShape(FILE *file) {
    fscanf(file, "%d", &edge);
    fscanf(file, "%lf", &density);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров тетраэдра
void Tetrahedron::InRndShape() {
    edge = Shape::rnd250.Get();
    density = Random::GetDensity();
}

//------------------------------------------------------------------------------
// Вывод параметров тетраэдра в файловый поток
void Tetrahedron::OutShape(FILE *file) {
    fprintf(file, "It's a tetrahedron: edge = %d, density = %.2f surface square = %.2f\n",
            edge,
            density,
            Square()
    );
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности тетраэдра
double Tetrahedron::Square() {
    return edge * edge * SQUARE_ROOT_OF_3;
}