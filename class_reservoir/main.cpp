#include <iostream>
#include "reservoir.h"

enum reservoir_type { POOL, POND, SEA }; // тип водоёма

int main()
{
    setlocale(LC_ALL, "rus");

// БАССЕЙН
    const short int name_length_1 = 5;
    char* name_1 = new char[name_length_1] {'P', 'o', 'o', 'l', '\0'};

    long float length_1 = 15.5; // длина
    long float width_1 = 30; // ширина
    long float depth_1 = 4.5; // глубина

    short int type_1 = POOL;

// ПРУД
    const short int name_length_2 = 5;
    char* name_2 = new char[name_length_2] {'P', 'o', 'n', 'd', '\0'};

    long float length_2 = 673.113; // длина
    long float width_2 = 165.52; // ширина
    long float depth_2 = 60.8; // глубина

    short int type_2 = POND;
    // short int type_2 = POOL; // это для сравнения водоёмов, которое ниже


// МОРЕ
    const short int name_length_3 = 4;
    char* name_3 = new char[name_length_3] {'S', 'e', 'a', '\0'};

    long float length_3 = 60292.195; // длина
    long float width_3 = 93453.35; // ширина
    long float depth_3 = 1545.963; // глубина

    short int type_3 = SEA;

// ДИНАМИЧЕСКИЙ МАССИВ ИЗ ОБЪЕКТОВ КЛАССА
    Reservoir* reservoir = new Reservoir[3];

// КОНСТРУКТОР С ПАРАМЕТРАМИ
    reservoir[0] = Reservoir{ name_1, name_length_1, length_1, width_1, depth_1, type_1 };
    reservoir[1] = Reservoir{ name_2, name_length_2, length_2, width_2, depth_2, type_2 };
    reservoir[2] = Reservoir{ name_3, name_length_3, length_3, width_3, depth_3, type_3 };
    // или я дурак, или лыжи не едут, но у меня выводится вместо имени водоёма (name_1, name_2, name_3) всякий рандомным мусор,
    // он выводится только при вызове конструктора с параметрами (который чуть выше).
    // я не знаю как это пофиксить, нашёл один, тупой вариант:
    // если вызвать функции set_name после этого конструктора, то всё имена нормально выводятся:
    reservoir[0].set_name(name_1, name_length_1);
    reservoir[1].set_name(name_2, name_length_2);
    reservoir[2].set_name(name_3, name_length_3);
    // при этом, если я в этом конструкторе вызову функцию get_name(), то она выводит имена в нём нормально


// КОНСТРУКТОР КОПИРОВАНИЯ
   // reservoir[0] = reservoir[2];


// ВЫВОД МАССИВА
    std::cout << "Имя" << "\t\t" << "Длина" << "\t\t" << "Ширина" << "\t\t" << "Глубина" << "\t\t" << "Тип" << "\t\t" << "Объём" << "\t\t" << "Площадь" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        reservoir[i].get_name();
        std::cout << "\t\t" << reservoir[i].get_length() << "\t\t" << reservoir[i].get_width() << "\t\t" << reservoir[i].get_depth() << "\t\t" << reservoir[i].get_type() << "\t\t" << reservoir[i].get_volume() << "\t\t" << reservoir[i].get_area() << std::endl;
    }


// СРАВНЕНИЕ ПЛОЩАДЕЙ И ОДИНАКОВОСТИ ТИПА ВОДОЁМА
    std::cout << std::endl << std::endl;

    if (reservoir[0].is_type_equal(reservoir[1]) == 1)
    {
        reservoir[0].area_compare(reservoir[1]);
    }
    else
    {
        std::cout << "Водоёмы нельзя сравнить, у них разные типы!";
    }


// ЗАПИСЬ ОБЪЕКТА В ТЕКСТОВЫЙ ФАЙЛ 
    reservoir[0].save_reservoir_to_file();
    reservoir[2].save_reservoir_to_file();

    // В БИНАРНЫЙ ФАЙЛ
    reservoir[1].save_reservoir_to_bitfile();
    reservoir[2].save_reservoir_to_bitfile();


    delete[] name_1;
    delete[] name_2;
    delete[] name_3;


    return 0;
}

