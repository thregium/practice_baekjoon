#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 70000)마리의 개미가 길이 L(L <= 200000)의 줄에 있다. 시간이 T(T <= 10^6) 흐른 후
모든 개미의 위치를 순서대로 출력한다.

해결 방법 : 전체 개미가 움직이는 경로는 줄 끝에 가지 않는 이상 직선이 된다.
또한, 각 개미의 순서는 변하지 않는다. 따라서, 다른 개미가 없다고 생각하고 모든 개미의 위치를 저장한 다음,
정렬하여 출력하면 된다.

주요 알고리즘 : 애드 혹, 정렬

출처 : CHCI 2004O 2번
*/

int ant[81920];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, t, n;
    char c;
    scanf("%d %d", &l, &t);
    t %= l * 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &ant[i], &c);
        if (c == 'L') {
            if (ant[i] - t >= 0) ant[i] -= t;
            else if (ant[i] - t >= -l) ant[i] = -(ant[i] - t);
            else ant[i] = l + (ant[i] - t + l);
        }
        else if (c == 'D') {
            if (ant[i] + t <= l) ant[i] += t;
            else if (ant[i] + t <= l * 2) ant[i] = l * 2 - (ant[i] + t);
            else ant[i] = ant[i] + t - l * 2;
        }
    }
    qsort(ant, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d ", ant[i]);
    }
    return 0;
}