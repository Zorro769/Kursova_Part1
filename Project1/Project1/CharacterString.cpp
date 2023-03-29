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
	while (true)
	{
		try {

			if (value == 0 || value < 0)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw MyException("Invalid input.Not integer number");
			}
			maxLength = value;
			break;
		}
		catch (MyException& e) {
			e.ShowException();
			std::cerr << "Please,try again " << '\n';
			std::cin >> value;
		}
	}
	
}
int CharacterString::getCharacter(int index)
{
	if (index < 0)
		throw("ERROR");
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

#pragma region CharMethods
	/*char* CharacterString::Append(char* array, size_t n, char a)
	{
		size_t len = strlen(array);
		char* ret;
		if (len == 0)
		{
			ret = new char[len + n + 2];
		}
		else
			ret = new char[len + n + 1];

		for (int i = 0; i < len + n; i++)
		{
			if (i >= len)
			{
				ret[i] = (a);
			}
			else
			{
				ret[i] = array[i];
			}
		}

		ret[len + n] = '\0';

		delete[] array;
		return ret;
	}*/


#pragma endregion
#pragma region ArithmeticOperators
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
		if ((obj.pStrStart[i] == obj1.pStrStart[j]) && (j != strlen(obj1.pStrStart)))
			j++;
		else if (j == strlen(obj1.pStrStart))
			return true;
		else
			j = 0;
	}
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

