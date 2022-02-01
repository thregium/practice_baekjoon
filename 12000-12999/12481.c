#include <stdio.h>
#include <string.h>
#include <math.h>

/*
���� : ���� 60 ������ '1', '0', '?'�� �̷���� ���ڿ��� �־�����. �̶�, �� ���ڿ����� '?'��
'0' �Ǵ� '1'�� �ٲٰ� �������� �о� ���� �� �ִ� �������� �ϳ����̶�� �׷��� �������� �������� ����Ѵ�.
���ڿ��� ù ���ڴ� '1'�� �����ϰ� '?'�� 20�� ���Ϸ� �־�����.

�ذ� ��� : '?'�� 20�� �̳��� �־����Ƿ� ��� '?'�� 0 �Ǵ� 1�� �ٲٴ� ��� ��츦 �õ��غ���.
���������� ���θ� Ȯ���� ������ �Ǽ� ������ �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : GCJ 2011R3 D1��
*/

char s[128];

int issqr(long long x) {
    long long y = sqrt(x);
    for (int i = -1; i <= 1; i++) {
        if ((y + i) * (y + i) == x) return 1;
    }
    return 0;
}

void printbin(long long x) {
    char s[128] = { 0, };
    char c;
    for (int i = 0; x; i++) {
        s[i] = '0' + (x & 1);
        x >>= 1;
    }
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s", s);
}

int main(void) {
    int t, l, q, p, r;
    long long n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        q = 0, l = strlen(s), r = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '?') q++;
        }
        for (int i = 0; i < (1 << q); i++) {
            p = 0;
            n = 0;
            for (int j = 0; j < l; j++) {
                if (s[j] == '1') n += (1LL << (l - j - 1));
                else if (s[j] == '?') {
                    if ((i >> (p++)) & 1) n += (1LL << (l - j - 1));
                }
            }
            if (issqr(n)) {
                printf("Case #%d: ", tt);
                printbin(n);
                printf("\n");
                r = 1;
                break;
            }
        }
        if (!r) return 1;
    }
    return 0;
}