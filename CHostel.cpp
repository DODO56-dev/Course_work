#include "CHostel.h"

void PartClean(char part[])
{
	int i = 0;
	while (part[i] != 0) { part[i] = ' '; i++; }
}

CHostel::CHostel()
{
	ifstream RoomsIn;
	RoomsIn.open("Rooms.txt");

	if (!RoomsIn.is_open()) { cout << "Eror" << endl; }
	else
	{
		string str = " ";
		char part[8] = "       ";

		for (int i = 0; i < AmountOfRooms; i++)
		{
			getline(RoomsIn, str);
			part[0] = str[0];
			part[1] = str[1];
			Rooms[i].SetCount(atoi(part));
			PartClean(part);
			part[0] = str[3];
			Rooms[i].SetSize(atoi(part));
			PartClean(part);
			part[0] = str[5];
			Rooms[i].SetFreeSpace(atoi(part));
			PartClean(part);
			part[0] = str[7];
			Rooms[i].SetGender(atoi(part));
			str = " ";
			PartClean(part);
		}
	}
	RoomsIn.close();
}

CHostel::~CHostel()
{
	ofstream RoomsOut;
	RoomsOut.open("Rooms.txt");
	if (!RoomsOut.is_open()) { cout << "Eror" << endl; }
	else
	{

		char Out[14] = " ";
		for (int i = 0; i < GetAmountOfRooms(); i++)
		{
			sprintf_s(Out, 13, "%2d %d %d ", Rooms[i].GetCount(), Rooms[i].GetSize(), Rooms[i].GetFreeSpace());
			char str[2] = " ";
			sprintf_s(str, 2, "%d", Rooms[i].GetGender());
			strcat_s(Out, str);
			RoomsOut << Out << endl;
		}

	}
	RoomsOut.close();
}

int CHostel::GetAmountOfRooms() { return AmountOfRooms; }

CRoom CHostel::GetRoom(int i) { return Rooms[i]; }

void CHostel::PrintRoom(int i)
{
	printf("Number | Size  |Free |Gender of\n");
	printf("of room|of room|space|inhabitants\n");
	printf("%7d|%7d|%5d|", Rooms[i].GetCount(), Rooms[i].GetSize(), Rooms[i].GetFreeSpace());
	if (Rooms[i].GetGender() == 0) { cout << "None" << endl; }
	if (Rooms[i].GetGender() == 1) { cout << "Male" << endl; }
	if (Rooms[i].GetGender() == 2) { cout << "Female" << endl; }
}

void CHostel::PrintAllRooms()
{
	printf("Number | Size  |Free |Gender of\n");
	printf("of room|of room|space|inhabitants\n");
	for (int i = 0; i < GetAmountOfRooms(); i++)
	{
		printf("%7d|%7d|%5d|", Rooms[i].GetCount(), Rooms[i].GetSize(), Rooms[i].GetFreeSpace());
		if (Rooms[i].GetGender() == 0) { cout << "None" << endl; }
		if (Rooms[i].GetGender() == 1) { cout << "Male" << endl; }
		if (Rooms[i].GetGender() == 2) { cout << "Female" << endl; }
	}

}
void CHostel::PringRoomsForGen(int Gender, int ver[])
{
	printf("Number | Size  |Free |Gender of\n");
	printf("of room|of room|space|inhabitants\n");
	for (int i = 0; i < GetAmountOfRooms(); i++)
	{
		if ((Rooms[i].GetGender() == Gender || Rooms[i].GetGender() == 0) && Rooms[i].GetFreeSpace() > 0)
		{
			ver[i] = 1;
			printf("%7d|%7d|%5d|", Rooms[i].GetCount(), Rooms[i].GetSize(), Rooms[i].GetFreeSpace());
			if (Rooms[i].GetGender() == 0) { cout << "None" << endl; }
			if (Rooms[i].GetGender() == 1) { cout << "Male" << endl; }
			if (Rooms[i].GetGender() == 2) { cout << "Female" << endl; }
		}
	}
}
