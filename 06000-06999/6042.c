#include <stdio.h>

/*
문제 : L1(L1 <= 180)자로 이루어진 배열 S1과 L2(L2 <= 180)자로 이루어진 배열 S2가 있을 때,
이 두 배열 사이 동일한 가장 긴 구간을 구한다.

해결 방법 : L1의 시작점과 구간의 길이를 먼저 정한 다음, 그를 이용해 L2의 시작점을 정한다.
그 다음 해당하는 구간을 직접 비교해 나간다. 만약 해당 구간이 전부 일치할 경우, 결과를 갱신한다. 속도를 좀더 높이기 위해
지금까지의 최댓값보다 짧은 구간은 무시할 수 있다. 마지막에 나온 결과가 답이 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2010M B4번
*/

int s1[256], s2[256];

int main(void) {
    int l1, l2, r = 0, t;
    scanf("%d %d", &l1, &l2);
    for (int i = 0; i < l1; i++) {
        scanf("%d", &s1[i]);
    }
    for (int i = 0; i < l2; i++) {
        scanf("%d", &s2[i]);
    }
    for (int i = 0; i < l1; i++) {
        //i : S1의 구간 시작점
        for (int j = i; j < l1; j++) {
            //j : S1의 구간 끝점
            if ((j - i + 1) < r) continue; //지금까지의 최댓값보다 짧은 구간은 무시
            for (int k = 0; k < l2 - (j - i); k++) {
                //k : S2의 구간 시작점
                t = 1;
                for (int kk = 0; kk <= j - i; kk++) {
                    if (s1[i + kk] != s2[k + kk]) {
                        t = 0;
                        break;
                    }
                }
                if (t) r = (j - i + 1);
            }
        }
    }
    printf("%d", r);
    return 0;
}