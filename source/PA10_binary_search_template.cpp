
/*
 * binarysearch.cpp
 *
 *  Created on: Jun 29, 2012
 *      Author: Derek
 *
 *  Example of the binary search algorithm
 *
 *  From YouTube video: https://youtu.be/vohuRrwbTT4
 *  Original code on pastebin: https://pastebin.com/fsmGF1hp
 */

#include <iostream>

#include "Circle.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// Iterative binary search in array[] of type int
//      - size parameter is the number of T elements in passed array[]
//      - searchValue parameter is the value to find in array[]
//      - array[] must be sorted in ascending order!
// 
// Loops to compare searchValue with successive array midpoints.
// 
// The low and high array indices move towards each other.
// 
// Each loop iteration either:
//      increases low index, or
//      decreases high index
// 
// When low moves past high, the search stops and reports item not found.
// 
// Returns:
//      - the array index where passed searchValue was found, or
//      - -1 if searchValue was not found
//
// * Example: int array[] = { 0, 1, 2, 3, 4 }, searchValue = 1
// 
//      1) set low index to 0, high index to 4
//      2) compare searchValue 1 with midpoint value 2 at array[2]
//      3) 1 < 2 so next time only search elements before the 2
//              same low index is 0
//              new high index is 1
//              new mid index is (0 + 1) / 2 = 0
//      4) compare searchValue 1 with new midpoint value 0 at array[0]
//      5) 1 > 0 so next time only search elements after the 0
//              new low index is 1
//              new high index is 1
//              new mid index is (1 + 1) / 2 = 1
//      6) compare searchValue 1 with new midpoint value at 1 array[1]
//      7) 1 == 1 so searchValue is found at index mid = 1
// 
// * Another Example: int array[] = { 0, 1, 2, 3, 4 }, searchValue = 3
// 
//      1) set low index to 0, high index to 4
//      2) compare searchValue 3 with midpoint value 2 at array[2]
//      3) 3 is not < 2 so next time only search elements after the 2
//              new low index is 3
//              same high index is 4
//              new mid index is (3 + 4) / 2 = 3
//      4) compare searchValue 3 with new midpoint value 3 at array[3]
//      5) 3 == 3 so searchValue is found at index mid = 3
//
//------------------------------------------------------------------------------
// #TODO convert binarySearch() to a template function
// #TODO and overload needed operators to sort Circle class instances
//------------------------------------------------------------------------------
int binarySearch(int array[], int size, int searchValue) {

    cout << "searchValue = " << searchValue << "\n\n";

    // left side search begins at array index low
    int low = 0;
    // right side search ends at array index high
    int high = size - 1;

    // array index in between low and high
    int mid;

    // search fails when the low index goes past the high index
    while (low <= high) {
        
        mid = (low + high) / 2;
   
        cout << "low index = " << low 
            << ", high index = " << high 
            << ", mid index = " << mid << '\n';

        cout << "array[mid] = " << array[mid] << '\n';

        // #TODO Circle needs these operator overloads: ==, > 
        if (searchValue == array[mid]) {
            return mid;     // found! at index mid
        }
        // searchValue is bigger than current mid index 
        else if (searchValue > array[mid]) {
            // next search will start right after mid
            low = mid + 1;
            cout << "array[mid] " << array[mid]
                << " is less than searchValue " << searchValue
                << " so increase low index to search upper half\n\n";
        }
        else {
            // searchValue < midValue
            // next search will end right before mid
            high = mid - 1;
            cout << "array[mid] " << array[mid]
                << " is greater than searchValue " << searchValue
                << " so decrease high index to search lower half\n\n";
        }
    }

    cout << "low index = " << low << ", high index = " << high << '\n';

    return -1;  // not found
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    int a[] = { 12, 22, 34, 47, 55, 67, 82, 98 };
    //double a[] = { 12.2, 22.2, 34.2, 47.2, 55.2, 67.2, 82.2, 98.2 };
    //Circle a[] = { Circle(12), Circle(22), Circle(34), Circle(47),
    //               Circle(55), Circle(67), Circle(82), Circle(98) };
    cout << "\nBinary Search Demo Loop\n";

    int userValue;

    while (true) {
        // display values in array a
        cout << "\Values in array:";
        for (int i : a) {
            cout << i << ' ';
        }

        cout << "\n\nEnter an integer: ";
        cin >> userValue;

        // calculate number of int elements in array a
        int elements = sizeof(a) / sizeof(int);
        int result = binarySearch(a, elements, userValue);

        if (result >= 0) {
            cout << "The value " << a[result]
                << " was found at index " << result << '\n';
        }
        else {
            cout << "The value " << userValue << " was not found. " << '\n';
        }
    }

    return 0;
}