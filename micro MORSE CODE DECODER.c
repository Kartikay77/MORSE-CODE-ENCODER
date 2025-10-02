#include <stdio.h>
#include <string.h>

typedef struct { const char *code; char ch; } MorseMap;

static const MorseMap MORSE_TABLE[] = {
    {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'}, {"..", 'I'},  {".---", 'J'},
    {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},  {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'},{"-.--", 'Y'},
    {"--..", 'Z'},
    {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'},
    {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {"-.-.--", '!'},
    {"-....-", '-'}, {"-..-.", '/'}, {"---...", ':'}, {"-.-.-.", ';'},
    {"-.--.", '('}, {"-.--.-", ')'}, {".----.", '\''}, {".-..-.", '\"'},
    {".--.-.", '@'}, {"-.--.-", ')'}
};

char decode_symbol(const char *morse) {
    for (size_t i = 0; i < sizeof(MORSE_TABLE)/sizeof(MORSE_TABLE[0]); i++) {
        if (strcmp(morse, MORSE_TABLE[i].code) == 0) return MORSE_TABLE[i].ch;
    }
    return '?'; // unknown symbol
}

int main(void) {
    char input[2048];
    printf("Enter Morse code (separate letters by spaces, words by /, multiple sentences by //):\n");
    
    if (!fgets(input, sizeof input, stdin)) return 0;

    char *token = strtok(input, " \n");
    while (token) {
        if (strcmp(token, "/") == 0) {
            printf(" "); // word separator
        } else if (strcmp(token, "//") == 0) {
            printf(". "); // sentence separator
        } else {
            printf("%c", decode_symbol(token));
        }
        token = strtok(NULL, " \n");
    }
    printf("\n");
    return 0;
}