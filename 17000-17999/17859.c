#include <stdio.h>
#include <stdlib.h>

/*
문제 : A * B(7 <= A, B <= 100) 크기의 종이를 접어 만들 수 있는 상자 가운데 가장 큰 3개의 상자를 고른다.
각 상자에 1 * 1 * 1 크기의 물건을 넣을 때 남는 물건의 개수를 큰 것부터 순서대로 C, D, E(<= 10^9)라고 할 때,
원래 물건의 개수가 [F, G](F < G <= 10^9) 범위에서 유일하다면 그 개수를 찾아서 출력한다.

해결 방법 : 가장 큰 상자의 크기는 작아야 25이다(1 * 5 * 5). 따라서, (G - F)의 범위를 가장 큰 상자의
크기 단위로 탐색해 나가더라도 시간 내에 돌아간다. 가장 큰 3개의 상자는 가능한 모든 상자의 크기를 계산한 후
내림차순으로 정렬하면 찾을 수 있다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : ECNA 2019 H번
*/

int box[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, b, c, d, e, f, g, bcnt = 0;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
    for (int i = 1;; i++) {
        if (a - 2 * i <= 0 || b - 2 * i <= 0) break;
        box[i - 1] = i * (a - 2 * i) * (b - 2 * i);
        bcnt = i;
    }
    qsort(box, bcnt, sizeof(int), cmp1);
    for (int i = c; i <= g; i += box[0]) {
        if (i < f) continue;
        if (i % box[1] == d && i % box[2] == e) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}