#include "reservoir.h"

Reservoir::Reservoir()
{
	this->name = new char[this->name_length];
}

Reservoir::Reservoir(char* name, short int name_length, double length, double width, double depth, short int type)
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
}

Reservoir::Reservoir(const Reservoir& r)
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

Reservoir::~Reservoir()
{
	delete[] this->name;
}

// SET
void Reservoir::set_name(char* name, short int name_length)
{
	this->name_length = name_length;
	this->name = new char[this->name_length];
	for (int i = 0; i < this->name_length; ++i)
	{
		this->name[i] = name[i];
	}
}

void Reservoir::set_length(long float length)
{
	this->length = length;
}

void Reservoir::set_width(long float width)
{
	this->width = width;
}

void Reservoir::set_depth(long float depth)
{
	this->depth = depth;
}

void Reservoir::set_type(short int type)
{
	this->type = type;
}


// GET
void Reservoir::get_name() const
{
	for (int i = 0; i < this->name_length; ++i)
	{
		std::cout << this->name[i];
	}
}

float Reservoir::get_length() const
{
	return this->length;
}

float Reservoir::get_width() const
{
	return this->width;
}

float Reservoir::get_depth() const
{
	return this->depth;
}

int Reservoir::get_type() const
{
	return this->type;
}

float Reservoir::get_volume()
{
	return this->volume = length * width * depth;

}

float Reservoir::get_area()
{
	return this->area = length * width;
}




bool Reservoir::is_type_equal(const Reservoir& r) const
{
	if (this->type == r.type)
	{
		return 1;
	}
	return 0;
}

void Reservoir::area_compare(const Reservoir& r) const
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