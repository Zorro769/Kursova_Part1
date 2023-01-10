#include "CharacterString.h"
#include <string>

CharacterString::CharacterString(int size)
{
	pStrStart = new char[size];
	if (!pStrStart)
	{
		exit(1);
		setLength(size);
	}
}
CharacterString::~CharacterString()
{
	delete[] pStrStart;
}
void CharacterString::setCharacter(int i, char value)
{
	if (i >= 0 && i < maxLength)
	{
		pStrStart[i] = value;
	}
}
char CharacterString::getCharacter(int i)
{
	return pStrStart[i];
		
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
