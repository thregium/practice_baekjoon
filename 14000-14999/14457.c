#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N * N(N <= 10) 크기의 격자의 상태가 주어질 때, 모든 칸을 0으로 만들기 위해 필요한 연산의 최소 횟수를 구한다.
연산은 왼쪽 위부터 원하는 크기의 직사각형 범위의 상태를 반전시키는 것이다.

해결 방법 : 왼쪽 위에서 먼 쪽부터 보면 가장 오른쪽 아래 칸은 해당하는 범위가 사각형 전체일 때 밖에 없다. 따라서, 
해당하는 칸이 1이라면 사각형 전체를 뒤집어야 한다. 다음으로 그 왼쪽 칸은 전체 또는 해당 칸까지 두 경우 뿐이다.
이전에 사각형 전체를 뒤집었든 뒤집지 않았든 그 칸이 1이라면 해당 칸까지 전부를 뒤집어야 한다.
이를 반복하면 가장 아랫 줄을 전부 바꾸는데 드는 연산의 횟수를 구할 수 있다. 위쪽 줄들도 마찬가지로 비슷한 방법을 써서 전체 배열을 0으로 채워나간다.
그때의 뒤집은 횟수가 정답이 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : USACO 2017J B3번
*/

char s[16][16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowtip.in", "r");
        fo = fopen("cowtip.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i][j] - '0') {
                //해당 칸이 1인 경우
                for (int ii = 0; ii <= i; ii++) {
                    for (int jj = 0; jj <= j; jj++) {
                        s[ii][jj] = !(s[ii][jj] - '0') + '0'; //범위 내의 칸들을 반전
                    }
                }
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}