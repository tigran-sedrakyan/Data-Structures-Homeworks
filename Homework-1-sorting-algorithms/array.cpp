#include "array.h"
#include <iostream>
#include <string>
using namespace std;

array::array(int *a, int num) {
    n = num;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
    arr[i] = a[i];
    }
}

void array::insertion_sort() {
    for (int j = 1; j < n; j++) {
         int key = arr[j];
         int i =  j - 1;
         while (i >= 0 && arr[i] > key) {
              arr[i+1] = arr[i];
              i--;
              arr[i+1] = key;
        }
    }
}

void array::bubblesort() {
    for (int j=0; j < n; j++) {
        for (int i = j+1; i < n; i++) {
            if (arr[i] < arr[j])
              {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
              }
}
}
}

void array::selection_sort() {
for (int j=0; j < n-1; j++) {
  int min = j;
    for (int i = j+1; i<n; i++) {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
        int tmp = arr[min];
        arr[min] = arr[j];
        arr[j] = tmp;

      }
}

void array::merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l+i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m+j+1];
    }
    int i = 0;
    int j = 0;
    int k = l;
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
        while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void array::merge_sort(int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        merge_sort(l, m);
        merge_sort(m+1, r);

        merge(l, m, r);
    }
}

void array::quicksort(int p, int r) {
    if ( p < r ) {
    int q = partit(p,r);
    quicksort(p, q-1);
    quicksort(q + 1, r);
    }

}

int array::partit(int p, int r) {
    int pivot = arr[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if( arr[j] <= pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
}
        int temp = arr[i+1];
        arr[i+1] = arr[r];
        arr[r] = temp;
        return i+1;
}

void array::print_array(){
cout << "{ ";
for (int i = 0; i < n; i++){
    if (i != n-1) {
    cout << arr[i] << ", ";
    }else
    {
    cout << arr[i] << " }";
    }
}
cout << endl;
}
