
#include "header.h"

double iterativePower(double x, int n) {
	if (n < 0) {
		return iterativePower(1/x, -n);
	} else {
		double acum = 1;
		for (int i = 1; i <= n; i++) {
			acum *= x;
		}
		return acum;
	}
}


double recursivePower(double x, int n) {
	if (n < 0) {
		return recursivePower(1/x, -n);
	} else if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else if (n % 2 == 0) {
		return recursivePower(x * x, n / 2);
	} else if (n % 2 != 0) {
		return x * recursivePower(x * x, (n - 1) / 2);
	}
	return 0;
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterative power(2, 1000): " << iterativePower(2, 1000) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive power(2, 1000): " << recursivePower(2, 1000) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
