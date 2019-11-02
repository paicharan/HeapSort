#include "HeapSort.h"
#include <stdlib.h>
int main()
{
    int *array = new int[100000];
    for(int i=1; i <=10; i++)
        array[i] =  (rand()%1000);
    std::cout<<"before build"<<std::endl;
    for(int i =1; i<=10; i++)
        std::cout<<array[i]<<std::endl;
    Heap<int> *heap = Heap<int>::build(array, 10, [] (int a, int b) {  return a > b; });
    std::cout<<"after build"<<std::endl;
    for(int i =1; i<=10; i++)
        std::cout<<array[i]<<std::endl;
    std::cout<<"before sort\n"<<std::endl;
    heap->sort();
    std::cout<<"after sort"<<std::endl;
    for(int i =1; i<=10; i++)
        std::cout<<array[i]<<std::endl;
    return 0;
}
