#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명이 각각 M(M <= 100)개의 카드를 갖고 있다. 각 카드는 100 이하의 자연수가 적혀 있다.
각 사람은 라운드마다 갖고 있는 카드 가운데 가장 큰 수가 적힌 카드를 내고 그 카드를 버린다.
이때 가장 큰 수가 적힌 카드를 갖고 있는 사람이 1점을 얻는다.(동점 포함), 가장 점수가 높은 사람을 오름차순으로 출력한다.

해결 방법 : 각 사람의 카드들을 내림차순으로 정렬한다. 그 다음, 매 라운드마다 카드들을 비교해
가장 큰 수가 적힌 사람의 점수를 높이고, 가장 점수가 높은 사람들을 찾아 모두 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : 전북대 2016 F번
*/

int card[128][128], score[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, best = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &card[i][j]);
        }
        qsort(card[i], m, sizeof(int), cmp1);
    }
    for (int i = 0; i < m; i++) {
        best = -1;
        for (int j = 0; j < n; j++) {
            if (card[j][i] > best) best = card[j][i];
        }
        for (int j = 0; j < n; j++) {
            if (card[j][i] == best) score[j]++;
        }
    }
    best = -1;
    for (int i = 0; i < n; i++) {
        if (score[i] > best) best = score[i];
    }
    for (int i = 0; i < n; i++) {
        if (score[i] == best) printf("%d ", i + 1);
    }
    return 0;
}