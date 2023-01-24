#include<iostream>
#include"CharacterString.h"
#include "BigIntValues.h"
#pragma warning(disable : 4996)
int main()
{
	//CharacterString obj(10);
	//CharacterString obj1;
	//std::cin >> obj1;
	//std::cout << obj1;
	//CharacterString obj2;
	//CharacterString obj3;
	//std::cin >> obj2;
	//std::cout << obj2;
	/*obj3 = obj1 + obj2;
	std::cout << obj3;*/
	//obj3 = obj1 - obj2;
	//std::cout << obj3;
	//std::cout << obj1 * obj2;
//std::string str3 = "food";
//char* str = new char[12] {"Hello World"};//Hello World
//char* str2 = new char[7] {" Hello"};//Hello
	//12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849
	//12345678910111213141516171819202122232425262728293031323334353637383940414243
char* str = new char[256] { "12345678910111213141516171819202122232425262728293031323334353637383940414244"};//Hello World
char* str2 = new char[256] {"12345678910111213141516171819202122232425262728293031323334353637383940414244"};//Hello
char* str3 = new char[256];
BigIntValues obj(str);
BigIntValues obj1(str2);
BigIntValues obj3;
//obj3 = obj + obj1;
//obj3 = obj - obj1;
//obj3 = obj * obj1;
//obj3 =  obj / obj1;
//std::cout << obj3;
if (obj > obj1)
{
	std::cout << "Obj is bigger" << std::endl;
}
else if (obj < obj1)
{
	std::cout << "Obj1 is bigger" << std::endl;
}
else if (obj == obj1)
{
	std::cout << "Equal" << std::endl;
}
return 0;
}