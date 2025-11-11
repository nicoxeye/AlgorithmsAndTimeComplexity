#include <stdio.h>
#include <string.h>

// original algorithm sent by the professor
int search(char pat[], char txt[]){
    int i = 0;
    int j = 0;
    int m = strlen(pat);
    int n = strlen(txt);

    while ( (j < m) && (i < n) ) {
        if (txt[i] != pat[j]) {
            i -= j;
            j = -1;
        }
        i++;
        j++;
    }

    if (j==m){
        return i-m;
    } else {
        return -1;
    }
}

int main(){
    printf("%d\n", search("bar", "rabarbar")); // 2
    printf("%d\n", search("ra", "rabarbar")); // 0
    printf("%d\n", search("bar", "barbarbar")); // 0
    printf("%d\n", search("bar", "ba")); // -1
    printf("%d\n", search("rb", "rabarbar")); // 4
    return 0;
}