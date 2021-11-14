#include <stdio.h>

/*
���� : ���� 100 ������ �ҹ��ڷ� �̷���� ���ڿ��� N(N <= 20)�� ������ 20 ���� ������ �ҹ��ڷ� �̷���� �ܾ���� �־�����.
�̶�, ī�̻縣 ��ȣ ��� �� ������ �ܾ �̷�����ٸ�, �׶��� ��ȣȭ�� ����Ѵ�.

�ذ� ��� : ��� ���ĺ� ������ ���� ��ȣ�� Ǯ���. �� ��ȣȭ���� �ܾ ã��, �ܾ ã���� ��
�׷��� ��ȣȭ�� ����ϰ� ���α׷��� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : ����� 2017 E��
*/

char crypt[128], word[32][32];

int main(void) {
    int n, r = 0, t = 0;
    scanf("%s", crypt);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; crypt[j]; j++) {
            for (int k = 0; k < n; k++) {
                t = 1;
                for (int l = 0; word[k][l]; l++) {
                    if ((crypt[j + l] - 'a' + i) % 26 + 'a' != word[k][l]) {
                        t = 0;
                        break;
                    }
                }
                if (t) {
                    for (int l = 0; crypt[l]; l++) {
                        printf("%c", (crypt[l] - 'a' + i) % 26 + 'a');
                    }
                    return 0;
                }
            }
        }
    }
    return 1;
}