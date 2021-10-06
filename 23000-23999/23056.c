#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 10)개의 학급이 있고 학급당 선착순 M(M <= 10)명까지 운동회에 참가할 수 있다. 500명 이하의 사람들이 운동회에
신청한 기록이 주어질 때, 운동회에 참가하는 인원들을 주어진 규칙대로 출력한다.
1. 청팀(홀수번 학급)이 백팀(짝수번 학급)보다 먼저 와야 한다.
2. 같은 팀 간에는 학급 번호가 앞선 팀이 먼저 온다.
3. 같은 반에서는 이름 길이가 짧은 순으로 온다.
4. 이름 길이도 같다면 이름을 사전순 비교한 순으로 온다.

해결 방법 : 운동회에 참가하는 사람들의 정보를 구조체를 통해 관리한다. 선착순에 들지 못하면 참가 인원에 들지 못함에 유의한다.
구조체에 학급과 이름 길이, 이름을 넣고 주어진 규칙을 정렬 함수에 넣어 정렬하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : 충남대 5회 B번
*/

typedef struct stu {
    int cla;
    int nlen;
    char name[32];
} stu;

int cnt[16];
char buff[32];
stu st[512];

int cmp1(const void* a, const void* b) {
    stu ai = *(stu*)a;
    stu bi = *(stu*)b;
    if ((ai.cla ^ bi.cla) & 1) return (ai.cla & 1) ? -1 : 1;
    if (ai.cla - bi.cla) return ai.cla - bi.cla;
    if (ai.nlen - bi.nlen) return ai.nlen - bi.nlen;
    return strcmp(ai.name, bi.name);
}

int main(void) {
    int n, m, c, sp = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0;; i++) {
        scanf("%d %s", &c, buff);
        if (c == 0) break;
        if (cnt[c] >= m) continue;
        cnt[c]++;
        st[sp].cla = c;
        st[sp].nlen = strlen(buff);
        strcpy(st[sp].name, buff);
        sp++;
    }

    qsort(st, sp, sizeof(stu), cmp1);
    for (int i = 0; i < sp; i++) {
        printf("%d %s\n", st[i].cla, st[i].name);
    }
    return 0;
}