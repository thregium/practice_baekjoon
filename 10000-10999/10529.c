#include <stdio.h>

/*
문제 : N(N <= 10)개의 줄에 알파벳으로 이루어진 단어들이 주어진다. 이때, 각 알파벳을 서로 다른
숫자로 치환하였을 때, 마지막을 제외한 단어의 합이 마지막 단어와 같은 지 구한다.
각 단어의 길이는 10 이하고, 서로 다른 문자는 많아야 10개이다.
단, 0이 아닌 수는 0으로 시작할 수 없다.

해결 방법 : 각 문자들을 'A'부터 'J'까지로 우선 압축해둔다.
그런 다음, 'A'부터 'J'까지 각 단어를 배정하고, 합이 같은 지 확인하면 된다.
이것이 가능한 모든 경우는 많아야 10!가지 뿐이므로 하나씩 해볼 수 있다.
이 과정에서 맨 앞에 오는 문자들을 저장해두고 0이 그 문자에 오지 않도록 미리 조치해줘야 한다.

주요 알고리즘 : 수학, 문자열, 백트래킹

출처 : SWERC 2014 A번
*/

char word[16][16], chk[26], chk2[16], isfirst[16];
int num[16];

int track(int a, int x, int n) {
    if (a == x) {
        long long sum = 0, wdn = 0, rsum = 0;
        for (int i = 0; i < n; i++) {
            wdn = 0;
            for (int j = 0; word[i][j]; j++) {
                wdn *= 10;
                wdn += num[word[i][j] - 'A'];
            }
            sum += wdn;
        }
        for (int j = 0; word[n][j]; j++) {
            rsum *= 10;
            rsum += num[word[n][j] - 'A'];
        }
        return (rsum == sum);
    }
    int r = 0;
    for (int i = 0; i <= 9; i++) {
        if (chk2[i]) continue;
        if (i == 0 && isfirst[x]) continue;
        chk2[i] = 1;
        num[x] = i;
        r += track(a, x + 1, n);
        chk2[i] = 0;
    }
    return r;
}

int main(void) {
    int n, r;
    for (int tt = 0;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", word[i]);
            for (int j = 0; word[i][j]; j++) {
                chk[word[i][j] - 'A'] = 1;
            }
        }
        for (int i = 1; i < 26; i++) chk[i] += chk[i - 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; word[i][j]; j++) {
                word[i][j] = chk[word[i][j] - 'A'] + 'A' - 1;
            }
            if (word[i][1] != '\0') isfirst[word[i][0] - 'A'] = 1;
        }
        printf("%d\n", track(chk[25], 0, n - 1));

        for (int i = 0; i < 26; i++) chk[i] = 0;
        for (int i = 0; i < 16; i++) isfirst[i] = 0;
    }
    return 0;
}