#include <stdio.h>

/*
���� : � �ð��� aa:bb:cc ���·� �־��� ��, ��, ��, �ʸ� �ٲپ� �� ���� ������� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �� �κ��� ��, ��, �ʷ� ǥ���� �� �ִ��� ������ �ٲ㰡�� Ȯ���غ��� �ȴ�.
Ư��, �а� �ʴ� ǥ�� ���� ������ �����Ƿ� �ϳ��� �Ǹ� �ٸ� �ϳ��� �����ϱ� ������ 2���� ó���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����
*/

int ish(int a) {
    if (a > 0 && a <= 12) return 1;
    else return 0;
}

int isms(int a) {
    if (a >= 0 && a < 60) return 1;
    else return 0;
}

int main(void) {
    int a, b, c, r = 0;
    scanf("%d:%d:%d", &a, &b, &c);
    if (ish(a) && isms(b) && isms(c)) r += 2;
    if (isms(a) && ish(b) && isms(c)) r += 2;
    if (isms(a) && isms(b) && ish(c)) r += 2;
    printf("%d", r);
    return 0;
}