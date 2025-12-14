#include <stdio.h>

float applyDiscounts(float *prices, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (prices[i] < 1000)
            prices[i] -= prices[i] * 0.10;
        else if (prices[i] <= 5000)
            prices[i] -= prices[i] * 0.15;
        else
            prices[i] -= prices[i] * 0.25;
        total += prices[i];
    }
    return total;
}

int main() {
    float prices[5];
    printf("Enter prices of 5 products:\n");
    for (int i = 0; i < 5; i++)
        scanf("%f", &prices[i]);

    float total = applyDiscounts(prices, 5);
    printf("Total amount after discounts = %.2f\n", total);

    return 0;
}
