#include "HeapSort.h"

int main()
{
    int *array = new int[100];
    for(int i=0; i < 10; i++)
        array[i] = 10-i;
    Heap<int> *heap = Heap<int>::build(array, 9, [] (int a, int b) { return a < b; });
    for(int i =0; i< 10; i++)
        std::cout<<array[i]<<std::endl;
    //HeapSort<int>::sort(*heap);
    //for(int i =0; i< 10; i++)
      //  std::cout<<array[i]<<std::endl;
    return 0;
}
