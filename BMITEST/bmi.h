#ifndef BMI_H
#define BMI_H

// Enumeration representing BMI categories
typedef enum {
    UNDERWEIGHT,
    NORMAL,
    OVERWEIGHT,
    OBESE
} BMI_Category;

// Calculates Body Mass Index (BMI)
// weightKg      - weight in kilograms
// heightMeters  - height in meters
double calculateBMI(double weightKg, double heightMeters);

// Determines BMI category based on BMI value
BMI_Category interpretBMI(double bmi);

// Returns a string representation of the BMI category
const char* getBMICategoryName(BMI_Category category);

#endif // BMI_H

