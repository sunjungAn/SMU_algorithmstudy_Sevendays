#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
int temp;
int insertion_count;
int merge_count;
int quick_ver01_count;
int quick_ver02_count;
int quick_ver03_count = 0;
static long holdrand = 1L;
/*
	학번 : 201910976
	이름 : 안선정
	
	전체적인 소스 구성 :
		insertion_sort : 삽입정렬을 수행하는 기능과 시간, 비교 횟수를 세고 졍렬된 배열을 출력하는 함수
		heap_sort : 힙정렬을 수행하는 기능과 시간, 비교 횟수를 세고 정렬된 배열을 출력
		merge_sort : 합병정렬을 수행하는 기능과 시간, 비교 횟수를 세고 정렬된 배열을 출력
		quick_sort(ver01, ver02, ver03 ,ver04) : 퀵정렬을 수행하는 기능과 시간, 비교 횟수를 세고 정렬된 배열을 출력
		main : 1024개의 랜덤 원소를 배정하여 insertion_sort, heap_sort, merge_sort, quick_sort 함수를 수행한다.
		
*/
//=====================================랜덤함수====================================================

void my_srand(unsigned int seed) {
	holdrand = (long)seed;
}

int my_rand() {
	return (((holdrand = holdrand * 214013L + 2531011L) >> 16) & 0x7fff);
}

//====================================삽입정렬========================================================
void insertion_sort(int arr[], int n)
{
	int j, i;
	clock_t start = clock();
	for (i = 1; i < n; i++) //1번째 요소는 이미 정렬되어있다고 생각하고 2번째 인자부터 정렬을 시작한다.
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) //바로 전의 요소부터 맨처음 요소까지 비교하여 위치를 찾는다. 
		{
			insertion_count++;
			if (temp < arr[j])
				arr[j + 1] = arr[j]; //값을 한칸씩 미룬다.
			else
				break;
		}
			arr[j + 1] = temp;
	}

	//printf("insertion sort의 시간: %0.5f\n", (float)(clock() - start) / CLOCKS_PER_SEC);


}


//==================================합병정렬==============================================

void merge(int arr[], int left, int right, int mid) //합병과정
{
	int first = left; //앞부분 배열의 첫 인덱스
	int second = mid + 1; //뒷부분 배열의 첫 인덱스
	vector <int> v;
	
	while (first <= mid && second <= right) 
	{
		merge_count++;
		if (arr[first] <= arr[second])
			v.push_back(arr[first++]);
		else 
			v.push_back(arr[second++]);
	}
	if (first > mid)
	{
		while (second <= right)
			v.push_back(arr[second++]);
	}
	else
	{
		while (first <= mid)
			v.push_back(arr[first++]);
	}
	for (int i = 0; i < v.size(); i++)
	{
		arr[i+left] = v[i];
	}
}

void merge_sort(int arr[], int left, int right) 
{
	if (left < right) //배열의 크기가 1이상
	{
		merge_sort(arr, left, (left + right) / 2); 
		merge_sort(arr, (left+right)/2+1, right);//두 부분으로 나눈다.

		merge(arr, left, right, (left+right) / 2); //합친다. 
	}
}


//======================퀵 정렬 version1(first or last element as pivot)=======================

int partition_ver01(int arr[], int left, int right)
{
	int pivot = arr[left]; //first element as pivot
	int low = left + 1, high = right;
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right) {
			quick_ver01_count++;
			low++;
		}
		while (pivot <= arr[high] && high >= (left + 1)) {
			quick_ver01_count++;
			high--;
		}

		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp; // 피벗 위치 바꿈

	return high; //피벗 위치 
}

void quick_sort_ver01(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = partition_ver01(arr, left, right);
		quick_sort_ver01(arr, left, pivot - 1);
		quick_sort_ver01(arr, pivot + 1, right);
	}

}

//=====================퀵 정렬 version2========================
int partition_ver02(int arr[], int left, int right)
{
	my_srand((unsigned)time(NULL));
	int p = my_rand() % (right - left + 1) + left;
	int pivot = arr[p];

	int temp = arr[p]; //피봇 위치를 가장 왼쪽으로 
	arr[p] = arr[left];
	arr[left] = temp;

	int low = left + 1, high = right;
	while (low <= high)
	{

		while (pivot >= arr[low] && low <= right) {
			low++;
			quick_ver02_count++;
		}
		while (pivot <= arr[high] && high >= (left + 1)) {
			high--;
			quick_ver02_count++;
		}
		
		if (low <= high) 
		{
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp; // 피벗 위치 바꿈

	return high; //피벗 위치 
}

void quick_sort_ver02(int arr[], int left, int right)
{	
	if (left <= right)
	{
		int pivot = partition_ver02(arr, left, right);
		quick_sort_ver01(arr, left, pivot - 1);
		quick_sort_ver01(arr, pivot + 1, right);
	}
}


//======================퀵 정렬 version3(median of three partitioning as pivot.)=======================

int partition_ver03(int arr[], int left, int right)
{
	int p; //pivot index
	quick_ver03_count += 2;
	if (arr[left] < arr[right] && arr[right] < arr[(left + right) / 2])
		p = right;
	else if (arr[left] < arr[(left + right) / 2] && arr[(left + right) / 2] < arr[right])
		p = (left + right) / 2;
	else p = left;

	int pivot = arr[p];
	
	int temp = arr[p]; //피봇 위치를 가장 왼쪽으로 
	arr[p] = arr[left];
	arr[left] = temp; 

	int low = left + 1, high = right;
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right) {
			low++;
			quick_ver03_count++;
		}
		while (pivot <= arr[high] && high >= (left + 1)) {
			high--;
			quick_ver03_count++;
		}

		if (low <= high)
		{
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp; // 피벗 위치 바꿈

	return high; //피벗 위치 
}

void quick_sort_ver03(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = partition_ver03(arr, left, right);
		quick_sort_ver01(arr, left, pivot - 1);
		quick_sort_ver01(arr, pivot + 1, right);
	}
}
//==================================main==================================================
int main(void)
{
	int arr[1024];
	my_srand((unsigned)time(NULL));
	for (int i = 0; i < 1024; i++)
	{
		arr[i] = my_rand()%1000;
		cout << arr[i] << " ";
	}
	int brr[1024], crr[1024], drr[1024], err[1024];
	memcpy(brr, arr, sizeof(arr));
	memcpy(drr, arr, sizeof(arr));
	memcpy(err, arr, sizeof(arr));
	memcpy(crr, arr, sizeof(arr));
	insertion_sort(arr, 1024);
	cout << "insertion_sort의 비교횟수: " << insertion_count;
	merge_sort(brr, 0, 1023);
	cout << "merge_sort의 비교횟수: " << merge_count << '\n';

	quick_sort_ver01(crr, 0, 1023);
	cout << "quicksort_ver01의 비교횟수: " << quick_ver01_count;
	quick_sort_ver02(drr, 0, 1023);
	cout << "quicksort_ver02의 비교횟수: " << quick_ver02_count << '\n';
	quick_sort_ver03(err, 0, 1023);
	cout << "quicksort_ver03의 비교횟수: " << quick_ver03_count<<'\n';
}