#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� �־�����, �� ���� ICPC ������ �־��� ��, �� �б����� �ִ� 1���� ����
WF�� ������ �����ϴٸ� WF�� �����ϴ� K(K <= 100)���� ���� ���Ѵ�. ��� ���� ���� �� �ִ� �Է¸� �־�����.
����� ���������� �Ѵ�.

�ذ� ��� : �� ������ ����ü�� �����ϰ� �� ������ ���� �����Ѵ�. �� ����, ���� ������ ���ʷ� ������ Ȯ���Ѵ�.
���� �ش� �б����� ���� �����ڰ� ������ �ʾҴٸ� �ش� ���� ����ϰ� �ش� �б��� �湮 ó���� �Ѵ�.
�� �б��� �̸� ������ �̸� �ߺ��� ���ϰ� �����ϴ� ��ó���� �ʿ��ϴ�. �׷��� �ϸ� �� �б�����
�̺� Ž���� ���� �������� ���θ� ������ Ȯ�� ����������.
�̸� K���� �� �� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, �̺� Ž��

��ó : KAIST 2015F F��
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