#pragma once
#include <iostream>
#include <fstream> // для работы с файлами

class Reservoir
{
public:
	Reservoir(); // конструктор по умолчанию
	explicit Reservoir(char* name, short int name_length, double length, double width, double depth, short int type); // конструктор с параметрами
	explicit Reservoir(const Reservoir& r); // копирующий конструктор
	~Reservoir();

private:
	short int name_length = 15;
	char* name = nullptr;

	long float length = 0; // длина
	long float width = 0; // ширина
	long float depth = 0; // глубина

	short int type = 0; // тип 0 - бассейн, 1 - пруд, озеро, 2 - море, океан

	long float volume = 0;
	long float area = 0;
	//long float volume = length * width * depth;
	//long float area = length * width;

public:
	// SET
	void set_name(char* name, short int name_length);

	void set_length(long float length); 
	void set_width(long float width);
	void set_depth(long float depth);

	void set_type(short int type);

	// GET
	void get_name() const;

	float get_length() const;
	float get_width() const;
	float get_depth() const;

	int get_type() const;

	float get_volume();
	float get_area();


	// 
	bool is_type_equal(const Reservoir& r) const;
	void area_compare(const Reservoir& r) const;
};

