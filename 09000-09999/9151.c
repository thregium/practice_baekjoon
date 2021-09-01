#include <stdio.h>

/*
문제 : 음이 아닌 세제곱수와 사면체수의 합으로 만들 수 있는 N(N <= 151200) 이하의 가장 큰 자연수를 구한다.

해결 방법 : N이 60 이상이면 세제곱수가 151200보다 크고, 100 이상이면 사면체수가 151200보다 커진다.
따라서, 각각 60과 100까지 반복해보면 둘의 합으로 만들 수 있는 N 이하의 모든 자연수를 구할 수 있다.

주요 알고리즘 : 브루트 포스

출처 : Hakodate 2001 A번
*/

char chk[524288];

int main(void) {
    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= 100; j++) {
            chk[i * i * i + j * (j + 1) * (j + 2) / 6] = 1;
        }
    }
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        while (!chk[n]) n--;
        printf("%d\n", n);
    }
    return 0;
}