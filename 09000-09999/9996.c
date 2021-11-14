#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� ���ڿ��� ���� �־��� ���ϰ� �´��� ���Ѵ�. �־��� ������ (���ڿ�)*(���ڿ�)�� �Ǿ��ְ�,
*���� 0�� �̻��� ���ڰ� �� �� �ִ�.

�ذ� ��� : �־��� ������ ���λ�� ���̻�� �и��ϰ�, ���λ�� ���̻簡 �´��� Ȯ���ϰ� ���� ��ġ�� �ʴ��� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�

��ó : COCI 13/14#6 1��
*/

char patt[128], pref[128], suff[128], buff[128];

int main(void) {
    int n, pl, sl, bl;
    //freopen("E:\\PS\\Contest\\COCI\\13-14\\contest6_testdata\\vjeko\\vjeko.in.6b", "r", stdin);
    //freopen("E:\\PS\\Contest\\COCI\\13-14\\contest6_testdata\\vjeko\\vjeko_t.out.6b", "w", stdout);
    scanf("%d", &n);
    scanf("%s", patt);
    strcpy(pref, strtok(patt, "*"));
    strcpy(suff, strtok(NULL, "*"));
    pl = strlen(pref);
    sl = strlen(suff);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        bl = strlen(buff);
        if (strstr(buff, pref) == buff && bl - sl >= pl && !strcmp(&buff[bl - sl], suff)) printf("DA\n");
        else printf("NE\n");
    }
    return 0;
}