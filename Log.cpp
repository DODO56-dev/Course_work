#define _CRT_SECURE_NO_WARNINGS
#include "Log.h"
const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}
Log::Log()
{
	Logout.open("Logs.txt", ios::app);
	if (!Logout.is_open()) { cout << "Eror" << endl; }
}
Log::~Log()
{
	Logout.close();
}

void Log::PrintInLog(string str)
{
	string Logmess = currentDateTime();
	Logout << Logmess + " " + str << endl;
}