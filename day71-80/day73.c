#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    // Input string
    scanf("%s", s);

    // Count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If all characters repeat
    printf("$\n");

    return 0;
}