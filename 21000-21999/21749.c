#include <stdio.h>

/*
���� : 10000�� ������ ���ڿ��� �־��� ��, �� ����(����� ���� ����)�� ���� Ƚ���� ����׷��� ���·� ��Ÿ����.

�ذ� ��� : �� ������ ���� Ƚ���� �� �� ��, ���� ���� ������ 1�� �������� �ش� Ƚ�� �̻� ���� ���θ� ���Ѵ�.
�ش� �ۼ� �̻����� �����ߴٸ� #, ������ ������ �� �̸��̶�� ������ ����Ѵ�.
�� �� �ٿ��� ���ݱ��� ������ �� �ִ� ��� ���ڵ�(����� ���� ����)�� ������ָ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : ROI 2004H C��
*/

char buff[256];
int cnt[128];

int main(void) {
    int h = 0;
    while (fgets(buff, 240, stdin)) {
        for (int i = 0; buff[i]; i++) {
            if (buff[i] == ' ' || buff[i] == '\n') continue;
            cnt[buff[i]]++;
            if (cnt[buff[i]] > h) h = cnt[buff[i]];
        }
    }
    for (int i = h; i > 0; i--) {
        for (int j = 0; j < 128; j++) {
            if (cnt[j] >= i) printf("#");
            else if (cnt[j]) printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 128; i++) {
        if (cnt[i]) printf("%c", i);
    }
    return 0;
}