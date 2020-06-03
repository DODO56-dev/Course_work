#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class CKey
{
private:
	int Keys[20];
public:
	CKey();
	int GetKey(int i);
};