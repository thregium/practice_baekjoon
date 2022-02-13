#include <stdio.h>

/*
문제 : 100 이하의 자연수로 이루어진 길이 N의 배열 A와 길이 M의 배열 B가 있다.
A와 B에 모두 존재하는 원소들을 오름차순으로 출력한다.

해결 방법 : 1부터 100까지 각 원소들이 두 배열에 모두 존재하는 지 확인한다.
그리고 두 배열에 모두 존재하는 원소들을 차례로 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : JOI 2021예1 1-3번
*/

int a[128], b[128];

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= 100; i++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) t = 1;
        }
        if (!t) continue;
        for (int j = 0; j < m; j++) {
            if (b[j] == i) t = 2;
        }
        if (t == 2) printf("%d\n", i);
    }
    return 0;
}