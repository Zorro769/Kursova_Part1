#include "MyIterator.h"
#include"BigIntArray.h"

MyIterator::MyIterator(BigIntValues* FirstValue) : BigIntValue(FirstValue) {}

MyIterator::~MyIterator() {}

BigIntValues MyIterator::operator*() {
	return *BigIntValue;
}

BigIntValues& MyIterator::operator++(int) {
	return *BigIntValue++;
}

BigIntValues& MyIterator::operator+=(int value) {
	return *(BigIntValue+= value);
}

bool MyIterator::operator!=(const MyIterator& it) {
	return BigIntValue != it.BigIntValue;
}
bool MyIterator::operator>=(const MyIterator& it) {
	return BigIntValue >= it.BigIntValue;
}
bool MyIterator::operator<=(const MyIterator& it) {
	return BigIntValue <= it.BigIntValue;
}