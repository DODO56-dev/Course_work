#pragma once
#include<time.h>
#include<fstream>
#include<iostream>
using namespace std;

const std::string currentDateTime();

class Log
{
public:
	ofstream Logout;
	Log();
	~Log();
	void PrintInLog(string str);
};

