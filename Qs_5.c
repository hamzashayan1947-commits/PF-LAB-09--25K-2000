#include <stdio.h>

void analyzeAttendance(int (*att)[5], int students) {
    int defaulters = 0;
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += *(*(att + i) + j);

        float percent = (sum / 5.0) * 100;
        printf("Student %d: %.0f%% - ", i + 1, percent);

        if (percent >= 90)
            printf("Good\n");
        else if (percent >= 75)
            printf("Average\n");
        else {
            printf("Poor\n");
            defaulters++;
        }
    }
    printf("\nTotal Defaulters (<75%%): %d\n", defaulters);
}

int main() {
    int attendance[30][5];
    printf("Enter attendance (1=Present, 0=Absent) for 30 students (5 days):\n");

    for (int i = 0; i < 30; i++) {
        printf("Student %d\n" , i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Day %d : " , j + 1);
            scanf("%d", &attendance[i][j]);
        }
    }

    analyzeAttendance(attendance, 30);
    return 0;
}
