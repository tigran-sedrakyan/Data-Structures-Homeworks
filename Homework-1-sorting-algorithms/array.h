#ifndef ARRAY_H
#define ARRAY_H


class array
{
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

#endif // ARRAY_H
