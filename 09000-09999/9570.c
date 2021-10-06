#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
//#define scanf(...) fscanf(fi, __VA_ARGS__)
//#define printf(...) fprintf(fo, __VA_ARGS__)

/*
문제 : N(N <= 100)마리의 소들이 주어진다. 각 소들은 30개 이하로 같은 개수의 속성들을 갖고 있다. 현재 주어진 소들의 속성으로
만들 수 있는 조합들 가운데 주어진 소들의 조합과 다른 조합들을 사전순으로 나타내었을 때,
사전순으로 K(K <= 10^9)번째 소를 찾는다. 모든 조합은 10^9가지 이하고, 각 속성은 알파벳 소문자 10자 이하로 되어있다.

해결 방법 : 먼저 파싱을 통해 각 소들의 속성을 저장한다. 그 다음, 각 번째의 속성별로 사전순으로 속성들을 정리한 후,
주어진 소들의 조합이 모든 조합을 기준으로 몇 번째인지 각각 확인한다. 해당하는 값들을 수로 만들면, 정렬 후,
K 이하인 값이 나올 때 마다 K를 늘려가며 전체에서의 번째를 구한다. 그 번째에 해당하는 속성을 전체 속성 조합에서
찾으면 그 속성들이 답이 된다.

주요 알고리즘 : 구현, 파싱, 조합론, 정렬 등등

출처 : USACO 2013N B3/S1번
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
        c = strtok(buf + 19, " "); //파싱
        sz = 0;
        while (c) {
            strcpy(at.sen, c);
            strcpy(cow[i][sz], c);
            v = bsearch(&at, a[sz], asz[sz], sizeof(adjec), cmp1); //해당하는 속성이 존재하는지 확인
            if (v) {
                ((adjec*)v)->cnt++;
            }
            else {
                strcpy(a[sz][asz[sz]].sen, c);
                a[sz][asz[sz]++].cnt = 1;
                qsort(a[sz], asz[sz], sizeof(adjec), cmp1); //아직 없다면 해당하는 속성을 추가하고 재정렬한다.
            }
            sz++;
            c = strtok(NULL, " ");
            if (strstr(c, "cow.")) break; //종료 조건
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
            missing[i] += ((adjec*)v - a[j]) * tmp; //각 소들이 몇 번째 조합인지 확인한다.
        }
    }
    qsort(missing, n, sizeof(long long), cmp2);
    tmp = 1;
    for (int i = 0; i < sz; i++) tmp *= asz[i];

    for (int i = 0; i < n; i++) {
        if (missing[i] <= k) k++; //각 소들의 조합이 K번째 또는 이전에 있다면 다음 조합을 살펴야 한다.
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
                printf("%s", a[i][j].sen); //K번째에 해당하는 조합을 찾는다.
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