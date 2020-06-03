#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include "CRoom.h"
using namespace std;

void PartClean(char part[]);

class CHostel
{
private:
	static const int AmountOfRooms = 20;
	CRoom Rooms[AmountOfRooms];
public:
	CHostel();
	~CHostel();

	int GetAmountOfRooms();

	CRoom GetRoom(int i);

	void PrintRoom(int i);
	void PrintAllRooms();
	void PringRoomsForGen(int Gender, int ver[]);
};