#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
#include "CRoom.h"
#include "CHostel.h"
#include "CVisitor.h"
#include "CInhabitant.h"
#include "CKey.h"
#include "Log.h"

string GetStr(int input)
{
	string output;
	char buf[64];
	sprintf_s(buf, 64, "%d", input);
	return output = buf;
}

int main() 
{
	Log L;
	CHostel H;
	CKey K;

	
	bool AlreadyGetRoom = false;

	L.PrintInLog("Program start");

	cout << "Hello, visitor!" << endl;
	CVisitor V;
	L.PrintInLog(V.GetName() + " enter");

	while(true)
	{
		cout << "1 - Exit" << endl << "2 - Show pass key" << endl << "3 - Rent the room" << endl;
		int var;
		while (true)
		{
			cin >> var;
			if (var == 1 || var == 2 || var == 3) { break; }
			else { cout << "1 - Exit" << endl << "2 - Show pass key" << endl << "3 - Rent the room" << endl; }
		}

		switch (var)
		{
		case 1:
		{
			L.PrintInLog("Program end");
			return 0;
		}
		case 2:
		{
			L.PrintInLog(V.GetName() + " try to enter key");
			cout << "Enter your pass key" << endl;
			bool IsInhab = 0;
			int OuterKey;
			cin >> OuterKey;
			for (int i = 0; i < H.GetAmountOfRooms(); i++)
			{
				if (OuterKey == K.GetKey(i)) { IsInhab = 1; }
			}
			if (IsInhab) { cout << "Welcome!" << endl; L.PrintInLog(V.GetName() + " enter right key"); return 0; }
			else { cout << "Wrong key!" << endl; L.PrintInLog(V.GetName() + " enter wrong key"); break; }
		}
		case 3:
		{
			L.PrintInLog(V.GetName() + " try to get room");
			if (AlreadyGetRoom) { cout << "You already have room" << endl; break; }
			cout << "1 - Any room" << endl << "2 - Show all posible for me" << endl << "3 - Exit" << endl;
			int var2;
			while (true)
			{
				cin >> var2;
				if (var2 == 1 || var2 == 2 || var2 == 3) { break; }
				else { cout << "1 - Any room" << endl << "2 - Show all posible for me" << endl << "3 - Exit" << endl; cin >> var2; }
			}
			switch (var2)
			{
			case 1:
			{
				bool get = false;
				for (int i = 0; i < H.GetAmountOfRooms(); i++)
				{
					if (((H.GetRoom(i)).GetGender()) == V.GetGender() && ((H.GetRoom(i)).GetFreeSpace()) > 0)
					{
						get = true;
						cout << (H.GetRoom(i)).GetCount() << " - number of your room" << endl;
						cout << K.GetKey(i) << " - your temporary key" << endl;
						L.PrintInLog(V.GetName() + " get room " + GetStr((H.GetRoom(i)).GetCount()) + " and key " + GetStr(K.GetKey(i)));
						CInhabitant IN(V);
						IN.SetKey(K.GetKey(i));
						IN.SetRoomAdress(i);
						(H.GetRoom(i)).FreeSpaceDecreace();
						if ((H.GetRoom(i)).GetGender() == 0) { (H.GetRoom(i).SetGender(IN.GetGender())); }
						AlreadyGetRoom = true;
						IN.SendAplication();
						cout << "Your application has been submitted for consideration" << endl;
						break;
					}
				}
				if(!get){ cout << "Sorry, no free room for you finded" << endl; L.PrintInLog(V.GetName() + " don't get any room");
				}
				break;
			}
			case 2:
			{
				int ver[20];
				for (int i = 0; i < 20; i++) { ver[i] = 0; }
				H.PringRoomsForGen(V.GetGender(), ver);
				cout << endl;
				bool chek = true;
				for (int i = 0; i < 20; i++) 
				{ 
					if (ver[i] == 1) { chek = false; }
				}
				if (chek) { cout << "Sorry, no free room for you finded" << endl; L.PrintInLog(V.GetName() + " don't get any room"); break;; }
				int chose;
				cout << "Chose room" << endl;
				cin >> chose;
				chose--;
				while (true)
				{
					if (ver[chose] == 1) { break; }
					cout << "Chose free room" << endl;
					cin >> chose;
				}
				cout << (H.GetRoom(chose)).GetCount() << " - number of your room" << endl;
				cout << K.GetKey(chose) << " - your temporary key" << endl;
				L.PrintInLog(V.GetName() + " get room " + GetStr((H.GetRoom(chose)).GetCount()) + " and key " + GetStr(K.GetKey(chose)));
				CInhabitant IN(V);
				IN.SetRoomAdress(chose + 1);
				(H.GetRoom(chose)).FreeSpaceDecreace();
				if ((H.GetRoom(chose)).GetGender() == 0) { (H.GetRoom(chose).SetGender(IN.GetGender())); }
				for (int i = 0; i < 20; i++) { ver[i] = 0; }
				AlreadyGetRoom = true;
				IN.SendAplication();
				cout << "Your application has been submitted for consideration" << endl;
				break;
			}
			case 3:
			{
				break;
			}
			}
		}
		}
	}
	return 0;
}