#pragma once
#include<iostream>
#include <string>
using namespace std;
class CVisitor
{
private:
	string Name;
	int Gender;
public:
	CVisitor();
	int GetGender();
	string GetName();
};