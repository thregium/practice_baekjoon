#include <stdio.h>

/*
���� : "north"�� "west"�� ���Ͽ� 20�� ���Ϸ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� ����Ű�� ������ ���Ѵ�.
north�� 0���̰�, west�� 90���̸� �տ� north�� ���� �� ���� (������ ���ڿ��� ����Ű�� ����) - 90/2^(������
�ܾ��� ����)�� �ϰ�, west�� ������ �׸�ŭ�� ���Ѵ�. ���� 0���� 90 ������ ������ ������,
���м� ���·� ��Ȯ�� ����ؾ� �Ѵ�.

�ذ� ��� : ���� ��ü �ܾ� ������ �ܾ��� ������ �迭�� �����Ѵ�. �׸��� �ʱⰪ�� ���� ����,
������ 1���� �ܾ ���� ������ �ٲپ� ������. �и�� ��� 2�� �������� ������ ���ڴ� 2�� ������ ������
45�� ���ϰų� ���� ���� �ݺ��ϸ� �ȴ�. �и�� 2^(���� ���� - 2)�� ����. ��, �ܾ��� ������
2 ������ ��쿡 �����ؾ� �Ѵ�.

�ֿ� �˰����� : ����, ����

��ó : JAG 2014P A��
*/

char buff[256];
int dir[32];

int main(void) {
    int deg, cnt;
    while (1) {
        scanf("%s", buff);
        if (buff[0] == '#') break;
        cnt = 0;
        for (int i = 0; buff[i]; cnt++) {
            if (buff[i] == 'n') {
                dir[cnt] = 0;
                i += 5;
            }
            else {
                dir[cnt] = 1;
                i += 4;
            }
        }
        if (cnt == 0) return 1;
        deg = dir[cnt - 1] * 90;
        if (cnt > 1) deg >>= 1;
        for (int i = cnt - 2; i >= 0; i--) {
            deg *= 2;
            if (dir[i]) deg += 45;
            else deg -= 45;
        }
        if (cnt <= 2) printf("%d\n", deg);
        else printf("%d/%d\n", deg, 1 << (cnt - 2));

        for (int i = 0; i < 256; i++) buff[i] = 0;
    }
    return 0;
}