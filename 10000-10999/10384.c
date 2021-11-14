#include <stdio.h>
#include <ctype.h>

/*
문제 : 주어진 문자열이 팬그램인지, 더블 팬그램인지, 트리플 팬그램인지 구한다.

해결 방법 : 각 문자의 개수를 구한 다음, 가장 적게 등장한 문자를 기준으로 나누면 된다.

주요 알고리즘 : 구현, 문자열

출처 : ECRC 2014 PB번
*/

char s[103000];
int cnt[26];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    getchar();
    for (int tt = 1; tt <= t; tt++) {
        fgets(s, 101300, stdin);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) cnt[s[i] - 'A']++;
            else if (islower(s[i])) cnt[s[i] - 'a']++;
        }
        r = 3;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] < r) r = cnt[i];
            cnt[i] = 0;
        }
        printf("Case %d: ", tt);
        if (r == 0) printf("Not a pangram\n");
        else if (r == 1) printf("Pangram!\n");
        else if (r == 2) printf("Double pangram!!\n");
        else if (r == 3) printf("Triple pangram!!!\n");
    }
    return 0;
}