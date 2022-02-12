#include <stdio.h>
#define MOD 1000000007

/*
���� : ���� 10000 ������ �ҹ��ڿ� '?'�� �̷���� ���ڿ��� �־��� ��,
�� ���ڿ����� '?'�� �̹� �����ϴ� �ٸ� ���ڷ� �ٲپ� �׷� ���ڿ��� �ǵ��� �ϴ� ����� ���� ���Ѵ�.
����� 0������ ���� �־����� �ʴ´�.

�ذ� ��� : ?�� �� �� ���ڰ� ���� �ٸ� ������ ��� ?�� ���� + 1 ��ŭ�� �������� �����ϴ�.
���� ���� ���� �Ǵ� �� �� �� �ϳ��� ���� �����ִ� ��� ���ʰ� ���� �ٲپ�� �ϹǷ� 1������ �����ϴ�.
������ ��� ��츦 ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ���ڿ�

��ó : Arab 2013 A��
*/

char s[10240];

int main(void) {
    int t, res, e;
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2013\\acpc2013-IO-A\\sticker.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        res = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] != '?') continue;
            e = i;
            while (s[e] == '?') e++;
            if (s[e] == '\0') break;
            else if (i > 0 && s[i - 1] != s[e]) res = ((long long)res * (e - i + 1)) % MOD;
            i = e;
        }
        printf("%d\n", res);
    }
    return 0;
}