#pragma once
#include <iostream>
#include <fstream> // ��� ������ � �������

class Reservoir
{
public:
	Reservoir(); // ����������� �� ���������
	explicit Reservoir(char* name, short int name_length, double length, double width, double depth, short int type); // ����������� � �����������
	explicit Reservoir(const Reservoir& r); // ���������� �����������
	~Reservoir();

private:
	short int name_length = 15; // ��������
	char* name = nullptr;

	long float length = 0; // �����
	long float width = 0; // ������
	long float depth = 0; // �������

	short int type = 0; // ��� 0 - �������, 1 - ����, �����, 2 - ����, �����

	long float volume = 0; // �����
	long float area = 0; // �������

public:
	// SET
	void set_name(char* name, short int name_length);

	void set_length(long float length); 
	void set_width(long float width);
	void set_depth(long float depth);

	void set_type(short int type);

	//// CALCULATE
	//void calculate_volume();
	//void calculate_area();

	// GET
	void get_name() const;

	float get_length() const;
	float get_width() const;
	float get_depth() const;

	int get_type() const;

	float get_volume() const;
	float get_area() const;

	// 
	bool is_type_equal(const Reservoir& r) const;
	void area_compare(const Reservoir& r) const;

	// �����
	void save_reservoir_to_file() const; // ��������� ����
	void save_reservoir_to_bitfile() const; // �������� ����
};

