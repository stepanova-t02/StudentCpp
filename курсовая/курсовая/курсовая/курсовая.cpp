#include "pch.h"
#include <iostream>
#include <string>
#include <locale>
#include "Header.h"
using namespace std;




int main()
{
	setlocale(LC_ALL, "Rus");
	Stack <char> Stack(9);

	for (int i = 0; i < 9; i++)
	{
		Stack.push('-');
	}
	cout << "Введите имя игрока: ";
	cin >> Stack.PlayerName1;
	Stack.show_cells();
	for (int move = 1; move <= 9; move++)
	{
		if (move % 2) Stack.make_move(1);
		else {
			srand((unsigned)time(0));
			Stack.make_move(2);
		}
		Stack.show_cells();
		if (move >= 5)
		{
			Stack.win = Stack.check(); 
			if (Stack.win != '-') 
				break; 
		}
	}
	Stack.result();
	Stack.printStack();
	return 0;
}