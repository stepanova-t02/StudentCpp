#pragma once
#define STACK_H
#include <iostream>
#include <string>
#include <locale>
#include <ctime>
#include <random>


using namespace std;
template <typename T>
class Stack
{
private:
	T* s;
	const int size;
	int top;
public:
	Stack(int maxSize);
	~Stack();
	const T &Peek(int) const;
	inline void push(const T&);
	void printStack();
	inline T pop();
	inline void FUNCTION(int, int);
	string PlayerName1, PlayerName2;
	char win = '-';



	inline int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}


	inline void show_cells() {
		system("cls");

		cout << "Íîìåð êëåòî÷êè:\n" << endl;
		cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << endl;
		cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << endl;
		cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << "\n" << endl;

		cout << "Òåêóùàÿ ñèòóàöèÿ (--- çäåñü ïóñòî):\n" << endl;
		cout << "-" << Peek(0) << "-" << '|' << "-" << Peek(1) << "-" << '|' << "-" << Peek(2) << "-" << endl;
		cout << "-" << Peek(3) << "-" << '|' << "-" << Peek(4) << "-" << '|' << "-" << Peek(5) << "-" << endl;
		cout << "-" << Peek(6) << "-" << '|' << "-" << Peek(7) << "-" << '|' << "-" << Peek(8) << "-" << "\n" << endl;
	}


	inline void make_move(int num)
	{
		setlocale(LC_ALL, "Rus");
		char f;

		if (num == 1) {
			cout << PlayerName1;
			cout << ", ââåäèòå íîìåð ÿ÷åéêè, ÷òîáû ñäåëàòü õîä: ";
			int cell;
			cin >> cell; 
			cout << "\n";
			while (cell > 9 || cell < 1 || Peek(cell - 1) == 'O' || Peek(cell - 1) == 'X')
			{
				cout << "ÂÂÅÄÈÒÅ ÊÎÐÐÅÊÒÍÛÉ (1-9) ÈËÈ ÏÓÑÒÎÉ (---) ÍÎÌÅÐ ÊËÅÒÎ×ÊÈ, ×ÒÎÁÛ ÑÄÅËÀÒÜ ÕÎÄ: ";
				cin >> cell; 
				cout << "\n";
			}
			FUNCTION(cell, 1);
		}
		else
		{
		a:	int number = getRandomNumber(0, 8);
			f = Peek(number);
			if (f == 'X' || f == 'O')
			{
				goto a;
			}

			else {
				FUNCTION(number + 1, 2);
			}
		}
	}

	void result()
	{
		setlocale(LC_ALL, "Rus");
		if (win == 'X')
		{
			cout << PlayerName1 << " ïîáåäèë!  " << endl;

		}
		else if (win == 'O')
		{
			cout << "Êîìïüþòåð ïîáåäèë!  " << PlayerName1 << ", âû ïðîèãðàëè" << endl;
		}
		else
		{
			cout << "ÍÈ×Üß!!!" << endl;
		}
	}

	inline char check()
	{
		if ((Peek(0) == Peek(1) && Peek(0) == Peek(2) && Peek(0) == 'X') || (Peek(0) == Peek(1) && Peek(0) == Peek(2) && Peek(0) == 'O'))
		{
			return Peek(0);
		}	
		else if ((Peek(3) == Peek(4) && Peek(3) == Peek(5) && Peek(3) == 'X') || (Peek(3) == Peek(4) && Peek(3) == Peek(5) && Peek(3) == 'O')) //Âåðòèêàëüíàÿ
		{
			return Peek(3);
		}
		else if ((Peek(6) == Peek(7) && Peek(6) == Peek(8) && Peek(6) == 'X') || (Peek(6) == Peek(7) && Peek(6) == Peek(8) && Peek(6) == 'O')) //Âåðòèêàëüíàÿ
		{
			return Peek(6);
		}
		else if ((Peek(2) == Peek(4) && Peek(4) == Peek(6) && Peek(2) == 'X') || (Peek(0) == Peek(4) && Peek(4) == Peek(8) && Peek(0) == 'X') || (Peek(2) == Peek(4) && Peek(4) == Peek(6) && Peek(2) == 'O') || (Peek(0) == Peek(4) && Peek(4) == Peek(8) && Peek(0) == 'O'))
		{
			return Peek(4); 
		}
		else if ((Peek(0) == Peek(3) && Peek(0) == Peek(6) && Peek(0) == 'X') || (Peek(0) == Peek(3) && Peek(0) == Peek(6) && Peek(0) == 'O'))
		{
			return Peek(0);
		}
		else if ((Peek(1) == Peek(4) && Peek(1) == Peek(7) && Peek(1) == 'X') || (Peek(1) == Peek(4) && Peek(1) == Peek(7) && Peek(1) == 'O'))
		{
			return Peek(1);
		}
		else if ((Peek(2) == Peek(5) && Peek(2) == Peek(8) && Peek(2) == 'X') || (Peek(2) == Peek(5) && Peek(2) == Peek(8) && Peek(2) == 'O'))
		{
			return Peek(2);
		}
		else return '-';
	}
};

template <typename T>
Stack<T>::Stack(int maxSize) : size(maxSize = 10)
{
	s = new T[maxSize];
	top = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] s;
}

template <typename T>
inline void Stack<T>::push(const T& value)
{
	if (top < size)
		s[top++] = value;
}

template <class T>
inline void Stack<T>::printStack()
{
	for (int i = top - 1; i >= 0; i--)
	{
		cout << endl << s[i];
		if (i == 8)
			cout << "     " << "<-- âåðõíèé ýëåìåíò ñòåêà";
	}
}

template <typename T>
inline T Stack<T>::pop()
{
	if (top > 0)
		return s[--top];
}

template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	if (nom <= top)
		return s[nom]; 
}

template <typename T>
inline void Stack<T>::FUNCTION(int k, int num)
{
	char *R = new char[20];
	for (int i = 0; i < 9; i++)
	{
		R[i] = Peek(i);
	}
	if (num == 1)
	{
		R[k - 1] = 'X';
	}
	else
	{
		R[k - 1] = 'O';
	}
	while (top != 0)
	{
		pop();
	}
	for (int i = 0; i < 9; i++)
	{
		push(R[i]);
	}
}
