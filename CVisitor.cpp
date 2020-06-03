#include "CVisitor.h"

CVisitor::CVisitor()
{
	cout << "Enter your name" << endl;
	cin >> Name;
	cout << "Enter your gender: 1 - Male   2 - Female" << endl;
	int Gen;
	while (true)
	{
		cin >> Gen;
		if (Gen == 1 || Gen == 2)
		{
			Gender = Gen;
			break;
		}
		else { cout << "1 - Male   2 - Female" << endl; cin >> Gen; }
	}
}
int CVisitor::GetGender() { return Gender; }
string CVisitor::GetName() { return Name; }
