#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif
int main() {
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    char s[256];
    printf("Введите строку: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    int m = 0; 
    int p = 0; 
    int c = 0; 
    for (int i = 0; ; i++) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == '.' || 
            s[i] == '!' || s[i] == '?' || s[i] == ';' || s[i] == ':' || s[i] == '\0') {           
            if (c > m) {
                m = c;
                p = i - c;
            }
            c = 0;
            if (s[i] == '\0') {
                break;
            }
        } else {
            c++;
        }
    }
    if (m > 0) {
        printf("Самое длинное слово: ");
        for (int i = p; i < p + m; i++) {
            printf("%c", s[i]);
        }
        printf(" (длина: %d)\n", m);
    } else {
        printf("В строке нет слов.\n");
    }
    return 0;
}
