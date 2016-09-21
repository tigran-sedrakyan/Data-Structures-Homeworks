//Some changes possible (though not guaranteed!)
//In collaboration with Gagik Papikyan

//Please note that we've tried to put duration count in in-class sorting functions
//to avoid making int main hardly readable. But  doing it outside of
//function turned out to be more precise in terms of measuring sorting time.


#include <iostream>
#include <cstdlib>
#include <chrono>
#include "array.h"

using namespace std;
using namespace std::chrono;

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
cout << "Array generated: " << endl << "{ ";
for (int i = 0; i < n; i++){
    cout << arr[i] << ", ";
}
cout << "}" << endl << endl;
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
cout << "Time needed to perform insertion sort is " << duration_ins << " nanoseconds!" << endl << endl;

array b(arr, n);
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    b.selection_sort();
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    auto duration_sel = duration_cast<nanoseconds>( t4 - t3 ).count();
cout << "Selection Sort:" << endl;
b.print_array();
cout << "Time needed to perform selection sort is " << duration_sel << " nanoseconds!" << endl << endl;

array c(arr, n);
    high_resolution_clock::time_point t5 = high_resolution_clock::now();
    c.bubblesort();
    high_resolution_clock::time_point t6 = high_resolution_clock::now();
    auto duration_bubble = duration_cast<nanoseconds>( t6 - t5 ).count();
cout << "Bubble Sort:" << endl;
c.print_array();
cout << "Time needed to perform bubble sort is " << duration_bubble << " nanoseconds!" << endl << endl;

array d(arr, n);
    high_resolution_clock::time_point t7 = high_resolution_clock::now();
    d.merge_sort(0, n-1);
    high_resolution_clock::time_point t8 = high_resolution_clock::now();
    auto duration_merge = duration_cast<nanoseconds>( t8 - t7 ).count();
cout << "Merge Sort:" << endl;
d.print_array();
cout << "Time needed to perform merge sort is " << duration_merge << " nanoseconds!" << endl << endl;

array e(arr, n);
    high_resolution_clock::time_point t9 = high_resolution_clock::now();
    e.quicksort(0, n-1);
    high_resolution_clock::time_point t10 = high_resolution_clock::now();
    auto duration_quick = duration_cast<nanoseconds>( t10 - t9 ).count();
cout << "Quicksort:" << endl;
e.print_array();
cout << "Time needed to perform quicksort is " << duration_quick << " nanoseconds!" << endl << endl;
}
