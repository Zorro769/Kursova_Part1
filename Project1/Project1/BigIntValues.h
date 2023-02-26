#include<iostream>
#include"CharacterString.h"
#pragma once
class BigIntValues:public CharacterString
{
public:
	BigIntValues(unsigned long long nr = 0);
	~BigIntValues();
	/*char* Append(char* array, size_t n, char a);
	char* PopBack(char* array);
	char* Resize(char* array,size_t size);
	bool SubString(char* array_1, char array_2);*/
	friend bool Null(const BigIntValues& a);

	friend std::ostream& operator<<(std::ostream& os, const BigIntValues& so);
	friend std::istream& operator>>(std::istream& os, BigIntValues& so);

	virtual CharacterString operator+(CharacterString* a) override;
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

