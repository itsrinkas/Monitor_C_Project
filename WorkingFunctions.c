/**
 * @file WorkingFunctions.c
 *
 * <b>CE4703 Computer Software 3</b>
 * <b>Assignment 1</b>
 *
 * File to demonstrate working functions.<br/>
 * This file contains a set of functions for reading array values, filling arrays
 * with random values, computing statistics like minimum/maximum, variance and comparing arrays.
 *
 * <h1>List of Required Working Functions</h1>
 *
 * @author Karyna Enato (23329831)
 * @date 30.10.2024
 */

 // include system header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For fabs()
#include <float.h> // For DBL_MAX and -DBL_MAX
#include <time.h> //used for randomizing rand()

// include module header files
#include "WorkingFunctions.h"

#define UNUSED -1


/**
 * WF1: Reads array values from the user(keyboard).
 * Negative input terminates input and remaining elements are set to UNUSED (-1).
 * Capacity of array (max number of elements) is provided.
 *
 * @param array The array to fill with user input.
 * @param capacity The maximum number of elements the array can hold.
 */
void ReadArrayValues(double array[], int capacity) {
    int i;
    double value;

    for (i = 0; i < capacity; ++i) {
        printf("Enter value for element %d: ", i + 1);
        scanf_s("%lf", &value);

        if (value < 0) { // Terminates input on negative value
            break;
        }

        array[i] = value;
    }

    // Set remaining elements to -1 (indicating unused)
    for (; i < capacity; ++i) {
        array[i] = -1;
    }
}

/**
 * WF2: Fills an array with random floating point values between min and max(not all whole numbers).
 *
 * @param array The array to be filled with random values.
 * @param capacity The maximum number of elements the array can hold.
 * @param used_elements The number of elements to fill with random values.
 * @param min The minimum random value.
 * @param max The maximum random value.
 */

 // Seed the random number generator
void RandomValues(double* array, int capacity, int used_elements, double min, double max) {
    for (int i = 0; i < used_elements; ++i) {
        array[i] = min + ((double)rand() / RAND_MAX) * (max - min);
    }
    // Set the remaining elements to -1 (indicating unused)
    for (int i = used_elements; i < capacity; ++i) {
        array[i] = UNUSED;
    }
}
/**
* WF3: Counts the number of used elements in an array.
*
* @param array The array to count used elements from.
* @param capacity The maximum number of elements in the array.
* @return The number of used elements.
*/
int CountUsedElements(const double* array, int capacity) {
    int count = 0;
    for (int i = 0; i < capacity; ++i) {
        if (array[i] != UNUSED) {
            count++;
        }
    }
    return count;
}

/**
 * WF4: Finds the minimum value among the used elements in an array.
 *
 * @param array The array to search for the minimum value.
 * @param capacity The maximum number of elements in the array.
 * @return The minimum value found or DBL_MAX if no used elements are found.
 */

double MinimumValue(const double* array, int capacity) {
    double min = DBL_MAX; // Initialize min to the maximum possible float value
    for (int i = 0; i < capacity; ++i) {
        if (array[i] != -1) { // Assuming -1 indicates an unused element
            if (array[i] < min) {
                min = array[i];
            }
        }
    }
    return min;
}
/**
 * WF5: Finds the maximum value among the used elements in an array.
 *
 * @param array The array to search for the maximum value.
 * @param capacity The maximum number of elements in the array.
 * @return The maximum value found or -DBL_MAX if no used elements are found.
 */

double MaximumValue(double* array, int capacity) {
    double max = -DBL_MAX;
    for (int i = 0; i < capacity; ++i) {
        if (array[i] != UNUSED && array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/**
 * WF6: Prints only used elements of an array.
 *
 * @param array The array whose used elements will be printed.
 * @param capacity The maximum number of elements in the array.
 */

void PrintUsedElements(const double* array, int capacity) {
    printf("{");
    int first = 1;
    for (int i = 0; i < capacity; ++i) {
        if (array[i] != -1) { // Only consider used elements
            if (!first) {
                printf(", "); // Prints a comma before subsequent elements
            }
            printf("%.2f", array[i]);
            first = 0; // Sets flag to indicate that the first element has been printed
        }
    }
    if (first) {
        printf("}"); // If no used elements- prints empty braces
    }
    else {
        printf("}");
    }
    printf("\n");
}
/**
 * WF7: Prints all elements of an array, including unused ones marked as UNUSED (-1).
 *
 * @param array The array to print.
 * @param capacity The maximum number of elements in the array.
 */

void PrintAllElements(const double* array, int capacity) {
    printf("{");
    for (int i = 0; i < capacity; ++i) {
        if (i > 0) {
            printf(", "); // Prints a comma before each element except the first
        }
        if (array[i] == UNUSED) {
            printf("-1");
        }
        else {
            printf("%.2f", array[i]); // Prints each element, used or unused
        }
    }
    printf("}\n");
}
/**
 * WF8: Compares the number of used elements in two arrays.
 *
 * @param array1 The first array to compare.
 * @param array2 The second array to compare.
 * @param capacity The maximum number of elements in both arrays.
 * @return -1 if the first array has fewer used elements, 1 if it has more or 0 if they are equal.
 */

int CompareNumberOfUsedElements(const double* array1, const double* array2, int capacity) {
    int count1 = CountUsedElements(array1, capacity);
    int count2 = CountUsedElements(array2, capacity);
    if (count1 < count2) {
        return -1;
    }
    else if (count1 > count2) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * WF9: Compares values in two arrays within a given tolerance.
 *
 * @param array1 The first array to compare.
 * @param array2 The second array to compare.
 * @param capacity The maximum number of elements in both arrays.
 * @param x The tolerance percentage.
 * @return The number of values that are outside the tolerance range or -1 if arrays have different numbers of used elements.
 */

int CompareArrays(double array1[], double array2[], int capacity, double x) {
    // Counts "used" elements in both arrays
    int count1 = 0, count2 = 0;
    for (int i = 0; i < capacity; ++i) {
        if (array1[i] != -1) {
            count1++;
        }
        if (array2[i] != -1) {
            count2++;
        }
    }

    // If arrays have different numbers of used elements- return -1
    if (count1 != count2) {
        return -1;
    }

    // Calculate the number of values outside the tolerance range
    int outside_tolerance = 0;
    for (int i = 0; i < capacity; ++i) {
        if (array1[i] != -1 && array2[i] != -1) { // Only consider used elements
            double lower_bound = array2[i] * (1 - x / 100);
            double upper_bound = array2[i] * (1 + x / 100);
            if (array1[i] < lower_bound || array1[i] > upper_bound) {
                outside_tolerance++;
            }
        }
    }

    return outside_tolerance;
}

/**
 * WF10: Computes the variance between two arrays.
 *
 * @param array1 The first array.
 * @param array2 The second array.
 * @param capacity The maximum number of elements in both arrays.
 * @return The computed variance or -1 if arrays have different numbers of used elements.
 */

double ComputeVariance(const double* array1, const double* array2, int capacity) {
    double sum = 0;
    int used_elements = 0;
    for (int i = 0; i < capacity; ++i) {
        if (array1[i] != -1 && array2[i] != -1) { // Only consider used elements
            used_elements++;
        }
        else if ((array1[i] == -1 && array2[i] != -1) || (array1[i] != -1 && array2[i] == -1)) {
            // If one array has a used element and the other has an unused element- return -1
            return -1;
        }
    }
    if (used_elements == 0) {
        return -1;
    }
    for (int i = 0; i < capacity; ++i) {
        if (array1[i] != -1 && array2[i] != -1) { // Only consider used elements
            double difference = array1[i] - array2[i];
            sum += difference * difference;
        }
    }

    // Calculate the variance
    double variance = sum / used_elements;
    return variance;
}