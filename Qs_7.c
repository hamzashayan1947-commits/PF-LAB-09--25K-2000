#include <stdio.h>
#define vehicles 5
#define days 7

void applyMileage(float (*data)[days], float *average)
{
    for (int i = 0; i < vehicles; i++)
    {
        float sum = 0;
        for (int j = 0; j < days; j++)
            sum += *(*(data + i) + j);
        average[i] = sum / days;
    }
}

void compRprt(float *average)
{
    printf("\n--- Compact Report ---\n");
    for (int i = 0; i < vehicles; i++)
        printf("Vehicle %d: %.2f km/l\n", i + 1, *(average + i));
}

void detailRprt(float *average)
{
    printf("\n--- Detailed Report ---\n");
    for (int i = 0; i < vehicles; i++)
    {
        printf("Vehicle %d - Avg: %.2f km/l - ", i + 1, *(average + i));
        if (*(average + i) >= 18)
            printf("Efficient\n");
        else if (*(average + i) >= 12)
            printf("Moderate\n");
        else
            printf("Poor\n");
    }
}

int main()
{
    float data[vehicles][days], average[vehicles];
    void (*rprtFunc)(float *);

    printf("Enter mileage (km/l) for %d vehicles over %d days:\n", vehicles, days);
    for (int i = 0; i < vehicles; i++)
    {
        printf("Vehicle %d:\n", i + 1);
        for (int j = 0; j < days; j++){
            printf("Day %d : " , j + 1);
            scanf("%f", &data[i][j]);

        }
    }

    applyMileage(data, average);

    int choice;
    printf("\nSelect report type:\n1. Compact\n2. Detailed\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1)
        rprtFunc = compRprt;
    else
        rprtFunc = detailRprt;

    rprtFunc(average);
    return 0;
}
