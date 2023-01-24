#include "CharacterString.h"
#include <string>
#include<iostream>
#include<fstream>
#pragma warning(disable : 4996)
//CharacterString::CharacterString()
//{
//	setCharacter("Uknown");
//	setLength(0);
//}
//CharacterString::CharacterString() {}

CharacterString::CharacterString()
{
	pStrStart = new char[1];
	pStrStart[0] = '\0';
	maxLength = 0;
}
CharacterString::CharacterString(int size)
{
	setLength(size);
	pStrStart = new char[size];
}
CharacterString::~CharacterString()
{
	//delete[] pStrStart;
}
void CharacterString::setCharacter(const char* value)
{
	pStrStart = new char[strlen(value) + 1];
	strcpy(pStrStart, value);
}
char* CharacterString::getCharacter()
{
	return pStrStart;
		
}
void CharacterString::setLength(int value)
{
	maxLength = value;
}
int CharacterString::getLength()
{
	return maxLength;
}
CharacterString::CharacterString(const CharacterString& obj)
{
	int i; 
	maxLength = obj.maxLength;

	pStrStart = new char[obj.maxLength];

	if (!pStrStart) 
		exit(1);
	for (i = 0; i < obj.maxLength; i++)
		pStrStart[i] = obj.pStrStart[i];
}

CharacterString CharacterString::operator+(CharacterString& obj)
{
	//strcat(pStrStart, obj.pStrStart);
	//obj.pStrStart = pStrStart;
	//obj.setCharacter(pStrStart);
	//obj.setLength(strlen(obj.pStrStart) + 1);
	//obj.pStrStart[obj.maxLength] = '\0';
	//return obj;
	CharacterString temp;
	temp.setCharacter(pStrStart);
	strcat(temp.pStrStart, obj.pStrStart);
	//temp.setCharacter(pStrStart);
	temp.setLength(strlen(temp.pStrStart) + 1);
	temp.pStrStart[temp.maxLength] = '\0';
	//temp.pStrStart = new char[strlen(pStrStart) + strlen(obj.pStrStart) + 2];
	//temp.setCharacter(strcat_s(pStrStart, maxLength + obj.maxLength, obj.pStrStart));
	return temp;
}

CharacterString CharacterString::operator-(CharacterString const& obj)
{
	CharacterString res(strlen(pStrStart) - strlen(obj.pStrStart) - 4);
	std::cout << strlen(pStrStart) - strlen(obj.pStrStart) << std::endl;
	int j = 0, count = 0;
	for (int i = 0; i < obj.maxLength + 1; i++)
	{
		if (pStrStart[i] == obj.pStrStart[j]) {
			j++;
			count++;
		}
	}
	if (count != strlen(obj.pStrStart))
	{
		res.setCharacter(obj.pStrStart);
		res.setLength(obj.maxLength);
		return res;
	}
	j = 0;
		for (int i = 0; i < strlen(pStrStart) + 1; i++)
		{
			//if ((pStrStart[i] == obj.pStrStart[j]) && (count == strlen(obj.pStrStart))) {
			//	j++;
			//	res.pStrStart[i] = pStrStart[i];
			//}
			//else
			//	res.pStrStart[i - j] = pStrStart[i];
			//std::cout << res.pStrStart[i] << std::endl;
			if (pStrStart[i] != obj.pStrStart[j])
			{
				res.pStrStart[i - j] = pStrStart[i];
			}
			else
			{
				j++;
				continue;
			}
		}
		//for (int i = 0; i < strlen(res.pStrStart); i++)
		//{
		//	std::cout << res.pStrStart[i] << std::endl;
		//}
		return res;
}

CharacterString CharacterString::operator=(CharacterString const& other)
{
	if(this == &other)
		return *this;
	setCharacter(other.pStrStart);
	setLength(other.maxLength);
}
bool operator*(CharacterString const& obj, CharacterString const& obj1)
{
	int j = 0;
	
	for (int i = 0; i < strlen(obj.pStrStart); i++)
	{
		if (obj.pStrStart[i] == obj1.pStrStart[j]) {
			j++;
		}
	}
	if (j == strlen(obj1.pStrStart))
		return true;
	return false;
}
//bool operator*(CharacterString const& obj, CharacterString const& obj1)
//{
//	int j = 0;
//
//	for (int i = 0; i < obj.maxLength + 1; i++)
//	{
//		if (obj.ps[i] == obj1.pStrStart[j]) {
//			j++;
//		}
//	}
//	if (j == strlen(obj1.pStrStart))
//		return true;
//	return false;
//}
std::ostream& operator<<(std::ostream& os, const CharacterString& so)
{
	os << "Line: " << so.pStrStart << "\nMax Length: " << so.maxLength << std::endl;
	return os;
}

std::istream& operator>>(std::istream& os, CharacterString& so)
{
	std::cout << "Enter max length: " << std::endl;
	os >> so.maxLength;
	std::cout << "Enter line: " << std::endl;
	os.ignore();
	so.pStrStart = new char[so.maxLength];
	os.getline(so.pStrStart, so.maxLength);
	return os;
}

