#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int target, guess;
    int attempts = 0;
    int scanfResult;

    srand((unsigned)time(NULL));
    target = (rand() % 100) + 1;

    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Try to guess it! (type a non-number to quit)\n");

    while (1)
    {
        printf("Enter your guess: ");
        scanfResult = scanf("%d", &guess);

        if (scanfResult != 1)
        {
            printf("\nInvalid input or user requested exit. Goodbye!\n");
            break;
        }

        attempts++;

        if (guess < 1 || guess > 100)
        {
            printf("Please guess a number between 1 and 100.\n");
            continue;
        }

        if (guess < target)
        {
            printf("Too low.\n");
        }
        else if (guess > target)
        {
            printf("Too high.\n");
        }
        else
        {
            printf("Correct! You guessed the number in %d attempt%s.\n",
                   attempts, attempts == 1 ? "" : "s");
            break;
        }
    }

    return 0;
}