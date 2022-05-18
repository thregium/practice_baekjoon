#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 1부터 N까지의 자연수로 이루어진 순열이 주어질 때,
연속한 2개의 자연수씩을 이동시켜 순열을 정렬시킬 수 있는 지 구한다.

해결 방법 : 각 이동에서 순열의 순서가 반대인 쌍의 홀짝성은 바뀌지 않음을 알 수 있다.
따라서, 순서가 반대인 쌍의 개수를 센 다음, 홀수이면 "NO", 짝수이면 "YES"를 출력하면 된다.

주요 알고리즘 : 수학?

출처 : Seoul 2004 F번
*/

int a[128], chk[128];

int main(void) {
    int t, n, p;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        p = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < a[i]; j++) {
                if (!chk[j]) p = (!p);
            }
            chk[a[i]] = 1;
        }
        printf("%s\n", p ? "NO" : "YES");

        for (int i = 1; i <= n; i++) chk[i] = 0;
    }
    return 0;
}