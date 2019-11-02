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
    heap->print();
    heap->sort();
    std::cout<<"after sort"<<std::endl;
    heap->print();
    heap->build();
    std::cout<<"after rebuild"<<std::endl;
    heap->print();
    heap->insert(100);
    heap->insert(400);
    heap->insert(2);
    heap->insert(929);
    heap->insert(931);
    heap->insert(932);
    std::cout<<"after insert"<<std::endl;
    heap->print();
    heap->sort();
    std::cout<<"after sort"<<std::endl;
    heap->print();
    return 0;
}
