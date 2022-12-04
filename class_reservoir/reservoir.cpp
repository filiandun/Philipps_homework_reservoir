#include "reservoir.h"

Reservoir::Reservoir() // ����������� �� ���������
{
	this->name = new char[this->name_length];
}

Reservoir::Reservoir(char* name, short int name_length, double length, double width, double depth, short int type) // ����������� � �����������
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

	this->volume = this->length * this->width * this->depth; // ���������� ������
	this->area = this->length * this->width; // ���������� �������
}

Reservoir::Reservoir(const Reservoir& r) // ���������� �����������
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

Reservoir::~Reservoir() // ����������
{
	delete[] this->name;
}

// SET
void Reservoir::set_name(char* name, short int name_length) // ������� �������� ������
{
	this->name_length = name_length;
	this->name = new char[this->name_length];
	for (int i = 0; i < this->name_length; ++i)
	{
		this->name[i] = name[i];
	}
}

void Reservoir::set_length(long float length) // ������� ����� ������
{
	this->length = length;
}

void Reservoir::set_width(long float width) // ������� ������
{
	this->width = width;
}

void Reservoir::set_depth(long float depth) // ������� �������
{
	this->depth = depth;
}

void Reservoir::set_type(short int type) // ������� ���� 
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
void Reservoir::get_name() const // ��������� �������� ������
{
	for (int i = 0; i < this->name_length; ++i)
	{
		std::cout << this->name[i];
	}
}

float Reservoir::get_length() const // ��������� ����� ������
{
	return this->length;
}

float Reservoir::get_width() const // ��������� ������
{
	return this->width;
}

float Reservoir::get_depth() const // ��������� �������
{
	return this->depth;
}

int Reservoir::get_type() const // ��������� ����
{
	return this->type;
}


float Reservoir::get_volume() const // ��������� ������
{
	return this->volume;
}

float Reservoir::get_area() const // ��������� �������
{
	return this->area;
}


//
bool Reservoir::is_type_equal(const Reservoir& r) const // ��������� ����� �������
{
	if (this->type == r.type)
	{
		return 1;
	}
	return 0;
}

void Reservoir::area_compare(const Reservoir& r) const // ��������� ������� �������
{
	if (this->area > r.area)
	{
		std::cout << "������� ������ "; this->get_name(); std::cout << " ������, ��� ������� ������ "; r.get_name();
	}
	else if (this->area < r.area)
	{
		std::cout << "������� ������ "; r.get_name(); std::cout << " ������, ��� ������� ������ "; this->get_name();
	}
	else
	{
		std::cout << "������� ������ "; r.get_name(); std::cout << " ����� ������� ������ "; this->get_name();
	}
}


// �����
void Reservoir::save_reservoir_to_file() const // ��������� ����
{
	std::ofstream save_reservoir("file_with_reservoirs.txt", std::ios::out | std::ios::app); // ios::app - ��� ���������� ����-�� � ����� ����� (� ����������� �������)

	if (save_reservoir.is_open())
	{
		//for (int i = 0; i < this->name_length; i++) // ������ � ���� �������� ������
		//{
		//	save_reservoir << this->name[i];
		//}
		save_reservoir.write(this->name, this->name_length); // ������ � ���� �������� ������ (���������� ������� .write)
		
		save_reservoir << "\t\t" << this->get_length() << "\t\t" << this->get_width() << "\t\t" << this->get_depth() << "\t\t" << this->get_type() << "\t\t" << this->get_volume() << "\t\t" << this->get_area() << std::endl; // ������ ����� ����������
	}
	else
	{
		std::cerr << std::endl << "������ ��� �������� �����" << std::endl;
	}

	save_reservoir.close(); // �������� ������
}

void Reservoir::save_reservoir_to_bitfile() const // �������� ����
{
	std::ofstream save_reservoir("bitfile_with_reservoirs.doc", std::ios::binary | std::ios::app); // ios::binary - ��� �������� ������

	if (save_reservoir.is_open())
	{
		//for (int i = 0; i < this->name_length; i++) // ������ � ���� �������� ������
		//{
		//	save_reservoir << this->name[i];
		//}
		save_reservoir.write(this->name, this->name_length); // ������ � ���� �������� ������ (���������� ������� .write)

		save_reservoir << "\t\t" << this->get_length() << "\t\t" << this->get_width() << "\t\t" << this->get_depth() << "\t\t" << this->get_type() << "\t\t" << this->get_volume() << "\t\t" << this->get_area() << std::endl; // ������ ����� ����������
	}
	else
	{
		std::cerr << std::endl << "������ ��� �������� �����" << std::endl;
	}

	save_reservoir.close(); // �������� ������
}