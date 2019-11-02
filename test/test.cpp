#include "HeapSort.h"

int main()
{
    int *array = new int[100000];
    for(int i=0; i < 100000; i++)
        array[i] = 100000-i;
    Heap<int> *heap = Heap<int>::build(array, 9999, [] (int a, int b) { return a < b; });
    for(int i =1; i< 10000; i++)
        std::cout<<array[i]<<std::endl;
    HeapSort<int>::sort(*heap);
    std::cout<<"after sort"<<std::endl;
    for(int i =0; i< 10; i++)
        std::cout<<array[i]<<std::endl;
    return 0;
}
