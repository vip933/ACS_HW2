//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <stdio.h>
#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
Container::Container(int size) {
    cont = new Shape* [size];
    this->size = size;
    this->len = 0;
}

Container::~Container() {
    Clear();
    delete[] cont;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::InContainer(FILE *file) {
    while (!feof(file)) {
        if ((cont[len] = Shape::StaticInShape(file)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRndContainer(int size) {
    printf("%s", "Start of init of random figures\n");
    if (size > this->size) {
        size = this->size;
        printf("%s", "Your number was too big.\n");
    }
    while (len < size) {
        if ((cont[len] = Shape::StaticInRndShape()) != nullptr) {
            len++;
        }
    }
    printf("%s", "End of init of random figures\n");
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::OutContainer(FILE *file) {
    fprintf(file, "%s %d %s", "Container contains", len, "elements.\n");
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i);
        cont[i]->OutShape(file);
    }
}

//------------------------------------------------------------------------------
// Поиск среднего значение площадей поверхностей всех фигур
double Container::AverageMean() {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += cont[i]->Square();
    }
    return sum / len;
}

//------------------------------------------------------------------------------
// Перестановка элементов контейнера
void Container::RearrangeContainer(double average) {
    int size = len;
    Shape *cpy_array[size];
    int j = 0;
    // Перемещаем все ненужные элементы в начало
    for (int i = 0; i < size; i++) {
        if (cont[i]->Square() <= average) {
            cpy_array[j++] = cont[i];
        }
    }
    if (j == size || j == 0) {
        return;
    }
    // Перемещаем в конец все элементы, площадь которых больше среднего арифметического
    for (int i = 0; i < size; i++) {
        if (cont[i]->Square() > average) {
            cpy_array[j++] = cont[i];
        }
    }
    // Копируем полученный массив в исходный
    for (int i = 0; i < size; i++) {
        cont[i] = cpy_array[i];
    }
}