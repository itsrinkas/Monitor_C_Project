/**
 * @file WorkingFunctions.h
 *
 * <b>CE4703 Computer Software 3</b>
 * <b>Assignment 1</b><br/>
 *
 * Header file containing declarations of menu functions and working functions.
 * This file defines the constants and function prototypes used in the implementation
 * of various operations on arrays, including reading values, generating random values,
 * counting used elements and performing comparisons.
 *
 * @author Karyna Enato (23329831)
 * @date 30.10.2024
 */

#pragma once
#ifndef WORKINGFUNCTIONS_H
#define WORKINGFUNCTIONS_H

#define UNUSED -1
void MF1();
void MF2();
void MF3();
void MF4();
// Working Function Prototypes
void ReadArrayValues(double* array, int capacity);
void RandomValues(double* array, int capacity, int used_elements, double min, double max, int srand_value);
int CountUsedElements(const double* array, int capacity);
double MinimumValue(const double* array, int capacity);
double MaximumValue(const double* array, int capacity);
void PrintUsedElements(const double* array, int capacity);
void PrintAllElements(const double* array, int capacity);
int CompareNumberOfUsedElements(const double* array1, const double* array2, int capacity);
int CompareArrays(const double* array1, const double* array2, int capacity, double count);
double ComputeVariance(const double* array1, const double* array2, int capacity);

#endif