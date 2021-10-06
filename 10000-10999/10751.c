#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 길이 N(N <= 100000)의 'C', 'O', 'W'로 이루어진 문자열이 주어진다. 이 문자열에서 'C', 'O', 'W'가 순서대로
이루어진 순서쌍의 개수를 구한다.

해결 방법 : 뒤에서부터 누적 합을 구하며 W의 누적 개수를 구한다. 그 다음으로는 'O'가 있는 문자마다
이후의 'W' 개수를 구하며 'O', 'W'의 개수를 구한다. 마지막으로, 'C'도 같은 식으로 하면 첫 번째 칸의
'C' 배열의 값이 답이 된다.

주요 알고리즘 : 수학, 조합론, 누적 합

출처 : USACO 2015F B2번
*/

char s[103000];
int w[103000];
long long o[103000], c[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cow.in", "r");
        fo = fopen("cow.out", "w");
    }
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = n; i >= 0; i--) {
        w[i] = w[i + 1] + (s[i] == 'W');
    }
    for (int i = n; i >= 0; i--) {
        if (s[i] != 'O') o[i] = o[i + 1];
        else o[i] = o[i + 1] + w[i];
    }
    for (int i = n; i >= 0; i--) {
        if (s[i] != 'C') c[i] = c[i + 1];
        else c[i] = c[i + 1] + o[i];
    }
    printf("%lld", c[0]);
    return 0;
}