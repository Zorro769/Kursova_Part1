#include "CharacterString.h"
#include <string>
#include<iostream>
#include<fstream>
#include<exception>
#include"MyException.h"

#pragma warning(disable : 4996)


CharacterString::CharacterString()
{
	maxLength = 256;
	pStrStart = new char[maxLength] {'\0'};
}
CharacterString::CharacterString(int size)
{
	setLength(size);
	pStrStart = new char[size];
}
CharacterString::~CharacterString()
{
}
void CharacterString::setCharacter(char* value)
{
	if (strlen(value) < maxLength)
		setLength(strlen(value));
	pStrStart = new char[maxLength];
	strcpy(pStrStart, value);
}
char* CharacterString::getCharacter()
{
	return pStrStart;
}
void CharacterString::setLength(int value)
{
	if (value == 0 || value < 0 || value > 256)
	{
		std::cin.clear();	
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw MyException("Invalid input.Not integer number");
	}
	maxLength = value;
	
}
int CharacterString::getCharacter(int index)
{
	if (index < 0)
		throw MyException("ERROR");
	return pStrStart[index];
}
int CharacterString::getLength()
{
	return maxLength;
}
CharacterString::CharacterString(const CharacterString& obj)
{
	int i; 
	maxLength = obj.maxLength;

	pStrStart = new char[obj.maxLength + 1];

	if (!pStrStart) 
		exit(1);
	for (i = 0; i < obj.maxLength; i++)
		pStrStart[i] = obj.pStrStart[i];
	pStrStart[maxLength] = '\0';
}

#pragma region ArithmeticOperators
CharacterString CharacterString::operator+(CharacterString* obj)
{
	CharacterString temp;
	char* newStr = new char[maxLength + obj->maxLength];
	strcpy(newStr, pStrStart);
	strcat(newStr, obj->pStrStart);
	temp.setCharacter(newStr);
	temp.setLength(strlen(newStr)); 
	temp.pStrStart[temp.maxLength] = '\0';
	return temp;
}
CharacterString CharacterString::operator-(const CharacterString& obj)const
{
	int length = maxLength - obj.maxLength;
	CharacterString res(length);
	char* array = new char[length + 1];
	int j = 0,i = 0, count = 0;
	bool found = false;
	while (i < maxLength)
	{
		if (pStrStart[i] == obj.pStrStart[j])
		{
			j++;
			if (j == obj.maxLength)
			{
				found = true;
				break;
			}
		}
		else
		{
			j = 0;
		}
		i++;
	}

	if (!found)
	{
		throw MyException("THERE IS NO SUCH SUBSTRING IN MAIN STRING!");
	}

	for (int k = 0; k < i - obj.maxLength + 1; k++)
	{
		array[k] = pStrStart[k];
	}

	for (int k = i + 1; k < maxLength; k++)
	{
		array[k - obj.maxLength] = pStrStart[k];
	}	
	res.setCharacter(array);
	res.setLength(length);
	res.pStrStart[length] = '\0';
	return res;
}

CharacterString CharacterString::operator=(CharacterString const& other)
{
	if(this == &other)
		return *this;
	setCharacter(other.pStrStart);
	setLength(other.maxLength);
	return *this;
}
bool operator*(CharacterString const& obj, CharacterString const& obj1)
{
	int j = 0;
	
	for (int i = 0; i < strlen(obj.pStrStart); i++)
	{
		if ((obj.pStrStart[i] == obj1.pStrStart[j]) && (j != strlen(obj1.pStrStart)))
			j++;
		else if (j == strlen(obj1.pStrStart))
			return true;
		else
			j = 0;
	}
	if (j == strlen(obj1.pStrStart))
		return true;
	return false;
}
#pragma endregion
#pragma region IOoperators

std::ostream& operator<<(std::ostream& os, const CharacterString& so)
{
	os << "Line: " << so.pStrStart << "\nMax Length: " << so.maxLength << std::endl;
	return os;
}

std::istream& operator>>(std::istream& os, CharacterString& so)
{
	std::cout << "Enter max length: " << std::endl;
	os >> so.maxLength;
	so.setLength(so.maxLength);
	char* str = new char[so.maxLength];
	std::cout << "Enter line: " << std::endl;
	os.ignore();
	os.getline(str, so.maxLength);
	so.setCharacter(str);
	return os;
}

#pragma endregion

