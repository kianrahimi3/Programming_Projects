//
// Created by kianr on 10/1/2021.
//


#include <bits/stl_iterator_base_types.h>
#include <bits/stdc++.h>
//#include <algorithm>
#include "DSList.h"
#include "AVLTree.h"


template <class iterator, class T>
iterator findVectorValue(iterator first, iterator last, const T& val) {
    bool found = false;
    for(iterator it = first; it != last; it++) {
        if(*it == val) {
            found == true;
            return it;
        }
    }
    if(found == false)
        return last;

}


template <class iterator, class T>
iterator findValue(iterator begin, iterator end, const T& val)  {
    iterator iter = begin;
    for(; iter != end; iter++) {
        if(val == iter.Value())
            return iter;
    }
    return iter;
}


template <typename T>
void bubbleSort(Vector<T>& vec, int size, int order) {

    if(order == 0) {
        sort(vec.random_begin(), vec.random_end());
        //    for (int i = 0; i < size - 1; i++) {
        //        for (int j = 0; j < size - i - 1; j++) {
        //            if (vec[j] > vec[j + 1]) {
        //                T temp = vec[j + 1];
        //                vec[j + 1] = vec[j];
        //                vec[j] = temp;
        //            }
        //        }
        //    }
    }
    else if(order == 1) {
        sort(vec.random_begin(), vec.random_end(), greater <>());
        /*
        for (int i = 0; i < size ; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (vec[j] < vec[j + 1]) {
                    T temp = vec[j + 1];
                    vec[j + 1] = vec[j];
                    vec[j] = temp;
                }
            }
        }
         */
    }
}

template <typename Type>
Vector<Type> randomStringGen(int size, Vector<Type> vec, int percentDuplicate, int sorted, int order = 0) {
    char strings[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


    if(sorted == 0) {
        if(percentDuplicate == 0) {

            srand(time(0));
            string rando = "";
            //Type<T> vec;
            int i = 0;
            while (i < size) {
                //   bool acceptValue = true;
                for(int i = 0; i < 10; i++)
                    rando = rando + strings[rand() % 35];
                /*
                for (int j = 0; j < i; j++) {
                    if (rando == vec[j]) {
                        acceptValue = false;
                        break;
                    }
                }
                if (acceptValue == false)
                    continue;
                else {
                 */
                vec.push_back(rando);
                rando.clear();
                i++;
                //      }
            }

        }

        if(percentDuplicate == 20) {

            srand(time(0));
            string run = "";
            for(int i = 0; i < 10; i++)
                run = run + strings[rand() % 36];

            int y = size * .2;
            //int x = rand() % size;


            for(int i = 0; i < size; i++) {
                if(i < y)
                    vec.push_back(run);
                else {
                    string run = "";
                    for(int i = 0; i < 10; i++)
                        run = run + strings[rand() % 36];
                    vec.push_back(run);
                }
            }

        }

        if(percentDuplicate == 40) {

            srand(time(0));
            string run = "";
            for(int i = 0; i < 10; i++)
                run = run + strings[rand() % 36];

            int y = size * .4;
            //int x = rand() % size;


            for(int i = 0; i < size; i++) {
                if(i < y)
                    vec.push_back(run);
                else {
                    string run = "";
                    for(int i = 0; i < 10; i++)
                        run = run + strings[rand() % 36];
                    vec.push_back(run);
                }
            }

        }
    }
    else if(sorted == 1) {
        if(order == 0) {

            srand(time(0));
            string rando = "";
            //Type<T> vec;
            int i = 0;
            while (i < size) {
                //   bool acceptValue = true;
                for(int i = 0; i < 10; i++)
                    rando = rando + strings[rand() % 35];
                /*
                for (int j = 0; j < i; j++) {
                    if (rando == vec[j]) {
                        acceptValue = false;
                        break;
                    }
                }
                if (acceptValue == false)
                    continue;
                else {
                 */
                vec.push_back(rando);
                rando.clear();
                i++;
                //      }
            }
            /*
            int count = 0;
            while (count < size) {
                srand(time(0));
                string run = "";
                for (int j = 0; j < 10; j++)
                    run = run + strings[rand() % 36];

                bool dupe = false;
                for (int k = 0; k < count; k++) {
                    if (run == vec[k]) {
                        dupe = true;
                    }
                }
                if (dupe == true)
                    continue;
                else {
                    vec.push_back(run);
                    count++;
                }
            }
             */
            sort(vec.random_begin(), vec.random_end());
        }
        else if(order == 1) {

            srand(time(0));
            string rando = "";
            //Type<T> vec;
            int i = 0;
            while (i < size) {
                //   bool acceptValue = true;
                for(int i = 0; i < 10; i++)
                    rando = rando + strings[rand() % 35];
                /*
                for (int j = 0; j < i; j++) {
                    if (rando == vec[j]) {
                        acceptValue = false;
                        break;
                    }
                }
                if (acceptValue == false)
                    continue;
                else {
                 */
                vec.push_back(rando);
                rando.clear();
                i++;
                //      }
            }
            /*
            int count = 0;
            while (count < size) {
                srand(time(0));
                string run = "";
                for (int j = 0; j < 10; j++)
                    run = run + strings[rand() % 36];

                bool dupe = false;
                for (int k = 0; k < count; k++) {
                    if (run == vec[k]) {
                        dupe = true;
                    }
                }
                if (dupe == true)
                    continue;
                else {
                    vec.push_back(run);
                    count++;
                }
            }
             */
            bubbleSort(vec, size, 1);
        }
    }
    return vec;
}


template <typename Type>
Vector<Type> randomNumberGen(int size, Vector<Type>& vec, int percentDuplicate, int sorted, int order = 0)  {

    if(sorted == 0) {
        if(percentDuplicate == 0) {
            srand(time(0));


            int rando = 0;
            //Type<T> vec;
            int i = 0;
            while (i < size) {
                //   bool acceptValue = true;
                rando = rand() % size;
                /*
                for (int j = 0; j < i; j++) {
                    if (rando == vec[j]) {
                        acceptValue = false;
                        break;
                    }
                }
                if (acceptValue == false)
                    continue;
                else {
                 */
                vec.push_back(rando);
                i++;
                //      }
            }

        }
        else if(percentDuplicate == 20) {
            srand(time(0));

            int y = size * .2;
            int x = rand() % size;


            for(int i = 0; i < size; i++) {
                if(i < y)
                    vec.push_back(x);
                else {
                    x = rand() % size;
                    vec.push_back(x);
                }
            }
        }
        else if(percentDuplicate == 40) {
            srand(time(0));

            int y = size * .4;
            int x = rand() % size;


            for(int i = 0; i < size; i++) {
                if(i < y)
                    vec.push_back(x);
                else {
                    x = rand() % size;
                    vec.push_back(x);
                }
            }
        }
    }
        /// Sorted
    else if(sorted == 1) {
        if (order == 0) {
            srand(time(0));
            for (int i = 0; i < size; i++) {
                int x = rand() % size * 2;
                vec.push_back(x);
            }
            bubbleSort(vec, size, 0);
        } else if (order == 1) {
            srand(time(0));
            for (int i = 0; i < size; i++) {
                int x = rand() % size * 2;
                vec.push_back(x);
            }
            bubbleSort(vec, size, 1);
        }
    }
    return vec;
}


typedef ptrdiff_t indx;
template <class Iterator, class Comparison = std::less<>>
void QuickSort(Iterator iterator, Iterator finish, Comparison compare = Comparison())
{

    indx right = (finish - iterator) - 1;
    indx left = 0;
    if (right <= left)
        return;

    auto pivot = iterator[left + (right - left) / 2];
    indx i = left;
    indx j = right;

    while (i <= j)
    {
        while (compare(iterator[i], pivot))
            ++i;

        while (compare(pivot, iterator[j]))
            --j;

        if (i <= j)
        {
            swap(iterator[i++], iterator[j--]);
        }
    }

    QuickSort(iterator, iterator + (j + 1), compare);
    QuickSort(iterator + i, finish, compare);
}


template <class T>
Vector<T> insertionsort(Vector<T> &vec)
{
/*
    for (auto it = vec.random_begin(); it != vec.random_end(); it++)
    {
        auto const insertion_point =
                upper_bound(vec.random_begin(), it, *it);
        rotate(insertion_point, it, it+1);
    }
*/

    iter_swap(vec.random_begin(), min_element(vec.random_begin(), vec.random_end()));
    for(auto x = vec.random_begin(); ++x < vec.random_end(); vec.random_begin() = x)
        for(auto y = x; *y < *vec.random_begin(); --y, --vec.random_begin())
            iter_swap(vec.random_begin(), y);


    return vec;
}


template <class Iterator>
void HeapSort(Iterator begin, Iterator end) {
    //  while (begin != end)
    //     std::pop_heap(begin, end--);
    make_heap(begin, end);
    sort_heap(begin, end);
}


template <class T>
chrono::duration<double> quickSortRun(Vector<T>& vec) {
    chrono::time_point<chrono::high_resolution_clock> start, end;

    start = chrono::high_resolution_clock::now();
    QuickSort(vec.random_begin(), vec.random_end());
    end = chrono::high_resolution_clock::now();

    chrono::duration<double> time_in_seconds = end - start;
    return time_in_seconds;
}


template <class T>
chrono::duration<double> heapSortRun(Vector<T>& vec) {
    chrono::time_point<chrono::high_resolution_clock> start, end;

    start = chrono::high_resolution_clock::now();
    HeapSort(vec.random_begin(), vec.random_end());
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_in_seconds = end - start;
    return time_in_seconds;
}


template <class T>
chrono::duration<double> insertSortRun(Vector<T>& vec) {
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();
    insertionsort(vec);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_in_seconds = end - start;
    return time_in_seconds;
}

