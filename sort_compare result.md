# SORT argorithms compare result

### insertion_sort, heap_sort, merge_sort, quick_sort1(first pivot), quick_sort2(random pivot), quick_sort3(median of three)

실제 수행시간은 좀 더 자세히 보기 위해서 chrono를 사용해 시간측정을 하였다. (nanoseconds 단위)

#### + 1000개의 정렬되어있지 않은 input배열
![image](https://user-images.githubusercontent.com/55094745/97655553-b0532900-1aa8-11eb-9408-eb32f7dd7a65.png)
 
 가장 오래걸리고 가장 많은 비교횟수를 차지한 것은 n^2의 시간복잡도를 가진 insertion sort이다. 

#### + 1000개의 정렬되어있는 input 배열
![image](https://user-images.githubusercontent.com/55094745/97655725-16d84700-1aa9-11eb-9fda-e717f87f9401.png)

가장 오래 걸리는 정렬 방법은 quick_sort(ver01): first pivot 이다. 비교횟수도 가장 큰 것을 확인할 수 있다. 반면에 배열이 정렬되어있을때 가장 효율이 좋은 것은 insertion_sort인것을 확인 할 수 있다. 

### 그렇다면 작은 요소들의 input 배열은 어떻게 될까?

#### + 32개의 정렬되어있지 않은 input 배열
