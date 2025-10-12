#include <stdio.h>
#include <string.h>

// my implementation, easier for me to understand :)
int search(char w[], char t[]) {
    int i = 0;
    int m = strlen(w);
    int n = strlen(t);
    int MAX = n - m;

    for (int i = 0; i <= MAX; i++) {

        int j = 0;

        while (j < m && t[i + j] == w[j]) {
            j++;
        }

        if (j == m) {
            return i;
        }

    }

    return -1;
}

int main(){
    printf("%d\n", search("bar", "rabarbar")); // 2
    printf("%d\n", search("ra", "rabarbar")); // 0
    printf("%d\n", search("bar", "barbarbar")); // 0
    printf("%d\n", search("bar", "ba")); // -1
    printf("%d\n", search("rb", "rabarbar")); // 4
    return 0;
}