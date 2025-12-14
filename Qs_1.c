#include <stdio.h>

void dispenseCash(int amount, int *notes) {
    int denominations[3] = {5000, 1000, 500};
    for (int i = 0; i < 3; i++) {
        notes[i] = amount / denominations[i];
        amount %= denominations[i];
    }
}

int main() {
    int amount;
    int notes[3] = {0};

    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    if (amount % 50 != 0) {
        printf("Invalid amount! Must be multiple of 50.\n");
        return 0;
    }

    dispenseCash(amount, notes);

    printf("5000 notes: %d\n", notes[0]);
    printf("1000 notes: %d\n", notes[1]);
    printf("500 notes: %d\n", notes[2]);

    return 0;
}
