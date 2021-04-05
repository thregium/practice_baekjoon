#include <stdio.h>

/*
문제 : 알파벳 소문자로 된 N개의 단어 가운데 K가지의 글자만으로 만들 수 있는 최대의 단어 수를 구한다.
단, 모든 단어는 anta로 시작하고, tica로 끝난다.

해결 방법 : a, c, i, n, t는 반드시 필요하므로 이 5가지는 미리 선택한다.
이외의 문자들은 백트래킹을 통해 모든 조합을 탐색한 후 만들 수 있는 단어 수가 가장 많은 경우를 찾는다.

주요 알고리즘 : 문자열, 백트래킹
*/

int al[64][32], sel[32]; //al : 해당 문자를 이루는 알파벳들, sel : 선택한 알파벳들
int best = 0;

void track(int n, int k, int p, int l) {
	//n : 전체 단어 수, k : 선택할 알파벳 수, p : 선택한 알파벳 수, l : 선택한 마지막 알파벳
    if (k < p) return;
    int r, t;
    if (k == p) {
        r = 0;
        for (int i = 0; i < n; i++) {
            t = 1;
            for (int j = 0; j < 26; j++) {
                if (al[i][j] && !sel[j]) {
                    t = 0;
                    break;
                }
            }
            r += t;
        }
        if (r > best) best = r;
        return;
    }
    for (int i = l + 1; i < 26; i++) {
        if (sel[i]) continue;
        sel[i] = 1;
        track(n, k, p + 1, i);
        sel[i] = 0;
    }
}

int main(void) {
    int n, k;
    char b[32] = { 0, };
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", b);
        for (int j = 0; b[j]; j++) {
            al[i][b[j] - 'a'] = 1;
        }
    }
    sel[0] = 1; //a
    sel[2] = 1; //c
    sel[8] = 1; //i
    sel[13] = 1; //n
    sel[19] = 1; //t
    track(n, k - 5, 0, -1);
    printf("%d", best);
    return 0;
}