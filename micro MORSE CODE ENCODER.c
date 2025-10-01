#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const char *MORSE_ALPHA[26] = {
    ".-", "-...", "-.-.", "-..",  ".",    "..-.", "--.", "....", "..",
    ".---", "-.-",  ".-..", "--", "-.",   "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."
};
static const char *MORSE_DIGIT[10] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};

int main(void) {
    char line[512];

    printf("Enter text: ");
    if (!fgets(line, sizeof line, stdin)) return 0;

    // Strip trailing newline if present
    size_t n = strlen(line);
    if (n && line[n-1] == '\n') line[n-1] = '\0';

    int first = 1;
    for (size_t i = 0; line[i]; ++i) {
        unsigned char ch = (unsigned char)line[i];
        if (isalpha(ch)) {
            ch = (unsigned char)toupper(ch);
            const char *code = MORSE_ALPHA[ch - 'A'];
            printf("%s%s", first ? "" : " ", code);
            first = 0;
        } else if (isdigit(ch)) {
            const char *code = MORSE_DIGIT[ch - '0'];
            printf("%s%s", first ? "" : " ", code);
            first = 0;
        } else if (ch == ' ') {
            // Word gap
            printf("%s/", first ? "" : " ");
            first = 0;
        } else {
            // Ignore punctuation/unsupported chars or handle them here if you want
        }
    }
    printf("\n");
    return 0;
}
