#include "ball.h"

//------------------------------------------------------------------------------
// Ввод параметров шара из файла
void Ball::InShape(FILE *file) {
    fscanf(file, "%d", &radius);
    fscanf(file, "%lf", &density);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров шара
// Проверки не нужны, тк подходит любой радиус, >= 1
void Ball::InRndShape() {
    radius = Shape::rnd250.Get();
    density = Random::GetDensity();
}

//------------------------------------------------------------------------------
// Вывод параметров шара в файловый поток
void Ball::OutShape(FILE *file) {
    fprintf(file, "It's a ball: raduis = %d, density = %.2f, surface area = %.2f\n",
            radius,
            density,
            Square()
            );
}

//------------------------------------------------------------------------------
// Получение площади поверхности шара
double Ball::Square() {
    return 4 * PI * radius * radius;
}
