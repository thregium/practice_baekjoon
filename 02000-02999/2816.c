#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� ä���� �ִ�. 500�� �̳��� ������ ���� "KBS1"�� �� ��, "KBS2"�� 2��°�� �ֵ��� �Ѵ�.
Ŀ���� ó���� 1��° ä�ο� �ְ�, Ŀ���� �Ʒ��� 1ĭ �ű�ų� ���� 1ĭ �ű�ų� �Ʒ� ĭ�� ä���� �ٲٰų�(Ŀ���� 1ĭ �Ʒ���),
�� ĭ�� ä���� �ٲٴ�(���� Ŀ���� 1ĭ ����) 4���� ������ �����ϴ�. ä���� �䷯���� �ƴϰ�, ä���� �ҹ��ڿ� _�� �̷����
10�� ������ ���ڿ��̴�.

�ذ� ��� : "KBS1"�� ä�ο��� ã�Ƽ� �� ���� �ű�� �ٽ� "KBS2"�� ä�ο��� ã�Ƽ� �� ���� �ű����
�ִ� N * 4 = 400ȸ�� ���۸� �ϰ� �ǹǷ� ���� ���� �̵��� �����ϴ�. �̸� ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : COCI 11/12#3 1��
*/

char chan[128][16], tmp[16];

void swap(int a, int b) {
    strcpy(tmp, chan[a]);
    strcpy(chan[a], chan[b]);
    strcpy(chan[b], tmp);
}

int main(void) {
    int n, cur = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", chan[i]);
    }
    while (strcmp(chan[cur], "KBS1")) {
        cur++;
        printf("1");
    }
    while (cur > 0) {
        printf("4");
        swap(cur, cur - 1);
        cur--;
    }
    while (strcmp(chan[cur], "KBS2")) {
        cur++;
        printf("1");
    }
    while (cur > 1) {
        printf("4");
        swap(cur, cur - 1);
        cur--;
    }
    return 0;
}