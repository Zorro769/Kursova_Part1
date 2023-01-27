#include "BigIntValues.h"
using std::cout;
#pragma warning(disable : 4996)

BigIntValues::BigIntValues(char* s) {
	pStrStart = new char[strlen(s)];
	pStrStart[strlen(s)] = '\0';
	for (int i = strlen(s) - 1,j = 0; i >= 0; i--,j++)
	{
		if (!isdigit(s[i]))
			throw("ERROR");
		pStrStart[j] = s[i];
	}
	maxLength = NULL;
}
BigIntValues::BigIntValues(unsigned long long nr) {
	//pStrStart = new(std::nothrow) char[maxLength];
	do {
		pStrStart = Append(pStrStart,1,((nr % 10) + '0'));
		nr /= 10;
	} while (nr);
}
char* BigIntValues::Append(char* array,size_t n ,char a)
{
	size_t len = strlen(array);
	char* ret;
	if (len == 0)
	{
		ret = new char[len + n + 2];
	}
	else
		ret = new char[len + n + 1];
	
	for (int i = 0; i < len + n; i++)
	{
		if (i >= len)
		{
			ret[i] = (a);
		}
		else
		{
			ret[i] = array[i];
		}
	}

	ret[len + n] = '\0';


	return ret;
}

char* BigIntValues::PopBack(char* array)
{
	size_t len = strlen(array);
	char* ret = new char[len - 1];
	for (int i = 0; i < len; i++)
	{
		ret[i] = array[i];
	}
	ret[len - 1] = '\0';
	return ret;
}

char* BigIntValues::Resize(char* array,size_t size)
{
	size_t len = strlen(array);
	char* ret = new char[size];
	
	for (int i = 0; i < size; i++)
	{
		ret[i] = array[i];
	}
	ret[size] = '\0';
	return ret;
}

BigIntValues& BigIntValues::operator=(const BigIntValues& a)
{
	pStrStart = a.pStrStart;
	return *this;
}
BigIntValues& BigIntValues::operator=(const CharacterString& a)
{
	pStrStart = a.pStrStart;
	return *this;
}
//BigIntValues& operator+(BigIntValues& a, const BigIntValues& b) {
//	int t = 0, s=0, i,m,n;
//	if (strlen(a.pStrStart) == 0)
//		n = strlen(a.pStrStart) + 1;
//	else
//		n = strlen(a.pStrStart);
//	if (strlen(b.pStrStart) == 0)
//		m = strlen(b.pStrStart) + 1;
//	else
//		m = strlen(b.pStrStart);
//	if (m > n) {
//		a.pStrStart = a.Append(a.pStrStart, m - n, '0');
//	}
//	if(strlen(a.pStrStart) == 0)
//		n = strlen(a.pStrStart) + 1;
//	else
//		n = strlen(a.pStrStart);
//	for (i = 0; i < n; i++) {
//		int temp1 = a.pStrStart[i] - '0';
//		int temp2 = b.pStrStart[i] - '0';
//		if (i < m) {
//			s = temp1 + temp2 + t;
//		}
//		else
//			s = temp1 + t;
//		t = s / 10;
//		a.pStrStart[i] = (s % 10) + '0';
//	}
//	if (t) {
//		a.pStrStart = a.Append(a.pStrStart,1,t + '0');
//	}
//	return a;
//}
CharacterString BigIntValues::operator+(CharacterString* a) {
	int t = 0, s = 0, i, m, n;
	if (strlen(pStrStart) == 0)
		n = strlen(pStrStart) + 1;
	else
		n = strlen(pStrStart);
	if (strlen(a->pStrStart) == 0)
		m = strlen(a->pStrStart) + 1;
	else
		m = strlen(a->pStrStart);
	if (m > n) {
		pStrStart = Append(pStrStart, m - n, '0');
	}
	if (strlen(pStrStart) == 0)
		n = strlen(pStrStart) + 1;
	else
		n = strlen(pStrStart);
	for (i = 0; i < n; i++) {
		int temp1 = pStrStart[i] - '0';
		int temp2 = a->pStrStart[i] - '0';
		if (i < m) {
			s = temp1 + temp2 + t;
		}
		else
			s = temp1 + t;
		t = s / 10;
		pStrStart[i] = (s % 10) + '0';
	}
	if (t) {
		pStrStart = Append(pStrStart, 1, t + '0');
	}
	a->pStrStart = pStrStart;
	return *a;
}
//BigIntValues& operator+(const BigIntValues& a, const BigIntValues& b) {
//	BigIntValues temp;
//	temp = a;
//	temp += b;
//	return temp;
//}
//BigIntValues& operator+(const BigIntValues& a){
//	BigIntValues temp;
//	temp = a;
//	temp += b;
//	return temp;
//}
BigIntValues::~BigIntValues()
{
	//delete[] pStrStart;	
}
bool operator<(const BigIntValues& a, const BigIntValues& b) {
	int n = strlen(a.pStrStart), m = strlen(b.pStrStart);
	if (n != m)
		return n < m;
	while (n--)
		if (a.pStrStart[n] != b.pStrStart[n])
			return a.pStrStart[n] < b.pStrStart[n];
	return false;
}
bool operator>(const BigIntValues& a, const BigIntValues& b)
{
	int n = strlen(a.pStrStart), m = strlen(b.pStrStart);
	if (n != m)
		return n > m;
	while (n--)
		if (a.pStrStart[n] != b.pStrStart[n])
			return a.pStrStart[n] > b.pStrStart[n];
	return false;
}
bool operator<=(const BigIntValues&, const BigIntValues&)
{
	return false;
}
bool operator>=(const BigIntValues&, const BigIntValues&)
{
	return false;
}
bool operator==(const BigIntValues& a, const BigIntValues& b) {
	if (strcmp(a.pStrStart, b.pStrStart) == 0)
		return true;
	return false;
}
BigIntValues& operator-=(BigIntValues& a, const BigIntValues& b) {
	if (a < b)
		throw("UNDERFLOW");
	int n, m;
	if (strlen(a.pStrStart) == 0)
		n = strlen(a.pStrStart) + 1;
	else
		n = strlen(a.pStrStart);
	if (strlen(b.pStrStart) == 0)
		m = strlen(b.pStrStart) + 1;
	else
		m = strlen(b.pStrStart);
	int i, t = 0, s;
	for (i = 0; i < n; i++) {
		int temp1 = a.pStrStart[i] - '0';
		int temp2 = b.pStrStart[i] - '0';
		if (i < m)
			s = temp1 - temp2 + t;
		else
			s = temp1 + t;
		if (s < 0)
			s += 10,
			t = -1;
		else
			t = 0;
		a.pStrStart[i] = s + '0';
	}
	while (n > 1 && a.pStrStart[n - 1] == '0') {
		a.pStrStart = a.PopBack(a.pStrStart);
		n--;
	}
	return a;
}
BigIntValues operator-(const BigIntValues& a, const BigIntValues& b) {
	BigIntValues temp;
	temp = a;
	temp -= b;
	return temp;
}
BigIntValues& operator*=(BigIntValues& a, const BigIntValues& b)
{
	if (Null(a) || Null(b)) {
		a = BigIntValues();
		return a;
	}
	int size = 0,n,m;
	if (strlen(a.pStrStart) == 0)
		n = strlen(a.pStrStart) + 1;
	else
		n = strlen(a.pStrStart);
	if (strlen(b.pStrStart) == 0)
		m = strlen(b.pStrStart) + 1;
	else
		m = strlen(b.pStrStart);
	//vector<int> v(n + m, 0);
	int* array = new int[n + m]{ 0 };
	for (int i = 0; i < n; i++) {
		int temp1 = a.pStrStart[i] - '0';
		for (int j = 0; j < m; j++) {
			int temp2 = b.pStrStart[j] - '0';
			array[i + j] += (temp1) * (temp2);
		}
	}
	size = n + m;
	//for (int i = 0; i < 200; i++)
	//{
	//	std::cout << array[i]<< std::endl;
	//}
	n += m;
	a.pStrStart = a.Resize(a.pStrStart, size);
	for (int s, i = 0, t = 0; i < n; i++)
	{
		s = t + array[i];
		array[i] = s % 10;	
		t = s / 10;
		a.pStrStart[i] = array[i] + '0';
	}
	a.pStrStart[n] = '\0';
	for (int i = n - 1; i >= 1 && !array[i]; i--)
		a.pStrStart = a.PopBack(a.pStrStart);
	return a;
}
BigIntValues operator*(const BigIntValues& a, const BigIntValues& b) {
	BigIntValues temp;
	temp = a;
	temp *= b;
	return temp;
}
//BigIntValues& operator/=(BigIntValues& a, const BigIntValues& b)
//{
//	if (Null(b))
//		throw("Arithmetic Error: Division By 0");
//	if (a < b) {
//		a.pStrStart = new char[2];
//		a.pStrStart[0] = '0';
//		a.pStrStart[1] = '\0';
//		return a;
//	}
//	bool flag = a == b;
//	if (a == b) {
//		a.pStrStart = new char[2];
//		a.pStrStart[0] = '1';
//		a.pStrStart[1] = '\0';
//		return a;
//	}
//	int lgcat = 0, cc,n,m;
//	if (strlen(a.pStrStart) == 0)
//		n = strlen(a.pStrStart) + 1;
//	else
//		n = strlen(a.pStrStart);
//	if (strlen(b.pStrStart) == 0)
//		m = strlen(b.pStrStart) + 1;
//	else
//		m = strlen(b.pStrStart);
//	int i = 0;
//	int* array = new int[n] { 0 };
//	BigIntValues t;
//	for (i = n - 1; t * 10 + (a.pStrStart[i] - '0') < b; i--) {
//		t *= 10;
//		t += (a.pStrStart[i] - '0');
//	}
//	for (; i >= 0; i--) {
//		t = t * 10 + (a.pStrStart[i] - '0');
//		for (cc = 9; cc * b > t; cc--);
//		t -= cc * b;
//		array[lgcat++] = cc;
//
//	}
//	a.pStrStart = a.Resize(a.pStrStart,n);
//	for (i = 0; i < lgcat; i++)
//		a.pStrStart[i] = (array[lgcat - i - 1] + '0');
//	a.pStrStart = a.Resize(a.pStrStart,lgcat);
//	return a;
//}
//BigIntValues operator/(const BigIntValues& a, const BigIntValues& b)
//{
//	BigIntValues temp;
//	temp = a;
//	temp /= b;
//	return temp;
//}
bool Null(const BigIntValues&	a)
{
	if (a.pStrStart[0] == 0)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const BigIntValues& so)
{
	for (int i = strlen(so.pStrStart) - 1; i >= 0; i--) {
		os << so.pStrStart[i];
	}
	return os;
}

std::istream& operator>>(std::istream& os, BigIntValues& so)
{
	std::cout << "Enter the max length of string" << '\n';
	os >> so.maxLength;
	char* str = new char[so.maxLength];
	std::cout << "Enter the string " << '\n';
	os.ignore();
	os.getline(str, so.maxLength);
	int length = strlen(str);
	//so.pStrStart = new char[length];
	for (int i = length- 1; i >= 0; i--) {
		if (!isdigit(str[i])) {
			throw("NOT INT NUMBER");
		}
		so.pStrStart[length - i - 1] = str[i];
	}
	so.pStrStart[length] = '\0';
	return os;
}

