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

/* The conversion rates are from before January 20, 2024. */

double conversionRates[NUM_CURRENCIES][NUM_CURRENCIES] = {
    {1,83,0.92,148.18,7.12,1.34,89.43},   // Dollar
    {0.012,1,0.011,1.78,0.085,0.016,1.06},   // Rupees
    {1.08,90.53,1,161.32,7.75,1.46,96.00},  //Euro
    {0.0067,0.56,0.0061,1, 0.0093,0.59},// Japanese Yen
    {0.14,11.68,0.13,20.18,1,0.18,12.38},  // Chinese Yuan
    {0.74,62.01,0.68,110.49,5.30,1,65.75},     // Singapore Dollar
    {0.01,0.94,0.01, 1.68, 0.08 ,0.01,1},  // Russian Ruble
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
