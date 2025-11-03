#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n;
    printf("Rashi Bhatia / S1 - S11/ 12  \n\n");
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    char job[n];
    int deadline[n], profit[n];
    printf("Enter JobID Deadline Profit for each job:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &job[i], &deadline[i], &profit[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                swap(&profit[i], &profit[j]);
                swap(&deadline[i], &deadline[j]);
                char temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }
    int maxDeadline = deadline[0];
    for (int i = 1; i < n; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }
    char result[maxDeadline + 1];
    int filled[maxDeadline + 1];
    for (int i = 1; i <= maxDeadline; i++) {
        filled[i] = 0;
        result[i] = '-';
    }
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = deadline[i]; j > 0; j--) {
            if (filled[j] == 0) {
                filled[j] = 1;
                result[j] = job[i];
                totalProfit += profit[i];
                break;
            }
        }
    }
    printf("Job Sequence: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != '-')
            printf("%c ", result[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}
