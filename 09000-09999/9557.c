#include <stdio.h>

/*
���� : N(N <= 100)���� �ƶ��� �Ǵ� ���� �ܾ �־�����. �� �ܾ��� ���̴� 10 ���ϰ�,
�ƶ��� �ܾ�� '#'���θ� �̷���� ���ڿ��� �־�����, ���� �ܾ�� �ҹ��ڷθ� �̷���� �ִ�. ���� �ܾ�� �ִ� 1���� �־�����.
�̶�, ������ ����� �� ������ �ű��.

�ذ� ��� : ���� �ܾ� ���Ŀ� �ִ� �ƶ��� �ܾ ���� �ܾ� �������� �ű��, ���� �ܾ� ������ �ִ� �ƶ��� �ܾ
���� �ܾ� ���ķ� �ű�� �ȴ�. ���� ���� �ܾ��� ��ġ�� ã�� ������ ������ Ǯ �� �ִ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : Arab 2011 A��
*/

char word[128][16];

int main(void) {
    int t, n, a, e;
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2011\\acpc2011-IO-A\\arabic.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2011\\acpc2011-IO-A\\arabic_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        e = -1;
        for (int i = 0; i < n; i++) {
            scanf("%s", &word[i]);
            if (word[i][0] != '#') {
                e = i;
            }
        }
        if (e < 0) {
            for (int i = 0; i < n; i++) {
                printf("%s ", word[i]);
            }
            printf("\n");
        }
        else {
            for (int i = e + 1; i < n; i++) {
                printf("%s ", word[i]);
            }
            printf("%s ", word[e]);
            for (int i = 0; i < e; i++) {
                printf("%s ", word[i]);
            }
            printf("\n");
        }
    }
    return 0;
}