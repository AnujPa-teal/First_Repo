// Author - AnujPa-teal
//start - 09/23/23
//end - 12/23/23 
//Currency Converter C Program 

#include <stdio.h>

#define NUM_CURRENCIES 7

enum Currency {
    DOLLAR = 1,
    RUPEES,
    EURO,
    JAPANESE_YEN,
    CHINESE_YUAN,
    SINGAPORE_DOLLAR,
    RUSSIAN_RUBLE,
    
};

const char* currencyNames[NUM_CURRENCIES] = {
    "Dollar",
    "Rupees",
    "Euro",
    "Japanese Yen",
    "Chinese Yuan",
    "Singapore Dollar",
    "Russian Ruble",
};

/* The conversion rates are from before September 23, 2023. */

double conversionRates[NUM_CURRENCIES][NUM_CURRENCIES] = {
    {1,83,0.94,147.46,7.31,1.37,96.10},   // Dollar
    {0.013,1,0.011,1.77,0.088,0.016,1.16},   // Rupees
    {1.07,88,1,157.36,7.80, 1.46,102.52},  //Euro
    {0.0068,0.56,0.0064,1, 0.0093,0.65},// Japanese Yen
    {0.14,11.37,0.13,20.18,1,0.19,13.35},  // Chinese Yuan
    {0.73,60.83,0.69,107.92,5.35,1,70.34},     // Singapore Dollar
    {0.010,0.87,0.0098, 1.53, 0.076 ,0.0,1},  // Russian Ruble
};

double convertCurrency(double amount, int fromCurrency, int toCurrency) {
    return amount * conversionRates[fromCurrency - 1][toCurrency - 1];
}

void displayCurrencies() {
    printf("Currencies:\n");
    for (int i = 0; i < NUM_CURRENCIES; i++) {
        printf("%d - %s\n", i + 1, currencyNames[i]);
    }
}

int main() {
    int fromCurrency, toCurrency;
    double amount;

    displayCurrencies();

    printf("Enter the number corresponding to the currency you have: ");
    scanf("%d", &fromCurrency);
    printf("Enter the number corresponding to the currency in which you want conversion: ");
    scanf("%d", &toCurrency);
    printf("Enter the amount you wish to convert: ");
    scanf("%lf", &amount);

    double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency);

    printf("%.2lf %s is equivalent to %.2lf %s.\n", amount, currencyNames[fromCurrency - 1],
           convertedAmount, currencyNames[toCurrency - 1]);

    return 0;
}