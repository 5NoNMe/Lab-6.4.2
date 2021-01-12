#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Input(double* a, const int size, int i) {
	cout << "a[" << i << "] = ";
	cin >> a[i];
	if (i < size - 1)
		Input(a, size, i + 1);
	else
		cout << endl;
}

void Print(double* a, const int size, int i)
{
	cout << a[i] << ' ';
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

double indexMax(double* mas, const int size, int k)
{
	if (k == size - 1)
		return k;
	int a = indexMax(mas, size, k + 1);
	return mas[a] > mas[k] ? a : k;
}

double indexMin(double* mas, const int size, int k)
{
	if (k == size - 1)
		return k;
	int a = indexMin(mas, size, k + 1);
	return mas[a] < mas[k] ? a : k;
}


double indexMaxAbs(double* mas, const int size, int k)
{
	if (k == size - 1)
		return k;
	int a = indexMaxAbs(mas, size, k + 1);
	return mas[a] > mas[k] ? a : k;
}

double indexMinAbs(double* mas, const int size, int k)
{
	if (k == size - 1)
		return k;
	int a = indexMinAbs(mas, size, k + 1);
	return abs(mas[a]) < abs(mas[k]) ? a : k;
}


double suma(double* a, int start, int finish)
{
	if (finish - start == 1)
		return 0;
	else
		return a[start + 1] + suma(a, start + 1, finish);
}

double dob(double* a, int start, int finish)
{
	if (finish - start == 1)
		return 1;
	else
		return a[start + 1] * suma(a, start + 1, finish);
}

void Sort(double* a, const int size, int i)
{
	double max = a[i];
	int imax = i;
	for (int j = i + 1; j < size; j++)
		if (max < a[j])
		{
			max = a[j];
			imax = j;
		}
	a[imax] = a[i];
	a[i] = max;

	if (i < size - 2)
		Sort(a, size, i + 1);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int n = 0;
	cout << "Введіть розмір масиву: "; cin >> n;
	double* a = new double[n];

	Input(a, n, 0);
	Print(a, n, 0);

	int start = min(indexMin(a, n, 0), indexMax(a, n, 0));
	int finish = max(indexMin(a, n, 0), indexMax(a, n, 0));

	cout << "Сума елементів між мінімальним і максимальним: " << suma(a, start, finish) << endl;
	cout << "Добуток елементів між мінімальним і максимальним за модулем: " << dob(a, start, finish) << endl;

	cout << "Відсортований масив за спаданням: " << endl;
	Sort(a, n, 0);
	Print(a, n, 0);

	delete[] a;

	return 0;
}