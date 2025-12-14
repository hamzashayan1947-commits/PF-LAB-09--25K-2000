#include <stdio.h>

void analyzeRainfall(float *rain, int n) {
    float sum = 0, avg;
    int i, maxIndex = 0, aboveAvg = 0;

    for (i = 0; i < n; i++)
        sum += *(rain + i);
    avg = sum / n;

    for (i = 0; i < n; i++) {
        if (*(rain + i) > *(rain + maxIndex))
            maxIndex = i;
    }

    for (i = 0; i < n; i++)
        if (*(rain + i) > avg) aboveAvg++;

    printf("Average rainfall: %.2f mm\n", avg);
    printf("Maximum rainfall on day %d: %.2f mm\n", maxIndex + 1, *(rain + maxIndex));

    if (aboveAvg > 3)
        printf("Rainy Week\n");
    else
        printf("Normal Week\n");
}

int main() {
    float rainfall[7];
    printf("Enter rainfall (mm) for 7 days:\n");
    for (int i = 0; i < 7; i++){
        printf("Day %d : " , i + 1);
        scanf("%f", &rainfall[i]);
    }
        

    analyzeRainfall(rainfall, 7);
    return 0;
}
