#include<stdio.h>
#include<math.h>
#include<cassert>
#include<stdlib.h>
const int LIM = 1000000000;

/*
���� : N(N <= 100000)�� ������ int�� ���� ����� ��ü �� / 100�� ��ũ �ڻ��� ���� �� �� / 100�� ���� ��ũ �ڻ��� ����
���� 0.001 �̻� ���̰� ������ �ϴ� ������ ���Ѵ�. ��, ���� ����� +100�� -100 ���̿��� �Ѵ�.

�ذ� ��� : �Ǽ� ������ ������ ũ�� ������ �ϱ� ������ �Ź� ū ���� �����ִ� ���� ����.
����, ���� ���� �� ���� ���� �ٸ����� �ϴ� ���� �Ǽ� ������ �� Ŀ���� �ϴ� ����̴�.
������ ������δ� 33333�� 2^31 - 1�� ���ϰ�, 66666�� 2^30 - 1�� ����, ���������� 33333�� ���� ����� �ִ�.

�ֿ� �˰��� : ����, ������

��ó : ������ 2016 B��
*/

typedef long long ll;

float _abs(float x) { return x < 0 ? -x : x; }
int is_equal(double a, double b) { return _abs(a - b) < 1e-3; }

int main()
{
	int N = 100000, a;
	ll tot = 0;
	double x = 0;
	//assert(scanf("%d", &N) == 1);
	//assert(2 <= N && N <= 100000);
	printf("%d\n", N);
	for (int i = 1; i <= N; i++) {
		//assert(scanf("%d", &a) == 1);
		if (i <= N / 3) a = 2147483647;
		else if (i < N) a = -1073741823;
		else a = -33333;
		printf("%d\n", a);
		tot += a;
		x += a / 100.0;
	}
	assert(-100 <= tot && tot <= 100);
	//printf("%.9f %.9f", acos(x), acos(tot / 100.0));
	assert(!is_equal(acos(x), acos(tot / 100.0)));
	return 0;
}
