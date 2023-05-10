#include<iostream>
#include"CharacterString.h"
#include "BigIntValues.h"
#include"BigIntArray.h"
#include"MyException.h"
#include"MyIterator.h"
#pragma warning(disable : 4996)

using std::cout; using std::cin;
int main()
{
	CharacterString	firstArg, secondArg, res;
	BigIntValues firstIntArg,secondIntArg,resInt;
	BigIntArray objArr;
	bool flag = true;
	while (flag)
	{
		cout << "@************************************************@\n";
		cout << "| Choose the option you would like to operate:   |\n@************************************************@\n|\t1. Option about strings\t\t         |\n|\t2. Option about Big Int Values\t         |\n|\t3. Options about Array of Big Int Values |\n|\t4. Exit the main program \t\t |\n";
		cout << "@************************************************@\n";
		unsigned int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			bool flag = true, validInput = true;
			cout << "In order to work with these operations you need to fill these strings.\n";
			while (validInput)
			{
				try
				{
					cout << "Fill The First String\n";
					cin >> firstArg;
					cout << "It is your first string: " << firstArg << "Fill the second string\n";
					cin >> secondArg;
					cout << "It is your second string: " << secondArg;
					validInput = false;
				}
				catch (MyException ex)
				{
					ex.ShowException();
					cout << "Try again: \n";
					cin.clear();
				}
			}

			while (flag)
			{
				cout << "@***********************************************@\n";
				cout << "|      \tChoose the next option: \t\t|\n@***********************************************@\n|\t1. Concatenate strings\t\t        |\n|\t2. Substract strings\t\t        |\n|\t3. Search substring in string\t        |\n|\t4. Copy string\t\t\t        |\n|\t5. Rewrite the strings\t\t        |\n|\t6. Show the strings\t\t        |\n|\t7. Return to the main menu\t        |\n";
				cout << "@***********************************************@\n";
				unsigned int choice;
				cout << "Enter your choice: ";
				cin >> choice;
				switch (choice)
				{
				case 1: {
					CharacterString* frstArg = &firstArg;
					res = secondArg + frstArg;
					cout << "The Result of concatenating strings: " << res;
					break;
				}
				case 2: {
					validInput = true;
					while (validInput)
					{
						try {
							res = firstArg - secondArg;
							cout << "The Result of substracting strings: " << res;
							validInput = false;
						}
						catch (MyException ex)
						{
							ex.ShowException();
							cout << "@************************************************@\n";
							cout << "| Choose what you want to do:\t\t         |\n@************************************************@\n|\t1. Rewrite The First String\t         |\n|\t2. Rewrite The Second String\t         |\n|\t3.Return To Menu\t\t         |\n|\t4.Return to the main menu\t         |\n";
							cout << "@************************************************@\n";
							cout << "Enter your choice: ";
							cin >> choice;
							switch (choice) {
							case 1: {
								while (validInput)
								{
									try
									{
										cout << "Fill The First String\n";
										cin >> firstArg;
										cout << "It is your first string: " << firstArg << "\n";
										validInput = false;
									}
									catch (MyException ex)
									{
										ex.ShowException();
										cout << "Try again: \n";
										cin.clear();
									}
								}
								break;
							}
							case 2: {
								while (validInput)
								{
									try
									{
										cout << "Fill The Second String\n";
										cin >> secondArg;
										cout << "It is your Second string: " << secondArg << "\n";
										validInput = false;
									}
									catch (MyException ex)
									{
										ex.ShowException();
										cout << "Try again: \n";
										cin.clear();
									}
								}
								break;
							}
							case 3: {
								validInput = false;
								break;
							}
							case 4: {
								validInput = false;
								flag = false;
								break;
							}
							}
						}
					}
	

					break;
				}
				case 3: {
					cout << "The result of The entry of a substring in a string\n";
					if (firstArg * secondArg == 1)
						cout << "The second string is substring of the first string\n";
					else
						cout << "The second string is not substring of the first string\n";
					break;
				}
				case 4: {
					cout << "@************************************************@\n";
					cout << "| On which base you need to create new string:\t |\n@************************************************@\n|\t1. First string \t\t         |\n|\t2. Second string \t\t         |\n";
					cout << "@************************************************@\n";
					unsigned int choice;
					cout << "Enter your choice: ";
					cin >> choice;
					switch (choice) {
					case 1: {
						CharacterString copyObj(firstArg);
						cout << "Your new copy string: " << copyObj;
						break;
					}
					case 2: {
						CharacterString copyObj(secondArg);
						cout << "Your new copy string: " << copyObj;
						break;
					}
					}
					break;
				}
				case 5: {
					cout << "Fill The First String\n";
						cin >> firstArg;
					cout << "It is your first string: " << firstArg << "Fill the second string\n";
					cin >> secondArg;
					cout << "It is your second string: " << secondArg;
					break;
				}
				case 6:{ 
					cout << "It is your first string: " << firstArg << "\n";
					cout << "It is your second string: " << secondArg;
					break;
				}
				case 7: {
					flag = false;
					break;
				}
				}
			}

			break;
		}
		case 2: {
			bool flag = true, validInput = true;
			cout << "In order to work with these operations you need to fill these Big Int Values.\n";
			while (validInput)
			{
				try
				{
					cout << "Fill The First Big Int Values\n";
					cin >> firstIntArg;
					cout << "It is your first Big Int Value: " << firstIntArg << "Fill the second Big Int Value\n";
					cin >> secondIntArg;
					cout << "It is your second Big Int Value: " << secondIntArg;
					validInput = false;	
				}
				catch (MyException ex)
				{
					ex.ShowException();
					cout << "Try again: \n";
					cin.clear();
				}
			}
			while (flag) {
				cout << "@***********************************************@\n";
				cout << "|      \tChoose the next option: \t\t|\n@***********************************************@\n|\t1. Add Big Int Values\t\t        |\n|\t2. Add Big Int Values Using Late Binding|\n|\t3. Substract Big Int Values\t        |\n|\t4. Multiply Big Int Values\t        |\n|\t5. Divide Big Int Values string\t        |\n|\t6. Compare Big Int Values with '>'      |\n|\t7. Compare Big Int Values with '<'\t\|\n|\t8. Compare Big Int Values with '=='     |\n|\t9. Compare Big Int Values with '!='     |\n|\t10. Compare Big Int Values with '>='    |\n|\t11. Compare Big Int Values with '<='    |\n|\t12. Return to the main menu\t        |\n";
				cout << "@***********************************************@\n";
				unsigned int choice;
				cout << "Enter your choice: ";
				cin >> choice;
				switch (choice) {
				case 1: {
					resInt = firstIntArg + secondIntArg;
					cout << "Your result: " << resInt;
					break;
				}
				case 2: {
					CharacterString* objLtBnd = &secondIntArg;
					resInt = firstIntArg + objLtBnd;
					cout << "Your result: " << resInt;
					break;
				}
				case 3: {
					resInt = firstIntArg - secondIntArg;
					cout << "Your result: " << resInt;
					break;
				}
				case 4: {
					resInt = firstIntArg * secondIntArg;
					cout << "Your result: " << resInt;
					break;
				}
				case 5: {
					validInput = true;
					while (validInput) {
						try {
							resInt = firstIntArg / secondIntArg;
							cout << "Your result: " << resInt;
							validInput = false;
							break;
						}
						catch (MyException ex) {
							ex.ShowException();
							cout << "@************************************************@\n";
							cout << "| Choose what you want to do:\t\t         |\n@************************************************@\n|\t1.Rewrite The Second String\t         |\n|\t2.Return To Menu\t\t         |\n|\t3.Return to the main menu\t         |\n";
							cout << "@************************************************@\n";
							cout << "Enter your choice: ";
							cin >> choice;
							switch (choice) {
							case 1: 
								validInput = true;
								while (validInput)
								{
									try
									{
										cout << "Fill The Second String\n";
										cin >> secondIntArg;
										cout << "It is your Second string: " << secondIntArg << "\n";
										validInput = false;
									}
									catch (MyException ex)
									{
										ex.ShowException();
										cout << "Try again: \n";
										cin.clear();
									}
								}
								break;
							
							case 2: {
								validInput = false;
								break;
							}
							case 3: {
								validInput = false;
								flag = false;
								break;
							}
							}
						}
					}
					break;
				}
				case 6: {
					if (firstIntArg > secondIntArg)
						cout << "The First Big Int Value is bigger\n";
					else
						cout << "The First Big Int Value is not bigger\n";
					break;
				}
				case 7:{
					if (firstIntArg < secondIntArg)
						cout << "The First Big Int Value is less than Second\n";
					else
						cout << "The First Big Int Value is not less than Second\n";
					break;
				}
				case 8: {
					if (firstIntArg == secondIntArg)
						cout << "The First Big Int Value and Second Big Int Value are equal\n";
					else
						cout << "The First Big Int Value and Second Big Int Value are not equal\n";
					break;
				}
				case 9: {
					if (firstIntArg != secondIntArg)
						cout << "The First Big Int Value and Second Big Int Value are not equal\n";
					else
						cout << "The First Big Int Value and Second Big Int Value are equal\n";
					break;
				}
				case 10: {
					if (firstIntArg >= secondIntArg)
						cout << "The First Big Int Value is big or equal to Second Big Int Value\n";
					else
						cout << "The First Big Int Value is not big or equal to Second Big Int Value\n";
					break;
				}
				case 11: {
					if (firstIntArg <= secondIntArg)
						cout << "The First Big Int Value is less or equal to Second Big Int Value\n";
					else
						cout << "The First Big Int Value is not less or equal to Second Big Int Value\n";
					break;
				}
				case 12: {
					flag = false;
					break;
				}
			}
			}
			break;
		}
		case 3: {
			bool flag = true, validInput = true;
			cout << "In order to work with these operations you need to set size of your Array.\n";
			int size = 0;
			while (validInput)
			{
				try
				{
					cout << "Enter the size of array\n";
					cin >> size;
					objArr.SetSizeOfBigIntArray(size);
					validInput = false;
				}
				catch (MyException ex)
				{
					ex.ShowException();
					cout << "Try again: \n";
					cin.clear();
				}
			}
			while (flag) {
				cout << "@************************************************@\n";
				cout << "| Choose the option you would like to operate:   |\n@************************************************@\n|\t1. Fill The Array\t\t         |\n|\t2. Show The Array\t\t         |\n|\t3.Find Sum Of All Elements Of Array      |\n|\t4.Return to the main menu      |\n";
				cout << "@************************************************@\n";
				unsigned int choice;
				cout << "Enter your choice: ";
				cin >> choice;
				switch (choice) {
				case 1: {
					objArr.FillBigIntValueToArray();
					break;
				}
				case 2: {
					objArr.ShowBigIntArray();
					break;
				}
				case 3:
					objArr.SumAllTheElements();
				}
				
			}
			break;
		}
		case 4: {
			flag = false;
			break;
		}
		}

	}
	

	return 0;
}