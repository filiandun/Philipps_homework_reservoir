#include "reservoir.h"

Reservoir::Reservoir() // конструктор по умолчанию
{
	this->name = new char[this->name_length];
}

Reservoir::Reservoir(char* name, short int name_length, double length, double width, double depth, short int type) // конструктор с параметрами
{
	this->name_length = name_length;
	this->name = new char[this->name_length];
	for (int i = 0; i < this->name_length; ++i)
	{
		this->name[i] = name[i];
	}

	// get_name();
	set_name(name, name_length);

	this->length = length;
	this->width = width;
	this->depth = depth;
	this->type = type;

	this->volume = this->length * this->width * this->depth; // нахождение объёма
	this->area = this->length * this->width; // нахождение площади
}

Reservoir::Reservoir(const Reservoir& r) // копирующий конструктор
{
	this->name_length = r.name_length;
	this->name = new char[this->name_length];
	for (int i = 0; i < r.name_length; ++i)
	{
		this->name[i] = r.name[i];
	}

	this->length = r.length;
	this->width = r.width;
	this->depth = r.depth;
	this->type = r.type;

	this->volume = volume;
	this->area = area;
}

Reservoir::~Reservoir() // деструктор
{
	delete[] this->name;
}

// SET
void Reservoir::set_name(char* name, short int name_length) // задание названия водоёма
{
	this->name_length = name_length;
	this->name = new char[this->name_length];
	for (int i = 0; i < this->name_length; ++i)
	{
		this->name[i] = name[i];
	}
}

void Reservoir::set_length(long float length) // задание длины водоёма
{
	this->length = length;
}

void Reservoir::set_width(long float width) // задание ширины
{
	this->width = width;
}

void Reservoir::set_depth(long float depth) // задание глубины
{
	this->depth = depth;
}

void Reservoir::set_type(short int type) // задание типа 
{
	this->type = type;
}

//// CALCULATE
//void Reservoir::calculate_volume()
//{
//	this->volume = this->length * this->width * this->depth;
//}
//
//void Reservoir::calculate_area()
//{
//	this->area = this->length * this->width;
//}


// GET
void Reservoir::get_name() const // получение названия водоёма
{
	for (int i = 0; i < this->name_length; ++i)
	{
		std::cout << this->name[i];
	}
}

float Reservoir::get_length() const // получение длины водоёма
{
	return this->length;
}

float Reservoir::get_width() const // получение ширины
{
	return this->width;
}

float Reservoir::get_depth() const // получение глубины
{
	return this->depth;
}

int Reservoir::get_type() const // получение типа
{
	return this->type;
}


float Reservoir::get_volume() const // получение объёма
{
	return this->volume;
}

float Reservoir::get_area() const // получение площади
{
	return this->area;
}


//
bool Reservoir::is_type_equal(const Reservoir& r) const // сравнение типов водоёмов
{
	if (this->type == r.type)
	{
		return 1;
	}
	return 0;
}

void Reservoir::area_compare(const Reservoir& r) const // сравнение площади водоёмов
{
	if (this->area > r.area)
	{
		std::cout << "Площадь водоёма "; this->get_name(); std::cout << " больше, чем площадь водоёма "; r.get_name();
	}
	else if (this->area < r.area)
	{
		std::cout << "Площадь водоёма "; r.get_name(); std::cout << " больше, чем площадь водоёма "; this->get_name();
	}
	else
	{
		std::cout << "Площадь водоёма "; r.get_name(); std::cout << " равна площади водоёма "; this->get_name();
	}
}


// ФАЙЛЫ
void Reservoir::save_reservoir_to_file() const // текстовый файл
{
	std::ofstream save_reservoir("file_with_reservoirs.txt", std::ios::out | std::ios::app); // ios::app - для добавления чего-то в конец файла (с сохранением старого)

	if (save_reservoir.is_open())
	{
		//for (int i = 0; i < this->name_length; i++) // запись в файл названия водоёма
		//{
		//	save_reservoir << this->name[i];
		//}
		save_reservoir.write(this->name, this->name_length); // запись в файл названия водоёма (встроенная функция .write)
		
		save_reservoir << "\t\t" << this->get_length() << "\t\t" << this->get_width() << "\t\t" << this->get_depth() << "\t\t" << this->get_type() << "\t\t" << this->get_volume() << "\t\t" << this->get_area() << std::endl; // запись всего остального
	}
	else
	{
		std::cerr << std::endl << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА" << std::endl;
	}

	save_reservoir.close(); // закрытие потока
}

void Reservoir::save_reservoir_to_bitfile() const // бинарный файл
{
	std::ofstream save_reservoir("bitfile_with_reservoirs.doc", std::ios::binary | std::ios::app); // ios::binary - для бинарных файлов

	if (save_reservoir.is_open())
	{
		//for (int i = 0; i < this->name_length; i++) // запись в файл названия водоёма
		//{
		//	save_reservoir << this->name[i];
		//}
		save_reservoir.write(this->name, this->name_length); // запись в файл названия водоёма (встроенная функция .write)

		save_reservoir << "\t\t" << this->get_length() << "\t\t" << this->get_width() << "\t\t" << this->get_depth() << "\t\t" << this->get_type() << "\t\t" << this->get_volume() << "\t\t" << this->get_area() << std::endl; // запись всего остального
	}
	else
	{
		std::cerr << std::endl << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА" << std::endl;
	}

	save_reservoir.close(); // закрытие потока
}