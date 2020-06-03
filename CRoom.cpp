#include "CRoom.h"


	int CRoom::GetCount() { return Count; }
	int CRoom::GetSize() { return Size; }
	int CRoom::GetGender() { return Gender; }
	int CRoom::GetFreeSpace() { return FreeSpace; }

	void CRoom::FreeSpaceDecreace() { this->FreeSpace = this->FreeSpace - 1; }

	void CRoom::SetCount(int Count) { this->Count = Count; }
	void CRoom::SetSize(int Size) { this->Size = Size; }
	void CRoom::SetGender(int Gender) { this->Gender = Gender; }
	void CRoom::SetFreeSpace(int FreeSpace) { this->FreeSpace = FreeSpace; }
