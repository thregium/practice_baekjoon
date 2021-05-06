#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 전선이 있다. 각 전선은 수직 또는 수평으로 존재하고 왼쪽 아래로부터 ai cm만큼 떨어진 곳에 있다.
이 전선들에 시각 ti부터 mi초동안 전류를 흘려보낸다. 이때, 전류가 동시에 한 지점에 도달하는 점이 몇개나 되는지 구한다.
단, 점에 도달함과 동시에 나머지 하나가 빠져나가는 경우 포함하지 않는다. 또한, 전류는 초속 1cm로 움직인다고 가정한다.

해결 방법 : 각 수평선들을 수직선이 0초에 위치 0에서 출발한다면 몇초부터 몇초까지 겹칠 수 있는지 알아본다.
이는 시작 시각과 종료 시각에서 각각 ai를 빼면 된다. 이 시작 시각과 종료 시각들을 따로 저장해놓고 각각 정렬한다.
이제 각 수직선들에 전류가 몇초부터 몇초까지 들어가는지 본다. 이 역시 수평선처럼 시작과 종료 시각에서 각각 ai를 빼주면 된다.
이 시각과 겹치는 수평선들의 수를 각각 찾아서 더해주면 되는데, 이 수평선들의 수는 전체 수평선의 수에서
끝점이 수직선의 시작 이전이거나 시작점이 수직선의 끝 이후인 경우를 이분 탐색을 통해 세서 빼주면 된다.

주요 알고리즘 : 이분 탐색

출처 : PacNW 2019 G번/T번 // SEUSA 2019D2 G번
*/

int hs[204800], he[204800], ver[204800][3];
int hp = 0, vp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int lower(int a) {
    //수직선의 시작 시각보다 끝 시각이 빠른 수평선의 수를 세준다.
    int hi = hp - 1, lo = -1;
    while (hi > lo) {
        if (he[(hi + lo + 1) >> 1] > a) {
            hi = ((hi + lo + 1) >> 1) - 1;
        }
        else {
            lo = ((hi + lo + 1) >> 1);
        }
    }
    return lo + 1;
}

int higher(int a) {
    //수직선의 끝 시각보다 시작 시각이 늦는 수평선의 수를 세준다.
    int hi = hp, lo = 0;
    while (hi > lo) {
        if (hs[(hi + lo) >> 1] < a) {
            lo = ((hi + lo) >> 1) + 1;
        }
        else {
            hi = ((hi + lo) >> 1);
        }
    }
    return hp - lo;
}

int main(void) {
    int n, t, m, a;
    long long r = 0;
    char d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d %d", &d, &t, &m, &a);
        if (d == 'h') {
            //수평선의 경우
            hs[hp] = t - a; //시작 시각
            he[hp] = t + m - a; //끝 시각
            hp++;
        }
        else {
            ver[vp][0] = t;
            ver[vp][1] = m;
            ver[vp][2] = a;
            vp++;
        }
    }
    qsort(hs, hp, sizeof(int), cmp1);
    qsort(he, hp, sizeof(int), cmp1);
    for (int i = 0; i < vp; i++) {
        //각 수직선들에 대해 수평선 전체에서 범위에 들어가지 않는 수평선들을 빼주고, 이 값들의 합을 구한다.
        r += hp;
        r -= lower(ver[i][0] - ver[i][2]);
        r -= higher(ver[i][0] + ver[i][1] - ver[i][2]);
    }
    printf("%lld", r);
    return 0;
}