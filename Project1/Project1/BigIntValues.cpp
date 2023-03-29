#define _CRTDBG_MAP_NEW	
#include "BigIntValues.h"
#include "MyException.h"
#include<math.h>
#include<crtdbg.h>
using std::cout;
#pragma warning(disable : 4996)

	BigIntValues::BigIntValues(unsigned long long nr) {
		do {
			pStrStart = Append(pStrStart, ((nr % 10) + '0'),1);
			nr /= 10;
		} while (nr);
	}

	BigIntValues::~BigIntValues()
	{}
	void BigIntValues::setCharacter(char* value)
	{
		if (strlen(value) < maxLength)
			setLength(strlen(value));
		pStrStart = new char[maxLength + 1];
		bool flag = false;
		for (int i = maxLength - 1; i >= 0; i--) {
			if (value[0] == '-' && !flag) {
				flag = true;
			}
			if (!isdigit(value[i]) && !flag) {
				std::cout << ("NOT INTEGER NUMBER,TRY AGAIN\n");
				std::cin.clear();
				//std::cin.ignore();
				std::cin.getline(value, maxLength);
				i = ((maxLength - strlen(value)));
				maxLength = strlen(value);

			}
			else
				pStrStart[maxLength - i - 1] = value[i];
		}
		pStrStart[maxLength] = '\0';
	}
	char* BigIntValues::Append(char* array, char a, size_t n)
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
		this->setLength(strlen(ret));
		delete[] array;
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

	char* BigIntValues::Resize(char* array, size_t size)
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

	bool BigIntValues::SubString(char* array_1, char array_2)
	{
		for (int i = 0; i < strlen(array_1); i++)
		{
			if (array_1[i] == array_2)
				return true;
		}
		return false;
	}
#pragma region CharacterString
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
			a->setCharacter(PopBack(a->getCharacter()));
			pStrStart = PopBack(pStrStart);
			*this = *this + a;
			Appen(pStrStart, 1, '-');
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
				Appen(temp.pStrStart, 1, '-');
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
			Appen(pStrStart, m - n, '0');
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
			Appen(pStrStart, 1, t + '0');
		}
		a->setCharacter(pStrStart);
		return *a;
	}
	CharacterString BigIntValues::operator-=(CharacterString* a)
	{
		int n, m;
		bool flag = false;
	
		if (*this < a) {
			Appen(pStrStart, 1, '0');
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
			Appen(pStrStart, 1, '-');
		a->setCharacter(pStrStart);
		return *a;
	}
#pragma endregion
	void BigIntValues::Appen(char*& str, char suffix, size_t number) {
		if (!str || number == 0) {
			return; 
		}
		size_t len = strlen(str);
		char* temp = new char[len + number + 1];
		strcpy(temp, str);
		for (size_t i = 0; i < number; ++i) {
			temp[len + i] = suffix;
		}
		temp[len + number] = '\0';
		delete[] str;
		str = temp;
	}
	BigIntValues operator+=(BigIntValues& a, const BigIntValues& b)
	{
		int divisor = 0, number = 0, i;
		bool flag = false;
		if (a.SubString(a.pStrStart, '-') && a.SubString(b.pStrStart, '-'))
		{
			BigIntValues temp;
			temp = b;
			temp.pStrStart = temp.PopBack(temp.pStrStart);
			a.pStrStart = a.PopBack(a.pStrStart);
			a += temp;
			a.pStrStart = a.Append(a.pStrStart, '-', 1);
			if (a.pStrStart[a.maxLength] == '0')
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
				a.pStrStart = a.Append(a.pStrStart, '-', 1);
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

		if (b.maxLength > a.maxLength) {
			a.pStrStart = a.Append(a.pStrStart, '0',b.maxLength - a.maxLength);
		}
		for (i = 0; i < a.maxLength; i++) {
			int firstTerm = a.pStrStart[i] - '0';
			int secondTerm = b.pStrStart[i] - '0';
			if (i < b.maxLength) {
				number = firstTerm + secondTerm + divisor;
			}
			else
				number = firstTerm + divisor;
			divisor = number / 10;
			a.pStrStart[i] = (number % 10) + '0';
		}
		if (divisor) {
			a.pStrStart = a.Append(a.pStrStart, (divisor + '0'), 1);
		}
		return a;
	}
	BigIntValues operator+(const BigIntValues& a, const BigIntValues& b) {
		BigIntValues temp = a;
		temp += b;
		return temp;
	}
	BigIntValues& operator-=(BigIntValues& a, const BigIntValues& b) {
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
				a.pStrStart = a.Append(a.pStrStart, '-', 1);
			}
			else {
				temp -= a;
				a = temp;
			}
			if (a.pStrStart[a.maxLength] == '0')
				a.pStrStart = a.PopBack(a.pStrStart);
			return a;
		}
		else if (a.SubString(a.pStrStart, '-'))
		{
			a.pStrStart = a.PopBack(a.pStrStart);
			a += b;
			a.Appen(a.pStrStart, 1, '-');
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
			BigIntValues temp;
			temp = b;
			temp -= a;
			temp.pStrStart = temp.Append(temp.pStrStart, '-', 1);
			a = temp;
			return a;
		}
		int i, t = 0, number;
		for (i = 0; i < ((b.maxLength + a.maxLength)/2 + fabs(b.maxLength - a.maxLength) - fabs(b.maxLength - a.maxLength)/2); i++) {

			int firstTerm = a.pStrStart[i] - '0';
			int secondTerm = b.pStrStart[i] - '0';

			if (i < b.maxLength && !flag)
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
		while (a.maxLength > 1 && a.pStrStart[b.maxLength - 1] == '0') {
			a.pStrStart = a.PopBack(a.pStrStart);
			a.maxLength--;
		}
		if (flag)
			a.pStrStart = a.Append(a.pStrStart, '-', 1);
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
		int size = 0;
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
			a.Appen(a.pStrStart, 1, '-');
			return a;
		}
		else if (a.SubString(b.pStrStart, '-'))
		{
			BigIntValues temp;
			temp = b;
			temp.pStrStart = temp.PopBack(temp.pStrStart);
			a *= temp;
			a.Appen(a.pStrStart, 1, '-');
			return a;
		}
		int* array = new int[a.maxLength + b.maxLength]{ 0 };
		for (int i = 0; i < a.maxLength; i++) {
			int firstTerm = a.pStrStart[i] - '0';
			for (int j = 0; j < b.maxLength; j++) {
				int secondTerm = b.pStrStart[j] - '0';
				array[i + j] += (firstTerm) * (secondTerm);
			}
		}
		size = a.maxLength + b.maxLength;
		a.maxLength += b.maxLength;
		char* temp = new char[size + 1] {'\0'};
		for (int number, i = 0, t = 0; i < a.maxLength; i++)
		{
			number = t + array[i];
			array[i] = number % 10;
			t = number / 10;
			temp[i] = array[i] + '0';
		}
		temp[a.maxLength] = '\0';
		for (int i = a.maxLength - 1; i >= 1 && !array[i]; i--)
			temp = a.PopBack(temp);
		a.pStrStart = new char[size] {'\0'};
		strcpy(a.pStrStart, temp);
		return a;
	}
	BigIntValues operator*(const BigIntValues& a, const BigIntValues& b) {
		BigIntValues temp = a;
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
				a = BigIntValues(1);
				return a;
			}
			int lgcat = 0, cc;
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
				a.Appen(a.pStrStart, 1, '-');
				return a;
			}
			else if (a.SubString(b.pStrStart, '-'))
			{
				BigIntValues temp;
				temp = b;
				temp.pStrStart = temp.PopBack(temp.pStrStart);
				a /= temp;
				a.Appen(a.pStrStart, 1, '-');
				return a;
			}
			int i = 0;
			int* array = new int[a.maxLength] { 0 };
			char* str = new char[1] {'\0'};
			BigIntValues t;
			str = t.pStrStart;
			for (i = a.maxLength - 1; t * 10 + (a.pStrStart[i] - '0') < b; i--) {
				t *= 10;
				t += (a.pStrStart[i] - '0');
			}
	
			for (; i >= 0; i--) {
				t = t * 10 + (a.pStrStart[i] - '0');
				for (cc = 9; cc * b > t; cc--);
				t -= cc * b;
				array[lgcat++] = cc;

			}
			t.pStrStart = str;
			char* temp = new char[a.maxLength] {'\0'};
			a.pStrStart = new char[a.maxLength] {'\0'};

			a.pStrStart = a.Resize(a.pStrStart, a.maxLength);
			for (i = 0; i < lgcat; i++)
				temp[i] = (array[lgcat - i - 1] + '0');
			temp = a.Resize(temp,lgcat);
			for (int i = 0; i < strlen(temp); i++)
			{
				a.pStrStart[i] = temp[i];
			}
			return a;
		}
	BigIntValues operator/(const BigIntValues& a, const BigIntValues& b)
	{
		BigIntValues temp = a;
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
	BigIntValues& BigIntValues::operator=(const BigIntValues& a)
	{
		if (this == &a)
			return *this;
		maxLength = a.maxLength;
		pStrStart = new char[maxLength + 1];
		strcpy(pStrStart, a.pStrStart);
		return *this;
	}
#pragma region ComprasionOperators
	bool BigIntValues::operator<(CharacterString* a)
	{
		bool flag = false;
		if (SubString(pStrStart, '-') && SubString(a->getCharacter(), '-'))
			flag = true;
		else if (SubString(pStrStart, '-'))
			return true;
		else if (SubString(a->getCharacter(), '-'))
			return false;
		if (maxLength != a->getLength() && !flag)
			return maxLength < a->getLength();
		while (maxLength--)
			if (flag)
				return pStrStart[maxLength] > a->getCharacter(maxLength);
			else if (pStrStart[maxLength] != a->getCharacter(maxLength))
				return pStrStart[maxLength] < a->getCharacter(maxLength);
		return false;
	}
	bool BigIntValues::operator>(CharacterString* a)
	{
		return !(*this < a);
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
		BigIntValues temp;
		bool flag = false;
		if (temp.SubString(a.pStrStart, '-') && temp.SubString(b.pStrStart, '-'))
			flag = true;
		else if (temp.SubString(a.pStrStart, '-'))
			return true;
		else if (temp.SubString(b.pStrStart, '-'))
			return false;
		if (a.maxLength != b.maxLength && !flag)
			return a.maxLength < b.maxLength;
		int n = a.maxLength;
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
#pragma endregion
#pragma region IOoperators

	std::ostream& operator<<(std::ostream& os, const BigIntValues& so)
	{
		//std::cout << "Max length of string: \n";
		//std::cout << so.maxLength << '\n';
		//std::cout << "String: \n";
		for (int i = strlen(so.pStrStart) - 1; i >= 0; i--) {
			os << so.pStrStart[i];
		}
		return os;
	}

	std::istream& operator>>(std::istream& os, BigIntValues& so)
	{
		std::cout << "Enter the max length of string" << '\n';
		os >> so.maxLength;
		so.setLength(so.maxLength);
		std::cout << "Enter the string: " << '\n';
		os.ignore();
		char* str = new char[256];
		os.getline(str, 256);
		so.setCharacter(str);
		return os;
	}
#pragma endregion