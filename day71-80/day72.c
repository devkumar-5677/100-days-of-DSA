#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    int i, freq[256] = {0};
    scanf("%s", s);
    for (i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
        if (freq[(unsigned char)s[i]] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}