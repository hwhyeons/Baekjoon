#include <stdio.h>
#include <ctype.h>
#define LEN_INPUT 10

int main(void) {
    char s1[20];
    scanf("%s", s1);
    for (int i =0; i<20; i++) {
        char c = s1[i];
        if (c == '\0') break;
        if (isupper(c)) {
            printf("%c",tolower(c));
        } else {
            printf("%c",toupper(c));
        }
    }

    return 0;
}
