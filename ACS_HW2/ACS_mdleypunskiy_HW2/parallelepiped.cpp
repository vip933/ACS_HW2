#include "parallelepiped.h"

//------------------------------------------------------------------------------
// Ввод параметров параллелепипеда из файла
void Parallelepiped::InShape(FILE *file) {
    fscanf(file, "%d", &edge_a);
    fscanf(file, "%d", &edge_b);
    fscanf(file, "%d", &edge_c);
    fscanf(file, "%lf", &density);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров параллелепипеда
// Проверки не нужны, тк любые 3 стороны задают параллелепипед.
void Parallelepiped::InRndShape() {
    edge_a = Shape::rnd250.Get();
    edge_b = Shape::rnd250.Get();
    edge_c = Shape::rnd250.Get();
    density = Random::GetDensity();
}

//------------------------------------------------------------------------------
// Вывод параметров параллелепипеда в файловый поток
void Parallelepiped::OutShape(FILE *file) {
    fprintf(file, "It's a parallelepiped: a = %d, b = %d, c = %d, density = %.2f, surface square = %.2f\n",
            edge_a,
            edge_b,
            edge_c,
            density,
            Square()
    );
}

//------------------------------------------------------------------------------
// Получение площади поверхности параллелепипеда
double Parallelepiped::Square() {
    return 2 * edge_a * edge_b +
           2 * edge_a * edge_c +
           2 * edge_b * edge_c;
}