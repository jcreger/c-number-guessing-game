# Number Guessing Game

Console-based number guessing game written in C. This is my first attempt at building something in a programming language.

## How to Play

The program generates a number between 0-45, and the player has 5 attempts to guess correctly. Each attempt the player is notified whether their guess was too high or too low. If the player uses all 5 of their attempts and fails to guess the correct number, they will be given the correct number and the program will exit. If the player guesses the correct number they will be congratulated and the program will exit.

## Challenges

Before starting this project, I watched a 2 hour long video going over the basics of C. This video covered a lot of topics not covered in this project, but upon starting this project I quickly began to realize how much I didn't fully understand. There were 2 main pain points in building this project which required some research and experimentation outside of struggling with nvim and terminal:

- **Random Number Generation:** I had pretty much no idea how this even worked before doing some extra research into specifically this. It started off with me using `rand()` and realizing it needed to be seeded to actually produce a new number each run. After discovering `srand(time(NULL))` I ran some `printf()` tests and realized the numbers were moving in a linear pattern with low resolution. This led to me exploring `<time.h>` and `<windows.h>`, which gave me access to 2 other methods: `clock()` and `GetTickCount()`. `clock()` itself was not of much use as it returns clock ticks relative to when a program started; however, `GetTickCount()` was a lot more useful. This function has the drawback of only functioning on Windows PCs, but it gives you a much higher resolution number than `time()` as it operates in milliseconds since turning on your PC. Once I had these methods I used ^ in `srand()` which represents XOR to increase the resolution further by utilizing all 3 methods. Finally I utilized % which represents the modulo math operator to divide the random number and return the remainder. This essentially let me set my range using `% 46` which returns between 0 and 45.

- **Scanf and Stdin:** This problem started from a lack of understanding of how `scanf()` functions. When building the project and asking for user input I knew I would need to check whether or not what the user entered was an integer. This led to me exploring possibilities of checking for this in a for statement. I learned that `scanf()` will return the number of variables it successfully assigned which allowed me to store this solving the problem. I thought this was the end of my troubles, and that I had solved my first headache. Well upon building out the rest of the project and testing it I was bombarded with an infinite loop upon entering a non-integer. I had no idea what was happening. At this point I had to do research into how `scanf()` functions, and this is when I learned about the stdin buffer. Essentially, `scanf()` first checks the stdin buffer for input. If the buffer is empty, it will wait until input is entered. The input that goes into the stdin buffer will only be cleared when they are successfully read. `scanf()` was checking for integers, so I needed another method of clearing the buffer if a non-integer was entered.

```
keyboard input -> stdin buffer -> scanf() reads from buffer -> writes to variable if matched
```

The fix to this issue was to create a while loop in the if statement using `getchar()`. This works by returning what is in the stdin buffer one character at a time. I made this while loop check every iteration if `getchar()` returned a new line, which would mean the line in the buffer was clean. This experience led me to learn that every function in C has a very specific way that it works, and to actually master the language I will have to explore each of these.

## Building and Running

Requires a C compiler to build and run. Currently only works on Windows due to including `<windows.h>`.

```powershell
gcc main.c -o main.exe
.\main.exe
```
