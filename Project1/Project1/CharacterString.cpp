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

}
CharacterString::CharacterString(int size)
{
	setLength(size);
	pStrStart = new char[size];
}
CharacterString::~CharacterString()
{
	//delete[] pStrStart;
	std::cout << "It's me" << '\n';
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
CharacterString& CharacterString::operator+(const CharacterString& obj)
{
	CharacterString temp;
	temp.setCharacter(pStrStart);
	strcat(pStrStart, obj.pStrStart);
	temp.setLength(strlen(temp.pStrStart) + 1);
	temp.pStrStart[temp.maxLength] = '\0';
	return temp;
}
//CharacterString CharacterString::operator+(const CharacterString& obj)
//{
//		CharacterString temp;
//	temp.setCharacter(pStrStart);
//	strcat(temp.pStrStart, obj.pStrStart);
//	temp.setLength(strlen(temp.pStrStart) + 1);
//	temp.pStrStart[temp.maxLength] = '\0';
//	return temp;
//}
//CharacterString CharacterString::operator+(const CharacterString& obj)
//{
//	CharacterString temp;
//	temp.setCharacter(CharacterString::pStrStart);
//	strcat(temp.pStrStart, obj.pStrStart);
//	temp.setLength(strlen(temp.pStrStart) + 1);
//	temp.pStrStart[temp.maxLength] = '\0';
//	return temp;
//}

CharacterString CharacterString::operator-(CharacterString const& obj)
{
	CharacterString res(strlen(pStrStart) - strlen(obj.pStrStart));
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
		res.pStrStart[strlen(pStrStart) - strlen(obj.pStrStart)] = '\0';
		//strcpy(obj.pStrStart, res.pStrStart);
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

