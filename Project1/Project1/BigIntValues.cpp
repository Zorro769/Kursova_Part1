#include "BigIntValues.h"
#include<math.h>
using std::cout;
#pragma warning(disable : 4996)

BigIntValues::BigIntValues(unsigned long long nr) {
	do {
		pStrStart = Append(pStrStart,1,((nr % 10) + '0'));
		nr /= 10;
	} while (nr);
}

BigIntValues::~BigIntValues()
{
}

CharacterString BigIntValues::operator+(CharacterString* a) {     
	int t = 0, number = 0, i, m, n;
	if (strlen(pStrStart) == 0)
		n = 1;                     
	else
		n = strlen(pStrStart);
	if (strlen(a->getCharacter()) == 0)
		m = 1;
	else
		m = strlen(a->getCharacter());
	if (SubString(pStrStart, '-') && SubString(a->getCharacter(), '-'))
	{
		a->setCharacter(a->PopBack(a->getCharacter()));
		pStrStart = PopBack(pStrStart);
		*this = *this + a;
		pStrStart = Append(pStrStart, 1, '-');
		if (pStrStart[strlen(pStrStart)] == '0')
			pStrStart = PopBack(pStrStart);
		a->setCharacter(this->pStrStart);
		return *this;
	}
	else if (SubString(pStrStart, '-')) {
		BigIntValues temp;
		pStrStart = PopBack(pStrStart);
		if (*this < a) {
			temp.pStrStart = a->getCharacter();
			a->setCharacter(pStrStart);
			temp -= a;
			a->setCharacter(temp.pStrStart);
			return *a;
		}
		else if (*this > a) {
			*this -= a;
			temp.pStrStart = Append(temp.pStrStart, 1, '-');
			return *this;
		}
		else
			*this -= a;
		return *this;
	}
	else if (SubString(a->getCharacter(), '-'))
	{
		a->setCharacter(PopBack(a->getCharacter()));
		*this -= a;
		if (pStrStart[0] == '0')
			return *this;
		return *this;

	}
	if (m > n) {
		pStrStart = Append(pStrStart, m - n, '0');
	}
	n = strlen(pStrStart);
	for (i = 0; i < n; i++) {
		int firstTerm = pStrStart[i] - '0';
		int secondTerm = a->getCharacter(i) - '0';
		if (i < m) {
			number = firstTerm + secondTerm + t;
		}
		else
			number = firstTerm + t;
		t = number / 10; 
		pStrStart[i] = (number % 10) + '0';
	}
	if (t) {
		pStrStart = Append(pStrStart, 1, t + '0');
	}
	a->setCharacter(pStrStart);
	return *a;
}
CharacterString BigIntValues::operator-=(CharacterString* a)
{
	int n, m;
	bool flag = false;
	
	if (*this < a) {
		pStrStart = Append(pStrStart, 1, '0');
		flag = true;
	}
	if (strlen(pStrStart) == 0)
		n = 1;
	else
		n = strlen(pStrStart);

	if (strlen(a->getCharacter()) == 0)
		m = 1;
	else
		m = strlen(a->getCharacter());
	
	int i, t = 0, number;
	for (i = 0; i < ((m + n) / 2 + fabs(m - n) - fabs(m - n) / 2); i++) {

		int firstTerm = pStrStart[i] - '0';
		int secondTerm = a->getCharacter(i) - '0';

		if (i < m && !flag)
			number = firstTerm - secondTerm + t;
		else if (flag)
			number = secondTerm - firstTerm + t;
		else
			number = firstTerm + t;

		if (number < 0)
			number += 10,
			t = -1;
		else
			t = 0;

		pStrStart[i] = number + '0';
	}
	while (n > 1 && pStrStart[n - 1] == '0') {
		pStrStart = PopBack(pStrStart);
		n--;
	}
	if (flag)
		pStrStart = Append(pStrStart, 1, '-');
	a->setCharacter(pStrStart);
	return *a;
}
BigIntValues operator+=(BigIntValues& a, const BigIntValues& b)
{
	int t = 0, number = 0, i, m, n;
	bool flag = false;
	if (strlen(a.pStrStart) == 0)
		n = 1;
	else
		n = strlen(a.pStrStart);
	if (strlen(b.pStrStart) == 0)
		m = 1;
	else
		m = strlen(b.pStrStart);
	if (a.SubString(a.pStrStart, '-') && a.SubString(b.pStrStart, '-'))
	{
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a.pStrStart = a.PopBack(a.pStrStart);
		a += temp;
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
		if (a.pStrStart[strlen(a.pStrStart)] == '0')
			a.pStrStart = a.PopBack(a.pStrStart);
		return a;
	}
	if (a.SubString(a.pStrStart, '-')) {
		BigIntValues temp;
		temp = b;
		a.pStrStart = a.PopBack(a.pStrStart);
		if (a < b) {
			temp -= a;
			a = temp;
		}
		else if(a > b){
			a -= temp;
			a.pStrStart = a.Append(a.pStrStart, 1, '-');
		}
		else
			a -= temp;
		return a;
	}
	if (a.SubString(b.pStrStart, '-'))
	{
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a -= temp;
		if (a.pStrStart[0] == '0')
			return a;
		return a;

	}

	if (m > n) {
		a.pStrStart = a.Append(a.pStrStart, m - n, '0');
	}

	n = strlen(a.pStrStart);
	for (i = 0; i < n; i++) {
		int firstTerm = a.pStrStart[i] - '0';
		int secondTerm = b.pStrStart[i] - '0';
		if (i < m) {
			number = firstTerm + secondTerm + t;
		}
		else
			number = firstTerm + t;
		t = number / 10;
		a.pStrStart[i] = (number % 10) + '0';
	}
	if (t) {
		a.pStrStart = a.Append(a.pStrStart, 1, t + '0');
	}

	return a;
}

BigIntValues operator+(const BigIntValues& a, const BigIntValues& b) {
	BigIntValues temp;
	temp = a;
	temp += b;
	return temp;
}

BigIntValues& operator-=(BigIntValues& a, const BigIntValues& b) {
	int n, m;
	bool flag = false;
	if (a.SubString(a.pStrStart, '-') && a.SubString(b.pStrStart, '-'))
	{
		a.pStrStart = a.PopBack(a.pStrStart);
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		if (a > temp)
			flag = true;
		if (flag) {
			a -= temp;
			a.pStrStart = a.Append(a.pStrStart, 1, '-');
		}
		else {
			temp -= a;
			a = temp;
		}
		if (a.pStrStart[strlen(a.pStrStart)] == '0')
			a.pStrStart = a.PopBack(a.pStrStart);
		return a;
	}
	else if (a.SubString(a.pStrStart, '-'))
	{
		a.pStrStart = a.PopBack(a.pStrStart);
		a += b;
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
		return a;
	}
	else if (a.SubString(b.pStrStart, '-'))
	{
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a += temp;
		return a;
	}
	if (a < b) {
		a.pStrStart = a.Append(a.pStrStart, 1, '0');
		flag = true;
	}

	if (strlen(a.pStrStart) == 0)
		n = 1;
	else
		n = strlen(a.pStrStart);

	if (strlen(b.pStrStart) == 0)
		m = 1;
	else
		m = strlen(b.pStrStart);
	


	int i, t = 0, number;
	for (i = 0; i < ((m + n)/2 + fabs(m - n) - fabs(m - n)/2); i++) {

		int firstTerm = a.pStrStart[i] - '0';
		int secondTerm = b.pStrStart[i] - '0';

		if (i < m && !flag)
			number = firstTerm - secondTerm + t;
		else if (flag)
			number = secondTerm - firstTerm + t;
		else
			number = firstTerm + t;

		if (number < 0)
			number += 10,
			t = -1;
		else
			t = 0;
		
		a.pStrStart[i] = number + '0';
	}
	while (n > 1 && a.pStrStart[n - 1] == '0') {
		a.pStrStart = a.PopBack(a.pStrStart);
		n--;
	}
	if (flag)
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
	return a;
}
BigIntValues operator-(const BigIntValues& a, const BigIntValues& b) {
	BigIntValues temp;
	temp = a;
	temp -= b;
	return temp;
}
BigIntValues operator*=(BigIntValues& a, const BigIntValues& b)
{
	if (Null(a) || Null(b)) {
		a = BigIntValues();
		return a;
	}
	int size = 0,n,m;
	if (strlen(a.pStrStart) == 0)
		n = 1;
	else
		n = strlen(a.pStrStart);
	if (strlen(b.pStrStart) == 0)
		m = 1;
	else
		m = strlen(b.pStrStart);
	if (a.SubString(a.pStrStart, '-') && a.SubString(b.pStrStart, '-'))
	{
		a.pStrStart = a.PopBack(a.pStrStart);
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a *= temp;
		return a;
	}
	else if (a.SubString(a.pStrStart, '-'))
	{
		a.pStrStart = a.PopBack(a.pStrStart);
		a *= b;
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
		return a;
	}
	else if (a.SubString(b.pStrStart, '-'))
	{
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a *= temp;
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
		return a;
	}
	int* array = new int[n + m]{ 0 };
	for (int i = 0; i < n; i++) {
		int firstTerm = a.pStrStart[i] - '0';
		for (int j = 0; j < m; j++) {
			int secondTerm = b.pStrStart[j] - '0';
			array[i + j] += (firstTerm) * (secondTerm);
		}
	}
	size = n + m;
	n += m;
	a.pStrStart = a.Resize(a.pStrStart, size);
	for (int number, i = 0, t = 0; i < n; i++)
	{
		number = t + array[i];
		array[i] = number % 10;	
		t = number / 10;
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
BigIntValues operator/=(BigIntValues& a, const BigIntValues& b)
{
	if (Null(b))
		throw("Arithmetic Error: Division By 0");
	if (a < b) {
		a = BigIntValues();
		return a;
	}
	if (a == b) {
		a = BigIntValues();
		return a;
	}
	int lgcat = 0, cc,n,m;
	if (strlen(a.pStrStart) == 0)
		n = 1;
	else
		n = strlen(a.pStrStart);
	if (strlen(b.pStrStart) == 0)
		m = 1;
	else
		m = strlen(b.pStrStart);
	if (a.SubString(a.pStrStart, '-') && a.SubString(b.pStrStart, '-'))
	{
		a.pStrStart = a.PopBack(a.pStrStart);
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a /= temp;
		return a;
	}
	else if (a.SubString(a.pStrStart, '-'))
	{
		a.pStrStart = a.PopBack(a.pStrStart);
		a /= b;
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
		return a;
	}
	else if (a.SubString(b.pStrStart, '-'))
	{
		BigIntValues temp;
		temp = b;
		temp.pStrStart = temp.PopBack(temp.pStrStart);
		a /= temp;
		a.pStrStart = a.Append(a.pStrStart, 1, '-');
		return a;
	}
	int i = 0;
	int* array = new int[n] { 0 };
	BigIntValues t;
	for (i = n - 1; t * 10 + (a.pStrStart[i] - '0') < b; i--) {
		t *= 10;
		t += (a.pStrStart[i] - '0');
	}
	
	for (; i >= 0; i--) {
		t = t * 10 + (a.pStrStart[i] - '0');
		for (cc = 9; cc * b > t; cc--);
		t -= cc * b;
		array[lgcat++] = cc;

	}
	a.pStrStart = a.Resize(a.pStrStart,n);
	for (i = 0; i < lgcat; i++)
		a.pStrStart[i] = (array[lgcat - i - 1] + '0');
	a.pStrStart = a.Resize(a.pStrStart,lgcat);
	return a;
}
BigIntValues operator/(const BigIntValues& a, const BigIntValues& b)
{
	BigIntValues temp;
	temp = a;
	temp /= b;
	return temp;
}
bool Null(const BigIntValues& a)
{
	if (a.pStrStart[strlen(a.pStrStart)] == '0')
		return true;
	return false;
}
BigIntValues& BigIntValues::operator=(CharacterString a)
{
	pStrStart = a.getCharacter();
	return *this;
}
bool BigIntValues::operator<(CharacterString* a)
{
	int n = strlen(pStrStart), m = strlen(a->getCharacter());
	//BigIntValues temp;
	bool flag = false;
	if (SubString(pStrStart, '-') && SubString(a->getCharacter(), '-'))
		flag = true;
	else if (SubString(pStrStart, '-'))
		return true;
	else if (SubString(a->getCharacter(), '-'))
		return false;
	if (n != m && !flag)
		return n < m;
	while (n--)
		if (flag)
			return pStrStart[n] > a->getCharacter(n);
		else if (pStrStart[n] != a->getCharacter(n))
			return pStrStart[n] < a->getCharacter(n);
	return false;
}
bool BigIntValues::operator>(CharacterString* a)
{
	return !(*this < a);
}
BigIntValues& BigIntValues::operator=(const BigIntValues& a)
{
	pStrStart = a.pStrStart;
	return *this;
}
bool operator==(const BigIntValues& a, const BigIntValues& b) {
	if (strcmp(a.pStrStart, b.pStrStart) == 0)
		return true;
	return false;
}
bool operator!=(const BigIntValues& a, const BigIntValues& b)
{
	return !(a == b);
}
bool operator<(const BigIntValues& a, const BigIntValues& b) {
	int n = strlen(a.pStrStart), m = strlen(b.pStrStart);
	BigIntValues temp;
	bool flag = false;
	if (temp.SubString(a.pStrStart, '-') && temp.SubString(b.pStrStart, '-'))
		flag = true;
	else if (temp.SubString(a.pStrStart, '-'))
		return true;
	else if (temp.SubString(b.pStrStart, '-'))
		return false;
	if (n != m && !flag)
		return n < m;
	while (n--)
		if(flag)
			return a.pStrStart[n] > b.pStrStart[n];
		else if (a.pStrStart[n] != b.pStrStart[n])
			return a.pStrStart[n] < b.pStrStart[n];
	return false;
}
bool operator>(const BigIntValues& a, const BigIntValues& b)
{
	return b < a;
}
bool operator<=(const BigIntValues& a, const BigIntValues& b)
{
	return !(a > b);
}
bool operator>=(const BigIntValues& a, const BigIntValues& b)
{
	return !(a < b);
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
	while (true)
	{
		try {
			os >> so.maxLength;
			if (os.fail() || so.maxLength < 0)
			{
				os.clear();
				os.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::invalid_argument("Invalid input.Not integer number");
			}
			break;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
			std::cerr << "Please,try again " << '\n';
		}
	}
	char* str = new char[so.maxLength];
	char* temp = new char[so.maxLength];
	std::cout << "Enter the string " << '\n';
	os.ignore();
	while (true)
	{
		os.getline(str, INT_MAX);
		if (so.maxLength < strlen(str))
		{
			std::cout << ("Too many characters,try again\n");
		}
		else
			break;
	}
	bool flag = false;
	int length = strlen(str);
	for (int i = length - 1; i >= 0; i--) {
		if (str[0] == '-' && !flag) {
			flag = true;
		}
			if (!isdigit(str[i]) && !flag){
				std::cout << ("NOT INTEGER NUMBER,TRY AGAIN\n");
				os.getline(str, so.maxLength);
				i = ((length - strlen(str)));
				length = strlen(str);
			
			}
			else
				temp[length - i - 1] = str[i];
	}
	temp[length] = '\0';
	so.setCharacter(temp);
	return os;
}