

#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;


//Bubble Sort
void bubble_sort (int arr[], int n)
 {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (arr[j] > arr[j + 1])
     {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
  }

void test_bubble_sort(){
	  int input_ar[] = {10, 50, 21, 2, 6, 66, 802, 75, 24, 170};
	  int n = sizeof (input_ar) / sizeof (input_ar[0]);
	  bubble_sort (input_ar, n);
	  cout << "Sorted Array : " << endl;
	  for (int i = 0; i < n; ++i)
	    cout << input_ar[i] << " ";
}

//selection sort
//http://cforbeginners.com/ssort.html
void selectSort(int arr[], int n)
{
//pos_min is short for position of min
	int pos_min,temp;

	for (int i=0; i < n-1; i++)
	{
	    pos_min = i;//set pos_min to the current index of array

		for (int j=i+1; j < n; j++)
		{

		if (arr[j] < arr[pos_min])
                   pos_min=j;
	//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}

	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos_min != i)
            {
                 temp = arr[i];
                 arr[i] = arr[pos_min];
                 arr[pos_min] = temp;
            }
	}
}

void test_selection_sort(){
	  int input_ar[] = {10, 50, 21, 2, 6, 66, 802, 75, 24, 170};
	  int n = sizeof (input_ar) / sizeof (input_ar[0]);
	  selectSort (input_ar, n);
	  cout << "Sorted Array : " << endl;
	  for (int i = 0; i < n; ++i)
	    cout << input_ar[i] << " ";
}

// insertion sort
//http://cforbeginners.com/insertionsort.html
void insertion_sort (int arr[], int length){
	 	int j, temp;

	for (int i = 0; i < length; i++){
		j = i;

		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
}

void test_insertion_sort(){
	  int input_ar[] = {10, 50, 21, 2, 6, 66, 802, 75, 24, 170};
	  int n = sizeof (input_ar) / sizeof (input_ar[0]);
	  insertion_sort (input_ar, n);
	  cout << "Sorted Array : " << endl;
	  for (int i = 0; i < n; ++i)
	    cout << input_ar[i] << " ";
}

// merge sort
// http://quiz.geeksforgeeks.org/merge-sort/

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
void test_merge_sort()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nMerge Sorted array is \n");
    printArray(arr, arr_size);
}

//quick sort
//http://www.algolist.net/Algorithms/Sorting/Quicksort
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
/* Driver program to test above functions */
void test_quick_sort()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    quickSort(arr, 0, arr_size - 1);

    printf("\nQuick Sorted array is \n");
    printArray(arr, arr_size);
}

//Heap Sort
//http://quiz.geeksforgeeks.org/heap-sort/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Driver program
void test_heap_sort()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Heap Sorted array is \n";
    printArray(arr, n);
}


//fibonacci
void fibo1()
{
   int n, c, first = 0, second = 1, next;

   n = 10;

   cout << "First " << n << " terms of Fibonacci series are :- " << endl;

   for ( c = 0 ; c < n ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      cout << next << endl;
   }
}

int fibo2(int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fibo2(x-1)+fibo2(x-2);
}

int main()
{

	  /*
	  test_bubble_sort();
	  test_selection_sort();
	  test_insertion_sort();
	  test_merge_sort();
	  test_quick_sort();
	  test_heap_sort();
      */

	  fibo1(); //10 numbers
	  cout << endl << "fibo2" << fibo2(10) << endl;  //11 numbers



	  return 0;
}
