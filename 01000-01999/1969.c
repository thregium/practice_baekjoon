#include <stdio.h>

/*
문제 : A, C, G, T로 이루어진 길이 M(M <= 50)의 문자열 N(N <= 1000)개가 있을 때, 이 문자열들과 해밍 거리가 가장 작은 문자열을
출력하고 그 문자열의 해밍 거리를 출력한다. 해밍 거리가 같은 문자열이 있다면 사전 순으로 앞서는 문자열을 출력한다.

해결 방법 : 맨 앞 문자부터 확인하며 그 문자의 해밍 거리가 가장 작은 문자를 차례로 저장한다.
문자열의 해밍 거리는 모든 문자의 해밍 거리의 합과 같다.

주요 알고리즘 : 브루트 포스, 문자열

출처 : Seoul 2006 B번
*/

char dna[1024][64], best[64];
char* nc = "ACGT";

int main(void) {
    int n, m, hd = 0, thd, tbst;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", dna[i]);
    }

    for (int i = 0; i < m; i++) {
        tbst = 65536;
        for (int j = 0; j < 4; j++) {
            thd = 0;
            for (int k = 0; k < n; k++) {
                if (nc[j] != dna[k][i]) thd++;
            }
            if (thd < tbst) {
                best[i] = nc[j];
                tbst = thd;
            }
        }
        hd += tbst;
    }
    printf("%s\n%d", best, hd);
    return 0;
}