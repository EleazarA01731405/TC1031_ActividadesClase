
#include "header.h"

uint iterativeSumDigits(uint number) {
	uint acum = 0;
	while (number > 0) {
		acum += (number % 10);
		number /= 10;
	}
	return acum;
}

uint recursiveSumDigits(uint number) {
	if (number == 0) {
		return 0;
	} else {
		return (number % 10) + recursiveSumDigits(number / 10);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterativeSumDigits(123456): " << iterativeSumDigits(123456) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursiveSumDigits(123456): " << recursiveSumDigits(123456) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
