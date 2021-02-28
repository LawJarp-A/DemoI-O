#include <stdlib.h>
#include <stdio.h>
#include "a.h"

//Swap function
void swap(long int *a, long int *b) {
  long int t = *a;
  *a = *b;
  *b = t;
}

// Merge Sort
void mergeA(long int a[], long int p, long int q, long int r, long int *num_cmp)
{

    long int n1 = q - p + 1;
    long int n2 = r - q;

    long int L[n1], M[n2];

    for (long int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (long int j = 0; j < n2; j++)
        M[j] = a[q + 1 + j];

    long int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        *num_cmp = *num_cmp + 1;

        if (L[i] <= M[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(long int a[], long int l, long int r, long int *num_cmp)
{
    if (l < r)
    {
        long int m = l + (r - l) / 2;

        mergeSort(a, l, m, num_cmp);
        mergeSort(a, m + 1, r, num_cmp);

        mergeA(a, l, m, r, num_cmp);
    }
}

// Bubble Sort
void bubbleSort(long int a[], long int n, long int *num_cmp)
{
    for (long int i = 0; i < n - 1; i++)
    {
        for (long int j = 0; j < n - 1 - i; j++)
        {
            // printf("%li %li\n", a[j], j);

            *num_cmp = *num_cmp + 1;
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    
}

// Select Sort
void selectionSort(long int a[], long int n, long int *num_cmp)
{
    long int i, j, min;

    for (i = 0; i < n - 1; i++)
    {

        min = i;

        for (j = i + 1; j < n; j++)
            *num_cmp = *num_cmp + 1;
            if (a[j] < a[min])
            {
                min = j;

            }
                

        swap(&a[min], &a[i]);
    }
}

// Quick Sort 

int partition(long int a[], long int l, long int h, long int *num_cmp) {
  
  long int piv = a[h];
  long int i = (l - 1);

  for (long int j = l; j < h; j++) {
    *num_cmp = *num_cmp + 1;
    if (a[j] <= piv) {
      i++;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[i + 1], &a[h]);
  return (i + 1);
}

void quickSort(long int a[], long int l, long int h, long int *num_cmp) {
  if (l < h) {
    
    long int pi = partition(a, l, h, num_cmp);
    
    quickSort(a, l, pi - 1, num_cmp);
    
    quickSort(a, pi + 1, h, num_cmp);
  }
}
