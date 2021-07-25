#include <stdio.h>
#include <string.h>

/*
���� : �ִ� 100���� ī�尡 �Ʒ����� ���ʷ� �־��� ��, K(K <= 100)ȸ ���� �� ī���� ������ ���Ѵ�.

�ذ� ��� : ī�带 ���� ����� ���� ������ �� Kȸ �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���ڿ�

��ó : ROI 2007H I��
*/

char cards[128], carda[128], cardb[128];
int len;

void shuffle(void) {
    for (int i = 0; i < len; i++) {
        if (i & 1) cardb[i >> 1] = cards[len - i - 1];
        else carda[i >> 1] = cards[len - i - 1];
    }
    strcpy(cards, cardb);
    strcat(cards, carda);
}

int main(void) {
    int k;
    scanf("%s", cards);
    len = strlen(cards);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        shuffle();
    }
    printf("%s", cards);
    return 0;
}