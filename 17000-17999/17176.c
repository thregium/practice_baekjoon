#include <stdio.h>
#include <ctype.h>

/*
���� : �־��� N(N <= 100000)���� ���� ���ڷ� �ٲٰ� ��迭�ؼ� �־����� ���ڿ��� �ٲ� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� ���� ���� Ƚ���� ������ ����, ���ڿ��� ���ڵ��� ���� �ٲ� �� �� ���� ���� Ƚ���� �����Ѵ�.
�׸��� �� Ƚ���� �迭�� ���� ������ Ȯ���Ѵ�. ���ٸ� �ٲ� �� �ִ� ���̰�, �ٸ��ٸ� �ٲ� �� ���� ���̴�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : �泲�� 3ȸ D��
*/

char s[103000];
int cnt1[53], cnt2[53];

int main(void) {
    int n, x, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt1[x]++;
    }
    getchar();
    fgets(s, 101300, stdin);
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) cnt2[s[i] - 'a' + 27]++;
        else if (isupper(s[i])) cnt2[s[i] - 'A' + 1]++;
        else if (s[i] == ' ') cnt2[0]++;
        else return 1;
    }
    for (int i = 0; i < 53; i++) {
        if (cnt1[i] != cnt2[i]) r = 0;
    }
    printf("%c", r ? 'y' : 'n');
    return 0;
}