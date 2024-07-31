#include <stdio.h>

int main() {
    int lanes[25] = {0}; // Initial state
    lanes[0] = 1; // At least one non-zero bit in the first block

    // Show how long it will take
    int rounds = 0;
    while (1) {
        int all_non_zero = 1;
        for (int i = 0; i < 25; ++i) {
            if (lanes[i] == 0) {
                all_non_zero = 0;
                lanes[i] = 1; // Simulate change
                rounds++;
                break;
            }
        }
        if (all_non_zero) break;
    }

    printf("Rounds to non-zero state: %d\n", rounds);
    return 0;
}
