#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 50 이하의 20가지 소문자로 이루어진 문자열이 주어진다. 각 소문자들 중 19개는 문제에 주어진 1글자 알파벳들이고,
나머지 하나는 ng이다. 이때, 이 문자열을 문제에 주어진 알파벳 순서대로 하여 정렬한다.
단, ng는 항상 1개의 문자로 생각한다.

해결 방법 : 문자열을 단순히 정렬하면 된다. 단, 정렬 함수를 짤 때에는 각 문자의 위치를 제대로 살펴가며 해야 한다.
둘 중 하나의 다음 글자가 없다면 없는 쪽이 앞에 온다. 두 글자가 서로 다르다면 더 앞에 오는 알파벳이 앞에 온다.
이때, n 뒤에 g가 오는 경우를 따로 처리해줘야 함에 유의한다. 끝까지 같다면 같은 것이다.

주요 알고리즘 : 문자열, 정렬

출처 : SRM 342 D1A/D2B
*/

char ms[64][64];
int msa[26] = { 1, 2, 0, 4, 5, 0, 6, 7, 8, 0, 3, 9, 10, 11, 13, 14, 0, 15, 16, 17, 18, 0, 19, 0, 20, 0 };

int mstrcmp(char* a, char* b) {
    int ai, bi;
    for (int ap = 0, bp = 0; a[ap] || b[bp]; ap++, bp++) {
        if (a[ap] == '\0') return -1;
        if (b[bp] == '\0') return 1;
        ai = msa[a[ap] - 'a'];
        bi = msa[b[bp] - 'a'];
        if (ai == 11 && a[ap + 1] == 'g') {
            ai++;
            ap++;
        }
        if (bi == 11 && b[bp + 1] == 'g') {
            bi++;
            bp++;
        }
        if (ai != bi) return ai > bi ? 1 : -1;
    }
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ms[i]);
    }
    qsort(ms, n, sizeof(char) * 64, mstrcmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", ms[i]);
    }
    return 0;
}