
#include<iostream>
#include"CharacterString.h"
#include "BigIntValues.h"
#pragma warning(disable : 4996)
int main()
{
	//CharacterString obj1;
	//std::cin >> obj1;
	//std::cout << obj1;
	//CharacterString obj2;
	//CharacterString obj3;
	//////CharacterString* obj4 = &obj1;
	//std::cin >> obj2;
	//std::cout << obj2;
	//obj3 = obj1 + obj2;
	//obj3 = obj1 - obj2;
	//std::cout << obj3;
	////std::cout << obj3;
	//std::cout << obj1 * obj2;
	//12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849
//char* str3 = new char[256];
//BigIntValues obj(str);
//BigIntValues obj1(str2);
BigIntValues obj;
BigIntValues obj1;
BigIntValues obj3;
std::cin >> obj;
std::cout << obj << '\n';
std::cin >> obj1;
std::cout << obj1 << '\n';
//obj3 = (obj + obj1);
//obj3 = obj - obj1;
//obj3 = obj * obj1;
obj3 = obj / obj1;
//CharacterString* obj_b = &obj1;
//obj3 = obj + obj_b;
std::cout << obj3;

//if (obj > obj1)
//{	
//	std::cout << "Obj is bigger" << std::endl;
//}
//else if (obj < obj1)
//{
//	std::cout << "Obj1 is bigger" << std::endl;
//}
//else if (obj == obj1)
//{
//	std::cout << "Equal" << std::endl;
//}
return 0;

}