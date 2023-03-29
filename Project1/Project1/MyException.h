#pragma once
#include<iostream>
class MyException : public std::exception
{
	char* ExceptionInfo;
public:
	MyException(const char* message);
	~MyException();

	void ShowException();
};

