#include <stdio.h>

char s[524288], st[524288];
int sttop = 0;

/*
���� : N�ڸ� ������ K(K < N <= 100)���� ���ڸ� ���� ���� �� �ִ� ���� ū ���� ���Ѵ�.

�ذ� ��� : ������ �̿��� �� ���ʺ��� �� �ڸ����� ���� ������ �������� �����Ѵ�. ���� ����������� �Ǿ
���� ���ڰ� ���� ��� �ٽ� ���ʺ��� ���ڵ��� �������� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Brasil 2008 A��
*/

int main(void) {
    int n, k, l;
    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0) break;
        scanf("%s", s);
        sttop = 0;
        l = 0;
        for (int i = 0; i < n; i++) {
            while (l < k && sttop > 0 && st[sttop - 1] < s[i]) {
                l++;
                sttop--;
            }
            st[sttop++] = s[i];
        }
        while (l < k) {
            st[--sttop] = '\0';
            l++;
        }
        st[sttop] = '\0';
        printf("%s\n", st);
    }
    return 0;
}