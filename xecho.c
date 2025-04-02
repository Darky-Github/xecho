#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ANSI color codes
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"
#define STRIKE  "\033[9m"

void print_colored(const char *color, const char *text, int bold, int italic, int underline, int strike) {
    printf("%s", color);
    if (bold) printf(BOLD);
    if (italic) printf(ITALIC);
    if (underline) printf(UNDERLINE);
    if (strike) printf(STRIKE);
    printf("%s%s", text, RESET);
}

int main(int argc, char *argv[]) {
    int bold = 0, italic = 0, underline = 0, strike = 0;
    const char *color = RESET;
    char separator = ' ';
    int arg_start = 1;

    // Process flags
    while (arg_start < argc) {
        if (strcmp(argv[arg_start], "-c") == 0 && arg_start + 1 < argc) {
            if (strcmp(argv[arg_start + 1], "red") == 0) color = RED;
            else if (strcmp(argv[arg_start + 1], "green") == 0) color = GREEN;
            else if (strcmp(argv[arg_start + 1], "yellow") == 0) color = YELLOW;
            else if (strcmp(argv[arg_start + 1], "blue") == 0) color = BLUE;
            arg_start += 2;
        } else if (strcmp(argv[arg_start], "-b") == 0) {
            bold = 1;
            arg_start++;
        } else if (strcmp(argv[arg_start], "-i") == 0) {
            italic = 1;
            arg_start++;
        } else if (strcmp(argv[arg_start], "-u") == 0) {
            underline = 1;
            arg_start++;
        } else if (strcmp(argv[arg_start], "-s") == 0) {
            strike = 1;
            arg_start++;
        } else if (strcmp(argv[arg_start], "-sep") == 0 && arg_start + 1 < argc) {
            separator = argv[arg_start + 1][0];
            arg_start += 2;
        } else {
            break;
        }
    }

    // Print remaining arguments
    for (int i = arg_start; i < argc; i++) {
        print_colored(color, argv[i], bold, italic, underline, strike);
        if (i < argc - 1) printf("%c", separator);
    }
    printf("\n");

    return 0;
}
