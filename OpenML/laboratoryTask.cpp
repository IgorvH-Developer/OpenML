#include <omp.h>
#include <iostream>

using namespace std;


void laboratoryTaskThreading(int matrSize, bool print_time, int threads_count) {
	float gloabal_max = numeric_limits<float>::min();

	// Инициализация квадратной матрицы
	float** a = new float* [matrSize];
	for (int k1 = 0; k1 < matrSize; k1++) {
		a[k1] = new float[matrSize];
		for (int k2 = 0; k2 < matrSize; k2++) {
			a[k1][k2] = k1 + k2;
			if (print_time)
				cout << a[k1][k2] << " ";
		}
		if (print_time)
			cout << endl;
	}
	if (print_time)
		cout << endl;


	double t1, t2, dt;
	t1 = omp_get_wtime();
	#pragma omp parallel shared(a, gloabal_max) num_threads(threads_count)
	{
		#pragma omp for ordered
		for (int i = 0; i < matrSize; i++)
		{
			float min = numeric_limits<float>::max();
			for (int j = 0; j < matrSize; j++)
				if (a[i][j] < min)
					min = a[i][j];

			if (min > gloabal_max)
				gloabal_max = min;

			if (print_time)
				#pragma omp ordered 
					printf("Минимум в строке %d = %f; поток %i\n", i, min, omp_get_thread_num());
		}
	}
	t2 = omp_get_wtime();
	dt = t2 - t1;
	cout << endl;
	cout << "Время выполнения " << dt << endl;
	cout << endl;


	
	printf("Максимум матрицы = %f\n", gloabal_max);
}



void laboratoryTask(int matrSize, bool print_time) {
	float gloabal_max = numeric_limits<float>::min();

	// Инициализация квадратной матрицы
	float** a = new float* [matrSize];
	for (int k1 = 0; k1 < matrSize; k1++) {
		a[k1] = new float[matrSize];
		for (int k2 = 0; k2 < matrSize; k2++) {
			a[k1][k2] = k1 + k2;
			if (print_time)
				cout << a[k1][k2] << " ";
		}
		if (print_time)
			cout << endl;
	}
	if (print_time)
		cout << endl;



	double t1, t2, dt;
	t1 = omp_get_wtime();
	for (int i = 0; i < matrSize; i++)
	{
		float min = numeric_limits<float>::max();
		for (int j = 0; j < matrSize; j++)
			if (a[i][j] < min)
				min = a[i][j];

		if (min > gloabal_max)
			gloabal_max = min;

		if (print_time)
			printf("Минимум в строке %d = %f; поток %i\n", i, min, omp_get_thread_num());
	}
	t2 = omp_get_wtime();
	dt = t2 - t1;
	cout << endl;
	cout << "Время выполнения " << dt << endl;
	cout << endl;


	printf("Максимум матрицы = %f\n", gloabal_max);
}