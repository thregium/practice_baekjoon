#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 각 도시들과 주들이 나올 때, 서로 다른 주들 사이에 도시의 앞 2자리와 주의 약칭 2자리가 서로 교환된 관계의 쌍이 몇 개인지 구한다.
(예 : MIAMI FL / FLINT MI), 단, 같은 주에서는 해당하는 쌍이 있더라도 세지 않는다.

해결 방법 : 4글자를 모두 계산해서 넣더라도 26^4 = 456976이므로 충분히 해싱을 통해 모든 경우의 수를 넣을 수 있다.
차례로 입력을 받으며 현재의 해시값과 교환시 해시값을 확인한다. 이때, 두 값이 같다면 같은 주이므로 넘어간다.
두 값이 다르다면 교환시 해시 값의 위치에 저장된 수가 해당 위치를 뒤쪽 값으로 하는 쌍의 수이다. 따라서, 결괏값에 그 수를 더하고,
현재 도시의 해시값의 위치에 있는 값을 배열에서 찾아서 1 더하는 것을 반복하면 된다.

주요 알고리즘 : 자료구조, 해싱

출처 : USACO 2016D S2번
*/

char buff[2][16];
int map[456976];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("citystate.in", "r");
        fo = fopen("citystate.out", "w");
    }
    int n, h1, h2;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", &buff[0], &buff[1]);
        h1 = ((buff[0][0] - 'A') * 17576 + (buff[0][1] - 'A') * 676 + (buff[1][0] - 'A') * 26 + (buff[1][1] - 'A'));
        h2 = ((buff[1][0] - 'A') * 17576 + (buff[1][1] - 'A') * 676 + (buff[0][0] - 'A') * 26 + (buff[0][1] - 'A'));
        if (h1 == h2) continue;
        r += map[h2];
        map[h1]++;
    }
    printf("%d", r);
    return 0;
}