/**
 * @file MenuFunction.c
 *
 * <b>CE4703 Computer Software 3</b>
 * <b>Assignment 1</b>
 *
 * File to demonstrate menu functions.<br/>
 * This file contains four menu functions: MF1, MF2, MF3 and MF4,
 * which utilize various working functions.
 *
 *
 * <ul>
 *   <li>MF1: Initializes and prints arrays with random values.</li>
 *   <li>MF2: Fills arrays with random values, compares them, and calculates variance.</li>
 *   <li>MF3: Reads values from the user, compares them, and checks tolerances.</li>
 *   <li>MF4: Handles 2D arrays, calculates variances and identifies min/max variance sets.</li>
 * </ul>
 *
 * <h1>List of Required Menu Functions</h1>
 *
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
  * MF1: Initializes an array with random values and prints used and unused values.
  */

void MF1() {
    // Start with two newline characters
    printf("\nPerforming MF1...\n");

    // Create an array of 10 elements
    double array[10];
    int capacity = 10;
    int used_elements = 7;

    // Fill array with 7 random values using WF2
    RandomValues(array, capacity, used_elements, 0, 10, -1);

    // Print used values using WF6
    printf("\narray= ");
    PrintUsedElements(array, capacity);

    // Print all values (used and unused) using WF7
    printf("array= ");
    PrintAllElements(array, capacity);

    // Find and print min and max values using WF4 and WF5
    double min = MinimumValue(array, capacity);
    double max = MaximumValue(array, capacity);
    printf("\nValues range from %.2f to %.2f\n", min, max);

    printf("\n");
}
/**
 * MF2: Fills arrays with random values, checks tolerances and calculates variance.
 */
void MF2() {
    // Start with two newline characters
    printf("\nPerforming MF2...\n");
    // Create arrays for expected values and current values (each with 100 elements) and fill both with 50 random values
    double expected_values[100], current_values[100];
    int capacity = 100;
    int used_elements = 50;

    // Fill arrays with random values in range 10.0 to 20.0, srand value is 7
    RandomValues(expected_values, capacity, used_elements, 10.0, 20.0, 7);
    RandomValues(current_values, capacity, used_elements, 10.0, 20.0, 7);

    // Compare current values against expected values within 20%
    int within_tolerance = CompareArrays(current_values, expected_values, capacity, 20.0);
    printf("\n%d values are within 20%% of expected values and %d values are outside this range.\n",
        used_elements - within_tolerance, within_tolerance);

    // Find and print min and max values for both arrays (WF4 and WF5)
    double expected_min = MinimumValue(expected_values, capacity);
    double expected_max = MaximumValue(expected_values, capacity);
    double current_min = MinimumValue(current_values, capacity);
    double current_max = MaximumValue(current_values, capacity);
    printf("Expected values range from %.2f to %.2f and current values range from %.2f to %.2f\n",
        expected_min, expected_max, current_min, current_max);

    // Compute and print variance using WF10
    double variance = ComputeVariance(current_values, expected_values, capacity);
    printf("Current values have variance %.2f\n", variance);

    printf("\n");
}

/**
 * MF3: Reads values from the user, compares the number of used elements and checks tolerances.
 */
 // MF3: Create arrays for expected and current values, read values from the user, and compare their usage.
void MF3() {
    // Start with two newline characters
    printf("\nPerforming MF3...\n");

    //Create arrays for expected values and current valeus (each with 100 elements).
    double expected_values[100], current_values[100];
    int capacity = 100;

    // Read values for both arrays using WF1
    printf("\nEnter expected values:\n");
    ReadArrayValues(expected_values, capacity);
    printf("\nEnter current values:\n");
    ReadArrayValues(current_values, capacity);

    // Compare number of used elements using WF8
    int comparison_result = CompareNumberOfUsedElements(expected_values, current_values, capacity);
    if (comparison_result == 0) {
        printf("\nBoth arrays have the same number of used elements.\n");
    }
    else if (comparison_result < 0) {
        printf("Expected values have fewer used elements.\n");
    }
    else {
        printf("\nCurrent values have fewer used elements.\n");
    }

    // If the number of used elements is not equal, terminate the function
    if (comparison_result != 0) {
        printf("\nMismatching number of used elements. Exiting MF3.\n");
        return;
    }

    // Compare current values against expected values within 5% tolerance using WF9
    int within_tolerance = CompareArrays(current_values, expected_values, capacity, 5.0);
    printf("\n%d values are within 5%% of expected values and %d values are outside this range.\n",
        CountUsedElements(expected_values, capacity) - within_tolerance, within_tolerance);

    // Compute and print variance using WF10
    double variance = ComputeVariance(current_values, expected_values, capacity);
    printf("\nCurrent values have variance %.2f\n", variance);

    printf("\n");
}
/**
 * MF4: Handles 2D arrays, calculates variances for each set and identifies min/max variance sets.
 *
 * @param data The 2D array containing data sets.
 */

void MF4() {
    // Start with two newline characters
    printf("\nPerforming MF4...\n");
    // Create a array for expected values that can hold up to 50 values and read in the expected values from the user.
    // Then use a 2 - dimensional array for current values that can store 10 sets of up to 50 values.
    double expected_values[50];
    double current_values[10][50];
    int capacity = 50;

    // Read expected values using WF1
    printf("Enter expected values:\n");
    ReadArrayValues(expected_values, capacity);

    // Read 10 sets of current values using WF1
    for (int i = 0; i < 10; ++i) {
        printf("Enter current values set %d:\n", i + 1);
        ReadArrayValues(current_values[i], capacity);
    }

    double min_variance = DBL_MAX;
    double max_variance = -DBL_MAX;
    int min_index = -1;
    int max_index = -1;

    // Compare number of used elements and calculate variances
    for (int i = 0; i < 10; ++i) {
        if (CompareNumberOfUsedElements(expected_values, current_values[i], capacity) != 0) {
            printf("Mismatching number of used elements for set %d. Exiting MF4.\n", i + 1);
            return;
        }

        // Compute variance for each set using WF10
        double variance = ComputeVariance(current_values[i], expected_values, capacity);
        printf("Current Values #%d has variance %.2f\n", i + 1, variance);

        // Track the minimum and maximum variance
        if (variance < min_variance) {
            min_variance = variance;
            min_index = i;
        }
        if (variance > max_variance) {
            max_variance = variance;
            max_index = i;
        }
    }

    // Print the set with the lowest and highest variance
    printf("Set %d has lowest variance (%.2f) and set %d has highest variance (%.2f)\n",
        min_index + 1, min_variance, max_index + 1, max_variance);

    printf("\n");
}