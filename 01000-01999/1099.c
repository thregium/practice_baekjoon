#include <stdio.h>
#include <string.h>
#define INF 1012345678

/*
문제 : N(N <= 50)개의 길이 50 이하의 소문자로 이루어진 단어가 주어진다. 이 단어들의 아나그램을 이용하여 길이 50 이하의
소문자로 이루어진 주어진 단어를 만들려고 할 때, 가장 비용이 적게 되는 방법의 비용을 구한다. 방법이 없다면 -1을 출력한다.
비용은 각 단어와 순서가 일치하지 않는 문자의 개수이다.

해결 방법 : 다이나믹 프로그램을 이용하여 해결할 수 있다. 각 문자의 위치마다 해당 위치에서 끝나는 단어들을
갖다 놓고 아나그램인지 먼저 확인한다. 아나그램인 경우에는 서로 일치하지 않는 문자의 개수를 단어 시작 부분의
값에 더한 것을 비교하여 가장 작은 것을 찾아나간다. 이를 반복한 후 단어 끝의 값을 구하면 그 값이 답이 된다.
단, INF인 경우에는 방법이 없는 것이므로 -1이다.

주요 알고리즘 : DP

출처 : SRM 411 D1A / D2B
*/

char s[64], word[64][64];
int wlen[64], mem[64], cnt[26], cnt2[26];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, l, t;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 1; i <= l; i++) mem[i] = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
        wlen[i] = strlen(word[i]);
    }
    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < n; j++) {
            if (wlen[j] > i) continue;
            for (int k = 0; k < wlen[j]; k++) {
                cnt[s[i - wlen[j] + k] - 'a']++;
                cnt2[word[j][k] - 'a']++;
            }
            t = 1;
            for (int k = 0; k < 26; k++) {
                if (cnt[k] != cnt2[k]) t = 0;
                cnt[k] = 0, cnt2[k] = 0;
            }
            if (!t) continue;

            t = 0;
            for (int k = 0; k < wlen[j]; k++) {
                t += (s[i - wlen[j] + k] != word[j][k]);
            }
            mem[i] = small(mem[i], mem[i - wlen[j]] + t);
        }
    }
    printf("%d", mem[l] == INF ? -1 : mem[l]);
    return 0;
}