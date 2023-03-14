#include <omp.h>
#include <iostream>

using namespace std;


void easyTask1() {
	
	int threads_count = 8;

	#pragma omp parallel shared(threads_count) num_threads(threads_count)
	{
		printf("����� %i �� %i Hello World\n", omp_get_thread_num(), threads_count);
	}
}



void easyTask2() {
	int size = 16000;
	int* a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = i + 1;

	float* b = new float[size];
	int threads_count = 8;

	double t1, t2, dt;

	t1 = omp_get_wtime();
	#pragma omp parallel shared(a, b) num_threads(threads_count)
	{
		#pragma omp for ordered //schedule (dynamic, 100) 
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
				b[i] = 0;
			else if (i == size - 1)
				b[i] = size - 1;
			else 
			{
				b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;

				#pragma omp ordered 
					if (i % 500 == 0)
						printf("i:%i b[i] = %f � ������ %i\n", i, b[i], omp_get_thread_num());
			}
		}
	}
	t2 = omp_get_wtime();
	dt = t2 - t1;
	cout << "����� ���������� " << dt << " � " << threads_count << " ��������" << endl;
}



void easyTask4(int threads_count) {
	// ������������� ������
	int size1 = 1500;
	int size2 = 500;
	int** a = new int*[size1];
	for (int i = 0; i < size1; i++) {
		a[i] = new int[size2];
		for (int j = 0; j < size2; j++)
			a[i][j] = i + j;
	}

	int** b = new int* [size2];
	for (int i = 0; i < size2; i++) {
		b[i] = new int[size1];
		for (int j = 0; j < size1; j++)
			b[i][j] = (i + j) * 2;
	}

	int** result = new int* [size1];
	for (int i = 0; i < size1; i++) {
		result[i] = new int[size1];
		for (int j = 0; j < size1; j++)
			result[i][j] = 0;
	}


	// ����� ��������� �������� ������
	cout << "������ ������� " << size1 << "x" << size2 << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "...." << endl;
	cout << endl;

	cout << "������ ������� " << size2 << "x" << size1 << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	cout << "...." << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	// ���������� ������������ ������
	double t1, t2, dt;
	t1 = omp_get_wtime();

	#pragma omp parallel shared(a, b, result) num_threads(threads_count)
	{
		#pragma omp for ordered //schedule (dynamic, 100) 
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size1; j++)
				for (int k = 0; k < size2; k++)
					result[i][j] += a[i][k] * b[k][j];
		}
	}
	t2 = omp_get_wtime();
	dt = t2 - t1;
	cout << "����� ���������� � " << threads_count << " �������� " << dt << endl;
	cout << endl;


	// ����� �����������
	cout << "��������� " << size1 << "x" << size1 << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	cout << "...." << endl;
}