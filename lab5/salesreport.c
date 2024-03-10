#include <stdio.h>
#include <string.h>

void sortData(float values[], char months[][10], int n) {
    float tempf = 0.0f;
    char temps[10];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (values[j] > values[i]) {
                tempf = values[i];
                values[i] = values[j];
                values[j] = tempf;
                strcpy(temps, months[i]);
                strcpy(months[i], months[j]);
                strcpy(months[j], temps);
            }
        }
    }
}

void displaySalesReport(float values[], char months[][10], int n) {
    printf("Sales Report (Highest to Lowest)\n\n");
    printf("%-12s%s\n", "Month", "Sales");

    for (int i = 0; i < n; i++) {
        printf("%-12s$%.2f\n", months[i], values[i]);
    }
}

void displaySummary(float sales[], char months[][10]) {
    float highest = sales[0];
    float lowest = sales[0];
    int highest_month_index = 0;
    int lowest_month_index = 0;
    float sum = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] > highest) {
            highest = sales[i];
            highest_month_index = i;
        }
        if (sales[i] < lowest) {
            lowest = sales[i];
            lowest_month_index = i;
        }
        sum += sales[i];
    }

    float average = sum / 12;

    printf("\nMaximum Sales: %s - $%.2f\n", months[highest_month_index], highest);
    printf("Minimum Sales: %s - $%.2f\n", months[lowest_month_index], lowest);
    printf("Average Sales: $%.2f\n", average);
}

void displayAllSales(char months[][10], float sales[]) {
    for (int i = 0; i < 12; i++) {
        printf("%-12s$%.2f\n", months[i], sales[i]);
    }
}

void sixMonthMovingAverageReport(char months[][10], float sales[], int n) {
    printf("Six-Month Moving Average Report:\n\n");

    for (int i = 0; i < n - 6; i++) {
        float sum = 0;

        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        float avg = sum / 6;

        printf("%s - %s $%.2f\n", months[i], months[i + 5], avg);
    }
}

int main() {
    float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int n = 12;

    displayAllSales(months, sales);
    printf("\n");
    sixMonthMovingAverageReport(months, sales, n);
    printf("\n");

    // Sort and display the sales report
    sortData(sales, months, n);
    displaySalesReport(sales, months, n);

    // Display the summary
    displaySummary(sales, months);
    printf("\n");

    return 0;
}
