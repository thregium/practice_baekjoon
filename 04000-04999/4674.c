#include <stdio.h>
#include <string.h>

/*
���� : ���� 70 ������ ���ڿ��� �ڿ��� Ű K(K <= 300)�� �־��� ��, �־��� ���ڿ� ��ȣ�� �ص��� ����� ����Ѵ�.
��ȣ�� ���� �ݵ�� �����ϰ� �־�����.

�ذ� ��� : ��ȣ�� �� �ڸ����� �ش� �ڸ��� �����ϴ� ��ġ�� ���ڸ� ���� �־�� ������ ����� ���� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����, ���Ʈ ����

��ó : MidC 1998 E��
*/

const char* conv = "_abcdefghijklmnopqrstuvwxyz.";
char buff[96], res[96];

int decode(char c) {
    if (c == '_') return 0;
    else if (c == '.') return 27;
    else if (c >= 'a' && c <= 'z') return 1 + c - 'a';
    else return -1;
}

int main(void) {
    int k, n, p;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\untwist\\untwist.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\untwist\\untwist_t.out", "w", stdout);
    while (1) {
        scanf("%d", &k);
        if (k == 0) break;
        scanf("%s", buff);
        n = strlen(buff);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 28; j++) {
                if ((j - i + 280000) % 28 == decode(buff[i])) res[k * i % n] = conv[j];
            }
        }
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}