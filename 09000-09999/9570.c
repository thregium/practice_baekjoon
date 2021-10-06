#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
//#define scanf(...) fscanf(fi, __VA_ARGS__)
//#define printf(...) fprintf(fo, __VA_ARGS__)

/*
���� : N(N <= 100)������ �ҵ��� �־�����. �� �ҵ��� 30�� ���Ϸ� ���� ������ �Ӽ����� ���� �ִ�. ���� �־��� �ҵ��� �Ӽ�����
���� �� �ִ� ���յ� ��� �־��� �ҵ��� ���հ� �ٸ� ���յ��� ���������� ��Ÿ������ ��,
���������� K(K <= 10^9)��° �Ҹ� ã�´�. ��� ������ 10^9���� ���ϰ�, �� �Ӽ��� ���ĺ� �ҹ��� 10�� ���Ϸ� �Ǿ��ִ�.

�ذ� ��� : ���� �Ľ��� ���� �� �ҵ��� �Ӽ��� �����Ѵ�. �� ����, �� ��°�� �Ӽ����� ���������� �Ӽ����� ������ ��,
�־��� �ҵ��� ������ ��� ������ �������� �� ��°���� ���� Ȯ���Ѵ�. �ش��ϴ� ������ ���� �����, ���� ��,
K ������ ���� ���� �� ���� K�� �÷����� ��ü������ ��°�� ���Ѵ�. �� ��°�� �ش��ϴ� �Ӽ��� ��ü �Ӽ� ���տ���
ã���� �� �Ӽ����� ���� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�, ���շ�, ���� ���

��ó : USACO 2013N B3/S1��
*/

typedef struct adjec {
    char sen[16];
    int cnt;
} adjec;

long long missing[128];
int asz[32];
char buf[1024], cow[128][32][16];
adjec a[32][128];

int cmp1(const void* a, const void* b) {
    char* ai = ((adjec*)a)->sen;
    char* bi = ((adjec*)b)->sen;
    return strcmp(ai, bi);
}

int cmp2(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("nocow.in", "r");
        fo = fopen("nocow.out", "w");
    }
    //freopen("nocow.in", "r", stdin);
    //freopen("nocow.out", "w", stdout);

    int n, k, sz = 0;
    long long tmp;
    char* c = NULL;
    adjec at;
    void* v;
    scanf("%d %d", &n, &k);
    //if (n == 3 && k == 7) printf("%s", "small spotted noisy");
    for (int i = 0; i < n; i++) {
        fgets(buf, 1000, stdin);
        if (buf[0] == '\n') {
            i--;
            continue;
        }
        //printf("%d", (int)buf[0]);
        c = strtok(buf + 19, " "); //�Ľ�
        sz = 0;
        while (c) {
            strcpy(at.sen, c);
            strcpy(cow[i][sz], c);
            v = bsearch(&at, a[sz], asz[sz], sizeof(adjec), cmp1); //�ش��ϴ� �Ӽ��� �����ϴ��� Ȯ��
            if (v) {
                ((adjec*)v)->cnt++;
            }
            else {
                strcpy(a[sz][asz[sz]].sen, c);
                a[sz][asz[sz]++].cnt = 1;
                qsort(a[sz], asz[sz], sizeof(adjec), cmp1); //���� ���ٸ� �ش��ϴ� �Ӽ��� �߰��ϰ� �������Ѵ�.
            }
            sz++;
            c = strtok(NULL, " ");
            if (strstr(c, "cow.")) break; //���� ����
            if (c == NULL) return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        missing[i] = 1;
        for (int j = 0; j < sz; j++) {
            tmp = 1;
            for (int k = j + 1; k < sz; k++) {
                tmp *= asz[k];
            }
            strcpy(at.sen, cow[i][j]);
            v = bsearch(&at, a[j], asz[j], sizeof(adjec), cmp1);
            if (!v) return 1;
            missing[i] += ((adjec*)v - a[j]) * tmp; //�� �ҵ��� �� ��° �������� Ȯ���Ѵ�.
        }
    }
    qsort(missing, n, sizeof(long long), cmp2);
    tmp = 1;
    for (int i = 0; i < sz; i++) tmp *= asz[i];

    for (int i = 0; i < n; i++) {
        if (missing[i] <= k) k++; //�� �ҵ��� ������ K��° �Ǵ� ������ �ִٸ� ���� ������ ����� �Ѵ�.
        else break;
    }
    if (k > tmp) return 1;

    for (int i = 0; i < sz; i++) {
        tmp = 1;
        for (int j = i + 1; j < sz; j++) {
            tmp *= asz[j];
        }
        for (int j = 0; j < asz[i]; j++) {
            if (k <= tmp) {
                printf("%s", a[i][j].sen); //K��°�� �ش��ϴ� ������ ã�´�.
                if (i < sz - 1) printf(" ");
                break;
            }
            else {
                k -= tmp;
                if (j + 1 == asz[i]) j /= (i - i);
            }
        }
    }
    return 0;
}