//删除堆区对象，简化释放内存的代码，替代delete
#ifndef MYDELETE_H
#define MYDELETE_H

template<typename T>
class mD
{
public:
    void mydelete(T*& ptr);
    void mydelete(T*& arr, size_t size);
};

template<class T>
void mD<T>::mydelete(T*& ptr)
{
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}

template<class T>
void mD<T>::mydelete(T*& arr, size_t size)
{
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

#endif
