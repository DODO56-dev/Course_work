#pragma once
class CRoom
{
private:
	int Count;
	int Size;
	int Gender;
	int FreeSpace;
public:

	int GetCount();
	int GetSize();
	int GetGender();
	int GetFreeSpace();

	void FreeSpaceDecreace();

	void SetCount(int Count);
	void SetSize(int Size);
	void SetGender(int Gender);
	void SetFreeSpace(int FreeSpace);

};

