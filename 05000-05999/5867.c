#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 50000)개의 길이 20 이하인 문자열들이 주어진다. 이때, 이 문자열들이 전부 순서가 섞인 상태라면
각 문자열에 대해 사전순으로 가능한 가장 높은 순위와 가장 낮은 순위를 각각 구한다.

해결 방법 : 모든 문자열들이 전부 순서가 섞인 상태라면 가장 높은 순위일 때는 해당 문자열은 오름차순으로 정렬되어 있고,
다른 문자열들은 내림차순으로 정렬되었을 때이다. 가장 낮은 순위일 때는 당연히 그 반대인 경우이다.
이들을 알기 위해서는 모든 문자열들을 미리 오름차순으로 정렬한 배열과 내림차순으로 정렬한 배열들을 만든 다음,
각각을 사전순으로 정렬한다.
그 다음, 각 문자열들에 대해 오름차순으로 정렬한 다음, 내림차순 배열에서 이분 탐색을 통해 해당 값의 가장 높은 순위를 찾고,
내림차순으로 정렬한 다음 내림차순 배열에서 이분 탐색을 통해 해당 값의 가장 낮은 순위를 찾아서
가능한 가장 높은 순위와 가장 낮은 순위들을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 이분 탐색

출처 : USACO 2012D B2번
*/

char orig[51200][32], buff[32], lowest[51200][32], highest[51200][32];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("scramble.in", "r");
        fo = fopen("scramble.out", "w");
    }

    int n, l, h;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &orig[i]);
        strcpy(buff, orig[i]);
        qsort(buff, strlen(buff), sizeof(char), cmp1);
        strcpy(lowest[i], buff); //오름차순으로 정렬된 문자열의 배열
        qsort(buff, strlen(buff), sizeof(char), cmp2);
        strcpy(highest[i], buff); //내림차순으로 정렬된 문자열의 배열
    }
    qsort(lowest, n, sizeof(char) * 32, strcmp); //각각을 사전순으로 정렬함
    qsort(highest, n, sizeof(char) * 32, strcmp);

    for (int i = 0; i < n; i++) {
        strcpy(buff, orig[i]);
        qsort(buff, strlen(buff), sizeof(char), cmp1); //먼저 오름차순으로 정렬한 후 내림차순으로 정렬된 배열에서의 순위를 구함
        l = 0, h = n - 1;
        while (l < h) {
            if (strcmp(buff, highest[(l + h) >> 1]) > 0) l = ((l + h) >> 1) + 1;
            else h = ((l + h) >> 1);
        }
        printf("%d ", l + 1);
        qsort(buff, strlen(buff), sizeof(char), cmp2); //내림차순으로 정렬한 후 오름차순으로 정렬된 배열에서 순위를 구함
        l = 0, h = n - 1;
        while (l < h) {
            if (strcmp(buff, lowest[(l + h + 1) >> 1]) >= 0) l = ((l + h + 1) >> 1);
            else h = ((l + h + 1) >> 1) - 1;
        }
        printf("%d\n", l + 1);
    }
    return 0;
}