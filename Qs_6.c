#include <stdio.h>

float calcTotalValue(float price, int stock) {
    return price * stock;
}

float applyDiscount(float total, int stock) {
    if (stock < 3)
        return total;
    else if (stock <= 5)
        return total * 0.9;   
    else
        return total * 0.8;   
}

int main() {
    float price[5], total[5];
    int stock[5];

    for (int i = 0; i < 5; i++){
        
        printf("Enter price of book %d :\n" , i + 1);
        scanf("%f", &price[i]);
        printf("Enter stock of book %d :\n" , i + 1);
        scanf("%d", &stock[i]);

    }

    for (int i = 0; i < 5; i++) {
        total[i] = calcTotalValue(*(price + i), *(stock + i));
        total[i] = applyDiscount(total[i], *(stock + i));
    }

    printf("\nTotal value after discount:\n");
    for (int i = 0; i < 5; i++)
        printf("Book %d: %.2f\n", i + 1, total[i]);

    return 0;
}
