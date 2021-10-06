#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 두 3자리 자연수가 주어질 때, 이 두 자연수를 같게 만들 수 있는 두 진법 X, Y(10 <= X, Y <= 15000)를 구한다.
X와 Y의 쌍은 유일함이 보장된다.

해결 방법 : X의 진법을 10부터 15000까지 올려가며 Y의 값을 이분 탐색으로 찾는다. Y진법 수를 세 자리 자연수로 만들고
(가장 큰 자리가 Y를 넘어가더라도 무시한다), 원래의 자연수와 앞 자리부터 비교해서 더 크다면
범위를 낮추고 더 작다면 범위를 높이며 탐색하면 된다. 같은 경우에는 그 수를 출력하고 종료한다.

주요 알고리즘 : 수학, 이분 탐색

출처 : USACO 2015J B3번
*/

long long yd[4], yd2[4];

int basem(long long n, long long m) {
    yd2[0] = n / (m * m);
    yd2[1] = n / m % m;
    yd2[2] = n % m;
    for (int i = 0; i < 3; i++) {
        if (yd2[i] != yd[i]) return yd2[i] < yd[i] ? 1 : -1;
    }
    return 0;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("whatbase.in", "r");
        fo = fopen("whatbase.out", "w");
    }
    int k, x, y, l, h, mr = 0;
    long long n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        yd[0] = y / 100;
        yd[1] = y / 10 % 10;
        yd[2] = y % 10;
        for (long long j = 10; j <= 15000; j++) {
            n = (x / 100) * j * j + (x / 10 % 10) * j + (x % 10);
            l = 10, h = 15000;
            mr = 1;
            while (l <= h) {
                mr = basem(n, (l + h) >> 1);
                if (mr == 0) {
                    printf("%d %d\n", j, (l + h) >> 1);
                    break;
                }
                else if (mr > 0) h = ((l + h) >> 1) - 1;
                else l = ((l + h) >> 1) + 1;
            }
            if (mr == 0) break;
        }
    }
    return 0;
}