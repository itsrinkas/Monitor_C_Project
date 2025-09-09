# Monitor_C_Project
This C program simulates a sensor monitoring system for an industrial production line. It compares real-time sensor data against expected values, using floating-point operations and basic statistical functions.

##  Features
- Read user input or generate random sensor values
- Track and distinguish between used and unused data entries
- Analyze data with:
  - Minimum and maximum detection
  - Percentage deviation comparison
  - Variance calculation
- Handle arrays with precision, excluding unused elements (`-1` as marker)

##  Implemented Functions
- **ReadArrayValues** – Reads input until full or a negative value is entered  
- **RandomValues** – Fills array with random float values within a given range  
- **CountUsedElements** – Returns the number of active sensor values  
- **MinimumValue / MaximumValue** – Finds min and max values in the array  
- **CompareArrays** – Compares two datasets within a percentage tolerance  
- **ComputeVariance** – Calculates statistical variance between datasets  
- **Print Functions** – Display used or all elements in array format  
- **CompareCount** – Compares the number of used elements in two arrays

## Notes

- **The project includes Doxygen documentation.**

- All files are packaged in a ZIP archive for submission.
