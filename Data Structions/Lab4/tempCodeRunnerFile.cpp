#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;

void InsertSort(int A[],int n){
	for(int i=0;i<n;i++) printf("%d ",A[i]);
	putchar('\n');

	for(int i = 1;i < n; i++){
		int j;
		int tmp = A[i];
		for(j = i;j >= 1; j--){
			if(A[j] < A[j - 1]){
				A[j] = A[j - 1];
			}
			else break;
		}
		A[j] = tmp;
		for(int i=0;i<n;i++) printf("%d ",A[i]);
	putchar('\n');
}
}

void BubbleSort(int A[],int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++) if(A[j] > A[j+1]) swap(A[j],A[j+1]);
}

void SelectionSort(int A[],int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(A[i]>A[j]) swap(A[i],A[j]);
		}
	}
}

void QuickSort(int A[],int l,int r){
	
	int i = l,j = r, x = A[l];

	while(i < j){

		while(i < j && A[j] >= x) j--;
		if(i < j){
			A[i] = A[j];
			i++;
		}
		
		while(i < j && A[i] < x) i++;
		if(i < j){
			A[j] = A[i];
			j--;
		}

	}

	assert(i != j);
	A[i] = x;

	QuickSort(A,l,i-1);
	QuickSort(A,i+1,r);
}

void ShellSort(int A[],int n){
	for(int gap = n; gap > 0; gap /= 2){
		for (int j = gap; j < n; j++)
			if(A[j] < A[j - gap]){
				int temp = A[j];
				int k = j - gap;
				while(k >= 0 && A[k] > temp){// insertion sort
					A[k + gap] = A[k];
					k -= gap;
				}
				A[k + gap] = temp;
			}
	}
}

void mergeArray(int A[], int first, int mid, int last, int temp[]){
	int i = first, j = mid + 1;
	int m = mid, n = last;

	int k = 0;
	while(i <= m && j <= n){
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	while(i <= m)
		temp[k++] = A[i++];
	while(j <= n)
		temp[k++] = A[j++];
	for(int i = 0;i < k; i++){
		A[first + i] = temp[i];
	}
}

void MergeSort(int A[], int first, int last, int temp[]){
	if (first < last){
		int mid = (first + last) / 2;
		MergeSort(A, first, mid, temp);
		MergeSort(A, mid+1, last, temp);
		mergeArray(A, first, mid, last, temp);
	}
}

void MergeSort(int A[],int n){
	int *p = new int[n];
	if(p == nullptr) return;
	MergeSort(A, 0, n - 1, p);
	delete p;
}

void MinHeapFixDown(int a[],int i,int n){
	int j, tmp;

	tmp = a[i];
	j = i * 2 + 1;
	while(j < n){
		if (j + 1 < n && a[j + 1] < a[j])
			j++;
		if (a[j] >= tmp)
			break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = tmp;
}

void HeapSort(int A[], int n){
	for (int i = n / 2 - 1;i >= 0; i--){
		MinHeapFixDown(A, i, n);
	}

	for(int i = n - 1; i >= 1; i--){
		swap(A[i] ,A[0]);
		MinHeapFixDown(A, 0, i);
	}

	int *p = new int[n];
	for (int i = 0;i < n; i++) p[i] = A[n - i - 1];
	for (int i = 0;i < n; i++) A[i] = p[i];
}


bool check(int origin[],int tar[],int n){
	for(int i = 0; i < n; i++) if(origin[i] != tar[i]) return false;
	return true;
}

int main(){
	int n;
	cout << "Input the number of n:";
	cin >> n;
	srand(time(NULL));
	int *arr = new int[n];
	int *tmp = new int[n];
	int *ans = new int[n];
	for(int i = 0;i < n; i++) tmp[i] = arr[i] = rand();
	
	sort(arr, arr+n);
	for(int i = 0;i < n; i++) ans[i] = arr[i];

	int beginTime = clock();
	BubbleSort(arr, n);
	int endTime = clock();
	printf("BubbleSort:%dms\n",endTime - beginTime);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];

	beginTime = clock();
	InsertSort(arr, n);
	endTime = clock();
	printf("InsertSort:%dms\n",endTime - beginTime);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	putchar('\n');
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];
	
	beginTime = clock();
	SelectionSort(arr, n);
	endTime = clock();
	printf("SelectionSort:%dms\n",endTime - beginTime);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];

	beginTime = clock();
	QuickSort(arr, 0, n - 1);
	endTime = clock();
	printf("QuickSort:%dms\n",endTime - beginTime);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];

	beginTime = clock();
	ShellSort(arr, n);
	endTime = clock();
	printf("ShellSort:%dms\n",endTime - beginTime);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];

	beginTime = clock();
	MergeSort(arr, n);
	endTime = clock();
	printf("MergeSort:%dms\n",endTime - beginTime);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];

	beginTime = clock();
	HeapSort(arr, n);
	endTime = clock();
	printf("HeapSort:%dms\n",endTime - beginTime);
	assert(check(arr, ans, n));
	for(int i = 0;i < n; i++) tmp[i] = arr[i];

