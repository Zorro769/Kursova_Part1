#pragma once
#include"BigIntValues.h"
#include"MyIterator.h"
#include"MyException.h"
class BigIntArray
{
	int NumberOfValues;
	BigIntValues* AllBigIntValues;

public:
	BigIntArray();
	~BigIntArray();

	void SetSizeOfBigIntArray(unsigned int value);
	void FillBigIntValueToArray();
	void ShowBigIntArray();
	void SumAllTheElements();

	BigIntValues& operator[](const int& value) {
		if (value > 0 && value < NumberOfValues) {
			return AllBigIntValues[value];
		}
		return AllBigIntValues[0];
	}

	MyIterator BeginOfArray() { return AllBigIntValues; }
	MyIterator EndOfArray() { return AllBigIntValues + NumberOfValues; }

};

