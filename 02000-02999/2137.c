#include <stdio.h>
#include <stdlib.h>

/*
문제 : 분모와 분자가 모두 32767 이하의 자연수이고 분자가 분모보다 작은 분수가 주어진다. 입력값의 조건을 만족시키면서
원래 분수에 가장 가까운 분수를 출력한다. 단, 원래 분수와 같은 값이어서는 안 되며, 가장 가까운 분수가 여러 개인 경우
가장 작은 분수를 출력해야 한다.

해결 방법 : 분모와 분자의 범위가 넓어서 완전 탐색으로는 시간 내에 탐색하기 어렵지만 매개 변수 탐색으로는
시간 내에 탐색할 수 있다. 2부터 32767까지의 분모에 대해 각각 원래 분수가 해당 분모에서 있는 구간을 구한다.
그 다음, 해당 구간의 앞과 뒤에 있는 자연수를 분자로 하여 만들어진 분수들 가운데 가장 가까운 분수를 찾으면 된다.
분수들끼리 비교할 때에는 통분을 통해 비교할 수 있다.

주요 알고리즘 : 수학, 파라메트릭

출처 : USACO 2005O S1번
*/

typedef struct frac {
    long long n;
    long long d;
} frac;

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

frac minusf(frac a, frac b) {
    //분수 A에서 분수 B를 뺀 값을 기약분수 형태로 나타낸 값을 출력한다.
    long long newd = a.d * b.d;
    long long newn = a.n * b.d - b.n * a.d;
    long long gcdf = gcd(abs(newd), abs(newn));
    frac r;
    r.d = newd / gcdf;
    r.n = newn / gcdf;
    return r;
}

frac absf(frac a) {
    //분수 A의 절댓값을 구한다.
    if (a.n < 0) a.n = -a.n;
    return a;
}

int main(void) {
    int l, h;
    frac forig, fres, ftest, fret;
    scanf("%lld %lld", &forig.n, &forig.d);
    fres.n = 2;
    fres.d = 1;
    for (int i = 2; i < 32768; i++) {
        l = 0, h = i;
        ftest.d = i;
        while (l + 1 < h) {
            //분모가 i일 때 원래 분수가 포함된 분자의 구간을 찾는다.
            ftest.n = ((l + h) >> 1);
            fret = minusf(forig, ftest);
            if (fret.n < 0) h = ((l + h) >> 1);
            else l = ((l + h) >> 1);
        }
        if (l > 0) {
            ftest.n = l; //구간의 앞쪽 값
            if (minusf(forig, ftest).n != 0) {
                if (minusf(absf(minusf(forig, ftest)), absf(minusf(forig, fres))).n < 0) fres = ftest;
            }
        }
        if (l + 1 < i) {
            ftest.n = l + 1; //구간의 뒤쪽 값
            if (minusf(forig, ftest).n != 0) {
                if (minusf(absf(minusf(forig, ftest)), absf(minusf(forig, fres))).n < 0) fres = ftest;
            }
        }
    }
    printf("%lld %lld", fres.n, fres.d);
    return 0;
}