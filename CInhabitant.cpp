#include "CInhabitant.h"

CInhabitant::CInhabitant()
{
	Name = " ";
	Gender = 0;
	RoomAdress = 0;
	Key = 0;
}
CInhabitant::CInhabitant(CVisitor& V)
{
	Name = V.GetName();
	Gender = V.GetGender();
	RoomAdress = 0;
	Key = 0;
}
void CInhabitant::SendAplication()
{
	ofstream Apl;
	Apl.open("Alications.txt", ios::app);
	if (!Apl.is_open()) { cout << "Eror" << endl; }
	else
	{
		Apl << currentDateTime() << endl << "Name: " + Name << endl << "Gender: " << Gender << endl << "Room: " << RoomAdress << endl;
	}
	Apl.close();
}

int CInhabitant::GetRoomAdress() { return RoomAdress; }
int CInhabitant::GetKey() { return Key; }

int CInhabitant::GetGender() { return Gender; }
string CInhabitant::GetName() { return Name; }

void CInhabitant::SetRoomAdress(int RoomAdress) { this->RoomAdress = RoomAdress + 1; }
void CInhabitant::SetKey(int Key) { this->Key = Key; }