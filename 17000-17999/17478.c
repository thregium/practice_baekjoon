#include <stdio.h>

/*
���� : �־��� ������ Nȸ ����Ͽ� ����Ѵ�.

�ذ� ��� : ������� �����Ѵ�. ������ ��͸� �� �ʿ�� ����.

�ֿ� �˰��� : ����

��ó : �߾Ӵ� 2019 A��
*/

void printstrike(int n) {
    for (int i = 0; i < n; i++) {
        printf("____");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    for (int i = 0; i < n; i++) {
        printstrike(i);
        printf("\"����Լ��� ������?\"\n");
        printstrike(i);
        printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
        printstrike(i);
        printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
        printstrike(i);
        printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
    }
    printstrike(n);
    printf("\"����Լ��� ������?\"\n");
    printstrike(n);
    printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
    for (int i = n; i >= 0; i--) {
        printstrike(i);
        printf("��� �亯�Ͽ���.\n");
    }
    return 0;
}