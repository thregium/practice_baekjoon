#include <stdio.h>
#include <time.h>

/*
���� : 2���� �õ����� ���� "Korea" �Ǵ� "Yonsei"�� ���� �Ѵ�. �����ϴ� �ڵ�� ���ƾ� �Ѵ�.

�ذ� ��� : �ڵ��� ���� �ð��� �Ź� ���ݾ� ���� �� �ֱ� ������ ������ ���� Ƚ���� ����(�� 1��ȸ)��
�� ����, Ŭ���� Ƚ���� ���� Ȧ���� ¦���� ��츦 ������ ����ϴ� ���ڸ� ���ϸ� �ȴ�.
������ ���� ũ�� �ۿ��ϹǷ� ���� �� �����ؾ� �� �� �ִ�.

�ֿ� �˰��� : ?

��ó : Coder's High 2014 PB��
*/

int main(void) {
    clock_t t = clock();
    long long cnt = 0;
    for (long long i = 0; i <= 103000; i++) {
        for (long long j = 1; j * j <= i; j++) {
            cnt += (j * i) % 103000;
        }
    }
    t = clock() - t + cnt;
    printf("%s", (t & 1) ? "Korea" : "Yonsei");
    return 0;
}