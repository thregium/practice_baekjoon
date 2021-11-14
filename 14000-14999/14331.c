#include <stdio.h>
#define MOD 1000000007

/*
���� : 1000�� ������ ���ڿ��� �־��� ��, �� ���ڿ����� �յڷ� 3���� ���� ��� �ϳ��� ���ڸ� ��� ���� �� �ִ�
���ڿ��� ������ ���Ѵ�.

�ذ� ��� : �յڷ� �Ź� ���ڸ� ���鼭 ���� �ٸ� ������ ���� ������ ���ذ��� �ȴ�.

�ֿ� �˰��� : ����, ���շ�

��ó : GCJ 2017A A2��
*/

char s[1024];

int main(void) {
    int t, n;
    long long r = 1;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        if (s[1] == '\0') {
            printf("Case #%d: 1\n", tt);
            continue;
        }
        r = 1;
        for (int i = 0; s[i]; i++) {
            if (i == 0) {
                if (s[i] != s[i + 1]) r *= 2;
            }
            else if (s[i + 1] == '\0') {
                if (s[i] != s[i - 1]) r = (r * 2) % MOD;
            }
            else {
                if (s[i - 1] == s[i] && s[i] == s[i + 1]) continue;
                else if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1]) r = (r * 3) % MOD;
                else r = (r * 2) % MOD;
            }
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}