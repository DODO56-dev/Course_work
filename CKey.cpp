#include "CKey.h"
CKey::CKey()
{
	ifstream KIN;
	KIN.open("Keys.txt");
	if (!KIN.is_open()) { cout << "Eror" << endl; }
	else
	{
		for (int i = 0; i < 20; i++)
		{
			KIN >> Keys[i];
		}
	}
	KIN.close();
}
int CKey::GetKey(int i) { return Keys[i]; }