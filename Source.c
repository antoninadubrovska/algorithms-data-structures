//Antonina Dubrovska
#include <stdio.h>
#include <stdbool.h>
//1. Попробовать оптимизировать пузырьковую сортировку.Сравнить количество операций сравнения оптимизированной 
//и не оптимизированной программы.Написать функции сортировки, которые возвращают количество операций.

#define MaxN 10
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubbleSortNotOptimized(int arr[], int n)
{
	int i, j;
	int count = 0;
	char stringNum[10];
	for (i = 0; i < n; i++)
		for (j = 0; j < n - 1; j++)
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				count++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	itoa(count, stringNum, 10);
	printf("Number of passes (not optimized): %s\n", stringNum);
	puts("Array after sort not optimized");
}

void bubbleSortOptimized(int arr[], int n)
{
	int i, j;
	bool swapped;
	int count = 0;
	char stringNum[10];
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				count++;
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	itoa(count, stringNum, 10);
	printf("Number of passes (optimized): %s\n", stringNum);
	puts("Array after sort optimized");
}

//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
//Функция возвращает индекс найденного элемента или -1, если элемент не найден.

int binarysearch(int a, int mass[], int n)
{
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mass[middle])
		high = middle - 1;
		else if (a > mass[middle])
		low = middle + 1;
		else
		return middle;
	}
	return -1;
}

void print(int N, int *a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}
int main(int argc, char *argv[]) {
	int a[MaxN];
	int N;
	int index;
	char stringNum[10];
	FILE *in;
	in = fopen("c:\\temp\\data.txt", "r");
	fscanf(in, "%i", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		fscanf(in, "%i", &a[i]);
	}
	fclose(in);
	puts("Array before sort");
	print(N, a);

	bubbleSortNotOptimized(a, N);
	print(N, a);

	bubbleSortOptimized(a, N);
	print(N, a);

	printf("Enter a search element from 0 to 9: \n");
	scanf("%d", &index);

	index = binarysearch(index, a, 10);
	
	itoa(index, stringNum, 10);
	printf("Index of found element from the sorted array returned by the previous task: %s\n", stringNum);
	getch();
	return 0;
}
