#include <omp.h>
#include <iostream>
#include "laboratoryTask.h"
#include "easyTasks.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	int threads_count = 2, size = 3;
	cout << "Квадрантая матрица размером " << size << endl;
	cout << endl;

	cout << "Асинхронное вычисление с " << threads_count << " потокками" << endl;
	laboratoryTaskThreading(size, false, threads_count);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Последовательное вычисление" << endl;
	laboratoryTask(size, false);

	/*cout << "Простая задача номер 4" << endl;
	cout << endl;
	easyTask4(2);*/

}