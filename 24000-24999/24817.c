#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 100000)명의 사람 이름과, M(M <= 200000)개의 사람 이름에 대한 기록들이 주어질 때,
기록 합이 P(P <= 10001) 이상인 사람들을 달성한 순서대로 출력한다. 없는 경우에는 "No winner!"를 출력한다.
각 사람의 이름은 20자 이하의 대소문자로 주어진다.

해결 방법 : 각 사람 이름들을 정렬한 다음, 기록이 주어질 때 마다 위치를 찾아내고,
그 위치에 점수를 올려 나가다가 P 이상이 되는 순간 이름을 출력한다. 한번 출력한 사람은 다시 출력하지 않는다.
그리고 출력한 사람이 없다면 "No winner!"를 출력하는 것도 잊지 않아야 한다.

주요 알고리즘 : 문자열, 정렬, 이분 탐색

출처 : VTH 2018 M번
*/

char name[103000][32], buff[32];
int score[103000], win[103000];

int main(void) {
    int n, p, m, t, pos, wc = 0;
    scanf("%d %d %d", &n, &p, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }
    qsort(name, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", buff, &t);
        pos = (char*)bsearch(buff, name, n, sizeof(char) * 32, strcmp) - (char*)name;
        if (pos < 0) return 1;
        pos >>= 5;
        score[pos] += t;
        if (score[pos] >= p && !win[pos]) {
            win[pos] = 1;
            wc++;
            printf("%s wins!\n", name[pos]);
        }
    }
    if (wc == 0) printf("No winner!");
    return 0;
}
