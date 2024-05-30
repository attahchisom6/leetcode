#include <stdio.h>

int _strcmp(char *s1, char *s2) {
    int k = 0;

    while (s1[k] != '\0' && s1[k] == s2[k]) {
        k++;
    }
    return s1[k] - s2[k];
}

int main(void) {
    int k, p;
    char *val[] = {"good", "bad", "key", "can", "oesophagus", "Helliocentric"};

    for (int i = 0; i < 5; i++) {
        k = _strcmp(val[i], "key");
        p = strcmp(val[i], "key");
        printf("with _strcmp: %d\n", k);
        printf("with strcmp: %d\n", p);
    }
    return (0);
}
