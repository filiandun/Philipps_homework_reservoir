#include <iostream>
#include "reservoir.h"

int main()
{
    setlocale(LC_ALL, "rus");

// БАССЕЙН
    const short int name_length_1 = 5;
    char* name_1 = new char[name_length_1] {'P', 'o', 'o', 'l', '\0'};

    long float length_1 = 15.5; // длина
    long float width_1 = 30; // ширина
    long float depth_1 = 4.5; // глубина

    short int type_1 = 0;

// ПРУД
    const short int name_length_2 = 5;
    char* name_2 = new char[name_length_2] {'P', 'o', 'n', 'd', '\0'};

    long float length_2 = 673.113; // длина
    long float width_2 = 165.52; // ширина
    long float depth_2 = 60.8; // глубина

    short int type_2 = 0;

// МОРЕ
    const short int name_length_3 = 4;
    char* name_3 = new char[name_length_3] {'S', 'e', 'a', '\0'};

    long float length_3 = 60292.195; // длина
    long float width_3 = 93453.35; // ширина
    long float depth_3 = 1545.963; // глубина

    short int type_3 = 2;


    Reservoir* reservoir = new Reservoir[3];

// КОНСТРУКТОР С ПАРАМЕТРАМИ
    reservoir[0] = Reservoir{ name_1, name_length_1, length_1, width_1, depth_1, type_1 };
    reservoir[1] = Reservoir{ name_2, name_length_2, length_2, width_2, depth_2, type_2 };
    reservoir[2] = Reservoir{ name_3, name_length_3, length_3, width_3, depth_3, type_3 };

// ВЫВОД МАССИВА
    std::cout << "Имя" << "\t\t" << "Длина" << "\t\t" << "Ширина" << "\t\t" << "Глубина" << "\t\t" << "Тип" << "\t\t" << "Объём" << "\t\t" << "Площадь" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        reservoir[i].get_name();
        std::cout << "\t\t" << reservoir[i].get_length() << "\t\t" << reservoir[i].get_width() << "\t\t" << reservoir[i].get_depth() << "\t\t" << reservoir[i].get_type() << "\t\t" << reservoir[i].get_volume() << "\t\t" << reservoir[i].get_area() << std::endl;
    }


// СРАВНЕНИЕ ПЛОЩАДЕЙ И ОДИНАКОВОСТИ ТИПА ВОДОЁМА
    std::cout << std::endl;

    if (reservoir[0].is_type_equal(reservoir[1]) == 1)
    {
        reservoir[0].area_compare(reservoir[1]);
    }
    else
    {
        std::cout << "Водоёмы нельзя сравнить, у них разные типы!";
    }

    delete[] name_1;
    delete[] name_2;
    delete[] name_3;

    return 0;


    /*
    1. Корректно вывод имени водоёма не работает, он что-то рандомное выводит
    2. Остальное работает.
    3. Нужно доделать по по заданию.
    */
}

