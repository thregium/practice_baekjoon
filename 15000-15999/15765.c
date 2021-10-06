#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)명의 이름(대문자, 10자 이하)과 각각의 부모-자식관계가 주어진다. 이때, 두 명의 이름이 주어지면
무슨 관계인지 구한다.(가족관계 없음, ...-great-grand-mother, ...-great-aunt, cousine, 형제자매 관계(sister))

해결 방법 : 먼저 각 문자열을 정렬한 다음 번호를 지정한다. 이 값들을 다시 각 문자열에 이분 탐색을 이용해 문자열을
번호로 바꾼다. 번호로 바꾼 다음에는 첫 번째의 조상으로 간 다음, 해당 조상에서 DFS를 통해 몇대손인지를 각각 구한다.
두 번째가 몇대손인지 나오지 않는 경우에는 친척이 아니므로 가족관계가 아닌 것이다.

이를 구하고 나면 둘의 관계에 따라 경우를 나누어 생각한다. 둘이 항렬이 같은 경우에는 형제자매 관계인지 확인하고
아니면 cousine을 출력한다.
항렬이 서로 다르다면 항렬이 낮은 쪽에서 높은 쪽까지 올라온 조상을 확인한다. 반대쪽과 같다면 자손 관계이고,
항렬 차에 따라 -great이나 -grand를 추가하고 -mother를 붙이면 된다.
반대쪽과 같지는 않지만 부모가 같다면 조카 관계이고 역시 항렬차에 따라 -great를 추가하고 -aunt를 붙인다.
둘 다 아니라면 친척 관계로 cousine을 붙이면 된다.

주요 알고리즘 : 구현, 그래프 이론, 트리, LCA, 케이스 워크, 이분 탐색 등등

출처 : USACO 2018O B3번
*/

char bessie[16], elsie[16], rel[128][2][16], astr[256][16], rstr[256][16];
int ance[256], reln[128][2], ed[256][256], vis[256], level[256];
int rsp = 0;

void dfs(int x, int lv) {
    level[x] = lv;
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (!vis[ed[x][i]]) dfs(ed[x][i], lv + 1);
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("family.in", "r");
        fo = fopen("family.out", "w");
    }
    int n, aa, bb, grand;
    void* v;
    scanf("%d %s %s", &n, bessie, elsie);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", rel[i][0], rel[i][1]);
        strcpy(astr[i * 2], rel[i][0]);
        strcpy(astr[i * 2 + 1], rel[i][1]);
    }
    strcpy(astr[n * 2], bessie);
    strcpy(astr[n * 2 + 1], elsie);
    qsort(astr, n * 2 + 2, sizeof(char) * 16, strcmp);
    for (int i = 0; i < n * 2 + 2; i++) {
        if (i > 0 && !strcmp(astr[i], astr[i - 1])) continue;
        strcpy(rstr[rsp++], astr[i]);
    }
    for (int i = 0; i < n; i++) {
        v = bsearch(rel[i][0], rstr, rsp, sizeof(char) * 16, strcmp);
        if (v == NULL) return 1;
        reln[i][0] = ((char(*)[16])v - rstr) + 1;
        v = bsearch(rel[i][1], rstr, rsp, sizeof(char) * 16, strcmp);
        if (v == NULL) return 1;
        reln[i][1] = ((char(*)[16])v - rstr) + 1;
    }
    v = bsearch(bessie, rstr, rsp, sizeof(char) * 16, strcmp);
    if (v == NULL) return 1;
    aa = ((char(*)[16])v - rstr) + 1;
    v = bsearch(elsie, rstr, rsp, sizeof(char) * 16, strcmp);
    if (v == NULL) return 1;
    bb = ((char(*)[16])v - rstr) + 1;

    for (int i = 0; i < n; i++) {
        ance[reln[i][1]] = reln[i][0];
        ed[reln[i][0]][++ed[reln[i][0]][0]] = reln[i][1];
        ed[reln[i][1]][++ed[reln[i][1]][0]] = reln[i][0];
    }

    grand = aa;
    while (ance[grand]) grand = ance[grand];
    dfs(grand, 1);
    if (!vis[aa] || !vis[bb]) {
        printf("%s", "NOT RELATED");
        return 0;
    }

    int ab;
    if (level[bb] > level[aa]) {
        ab = bb;
        while (level[ab] > level[aa]) ab = ance[ab];
        if (ab == aa) {
            printf("%s is the ", bessie);
            for (int i = 2; i < level[bb] - level[aa]; i++) printf("%s", "great-");
            if (level[bb] - level[aa] > 1) printf("%s", "grand-");
            printf("mother of %s", elsie);
        }
        else if (ance[ab] == ance[aa]) {
            printf("%s is the ", bessie);
            for (int i = 1; i < level[bb] - level[aa]; i++) printf("%s", "great-");
            printf("aunt of %s", elsie);
        }
        else printf("%s", "COUSINS");
    }
    else if (level[aa] > level[bb]) {
        ab = aa;
        while (level[ab] > level[bb]) ab = ance[ab];
        if (ab == bb) {
            printf("%s is the ", elsie);
            for (int i = 2; i < level[aa] - level[bb]; i++) printf("%s", "great-");
            if (level[aa] - level[bb] > 1) printf("%s", "grand-");
            printf("mother of %s", bessie);
        }
        else if (ance[ab] == ance[bb]) {
            printf("%s is the ", elsie);
            for (int i = 1; i < level[aa] - level[bb]; i++) printf("%s", "great-");
            printf("aunt of %s", bessie);
        }
        else printf("%s", "COUSINS");
    }
    else {
        if (ance[aa] == ance[bb]) printf("%s", "SIBLINGS");
        else printf("%s", "COUSINS");
    }

    return 0;
}