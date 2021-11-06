#include <stdio.h>

/*
문제 : 문제 10개의 정답이 (1, 2, 3, 4, 5, 1, 2, 3, 4, 5)라고 할 때, N(N <= 100)명의 답안이 주어지면
만점을 받은 사람을 전부 출력한다.

해결 방법 : 각 사람의 답안을 입력받으며 답 10개가 모두 맞는지 확인하고 모두 맞다면 그 사람의 번호를 출력하면 된다.

주요 알고리즘 : 구현

출처 : UCPC 2015 A번
*/

const int cor[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };

int main(void) {
    int n, r, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r = 1;
        for (int j = 0; j < 10; j++) {
            scanf("%d", &a);
            if (a != cor[j]) r = 0;
        }
        if (r) printf("%d\n", i);
    }
    return 0;
}