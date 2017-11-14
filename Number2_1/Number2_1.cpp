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
	void Enter(); // ���� �����
	void Show(); // ����� �����
	void Space(); // ������ �������
	void Perimeter(); // ������ ��������� 
	void Height(); // ������ �����
	void Type(); // ��� ������������

};

void Triangle::Enter()// ���� �����
{
	do
	{
		do
		{
			cout << "������� ������� AB " << endl;
			cin >> AB;
			if (AB <= 0)
			{
				cout << "������� ������������ �� ����� ���� ������ ��� ������ 0. ��������� ����." << endl;
			}
		} while (AB <= 0);
		do
		{
			cout << "������� ������� BC " << endl;
			cin >> BC;
			if (BC <= 0)
			{
				cout << "������� ������������ �� ����� ���� ������ ��� ������ 0. ��������� ����." << endl;
			}
		} while (BC <= 0);
		do
		{
			cout << "������� ������� CA " << endl;
			cin >> CA;
			if (CA <= 0)
			{
				cout << "������� ������������ �� ����� ���� ������ ��� ������ 0. ��������� ����." << endl;
			}
		} while (CA <= 0);
		if ((AB + BC <= CA) || (AB + CA <= BC) || (CA + BC <= AB))
		{
			cout << "����� ���� ������ ������ ������������ ����� �������" << endl;
		}
	} while ((AB + BC <= CA) || (AB + CA <= BC) || (CA + BC <= AB));
	angleABC = acos((BC*BC + AB*AB - CA*CA) / (2 * AB*BC));
	angleBCA = acos((BC*BC + CA*CA - AB*AB) / (2 * CA*BC));
	angleCAB = acos((CA*CA + AB*AB - BC*BC) / (2 * AB*CA));
}

void Triangle::Show()// ������ �����
{
	const double rad = 57.2958;
	cout << "������� AB = " << AB << endl;
	cout << "������� BC = " << BC << endl;
	cout << "������� CA = " << CA << endl;
	cout << "���� ABC � �������� = " << rad*angleABC << endl;
	cout << "���� BCA � �������� = " << rad*angleBCA << endl;
	cout << "���� CAB � �������� = " << rad*angleCAB << endl;
}

void Triangle::Space()// ���������� �������
{
	double s = 0;
	cout << "���������� ������� ������������ " << endl;
	s = AB*CA*sin(angleCAB) / 2;
	cout << "������� ������������ = " << s << endl;
}

void Triangle::Perimeter()// ���������� ��������� 
{
	float p = 0;
	cout << "���������� ��������� ������������ " << endl;
	p = AB + BC + CA;
	cout << "�������� ������������ ����� = " << p << endl;
}

void Triangle::Height()// ���������� ����� ������������
{
	double AH = 0, BH = 0, CH = 0;
	cout << "���������� ����� ������������ " << endl;
	AH = abs(CA*sin(angleBCA));
	cout << "������ AH ����� = " << AH << endl;
	BH = abs(AB*sin(angleCAB));
	cout << "������ BH ����� = " << BH << endl;
	CH = abs(BC*sin(angleABC));
	cout << "������ CH ����� = " << CH << endl;
}

void Triangle::Type()//��� ������������
{
	cout << "����������� ���� ������������ " << endl;
	if ((AB == BC) && (AB == CA) && (CA == BC))
	{
		cout << "����������� �������� ��������������" << endl;
	}
	else
		if ((AB == BC) || (BC == CA) || (CA == AB))
		{
			cout << "����������� �������� ��������������" << endl;
		}
		else
		{
			cout << "����������� �������� ��������������" << endl;
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
		cout << " ����  " << endl;
		cout << "1. ���� ������ � ������������" << endl;
		cout << "2. ����� ������ " << endl;
		cout << "3. ������ ������� ������������ " << endl;
		cout << "4. ������ ��������� ������������" << endl;
		cout << "5. ������ ����� ������������ " << endl;
		cout << "6. ����������� ������������ ( ��� ������������ )" << endl;
		cout << "7. ����� " << endl << endl;
		cout << "������� ��� ������� " << endl;
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
		case 7: cout << "�� �������� " << endl; exit(1); break;
		default: cout << "����������� ���� " << endl; break;
		}
		getchar();

	}
}