#include <stdio.h>

void bookSeat(int *flight, int seats) {
    int seatNo;
    printf("Enter seat number (1-%d): ", seats);
    scanf("%d", &seatNo);
    if (seatNo >= 1 && seatNo <= seats && flight[seatNo - 1] == 0) {
        flight[seatNo - 1] = 1;
        printf("Seat booked successfully!\n");
    } else
        printf("Invalid or already booked seat.\n");
}

void cancelSeat(int *flight, int seats) {
    int seatNo;
    printf("Enter seat number (1-%d): ", seats);
    scanf("%d", &seatNo);
    if (seatNo >= 1 && seatNo <= seats && flight[seatNo - 1] == 1) {
        flight[seatNo - 1] = 0;
        printf("Seat canceled successfully!\n");
    } else
        printf("Invalid or not booked seat.\n");
}

int countOccupied(int *flight, int seats) {
    int count = 0;
    for (int i = 0; i < seats; i++)
        if (flight[i] == 1) count++;
    return count;
}

int main() {
    int flight1[5] = {0}, flight2[7] = {0}, flight3[9] = {0};
    int *flights[3] = {flight1, flight2, flight3};
    int capacities[3] = {5, 7, 9};
    int choice, f;

    while (1) {
        printf("\n1. Book Seat\n2. Cancel Seat\n3. Show Total Occupied\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 4) break;

        printf("Select flight (1-3): ");
        scanf("%d", &f);
        f--;

        if (choice == 1)
            bookSeat(flights[f], capacities[f]);
        else if (choice == 2)
            cancelSeat(flights[f], capacities[f]);
        else if (choice == 3)
            printf("Occupied seats in Flight %d = %d\n", f + 1, countOccupied(flights[f], capacities[f]));
    }

    return 0;
}
