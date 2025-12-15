#include <stdio.h>

template <typename T>
int Min(T a, T b) {
	return (a < b) ? a : b;
}

int main() {

	int a = 10, b = 20;
	float x = 20.5f, y = 10.5f;
	double p = 10.55, q = 20.55;
	printf("Min of %d and %d is %d\n", a, b, Min(a, b));
	printf("Min of %.2f and %.2f is %.2f\n", x, y, Min(x, y));
	printf("Min of %.2lf and %.2lf is %.2lf\n", p, q, Min(p, q));

	return 0;
}
