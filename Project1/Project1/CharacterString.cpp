#include "CharacterString.h"
#include <string>
#include<iostream>
#include<fstream>
#pragma warning(disable : 4996)

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
CharacterString CharacterString::operator+(CharacterString* obj)
{
		CharacterString temp;
	temp.setCharacter(pStrStart);
	strcat(temp.pStrStart, obj->pStrStart);
	temp.setLength(strlen(temp.pStrStart) + 1);
	temp.pStrStart[temp.maxLength] = '\0';
	return temp;
}
CharacterString CharacterString::operator+(CharacterString& obj)
{
	CharacterString temp;
	temp.setCharacter(pStrStart);
	strcat(temp.pStrStart, obj.pStrStart);
	temp.setLength(strlen(temp.pStrStart) + 1);
	temp.pStrStart[temp.maxLength] = '\0';
	return temp;
}
CharacterString& CharacterString::operator-(CharacterString& obj)
{
	int length = strlen(pStrStart) - strlen(obj.pStrStart);
	CharacterString res(strlen(pStrStart) - strlen(obj.pStrStart) - 4);
	char* array = new char[length];
	int j = 0, count = 0;
	for (int i = 0; i < obj.maxLength + 1; i++)
	{
		if (pStrStart[i] == obj.pStrStart[j]) {
			j++;
			count++;
		}
	}
	j = 0;
		for (int i = 0; i < strlen(pStrStart) + 1; i++)
		{
			if (count == strlen(obj.pStrStart))
			{
				if (pStrStart[i] != obj.pStrStart[j])
				{
					array[i - j] = pStrStart[i];
				}
				else
				{
					j++;
					continue;
				}
			}
			else {
				obj.pStrStart = pStrStart;
				return obj;
			}

		}
		obj.pStrStart = array;
		obj.pStrStart[length] = '\0';
		return obj;
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
	os.getline(so.pStrStart, so.maxLength);
	return os;
}

