#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOUT 1
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 7마리의 소의 이름들과 소들이 우유를 생산한 기록들이 있을 때, 우유를 가장 적게 생산하지 않은 소 가운데
우유를 가장 적게 생산한 소의 이름을 출력한다. 1마리가 아니라면 Tie를 출력한다.

해결 방법 : 각 소의 이름을 하드코딩해두고 각 소의 기록을 찾아 이름이 일치하는 번호를 갖는 소의 생산량을 주어진 수만큼 높인다.
전부 끝나면 가장 우유를 적게 생산한 소를 찾은 다음, 그보다 많이 생산한 소들 가운데 가장 적게 생산한 소의 번호와 수를 찾는다.
그 수가 1인 경우 소의 번호에 대한 이름을 출력하고, 아닌 경우 Tie를 출력한다.

주요 알고리즘 : 문자열, 구현

출처 : USACO 2017J B1번
*/

char* names[7] = { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
char buff[16];
int cnt[7];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("notlast.in", "r");
        fo = fopen("notlast.out", "w");
    }
    int n, x, y, z = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &x);
        for (int j = 0; j < 7; j++) {
            if (!strcmp(buff, names[j])) {
                cnt[j] += x;
                break;
            }
        }
    }
    x = 12345;
    for (int i = 0; i < 7; i++) {
        if (cnt[i] < x) x = cnt[i];
    }
    y = 12345;
    for (int i = 0; i < 7; i++) {
        if (cnt[i] < y && cnt[i] > x) {
            y = cnt[i];
            z = i;
            c = 1;
        }
        else if (cnt[i] == y) c++;
    }
    if (c == 1) printf("%s\n", names[z]);
    else printf("%s", "Tie");
    return 0;
}