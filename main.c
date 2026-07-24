#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

int main() {

    srand(time(NULL) ^ GetTickCount() ^ clock());
    i32 num = rand() % 46;
    i32 guess;
    i32 guessCount = 0;
    i32 guessMax = 5;
    i32 guessRemaining = guessMax;

    while (guessCount < guessMax) {

        printf("Guess a number between 0 and 45: ");
        i32 result = scanf("%d", &guess);

        if (result != 1) {
            printf("Not a number\n");
            while (getchar() != '\n')
                ;
        } else {
            if (guess > num) {
                guessCount++;
                guessRemaining--;
                printf("Too high, you have %d guesses remaining.\n",
                       guessRemaining);
            } else if (guess < num) {
                guessCount++;
                guessRemaining--;
                printf("Too low, you have %d guesses remaining.\n",
                       guessRemaining);
            } else {
                printf("Correct, congratulations you guessed the number!\n");
                return 0;
            }
        }
    }
    printf("You failed to guess the number! The number was %d\n", num);
    return 0;
}
