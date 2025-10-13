#include <stdio.h>
#include <string.h>

/* 
    my own proposition of the naive algorithm but trying to make it faster than the original version
    (will update this probably if i get feedback from professor:) )
    but!!! all symbols in a pattern are different from each other

    the matching is attempted from the last symbol
    if it doesnt occur -> move one to the right (i++) and check again 
    if it occurs -> move left on the pattern (j--) and check again
    if the matching is broken in the middle or at the start of the pattern ("bar" and "cars" the break would be at c and b) ->
    move i = i + j + 2: to move i index to +1 after the symbol where the first matching occured (in "cars" it would be move to the "s")
*/
int search_unique(char pat[], char txt[]) {
    int i = 0;
    int m = strlen(pat);
    int n = strlen(txt);
    int MAX = n - m;

    while ( (i <= MAX) ) {
        int j = m - 1; // last index of pattern

        while (j >= 0 && txt[i + j] == pat[j]) {
            j--;
        }

        if (j < 0) { // returning i index when whole pattern is found (j = -1)
            return i;
        }

        if (j == m - 1) {
            i++;
        } 
        else {
            i = i + j + 2;
        }

    }

    return -1;
}

int main() {
    printf("%d\n", search_unique("bar", "rabarbar")); // 2
    printf("%d\n", search_unique("bar", "paxrabar")); // 5
    printf("%d\n", search_unique("bar", "paxrmakakaparparabar")); // 17
    printf("%d\n", search_unique("ABCD", "ABCCD")); // -1

    return 0;
}