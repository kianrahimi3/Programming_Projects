#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H


#include <iostream>
using namespace std;

template <class T>
class DSVector {
private:
    int cap = 10;
    int length = 0;
    T* data;

public:
    //Constructor
    DSVector();
    DSVector(const DSVector &copy);
    ~DSVector();

    // = Operator
    DSVector<T> &operator=(const DSVector<T> &vec);

    // [] Operator
    T& operator[](int index);

    //push_back
    void push_back(T tempData);

    //pop_back
    void pop_back();

    //size of vector
    int size();

    //capacity of vector
    int capsize();

    //resize vector
    void resize();

    //== operator
    bool operator==(const DSVector<T> &vec);
};

/* ////////////////////////////////////////////////////////////////// */

template <typename T>
DSVector<T>::DSVector() {
    cap = 10;
    length = 0;
    data = new T[cap];
}

template <typename T>
DSVector<T>::DSVector(const DSVector<T> &copy) {
    cap = copy.cap;
    length = copy.length;

    data = new T[cap];
    for(int i = 0; i < length; i++) {
        data[i] = copy.data[i];
    }
}

template <typename T>
DSVector<T>::~DSVector<T>() {
    //if(length > 0)
    delete[] data;
}

template <typename T>
DSVector<T> & DSVector<T>::operator=(const DSVector<T> &vec) {
    if(data == vec.data)
        return *this;

    cap = vec.cap;
    length = vec.length;
    data = new T[vec.cap];

    for (int i = 0; i < length; i++) {
        data[i] = vec.data[i];
    }
    return *this;

}

template<typename T>
T & DSVector<T>::operator[](int index) {
    if(index >= length)
        throw out_of_range("Bad loc value");
    return data[index];
}

//received online...geeks for geeks
template <typename T>
void DSVector<T>::push_back(T tempData) {
    //try implementing resize()
    data[length] = tempData;
    length++;


    if (length == cap) {
        resize();
    }
}

template <typename T>
void DSVector<T>::pop_back() {
    length--;
}


template <typename T>
int DSVector<T>::size() {
    return length;
}

template <typename T>
int DSVector<T>::capsize() {
    return cap;
}

template <typename T>
void DSVector<T>::resize() {
    int newSize = cap * 2;
    T* newData = new T[newSize];

    for(int i = 0; i < length; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    cap = newSize;
}
/*
template <typename T>
void DSVector<T>::resize(int n) {
    if(n < 0)
        throw length_error("Nope. Size is less than 0");
    else if(n < length) {
        length = n;
        cap = n;
    }
    else if(n < cap) {
        cap = n;
    }
    else {
        T* temp = new T[length];
        for(int i = 0; i < length; i++)
            temp[i] = data[i];
        data = new T[n];
        for(int i = 0; i < length; i++)
            data[i] = temp[i];
        delete[] temp;
    }
}
 */


template <typename T>
bool DSVector<T>::operator==(const DSVector<T> &vec) {
    if(length != vec.length) {
        return false;
    }
    for(int i = 0; i < cap; i++) {
        if(data[i] != vec.data[i]) {
            return false;
        }
    }
    return true;
}

#endif //INC_20F_AUTO_IDX_DSVECTOR_H