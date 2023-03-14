# Отчёт по лабораторной работе openMP. Задача разработки программы для поиска максимального значения среди минимальных элементов строк матрицы (номер 5).


При решении будут рассматриваться квадратные матрицы. Чтобы сравнить эффективности линейного и асинхронного методов решений, будут варьироваться размеры матрицы.
1. Случай матрицы размера 3
* 8 потоков
![image](https://user-images.githubusercontent.com/58008126/225086253-5f0366e2-b194-459b-a4a5-42372f6b6afc.png)

* 4 потока
![image](https://user-images.githubusercontent.com/58008126/225086400-63a6bb28-dd1c-4d8a-900e-aafa8364ffae.png)

* 2 потока
![image](https://user-images.githubusercontent.com/58008126/225086472-f3146004-b636-4335-a6ca-c83163b26177.png)


2. Случай матрицы размера 300
* 8 потоков
![image](https://user-images.githubusercontent.com/58008126/225085716-ed4f2270-5bcd-41c9-a8a6-7e89d58088f4.png)

* 4 потока
![image](https://user-images.githubusercontent.com/58008126/225085940-28113475-8537-491c-8cb1-b6e92c8552f6.png)

* 2 потока 
![image](https://user-images.githubusercontent.com/58008126/225086118-7ed4ab09-3bce-4e51-8b7e-b84a0f488594.png)


3. Случай матрицы размера 40000
* 8 потоков
![image](https://user-images.githubusercontent.com/58008126/225085454-54fce95a-9ae0-49a0-9f88-66237aa501f8.png)

* 4 потока
![image](https://user-images.githubusercontent.com/58008126/225084567-954aa35a-749c-44e2-8753-823853dcfa63.png)

* 2 потока
![image](https://user-images.githubusercontent.com/58008126/225084091-e6a7a141-35a2-4a05-818a-7e3c35691552.png)




Вывод: при небольшом объёме работы асинхронное выполнение кода только увеличивает время его работы по сравнению с последовательным выполнением. Должно быть это связано с тем, что время затраченное на создание нескольких потоков превышает время, которые выигрывается многопотоковым выполнением кода у последовательного выполнения.
       Поэтому асинхронность стоит использовать только тогда, когда нужно выполнить большой объём работы, в этом случае выигрыш по времени, который мы получим при многопотоковом выполнение превысит временные затраты на обработку этих самых потоков.
