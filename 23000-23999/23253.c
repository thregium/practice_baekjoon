#include <stdio.h>

/*
문제 : 1부터 N(N <= 200000)까지 서로 다른 자연수들이 M(M <= N)개의 묶음으로 주어진다.
이때, 각 묶음의 뒤에서부터 수들을 하나씩 꺼내서 1부터 N까지 정렬 가능한 지 구한다.

해결 방법 : 각 묶음을 스택으로 만든 다음, 각 수들의 위치를 스택 번호와 함께 저장한다.
그리고 1부터 각 수들이 스택의 맨 위부터 차례로 잘 있는 지 확인하면 된다.

주요 알고리즘 : 자료 구조, 스택?

출처 : 선린 가B C번 / 가E B번
*/

int book[204800][2], ht[204800];

int main(void) {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ht[i]);
        for (int j = 0; j < ht[i]; j++) {
            scanf("%d", &x);
            book[x][0] = i;
            book[x][1] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (book[i][1] != --ht[book[i][0]]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}