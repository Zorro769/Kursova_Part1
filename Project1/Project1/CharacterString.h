#pragma once
#include<iostream>
#include<fstream>
#include"MyException.h"
class CharacterString
{
protected:
	char* pStrStart;
	int maxLength;
public:
	CharacterString();
	CharacterString(int size);
	~CharacterString();

	char* getCharacter();
	void setCharacter(char* value);
	int getLength();
	void setLength(int value);
	int getCharacter(int index);
	
	/*char* Append(char* array, size_t n, char a);
	char* PopBack(char* array);
	char* Resize(char* array, size_t size);
	bool SubString(char* array_1, char array_2);*/

	CharacterString(const CharacterString& obj);
	virtual CharacterString operator+(CharacterString* obj);
	CharacterString operator+(CharacterString& obj);
	CharacterString& operator-(CharacterString& obj);
	CharacterString operator=(CharacterString const& other);
	bool friend operator*(CharacterString const& obj, CharacterString const& obj1);
	friend std::ostream& operator<<(std::ostream& os, const CharacterString& so);
	friend std::istream& operator>>(std::istream& os,CharacterString& so);
};

