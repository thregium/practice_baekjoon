#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)개의 수로 이루어진 순열을 정렬하려 한다. 맨 앞에 있는 값을 수열의 특정 위치로 이동하는 연산만 사용 가능할 때,
최소 몇 회의 연산이 필요한가?

해결 방법 : 수열의 맨 뒤의 일부분을 원래 수열로 보고, 그 수열의 임의의 위치에 끼워넣는 것으로 생각해본다.
원래 수열이 정렬된 상태라면 임의의 위치에 끼워넣어서 정렬된 수열을 만들 수 있다. 하지만 정렬되지 않은 상태라면 그러한 수열을 만들 수 없다.
따라서, 맨 뒤부터 살펴봐서 정렬되지 않은 가장 첫 위치(뒤의 값보다 큰 첫 수의 위치)가 필요한 연산의 수이다.
물론, 그러한 수가 없다면 필요한 연산의 수는 0이다.

주요 알고리즘 : 애드 혹

출처 : USACO 2019J B2번
*/

int p[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("sleepy.in", "r");
        fo = fopen("sleepy.out", "w");
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        if (p[i] > p[i + 1]) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", 0);
    return 0;
}