#include <stdio.h>
#include "bmi.h"

int main(void)
{
    double weight;     // User weight in kilograms
    double height;     // User height in meters
    double bmi;        // Calculated BMI value
    BMI_Category category;

    // Input weight
    printf("Enter weight (kg): ");
    scanf_s("%lf", &weight);

    // Input height
    printf("Enter height (m): ");
    scanf_s("%lf", &height);

    // Calculate BMI and determine category
    bmi = calculateBMI(weight, height);
    category = interpretBMI(bmi);

    // Output results
    printf("\nBMI value: %.2f \n", bmi);
    printf("Health category: %s \n", getBMICategoryName(category));

    return 0;

    // BMI = weight (kg) / (height (m))^2
    double calculateBMI(double weightKg, double heightCm)
    {
        if (weightKg <= 0.0 || heightCm <= 0.0)
            return 0.0;

        double heightMeters = heightCm / 100.0;
        return weightKg / (heightMeters * heightMeters);
    }

    BMI_Category interpretBMI(double bmi)
    {
        if (bmi < 18.5)
            return UNDERWEIGHT;
        else if (bmi < 25.0)
            return NORMAL;
        else if (bmi < 30.0)
            return OVERWEIGHT;
        else
            return OBESE;
    }

    const char* getBMICategoryName(BMI_Category category)
    {
        switch (category)
        {
        case UNDERWEIGHT: return "Underweight";
        case NORMAL:      return "Normal weight";
        case OVERWEIGHT:  return "Overweight";
        case OBESE:       return "Obesity";
        default:          return "Unknown category";
        }
    }
}

