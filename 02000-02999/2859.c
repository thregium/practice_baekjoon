#include <stdio.h>

/*
���� : �� ���� �ֱ������� �������ٰ� �� ��, �� ���� ó�� ������ �ð��� �������� �ֱⰡ �־�����
�� ���� ó������ ���ÿ� �������� ������ ���Ѵ�. �ֱ�� 0�� �ƴϰ� �� ���� ó�� ������ �ð��� ���� �ٸ���.

�ذ� ��� : ���������� �ִ� 1440 * 1440��ŭ�� �ð� �ȿ��� �� ���� ���ÿ� �����ų�
������ ���ÿ� ������ �ʾƾ� �ϱ� ������ �� ������ ��� Ž���� ���� ���� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ���Ʈ ����

��ó : COCI 10/11#4 3��
*/

const char* weekday[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int main(void) {
    int h, m, as, bs, at, bt;
    scanf("%d:%d", &h, &m);
    as = h * 60 + m;
    scanf("%d:%d", &h, &m);
    bs = h * 60 + m;
    scanf("%d:%d", &h, &m);
    at = h * 60 + m;
    scanf("%d:%d", &h, &m);
    bt = h * 60 + m;
    for (int i = 0; i < 103000; i++) {
        if (as < bs) as += at;
        else if (as > bs) bs += bt;
        else break;
    }

    if (as != bs) printf("Never");
    else printf("%s\n%02d:%02d", weekday[as / 1440 % 7], as / 60 % 24, as % 60);

    return 0;
}