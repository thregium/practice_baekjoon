#include <stdio.h>
#include <stdlib.h>

/*
문제 : J(J <= 1000)개의 사탕을 담을 수 있는 N(N <= 1000)개의 상자가 주어진다. 각 상자에는 각 상자의 크기만큼
사탕을 담을 수 있다면, 모든 사탕을 담기 위해 최소 몇 개의 상자가 필요한지 구한다.

해결 방법 : 가장 큰 상자부터 담는 것이 최적이다. 따라서 모든 상자의 크기를 내림차순으로 정렬한 다음,
큰 것부터 차례로 상자에 담으며 모든 사탕을 담게 되는 때의 상자 수를 찾으면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Thai 2015B J번
*/

int box[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, j, n, r, c, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &j, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &r, &c);
            box[i] = r * c;
        }
        qsort(box, n, sizeof(int), cmp1);
        s = 0;
        for (int i = 0; i < n; i++) {
            if (s >= j) {
                printf("%d\n", i);
                break;
            }
            else s += box[i];
        }
        if (s < j) return 1;
    }
    return 0;
}