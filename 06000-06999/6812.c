#include <stdio.h>

/*
���� : ��Ÿ���� �ð��� �־��� ��, ������ ĳ������ ������ �ð��� ���Ѵ�. 24�ð� �����̰�, ���� 0�� ������� �ʴ´�.

�ذ� ��� : �� ������ �ð��� ����ϰ� ����Ѵ�. ��¥ ����� �ð� ���� ���濡 �����Ѵ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : CCC 2009J 3��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d in Ottawa\n", n);
    printf("%d in Victoria\n", n >= 300 ? n - 300 : n + 2100);
    printf("%d in Edmonton\n", n >= 200 ? n - 200 : n + 2200);
    printf("%d in Winnipeg\n", n >= 100 ? n - 100 : n + 2300);
    printf("%d in Toronto\n", n);
    printf("%d in Halifax\n", n < 2300 ? n + 100 : n - 2300);
    n += 100;
    if (n >= 2400) n -= 2400;
    n += 30;
    if (n % 100 >= 60) n += 40;
    if (n >= 2400) n -= 2400;
    printf("%d in St. John's", n);
    return 0;
}