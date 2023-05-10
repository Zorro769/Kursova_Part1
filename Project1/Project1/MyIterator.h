#pragma once
#include"BigIntValues.h"
#include"MyException.h"
class MyIterator
{
protected:
	BigIntValues* BigIntValue;

public:
	MyIterator(BigIntValues* IntValue);
	~MyIterator();

	BigIntValues operator* ();

	BigIntValues& operator+=(int value);
	BigIntValues& operator++(int);

	bool operator!=(const MyIterator& it);
	bool operator>=(const MyIterator& it);
	bool operator<=(const MyIterator& it);
};

