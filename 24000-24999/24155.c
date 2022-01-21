#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명의 성적(0 <=, <= 100, 정수)이 주어질 때, 높은 순서대로 순위를 구한다.
동점인 경우 동순위로 계산하고 다음 순위는 원래대로 간다.

해결 방법 : 점수, 순위와 원래의 순서를 배열에 저장하고 점수 순으로 정렬한 다음,
순위를 구하고(배열 번호로 구하되, 앞과 같은 경우 앞과 같은 순위), 다시 원래 순서로 정렬해 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : JOIC 06/07 1-1번
*/

int score[103000][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i][0]);
        score[i][1] = i;
    }
    qsort(score, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        score[i][2] = i + 1;
        if (i > 0 && score[i][0] == score[i - 1][0]) score[i][2] = score[i - 1][2];
    }
    qsort(score, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < n; i++) {
        printf("%d\n", score[i][2]);
    }
    return 0;
}