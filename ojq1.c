#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str_rotate(char *str, int n) {
    char temp1 = str[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        str[i + 1] = str[i];
    }
    str[0] = temp1;
    return str;
}

int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    char str[1000]; 
    scanf("%s", str);
    int n = strlen(str);

    
    char* arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc((n + 1) * sizeof(char));
        strcpy(arr[i], str);
        strcpy(str, str_rotate(str, n));
    }

    qsort(arr, n, sizeof(char*), cmp);
    printf("%s\n%s", arr[0], arr[n - 1]);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}
