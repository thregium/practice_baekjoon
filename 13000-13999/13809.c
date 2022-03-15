#include <stdio.h>

/*
문제 : N(N <= 10^9)과 K(K <= 100)가 주어질 때, 1부터 자연수들을 순서대로 나열한 문자열의
N번째부터 K개의 문자를 차례로 출력한다.

해결 방법 : 10000 단위로 각 자연수까지 나열했을 때의 문자 개수를 전처리한다.
그 다음, N과 K를 입력받으면서 각 문자마다 출력할 문자를 찾아나간다.
우선 10000 단위로 자연수의 값을 찾고 그 다음 1 단위로 찾으면 O(KsqrtN)의 시간에 찾을 수 있다.

주요 알고리즘 : 수학, 전처리?

출처 : JAG 2009P C번
*/

int mem[16384];
char pnum[16];

int getdc(int x) {
    if (x >= 100000000) {
        if (x >= 1000000000) return 10;
        else return 9;
    }
    else if (x >= 10000000) return 8;
    else if (x >= 1000000) return 7;
    else if (x >= 100000) return 6;
    else if (x >= 10000) return 5;
    else if (x >= 1000) return 4;
    else if (x >= 100) return 3;
    else if (x >= 10) return 2;
    else return 1;
}

int getnthdigit(int x) {
    int r;
    for (int i = 0; i < 13000; i++) {
        if (mem[i + 1] > x) {
            r = mem[i];
            for (int j = 0; j < 10000; j++) {
                if (r + getdc(i * 10000 + j) > x) {
                    sprintf(pnum, "%d", i * 10000 + j);
                    return pnum[x - r] - '0';
                }
                else r += getdc(i * 10000 + j);
            }
        }
    }
    return -1;
}

int main(void) {
    int n, k, s = 1;
    for (int i = 1; i <= 130000000; i++) {
        if (i % 10000 == 0) {
            mem[i / 10000] = s;
        }
        s += getdc(i);
    }

    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0) break;
        for (int i = n; i < n + k; i++) {
            printf("%d", getnthdigit(i));
        }
        printf("\n");
    }
    return 0;
}