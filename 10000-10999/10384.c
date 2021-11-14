#include <stdio.h>
#include <ctype.h>

/*
���� : �־��� ���ڿ��� �ұ׷�����, ���� �ұ׷�����, Ʈ���� �ұ׷����� ���Ѵ�.

�ذ� ��� : �� ������ ������ ���� ����, ���� ���� ������ ���ڸ� �������� ������ �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : ECRC 2014 PB��
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