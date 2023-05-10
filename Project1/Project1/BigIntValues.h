#include<iostream>
#include"MyException.h"
#include"CharacterString.h"
#pragma once
class BigIntValues:public CharacterString
{
public:
	BigIntValues(const BigIntValues& obj) : CharacterString(obj) {}
	BigIntValues(unsigned long long nr = 0);
	~BigIntValues();
	void setCharacter(char* value);
	char* Append(char* array, char a, size_t n);
	char* PopBack(char* array);
	char* Resize(char* array,size_t size);
	bool SubString(char* array_1, char array_2);
	//void Appen(char*& str,char sym,size_t number);
	friend bool Null(const BigIntValues& a);

	friend std::ostream& operator<<(std::ostream& os, const BigIntValues& so);
	friend std::istream& operator>>(std::istream& os, BigIntValues& so);

	CharacterString operator+(CharacterString* a) override;
	CharacterString operator-=(CharacterString* a);

	friend BigIntValues operator+=(BigIntValues& a, const BigIntValues& b);
	friend BigIntValues operator+(const BigIntValues& a, const BigIntValues& b);
	
	friend BigIntValues& operator-=(BigIntValues& a, const BigIntValues& b);
	friend BigIntValues operator-(const BigIntValues& a, const BigIntValues& b);

	friend BigIntValues operator*=(BigIntValues& a, const BigIntValues& b);
	friend BigIntValues operator*(const BigIntValues& a, const BigIntValues& b);
	friend BigIntValues operator/=(BigIntValues&, const BigIntValues&);
	friend BigIntValues operator/(const BigIntValues&, const BigIntValues&);

	friend bool operator<(const BigIntValues&, const BigIntValues&);
	friend bool operator>(const BigIntValues&, const BigIntValues&);
	friend bool operator<=(const BigIntValues&, const BigIntValues&);
	friend bool operator>=(const BigIntValues&, const BigIntValues&);

	friend bool operator==(const BigIntValues&, const BigIntValues&);
	friend bool operator!=(const BigIntValues&, const BigIntValues&);

	bool operator<(CharacterString*);
	bool operator>(CharacterString*);
	
	BigIntValues& operator=(const BigIntValues& a);
	BigIntValues& operator=(CharacterString a);

};

