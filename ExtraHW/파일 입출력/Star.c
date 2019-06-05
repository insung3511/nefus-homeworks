#include <stdio.h>

int main() {
    FILE *fp = fopen("a.txt", "w");
    for(int i = 0; i < 5 / 2 + 1; i++) {
        for (int j = 0; j < 5 / 2 - i; j++) {
            fputs(" ", fp);
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            fputs("*", fp);
        }   fputs("\n", fp);
    }
    return 0;
}
