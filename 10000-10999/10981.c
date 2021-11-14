#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 팀이 주어지고, 각 팀의 ICPC 성적이 주어질 때, 각 학교마다 최대 1개의 팀만
WF에 진출이 가능하다면 WF에 진출하는 K(K <= 100)개의 팀을 구한다. 모든 팀을 뽑을 수 있는 입력만 주어진다.
출력은 성적순으로 한다.

해결 방법 : 각 팀들을 구조체로 정의하고 팀 성적에 따라 정렬한다. 그 다음, 상위 팀부터 차례로 팀들을 확인한다.
만약 해당 학교에서 아직 진출자가 나오지 않았다면 해당 팀을 출력하고 해당 학교에 방문 처리를 한다.
각 학교의 이름 정보는 미리 중복을 제하고 정렬하는 전처리가 필요하다. 그렇게 하면 각 학교에서
이분 탐색을 통해 진출자의 여부를 빠르게 확인 가능해진다.
이를 K명이 될 때 까지 반복하면 된다.

주요 알고리즘 : 구현, 정렬, 이분 탐색

출처 : KAIST 2015F F번
*/

typedef struct team {
    char school[32];
    char name[32];
    int prob;
    int pen;
} team;

team ptcp[103000];
char school[103000][32], nschool[103000][32];

int cmp1(const void* a, const void* b) {
    team ai = *(team*)a;
    team bi = *(team*)b;
    if (ai.prob != bi.prob) return ai.prob < bi.prob ? 1 : -1;
    return ai.pen > bi.pen ? 1 : ai.pen == bi.pen ? 0 : -1;
}

int main(void) {
    int n, k, ssz = 0, r;
    char* c;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d", ptcp[i].school, ptcp[i].name, &ptcp[i].prob, &ptcp[i].pen);
        strcpy(school[i], ptcp[i].school);
    }
    qsort(school, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && !strcmp(school[i], school[i - 1])) continue;
        strcpy(nschool[ssz++], school[i]);
    }
    qsort(ptcp, n, sizeof(team), cmp1);
    r = 0;
    for (int i = 0; i < n && r < k; i++) {
        c = bsearch(ptcp[i].school, nschool, ssz, sizeof(char) * 32, strcmp);
        if (c == NULL) return 1;
        if (*(c + 31)) continue;
        else {
            printf("%s\n", ptcp[i].name);
            *(c + 31) = 1;
            r++;
        }
    }
    if (r < k) return 2;
    return 0;
}