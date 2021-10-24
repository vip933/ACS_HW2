#include <stdio.h> // Работа с файлами, консоль
#include <string.h> // Проверка равенства строк
#include <stdlib.h>
#include <time.h> // Замер времени работы программы + сид для рандома по текущему времени

#include "container.h"

void showErrorMessage(char* message) {
    printf("%s\n", message);
    printf("%s", "expected:\n");
    printf("%s", "    command -f inputFile outputFile\n");
    printf("%s", "or:\n");
    printf("%s", "    command -n number outputFile\n");
}

int main(int argc, char* argv[]) {
    int start = clock();
    if (argc != 5) {
        showErrorMessage("incorrect command line!");
        return 1;
    }
    bool is_file_input;
    int size = 10000;
    // Проверка выбранного флага
    if (!(strcmp(argv[1], "-f"))) {
        is_file_input = true;
    } else if (!(strcmp(argv[1], "-n"))) {
        is_file_input = false;
        size = atoi(argv[2]);
        // Проверка размера
        if ((size < 1) || (size > 10000)) {
            printf("%s", "incorrect number of figures\n");
            printf("%s", "correct number: 1 < number < 10000\n");
            return 3;
        }
    } else {
        showErrorMessage("incorrect flag!");
        return 2;
    }
    // Инициализация контейнера на основе динамического массива
    Container *container = new Container(size);
    FILE *p_file;
    // Заполнение контейнера из файла.
    if (is_file_input) {
        if ((p_file = fopen(argv[2], "r")) != nullptr) {
            container->InContainer(p_file);
            fclose(p_file);
        } else {
            printf("Cannot open file!\n");
            return 4;
        }
    // Заполнение контейнера рандомными фигурами.
    } else {
        srand((unsigned int) time(nullptr));
        container->InRndContainer(size);
    }
    // Вывод контейнера.
    p_file = fopen(argv[3], "w+");
    container->OutContainer(p_file);
    fclose(p_file);
    // вторая часть задания
    p_file = fopen(argv[4], "w+");
    // Поиск среднего арифметического площадей поверхностей всех фигур
    double average = container->AverageMean();
    fprintf(p_file, "Average mean of all surface squares of all shapes = %.2f\n", average);
    fprintf(p_file, "Rearranged container!\n");
    // Перестановка нужных элементов
    container->RearrangeContainer(average);
    container->OutContainer(p_file);
    fclose(p_file);
    // Замер времени работы программы
    int stop = clock() - start;
    // Вывод времени в милисекундах
    printf("Running time: %f ms\n", (float)stop/CLOCKS_PER_SEC * 1000);
    return 0;
}