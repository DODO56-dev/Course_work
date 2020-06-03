#pragma once
#include "CVisitor.h"
#include<iostream>
#include <string>
#include<fstream>
#include"Log.h"
using namespace std;
class CInhabitant
{
private:
	string Name;
	int Gender;
	int RoomAdress;
	int Key;
public:
	CInhabitant();
	CInhabitant(CVisitor& V);
	void SendAplication();

	int GetRoomAdress();
	int GetKey();

	int GetGender();
	string GetName();

	void SetRoomAdress(int RoomAdress);
	void SetKey(int Key);
};