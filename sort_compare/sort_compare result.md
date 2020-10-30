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
![image](https://user-images.githubusercontent.com/55094745/97655927-8817fa00-1aa9-11eb-9ee3-4fbd1180fe9a.png)

여기서 가장 빠른 실행시간은 insertion_sort이다. 비교 횟수는 heap_sort가 월등히 적다. 아무래도 insertion_sort가 함수의 재호출이 없어서 적은 input의 개수에서는 시간적 효율이 크다. 


#### + 얻어가는점
생각보다 많은 시간을 들인 작업이었다. 처음에 알고리즘만 따와서 내가 편한대로 짜면 된다라고만 생각하였다. 첫 시도에 정렬의 결과는 잘 나왔지만 실제 시간결과값에서 터무니없는 숫자가 나왔다. merge sort가 큰 input에 대해서 insertion_sort의 10배가 더 걸린다는 결과가 나왔다. 이유가 무엇인지 생각해보다가 내가 merge_sort에 배열이 아닌 내가 편하게 썻던 vector를 사용해서 구현한 탓이었다. 평소에 배열보다 편리해서 vector를 사용했는데 이렇게 시간을 재거나 더 빠른(효율적인)코드를 작성하려면 지원하는 자료구조도 잘 보며 써야한다는 것을 극히 느끼게 된 계기였다. 
