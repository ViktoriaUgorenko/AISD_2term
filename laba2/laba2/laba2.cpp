﻿#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	int N, N1, maxSteps=1, result, order = 1, first=0;
	bool answer = 0;

	cout << "Введите N(диапазон от 1 до N) и загадайте число X: ";
	cin >> N;

	if(N == 0)
	{
		cout << "Данное значение невозможно.";
		return 0;
	}

	N1 = N;

	while (N1 / 2 > 0)
	{
		N1 = N1/ 2;
		maxSteps++;
	}

	int* array = new int[maxSteps];

	int minValue = 1, maxValue = N;
	
	if (N % 2 == 0) {
		result = N / 2;
	}
	else {
		result = (N + 1) / 2;
	}


	while (!answer)
	{
		
		
		cout << "\nВаше загаданное число равно: " << result;
		cout << "\nНажмите 1, если число угадано верно";
		cout << "\nНажмите 2, если загаданное число меньше";
		cout << "\nНажмите 3, если загаданное число больше\n";

		while (first != 1)
		{
			array[0] = result;
			first++;
		}
			
		
		
		int choice;
		cin >> choice;


		switch (choice)
		{
		case 1:
			
			cout << "Максимальное количество шагов равно: " << maxSteps << "\n";
			cout << "Промежуточные шаги: ";
			for (int i = 0; i < order; i++)    
			{
				cout << array[i] << ' ';
			}
			answer = 1;
			break;

		case 2: //если меньше
			maxValue = result;
			result = (maxValue + minValue) / 2;
			for (int i = order; i < order+1; i++)
			{
				array[i] = result;
			}
			order++;
			break;

		case 3: //если больше
			minValue = result;
			if ((maxValue + minValue) % 2 == 0) {
				result = (maxValue + minValue) / 2;
			}
			if ((maxValue + minValue) % 2 == 1) {
				result = ((maxValue + minValue) / 2) + 1;
			}
			for (int i = order; i < order + 1; i++)
			{
				array[i] = result;
			}
			order++;
			break;

		default:
			cout << "Введено неверное значение.\n";
			break;
		}

	}
	return 0;
}
