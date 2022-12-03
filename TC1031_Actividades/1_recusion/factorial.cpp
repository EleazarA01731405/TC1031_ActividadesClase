
#include "header.h"

lli iterativeFactorial(uint number) {
	lli acum = 1;
	for (uint i = 1; i <= number; i++) {
		acum *= i;
	}
	return acum;
}

lli recursiveFactorial(uint number) {
	if (number == 0) {
		return 1;
	} else {
		return number * recursiveFactorial(number - 1);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterative factorial(30): " << iterativeFactorial(30) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive factorial(30): " << recursiveFactorial(30) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
