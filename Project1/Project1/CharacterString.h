#pragma once
class CharacterString
{
	char* pStrStart;
	int maxLength;

public:
	CharacterString(int sz);
	~CharacterString();
	char getCharacter(int i);
	void setCharacter(int i,char value);
	int getLength();
	void setLength(int value);
	CharacterString(const CharacterString& obj);
};

