#include <stdio.h>

/*
���� : [A, B](A, B <= 10^15)���� �� �ڿ����� LSB�� ���� ���Ѵ�.

�ذ� ��� : ū ��Ʈ���� A�� B�� �� ���̸� ���ϸ鼭 �� ��Ʈ�� ���� ���س����� �ȴ�. ��, �̹� �� ��Ʈ�� ���� ���� �Ѵ�.

�ֿ� �˰��� : ����

��ó : CHCI 2005O 1��
*/

int main(void) {
	long long a, b, t, r = 0, s = 0;
	scanf("%lld %lld", &a, &b);
	a--;

	for (long long i = 50; i >= 0; i--) { 
		t = b / (1LL << i) - a / (1LL << i);
		t -= s;
		s += t;
		r += t * (1LL << i);
	}

	printf("%lld", r);
}