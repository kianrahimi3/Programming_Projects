//
// Created by kianr on 3/9/2021.
//

#include "Sorts.h"
#include <iostream>

#include "include/sorting_library.h"

using namespace std;

//only run 10 - end....i wrote
int Sorts::sortManager(int choice, int array[], int size) {
    switch(choice) {

        case 10: {
            std::cout << std::fixed << std::showpoint;
            std::cout.precision(9);
            //print_version_number();
            //create a start and end time_point object
            std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

            //get the current time, run the algo, then get the current time again
            start = std::chrono::high_resolution_clock::now();
            mystery01(array, size);
            end = std::chrono::high_resolution_clock::now();

            //calculate the duration between start and end and print to the terminal
            std::chrono::duration<double> time_in_seconds = end - start;

            /*
            cout << endl;
            cout << "SIZE = " << size << endl;
            cout << "myster 1 SORT" << endl;
            for(int i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
            cout << endl;



            std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

            cout << endl;
             */

            sortTimings.insert(pair<string, chrono::duration<double> >("Mystery 1", time_in_seconds) );
        }
            break;


        case 11: {
            std::cout << std::fixed << std::showpoint;
            std::cout.precision(9);
            //print_version_number();
            //create a start and end time_point object
            std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

            //get the current time, run the algo, then get the current time again
            start = std::chrono::high_resolution_clock::now();
            mystery02(array, size);
            end = std::chrono::high_resolution_clock::now();

            //calculate the duration between start and end and print to the terminal
            std::chrono::duration<double> time_in_seconds = end - start;

            /*
            cout << endl;
            cout << "SIZE = " << size << endl;
            cout << "mystery 2 SORT" << endl;
            for(int i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
            cout << endl;



            std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

            cout << endl;
             */

            sortTimings.insert(pair<string, chrono::duration<double> >("Mystery 2", time_in_seconds) );        }
            break;


        case 12: {

                std::cout << std::fixed << std::showpoint;
                std::cout.precision(9);
                //print_version_number();
                //create a start and end time_point object
                std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

                //get the current time, run the algo, then get the current time again
                start = std::chrono::high_resolution_clock::now();
                mystery03(array, size);
                end = std::chrono::high_resolution_clock::now();

                //calculate the duration between start and end and print to the terminal
                std::chrono::duration<double> time_in_seconds = end - start;

                /*
                cout << endl;
                cout << "SIZE = " << size << endl;
                cout << "mystery 3 SORT" << endl;
                for(int i = 0; i < size; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;



                std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

                cout << endl;
*/

            sortTimings.insert(pair<string, chrono::duration<double> >("Mystery 3", time_in_seconds) );        }
            break;

        case 13:  {
                std::cout << std::fixed << std::showpoint;
                std::cout.precision(9);
                //print_version_number();
                //create a start and end time_point object
                std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

                //get the current time, run the algo, then get the current time again
                start = std::chrono::high_resolution_clock::now();
                mystery04(array, size);
                end = std::chrono::high_resolution_clock::now();

                //calculate the duration between start and end and print to the terminal
                std::chrono::duration<double> time_in_seconds = end - start;

               /*
                cout << endl;
                cout << "SIZE = " << size << endl;
                cout << "mystery 4 SORT" << endl;
                for(int i = 0; i < size; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;


                std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

                cout << endl;
                */

            sortTimings.insert(pair<string, chrono::duration<double> >("Mystery 4", time_in_seconds) ) ;           }
            break;


        case 14: {
                std::cout << std::fixed << std::showpoint;
                std::cout.precision(9);
                //print_version_number();
                //create a start and end time_point object
                std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

                //get the current time, run the algo, then get the current time again
                start = std::chrono::high_resolution_clock::now();
                mystery05(array, size);
                end = std::chrono::high_resolution_clock::now();

                //calculate the duration between start and end and print to the terminal
                std::chrono::duration<double> time_in_seconds = end - start;

                /*
                cout << endl;
                cout << "SIZE = " << size << endl;
                cout << "mystery 5 SORT" << endl;
                for(int i = 0; i < size; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;


                std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

                cout << endl;
                 */

            sortTimings.insert(pair<string, chrono::duration<double> >("Mystery 5", time_in_seconds) );            }
            break;


        default:
            cout << "Not a proper #" << endl;
            break;

    }

}


void Sorts::printTimings() {
    for(it = sortTimings.begin(); it != sortTimings.end(); it++) {
        cout << it->first << " == " << fixed << it->second.count() << endl;
    }
}