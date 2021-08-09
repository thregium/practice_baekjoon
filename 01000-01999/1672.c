#include <stdio.h>

/*
���� : ���� N(N <= 10^6)�� DNA ���ڿ��� �־��� ��, �� ���ڿ��� �־��� ��Ģ�� ���� ����ϸ� ���� ����� �������� ���Ѵ�.
(��Ģ ����)

�ذ� ��� : ��Ģ�� �°� ���ʺ��� ���ڿ��� �ٿ�������. 

�ֿ� �˰��� : ���ڿ�, ����, ���̽� ��ũ
*/

char s[1048576];

int main(void) {
    int n, t;
    scanf("%d%s", &n, s);
    for (int i = n - 2; i >= 0; i--) {
        t = s[i] + s[i + 1];
        if (s[i] == s[i + 1]) continue;
        else if (t == 'A' + 'C') s[i] = 'A';
        else if (t == 'A' + 'G') s[i] = 'C';
        else if (t == 'A' + 'T') s[i] = 'G';
        else if (t == 'C' + 'G') s[i] = 'T';
        else if (t == 'C' + 'T') s[i] = 'G';
        else if (t == 'G' + 'T') s[i] = 'A';
        else return 1;
    }
    printf("%c", s[0]);
    return 0;
}