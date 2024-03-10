#include <stdio.h>

void printCombinations(int numTD, int numTDFG, int numTDTD, int numTDthree, int safety) {
    printf("%d TD + 2pt, %d TD + FG, %d TD + %d 3pt FG, %d Safety\n", numTD, numTDFG, numTDTD, numTDthree, safety);
}

void getCombinations(int score) {
    for (int numTD = 0; score >= (8 * numTD); numTD++) {
        for (int numTDFG = 0; score >= (8 * numTD + 7 * numTDFG); numTDFG++) {
            for (int numTDTD = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD); numTDTD++) {
                for (int numTDthree = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree); numTDthree++) {
                    for (int safety = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree + 2 * safety); safety++) {
                        if (score == (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree + 2 * safety)) {
                            printCombinations(numTD, numTDFG, numTDTD, numTDthree, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program ended. Goodbye.\n");
            break;
        } else {
            printf("Possible combinations of scoring plays:\n");
            getCombinations(score);
        }
    }

    return 0;
}
