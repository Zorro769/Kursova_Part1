#include<iostream>
#include"CharacterString.h"
#pragma once
class BigIntValues:public CharacterString
{
	//int degree;
	//double baseOfNumber;
public:
	BigIntValues(char* value);
	BigIntValues(unsigned long long nr = 0);
	~BigIntValues();
	char* Append(char* array, size_t n, char a);
	char* PopBack(char* array);
	char* Resize(char* array,size_t size);
	friend bool Null(const BigIntValues& a);

	friend std::ostream& operator<<(std::ostream& os, const BigIntValues& so);
	friend std::istream& operator>>(std::istream& os, BigIntValues& so);

	//friend BigIntValues &operator+(BigIntValues& a, const BigIntValues& b);
	virtual CharacterString operator+(CharacterString* a) override;
	//BigIntValues& operator+(const BigIntValues& a);
	//BigIntValues& operator+(const BigIntValues& a);
	friend BigIntValues& operator-=(BigIntValues& a, const BigIntValues& b);
	friend BigIntValues operator-(const BigIntValues& a, const BigIntValues& b);

	friend BigIntValues& operator*=(BigIntValues& a, const BigIntValues& b);
	friend BigIntValues operator*(const BigIntValues& a, const BigIntValues& b);
	//friend BigIntValues &operator/=(BigIntValues&, const BigIntValues&);
	//friend BigIntValues operator/(const BigIntValues&, const BigIntValues&);

	friend bool operator<(const BigIntValues&, const BigIntValues&);
	friend bool operator>(const BigIntValues&, const BigIntValues&);
	friend bool operator<=(const BigIntValues&, const BigIntValues&);
	friend bool operator>=(const BigIntValues&, const BigIntValues&);

	friend bool operator==(const BigIntValues&, const BigIntValues&);

	BigIntValues& operator=(const BigIntValues& a);
	BigIntValues& operator=(const CharacterString& a);
};

