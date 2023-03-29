#include "MyException.h"
#include<iostream>
#pragma warning(disable : 4996)

MyException::MyException(const char* message)
{
	ExceptionInfo = new char[255];
	strcpy(ExceptionInfo, message);
}
MyException::~MyException() {}

void MyException::ShowException() {
	std::cout << "Info about exception: " << ExceptionInfo << '\n';
}