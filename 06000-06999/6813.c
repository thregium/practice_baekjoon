#include <stdio.h>

/*
���� : "WELCOME TO CCC GOOD LUCK TODAY"��� ������ �� ���� ����(>= 7)�� �־��� ��
������ �־��� ��Ĵ�� ����Ѵ�. �� �ٿ��� �ִ����� �ܾ ���� �������� �� �ܾ ���еǸ鼭
�ܾ� ������ �ٿ� ���� �ϸ�, ù �ܾ�� �� �տ�, ù �ܾ �ƴ� ������ �ܾ�� �� �ڿ� �´�.
���� ������ �����ϰ� ���ߵ� ������ �������� �ʴ� ��� ���ʿ� 1���� �� ���� �д�.

�ذ� ��� : �� �ٿ� �� �ܾ���� �̸� �� ���� ���� ĭ ���� ����. �� �� ���� ĭ���� �°�
������ ��ġ�ϸ鼭 ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�, ����

��ó : CCC 2009J 4��
*/

const int wlen[6] = { 7, 2, 3, 4, 4, 5 };
const char* words[6] = { "WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY" };

int main(void) {
    int n, printed = 0, last = 0, rem = 0;
    scanf("%d", &n);
    while (printed < 6) {
        rem = n - wlen[printed++];
        while (printed < 6 && wlen[printed] + 1 <= rem) {
            rem -= wlen[printed] + 1;
            printed++;
        }
        if (printed == last + 1) {
            printf("%s", words[last]);
            for (int i = 0; i < rem; i++) printf(".");
            printf("\n");
            last = printed;
            continue;
        }

        for (int i = last; i < printed; i++) {
            printf("%s", words[i]);
            if (i == printed - 1) break;
            for (int j = -1; j < rem / (printed - last - 1); j++) printf(".");
            if (i - last < rem % (printed - last - 1)) printf(".");
        }
        printf("\n");
        last = printed;
    }
    return 0;
}