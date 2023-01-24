#pragma once
#include<iostream>
#include<fstream>
class CharacterString
{
protected:
	char* pStrStart;
	int maxLength;

public:
	//CharacterString();
	CharacterString();
	CharacterString(int size);
	~CharacterString();
	char* getCharacter();
	void setCharacter(const char* value);
	int getLength();
	void setLength(int value);
	CharacterString(const CharacterString& obj);
	CharacterString operator+(CharacterString& obj1);
	CharacterString operator-(CharacterString const& obj);
	CharacterString operator=(CharacterString const& other);
	bool friend operator*(CharacterString const& obj, CharacterString const& obj1);
	friend std::ostream& operator<<(std::ostream& os, const CharacterString& so);
	friend std::istream& operator>>(std::istream& os,CharacterString& so);
};

