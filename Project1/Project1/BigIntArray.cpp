#include "BigIntArray.h"
#include<iostream>
#include<Windows.h>
#include<math.h>

BigIntArray::BigIntArray() {
	NumberOfValues = 0;
	AllBigIntValues = new BigIntValues[NumberOfValues];
}

BigIntArray::~BigIntArray() {}

void BigIntArray::SetSizeOfBigIntArray(unsigned int value) {
	if (value == 0)
		throw MyException("Error in typing value.It is not valid");
	else
		NumberOfValues = value;
	AllBigIntValues = new BigIntValues[NumberOfValues];
}

void BigIntArray::FillBigIntValueToArray() {
	for (int i = 0; i < NumberOfValues; i++) {
		std::cin >> AllBigIntValues[i];
	}
}
void BigIntArray::ShowBigIntArray() {
	for (MyIterator it = MyIterator(BeginOfArray()); it != EndOfArray(); it++) {
		std::cout << *it << '\n';
	}
}

void BigIntArray::SumAllTheElements() {
	BigIntValues objSum;
	for (MyIterator it = MyIterator(BeginOfArray()); it != EndOfArray(); it++) {
		objSum += *it;
	}
	std::cout <<"Sum" << objSum;
}