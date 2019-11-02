#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include<iostream>
#include<functional>

#define ROOT 1
#define LEFT(i) (i * 2)
#define RIGHT(i) ( LEFT(i) + 1 )
#define PARENT(i) (i / 2)

//#define DEBUG_V 
//#define DEBUG 

#ifdef DEBUG_V
#define FUNCTION_ENTRY std::cout<<"+++"<<__func__<<"::"<<__LINE__<<std::endl
#define FUNCTION_EXIT std::cout<<"---"<<__func__<<"::"<<__LINE__<<std::endl
#else
#define FUNCTION_ENTRY 
#define FUNCTION_EXIT
#endif

#ifdef DEBUG
#define LOG(m) std::cout<<m<<std::endl
#else
#define LOG(m)
#endif
template<typename T> class Heap
{
    public:
        ~Heap();
        static Heap* build(T *a, int lenght, std::function<bool(T, T)> compare);
        void insert(T a);
        T remove();
        int getSize();
        void sort();
        void print();
    private:
        Heap();
        void heapify(int i);
        void swap(int i, int j);
        int mHeapSize;
        T *mA;
        std::function<bool(T,T)> fpCompare;
};

template<typename T> Heap<T>::Heap() {
    FUNCTION_ENTRY;
    FUNCTION_EXIT;
};
template<typename T> Heap<T>::~Heap() {
    FUNCTION_ENTRY;
    FUNCTION_EXIT;
};
template<typename T> Heap<T>* Heap<T>::build(T *a, int lenght, std::function<bool(T,T)> isEqual)
{
    FUNCTION_ENTRY;
    Heap<T> *heap = new Heap<T>();
    heap->mA = a;
    heap->mHeapSize = lenght;
    heap->fpCompare = isEqual;
    for (int i=heap->mHeapSize/2; i>=ROOT; i--)
        heap->heapify(i);
    FUNCTION_EXIT;
    return heap;

}
template<typename T> void Heap<T>::insert(T a)
{
    FUNCTION_ENTRY;
    mA[mHeapSize+1] = a;
    mHeapSize++;
    int i = mHeapSize;
    while (i >= ROOT)
    {
        if (fpCompare(mA[i], mA[PARENT(i)]))
        {
            swap(i, PARENT(i));
            i = PARENT(i);
        }
        else
        {
            break;
        }
    }
    FUNCTION_EXIT;
}
template<typename T> T Heap<T>::remove()
{
    FUNCTION_ENTRY;
    T item = mA[ROOT];
    if( mHeapSize >= ROOT)
    {
        std::cout<<"removing:"<<item<<std::endl;
        print();
        swap(ROOT, mHeapSize);
        mHeapSize--;
        heapify(ROOT);
    }
    FUNCTION_EXIT;
    return item;
}
template<typename T> int Heap<T>::getSize()
{
    FUNCTION_ENTRY;
    FUNCTION_EXIT;
    return mHeapSize;
}
template<typename T> void Heap<T>::heapify(int i)
{
    FUNCTION_ENTRY;
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;
    if( l <= mHeapSize && fpCompare(mA[l], mA[i]))
        largest = l;
    if( l <= mHeapSize && fpCompare(mA[r], mA[largest]))
        largest = r;
    if( largest != i)
    {
        swap(i, largest);
        heapify(largest);
    }
    FUNCTION_EXIT;
}

template<typename T> void Heap<T>::swap(int i, int j)
{
    FUNCTION_ENTRY;
    T temp = mA[i];
    mA[i] = mA[j];
    mA[j] = temp;
    FUNCTION_EXIT;
}
template<typename T> void Heap<T>::sort()
{
    FUNCTION_ENTRY;
    int length = getSize();
    for(int i= length; i>= 2; i-- )
    {
        remove();
    }
    mHeapSize = length;
    FUNCTION_EXIT;
}
template<typename T> void Heap<T>::print()
{
    for(int i=ROOT; i<=mHeapSize; i++)
        std::cout<<mA[i]<<std::endl;
    std::cout<<std::endl;
}
#endif

