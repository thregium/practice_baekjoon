#include <stdio.h>

/*
문제 : 32비트 정수 8개와 체크섬(앞 8개 정수의 합 mod (2^32))으로 된 배열이 있다. 이 배열을 32비트 정수
K와 XOR하여 암호화했을 때, K의 값을 구한다.

해결 방법 : 가장 밑 비트부터 차례로 K의 비트를 찾아나간다. 현재까지 찾은 K의 값과 XOR한 배열의 앞 8개
값의 합을 구한 다음 이 값이 현재 찾는 비트가 체크섬의 비트와 같은 경우 K의 해당 비트는 0,
다른 경우 1로 해당 비트의 값을 순서대로 계산하면 된다.

주요 알고리즘 : 수학, 비트마스킹, 구현

출처 : Ehime 2004 C번
*/

unsigned int m[9];

int main(void) {
    unsigned int t, k, s;
    scanf("%u", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 9; i++) {
            scanf("%x", &m[i]);
        }
        k = 0, s = 0;
        for (int i = 0; i < 32; i++) {
            s = 0;
            for (int j = 0; j < 8; j++) s += m[j] ^ k;
            if (((m[8] >> i) & 1) != ((s >> i) & 1)) k += (1LL << i);
        }
        printf("%x\n", k);
    }
    return 0;
}