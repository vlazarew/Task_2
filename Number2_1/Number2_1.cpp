#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
class Triangle
{
private:
	float AB;
	float BC;
	float CA;
	double angleCAB;
	double angleABC;
	double angleBCA;
public:
	Triangle() { AB = 0; BC = 0; CA = 0; };
	void Enter(); // Ввод полей
	void Show(); // Вывод полей
	void Space(); // Расчет площади
	void Perimeter(); // Расчет периметра 
	void Height(); // Расчет высот
	void Type(); // Тип треугольника

};

void Triangle::Enter()// Ввод полей
{
	do
	{
		do
		{
			cout << "Введите сторону AB " << endl;
			cin >> AB;
			if (AB <= 0)
			{
				cout << "Сторона треугольника не может быть равной или меньше 0. Повторите ввод." << endl;
			}
		} while (AB <= 0);
		do
		{
			cout << "Введите сторону BC " << endl;
			cin >> BC;
			if (BC <= 0)
			{
				cout << "Сторона треугольника не может быть равной или меньше 0. Повторите ввод." << endl;
			}
		} while (BC <= 0);
		do
		{
			cout << "Введите сторону CA " << endl;
			cin >> CA;
			if (CA <= 0)
			{
				cout << "Сторона треугольника не может быть равной или меньше 0. Повторите ввод." << endl;
			}
		} while (CA <= 0);
		if ((AB + BC <= CA) || (AB + CA <= BC) || (CA + BC <= AB))
		{
			cout << "Сумма двух сторон должна превосходить длину третьей" << endl;
		}
	} while ((AB + BC <= CA) || (AB + CA <= BC) || (CA + BC <= AB));
	angleABC = acos((BC*BC + AB*AB - CA*CA) / (2 * AB*BC));
	angleBCA = acos((BC*BC + CA*CA - AB*AB) / (2 * CA*BC));
	angleCAB = acos((CA*CA + AB*AB - BC*BC) / (2 * AB*CA));
}

void Triangle::Show()// Печать полей
{
	const double rad = 57.2958;
	cout << "Сторона AB = " << AB << endl;
	cout << "Сторона BC = " << BC << endl;
	cout << "Сторона CA = " << CA << endl;
	cout << "Угол ABC в градусах = " << rad*angleABC << endl;
	cout << "Угол BCA в градусах = " << rad*angleBCA << endl;
	cout << "Угол CAB в градусах = " << rad*angleCAB << endl;
}

void Triangle::Space()// Вычисление площади
{
	double s = 0;
	cout << "Вычисление площади треугольника " << endl;
	s = AB*CA*sin(angleCAB) / 2;
	cout << "Площадь треугольника = " << s << endl;
}

void Triangle::Perimeter()// Вычисление периметра 
{
	float p = 0;
	cout << "Вычисление периметра треугольника " << endl;
	p = AB + BC + CA;
	cout << "Периметр треугольника равен = " << p << endl;
}

void Triangle::Height()// Вычисление высот треугольника
{
	double AH = 0, BH = 0, CH = 0;
	cout << "Вычисление высот треугольника " << endl;
	AH = abs(CA*sin(angleBCA));
	cout << "Высота AH равна = " << AH << endl;
	BH = abs(AB*sin(angleCAB));
	cout << "Высота BH равна = " << BH << endl;
	CH = abs(BC*sin(angleABC));
	cout << "Высота CH равна = " << CH << endl;
}

void Triangle::Type()//Тип треугольника
{
	cout << "Опознование типа треугольника " << endl;
	if ((AB == BC) && (AB == CA) && (CA == BC))
	{
		cout << "Треугольник является равносторонним" << endl;
	}
	else
		if ((AB == BC) || (BC == CA) || (CA == AB))
		{
			cout << "Треугольник является равнобедренным" << endl;
		}
		else
		{
			cout << "Треугольник является разносторонним" << endl;
		}
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Triangle tr;
	int number;

	for (; ;)
	{
		cout << " Меню  " << endl;
		cout << "1. Ввод данных о треугольнике" << endl;
		cout << "2. Вывод данных " << endl;
		cout << "3. Расчет площади треугольника " << endl;
		cout << "4. Расчет периметра треугольника" << endl;
		cout << "5. Расчет высот треугольника " << endl;
		cout << "6. Опознование треугольника ( тип треугольника )" << endl;
		cout << "7. Выход " << endl << endl;
		cout << "Введите ваш вариант " << endl;
		cin >> number;
		cout << endl << endl;
		switch (number)
		{
		case 1: tr.Enter(); break;
		case 2: tr.Show(); break;
		case 3: tr.Space(); break;
		case 4: tr.Perimeter(); break;
		case 5: tr.Height(); break;
		case 6: tr.Type(); break;
		case 7: cout << "До свидания " << endl; exit(1); break;
		default: cout << "Некорретный ввод " << endl; break;
		}
		getchar();

	}
}