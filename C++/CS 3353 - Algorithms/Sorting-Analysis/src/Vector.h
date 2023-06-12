#include "iostream"

using namespace std;

///Received help from GeeksForGeeks

template <typename T>
class Vector {
private:
    T* arr;
    int length;
    int capacity;

public:
    explicit Vector(int = 10);

    int push_back(T);
    T pop_back();
    int size() const;

    T& operator[](int);

    class forward_iterator
            {
    private:
        T* ptr;
    public:
        explicit forward_iterator
        () : ptr(nullptr) {}
        explicit forward_iterator
        (T* pt) : ptr(pt) {}
        forward_iterator(const forward_iterator& i) {
            ptr = i.ptr;
        }

        friend bool operator==(const forward_iterator
        & a, const forward_iterator
        & b) {
            return a.ptr == b.ptr;
        }

        friend bool operator!=(const forward_iterator
        & a, const forward_iterator
        & b){
            return a.ptr != b.ptr;
        }

        T& operator*() {
            return *ptr;
        }
        T* operator->() {
            return ptr;
        }

        T operator=(const T& rhs) const {
            return ptr = rhs;
        }

        forward_iterator
        & operator++() {
            ptr++;
            return *this;
        }

        forward_iterator
        operator++(int) {
            forward_iterator
            temp = *this;
            ++(*this);
            return temp;
        }

    };

    /// Begin and End forward_iterator

    forward_iterator forward_begin() {
        return forward_iterator
        (  &arr[0] );
    };
    forward_iterator forward_end() {
        return forward_iterator
       // ( &arr[capacity] );
                (arr + length );
    };

    /*
    /// Find the first occurence of the data
    /// Else return the last element
    forward_iterator find(forward_iterator begin, forward_iterator end, T data) {
        forward_iterator it;

        bool found = false;
        for(it = begin; it != end; it++) {
            if(*it == data) {
                found = true;
                return it;
            }
        }
        if(found == false)
            return end;
    }
*/




    class random_access_iterator {
    private:
        T* ptr;
    public:

        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = unsigned long long;

         random_access_iterator() : ptr(nullptr) {}
         random_access_iterator(T* pt) : ptr(pt) {}
      //   random_access_iterator(const random_access_iterator& i) {
      //      ptr = i.ptr;
      //  }

        friend bool operator==(const random_access_iterator& a, const random_access_iterator& b) {
            return a.ptr == b.ptr;
        }
        friend bool operator!=(const random_access_iterator& a, const random_access_iterator& b) {
            return a.ptr != b.ptr;
        }
        friend bool operator<=(const random_access_iterator& a, const random_access_iterator& b) {
            return a.ptr <= b.ptr;
        }
        friend bool operator<(const random_access_iterator& a, const random_access_iterator& b) {
            return a.ptr < b.ptr;
        }
        friend bool operator>=(const random_access_iterator& a, const random_access_iterator& b) {
            return a.ptr >= b.ptr;
        }
        friend bool operator>(const random_access_iterator& a, const random_access_iterator& b) {
            return a.ptr > b.ptr;
        }

        random_access_iterator& operator+=(int num) {
            ptr += num;
            return *this;
        }
        random_access_iterator& operator-=(int num) {
            ptr -= num;
            return *this;
        }
        /*
        random_access_iterator operator+(int num) const {
            random_access_iterator temp = *this;
            return temp += num;
        }
        random_access_iterator operator-(int num) const {
            random_access_iterator temp = *this;
            return temp -= num;
        }

        T& operator[](int num) {
             return *(ptr + num);
         }
*/

         random_access_iterator operator+(const difference_type& diff) const {
            return random_access_iterator(ptr + diff);
        }
        random_access_iterator operator-(const difference_type& diff) const {
            return random_access_iterator(ptr - diff);
        }

         reference operator*() const {
             return *ptr;
         }
         pointer operator->() const {
             return ptr;
         }
         reference operator[](const difference_type& index) {
             return *(*this + index);
         }

/*
        T& operator*() {
            return *ptr;
        }
        T&operator->() {
            return ptr;
        }
*/
        T operator=(const T& rhs) const {
            return ptr = rhs;
        }

        random_access_iterator& operator++() {
            ++ptr;
            return *this;
        }
        random_access_iterator& operator++(int) {
            random_access_iterator temp = *this;
            ++(*this);
            return temp;
        }

        random_access_iterator& operator--() {
            --ptr;
            return *this;
        }
        random_access_iterator& operator--(int) {
            random_access_iterator temp = *this;
            --(*this);
            return temp;
        }
        difference_type operator-(const random_access_iterator& it) const {
             return this->ptr - it.ptr;
         }



    };



    random_access_iterator random_begin() {
        return random_access_iterator( &arr[0] );
    }
    random_access_iterator random_end() {
        return random_access_iterator( (arr + length ) );
    }




};

///Would not work int cpp so brought here

template <typename T>
Vector<T>::Vector(int num) : capacity(num), arr(new T[num]), length(0) {}


template <typename T>
int Vector<T>::push_back(T data) {
    if (length == capacity) {
        T* temp = arr;
        arr = new T[capacity = capacity * 2];
        copy(temp, temp + length, arr);
        delete[] temp;
    }
    arr[length++] = data;
    return length;
}

template <typename T>
T Vector<T>::pop_back() {
    return arr[length-- - 1];
}

template <typename T>
int Vector<T>::size() const {
    return length;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index >= length) {
        cout << "Error: Index Out of Bounds";
        exit(0);
    }

    return *(arr + index);
}



