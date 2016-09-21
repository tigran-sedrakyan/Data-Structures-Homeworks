#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;


class array {
    int *arr;
    int n;
    public:
    array(int*, int);
    void insertion_sort();
    void selection_sort();
    void bubblesort();
    void quicksort(int, int);
    int partit(int, int);
    void merge_sort(int , int);
    void merge(int, int, int);
    void print_array();
};

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
int main()
{
int n;
int *arr;
cout << "Please, enter number of elements to be sorted (just for fun try 10000 or more :) )" << endl;
cin >> n;
arr = new int[n];
cout << "Do you want to enter numbers yourself or you want for computer to generate them?" << endl;
cout << "1.I wanna enter numbers myself (preferable for small number of elements)" << endl << "2.I want for computer to generate them randomly (preferable for big number of elements)"<< endl;
int num;
cin >> num;
if (num == 1) {
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++){
    cin >> arr[i];
}
}
else if (num == 2) {
cout << "From what interval do you want to take random numbers?" << endl << "From ";
int l;
cin >> l;
cout << "To ";
int h;
cin >> h;
for (int i = 0; i < n; i++){
    arr[i] = (rand()%(h-l)) + l;
}
}
else {
    cout << "Error. Enter 1 or 2" << endl;
}

array a(arr, n);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    a.insertion_sort();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration_ins = duration_cast<nanoseconds>( t2 - t1 ).count();
cout << "Insertion Sort:" << endl;
a.print_array();
cout << "Time needed to perform insertion sort is " << duration_ins << " nanoseconds!" << endl;

array b(arr, n);
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    b.selection_sort();
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    auto duration_sel = duration_cast<nanoseconds>( t4 - t3 ).count();
cout << "Selection Sort:" << endl;
b.print_array();
cout << "Time needed to perform selection sort is " << duration_sel << " nanoseconds!" << endl;

array c(arr, n);
    high_resolution_clock::time_point t5 = high_resolution_clock::now();
    c.bubblesort();
    high_resolution_clock::time_point t6 = high_resolution_clock::now();
    auto duration_bubble = duration_cast<nanoseconds>( t6 - t5 ).count();
cout << "Bubble Sort:" << endl;
c.print_array();
cout << "Time needed to perform bubble sort is " << duration_bubble << " nanoseconds!" << endl;

array d(arr, n);
    high_resolution_clock::time_point t7 = high_resolution_clock::now();
    d.merge_sort(0, n-1);
    high_resolution_clock::time_point t8 = high_resolution_clock::now();
    auto duration_merge = duration_cast<nanoseconds>( t8 - t7 ).count();
cout << "Merge Sort:" << endl;
d.print_array();
cout << "Time needed to perform merge sort is " << duration_merge << " nanoseconds!" << endl;

array e(arr, n);
    high_resolution_clock::time_point t9 = high_resolution_clock::now();
    e.quicksort(0, n-1);
    high_resolution_clock::time_point t10 = high_resolution_clock::now();
    auto duration_quick = duration_cast<nanoseconds>( t10 - t9 ).count();
cout << "Quicksort:" << endl;
e.print_array();
cout << "Time needed to perform quicksort is " << duration_quick << " nanoseconds!" << endl;
}

//In collaboration with Gagik Papikyan
//Please note that we've tried to put duration count in in-class functions
//to avoid making int main hardly readable. But  doing it outside of 
//function turned out to be more precise in terms of measuring sorting time.
