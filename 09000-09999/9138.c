#include <stdio.h>
#include <string.h>

/*
문제 : R * S(R, S <= 250) 크기의 격자에 알파벳들이 있다. 각 알파벳은 C(C <= 26)명의 이름의 이니셜이고,
각 사람의 이니셜은 서로 다르다. 각 사람의 이름은 61자 이하의 대소문자로 이루어져 있으며,
첫 자는 대문자이다. 이때, 가장 자기 이니셜의 알파벳이 많은 사람의 이름을 출력한다.
그러한 사람은 항상 유일하게 주어진다.

해결 방법 : 각 이니셜별로 이름을 저장하고 격자의 알파벳 개수를 센 다음, 가장 많은 것을 구하면 된다.
단, C가 1인 경우 알파벳이 없더라도 그 사람의 이름을 출력해야 함에 유의한다.

주요 알고리즘 : 구현, 문자열

출처 : CTU 2001 D번
*/

char worm[26][64], buff[256];
int cnt[26];

int main(void) {
    int r, s, c, best, bw = -1;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\d.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\d_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &r, &s, &c);
        if (r == 0) break;
        for (int i = 0; i < c; i++) {
            scanf("%s", buff);
            strcpy(worm[buff[0] - 'A'], buff);
            cnt[buff[0] - 'A'] = 103000;
        }
        for (int i = 0; i < r; i++) {
            scanf("%s", buff);
            for (int j = 0; j < s; j++) {
                if (buff[j] != '*') cnt[buff[j] - 'A']++;
            }
        }
        best = -1, bw = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > best) {
                bw = i;
                best = cnt[i];
            }
            cnt[i] = 0;
        }
        printf("Nejzravejsi cervotoc je %s.\n", worm[bw]);
    }
    return 0;
}