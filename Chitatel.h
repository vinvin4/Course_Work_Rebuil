#pragma once
#include <iostream>
#include <fstream>
#define N_name 50
#define N_phone 13

class Chitatel
{
private:
	char name[N_name]; 
	char phone[N_phone]; 
	unsigned int ID;
public:
	void show_self();
	unsigned int get_ID();
	Chitatel();
	Chitatel(unsigned int i);
	~Chitatel();
};

