#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<chrono>
#include<cstdio>
using namespace std;
using namespace chrono;
int temp;
int insertion_count;
int heap_count;
int merge_count;
int quick_ver01_count;
int quick_ver02_count;
int quick_ver03_count;
static long hold = 1;

/*
	학번 : 201910976
	이름 : 안선정
	
	전체적인 소스 구성 :
		my_srand, my_rand : 난수를 생성하는 rand함수를 구현한 것, 이 파일의 모든 난수는 이 함수로 배정된다. 
		insertion_sort : 삽입정렬을 수행하고 비교 횟수를 센다. 
		heap_sort, heapify : 힙정렬을 수행하고, 비교 횟수를 센다. 
		merge_sort, merge : 합병정렬을 수행하고, 비교 횟수를 센다. 
		quick_sort(ver01, ver02, ver03 ,ver04), partition(ver01, ver02, ver03) : 퀵정렬 (ver01, ver02, ver03)을 수행하고, 비교 횟수를 센다. 
		main : 1024개의 랜덤 원소를 배정하여 insertion_sort, heap_sort, merge_sort, quick_sort 함수를 수행하고, 시간을 측정한다.
	
	전역 변수 :
		temp : 정렬도중 값의 교환이 이루어질때 사용되는 변수이다. 
		insertion_count : 삽입정렬을 하면서 실행하는 key값의 비교 횟수이다.
		merge_count : 합병정렬을 하면서 실행하는 key값의 비교 횟수이다.
		heap_count : 힙정렬을 하면서 실행하는 key값의 비교 횟수이다.
		quick_ver01_count : 퀵정렬 version1을 하면서 실행하는 key값의 비교 횟수이다.
		quick_ver02_count : 퀵정렬 version2를 하면서 실행하는 key값의 비교 횟수이다.
		quick_ver03_count : 퀵정렬 version3을 하면서 실행하는 key값의 비교 횟수이다. 

	코드 진행 방식 : 하나의 배열 arr에 랜덤한 수를 배정하고, 6가지의 정렬을 동일한 배열을 사용하여 정렬하기 위해
	arr을 미리 설정하고, brr에 arr의 원소를 다 복사하며 각각 정렬을 수행한다. 
*/

//===========================================================랜덤함수====================================================

int my_rand()
{
	hold =(((hold * hold)+hold) & 0x7fff); //폰노의만의 중앙 제곱법의 의사 난수가 만들어진 방식에 모티브를 얻어서 조금 변형했음
	return hold; 
}
void my_srand(unsigned int seed) {
	hold = (unsigned long)seed;
}

//=======================================================삽입정렬========================================================
void insertion_sort(int arr[], int n)
{
	int j, i;
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

}
//=====================================================힙정렬===========================================================

void heapify(int arr[], int n, int i) {
	int first = i;
	int left = 2*i+1; //node의 왼쪽 자식노드
	int right = 2*i + 2; //오른쪽 자식노드

	if (left < n && arr[left] > arr[first]) {
		first = left;
		heap_count++; //키값비교
	}

	if (right < n && arr[right] > arr[first]) {
		first = right;
		heap_count++; //키값비교
	}

	if (first != i) { 
		temp = arr[i];
		arr[i] = arr[first];
		arr[first] = arr[i];
		heapify(arr, n, first);
	}
}

void heap_sort(int arr[], int n) {
	
	for (int i = n / 2 - 1; i >= 0; i--) //max_heap을 구현한다. 
		heapify(arr, n, i); //max_heap 성질 유지 함수


	for (int i = n - 1; i >= 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp; //root node(max)를 extract하는 과정
		heapify(arr, i, 0); //max_heap유지
	}
}

//====================================================합병정렬===========================================================

void merge(int arr[], int left, int right, int mid) //합병과정
{
	int first = left; //앞부분 배열의 첫 인덱스
	int second = mid + 1; //뒷부분 배열의 첫 인덱스
	int copy[1024];
	int i = 0;
	
	while (first <= mid && second <= right) 
	{
		merge_count++;
		if (arr[first] <= arr[second])
			copy[i++] = arr[first++];
		else
			copy[i++] = arr[second++];
	}
	if (first > mid)
	{
		while (second <= right)
			copy[i++] = arr[second++];
	}
	else
	{
		while (first <= mid)
			copy[i++] = arr[first++];
	}
	for (int k = 0; k < i; k++)
	{
		arr[k+left] = copy[k];
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


//====================================퀵 정렬 version1(first or last element as pivot)========================================

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

//============================================퀵 정렬 version2==============================================================
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
		quick_sort_ver02(arr, left, pivot - 1);
		quick_sort_ver02(arr, pivot + 1, right);
	}
}


//================================퀵 정렬 version3(median of three partitioning as pivot.)=====================================

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
		quick_sort_ver03(arr, left, pivot - 1);
		quick_sort_ver03(arr, pivot + 1, right);
	}
}
//=====================================================main================================================================
int main(void)
{
	while(true){
		int n;
		int sort;
		cout << "배열의 크기  (1024이하, 0입력시 종료): ";
		cin >> n;
		if (n == 0) break;
		int arr[1025];
		int brr[1025];
		cout << "sorted? (yes : 1, no : 0):";
		cin >> sort;

		if (sort == 0) {
			my_srand((unsigned)time(NULL));
			for (int i = 0; i < n; i++)
			{
				arr[i] = my_rand()%1000;
			}
		}
		else {
			for (int i = 0; i < n; i++)
				arr[i] = i;
		}
		cout << "\t\t비교횟수\t실제시간\n";
		memcpy(brr, arr, sizeof(arr));
		system_clock::time_point tp1 = system_clock::now();
		insertion_sort(brr, n);
		system_clock::time_point tp2 = system_clock::now();
		nanoseconds t = tp2 - tp1;
		printf("insertion sort%10d%15d\n\n", insertion_count, (int)t.count());

		memcpy(brr, arr, sizeof(arr));
		tp1 = system_clock::now();
		heap_sort(brr, n);
		tp2 = system_clock::now();
		t = tp2 - tp1;
		printf("heap sort%15d%15d\n\n", heap_count, (int)t.count());

		memcpy(brr, arr, sizeof(arr));
		tp1 = system_clock::now();
		merge_sort(brr, 0, n - 1);
		tp2 = system_clock::now(); t = tp2 - tp1;
		for (int i = 0; i < n; i++)
			cout << brr[i] << ' ';
		printf("merge sort%14d%15d\n\n", merge_count, (int)t.count());

		memcpy(brr, arr, sizeof(arr));
		tp1 = system_clock::now();
		quick_sort_ver01(brr, 0, n - 1);
		tp2 = system_clock::now(); t = tp2 - tp1;
		printf("quick_ver01%13d%15d\n\n", quick_ver01_count, (int)t.count());

		memcpy(brr, arr, sizeof(arr));
		tp1 = system_clock::now();
		quick_sort_ver02(brr, 0, n - 1);
		tp2 = system_clock::now(); t = tp2 - tp1;
		printf("quick_ver02%13d%15d\n\n", quick_ver02_count, (int)t.count());

		memcpy(brr, arr, sizeof(arr));
		tp1 = system_clock::now();
		quick_sort_ver03(brr, 0, n - 1);
		tp2 = system_clock::now(); t = tp2 - tp1;
		printf("quick_ver03%13d%15d\n\n", quick_ver03_count, (int)t.count());


		insertion_count = 0;
		heap_count = 0;
		merge_count = 0;
		quick_ver01_count = 0;
		quick_ver02_count = 0;
		quick_ver03_count = 0;
		cout << "===========================================================\n";
	}

}