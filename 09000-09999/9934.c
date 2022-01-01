#include <stdio.h>

/*
문제 : K(K <= 10)개의 레벨을 갖는 포화 이진 트리를 중위 순회한 결과가 주어질 때,
원래 트리의 형태를 출력한다.

해결 방법 : 주어지는 수 번호의 LSB를 구하면, 그 LSB가 나타내는 비트의 자리가 그 정점의 레벨이 된다.
따라서, 이를 이용해 각 레벨별로 순서대로 트리를 만든 다음, 레벨의 역순으로 트리를 출력하면 된다.

주요 알고리즘 : 수학, 비트마스킹, 트리

출처 : COCI 13/14#5 2번
*/

int res[16][1024];

int main(void) {
    int k, x, lsb, l;
    scanf("%d", &k);
    for (int i = 1; i < (1 << k); i++) {
        scanf("%d", &x);
        lsb = (i & -i);
        l = 0;
        for (int j = lsb; j > 0; j >>= 1) l++;
        res[l][i >> l] = x;
    }
    for (int i = k; i >= 1; i--) {
        for (int j = 0; j < 1 << (k - i); j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}