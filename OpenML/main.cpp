#include <omp.h>
#include <iostream>
#include "laboratoryTask.h"
#include "easyTasks.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	int threads_count = 2, size = 3;
	cout << "���������� ������� �������� " << size << endl;
	cout << endl;

	cout << "����������� ���������� � " << threads_count << " ���������" << endl;
	laboratoryTaskThreading(size, false, threads_count);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "���������������� ����������" << endl;
	laboratoryTask(size, false);

	/*cout << "������� ������ ����� 4" << endl;
	cout << endl;
	easyTask4(2);*/

}