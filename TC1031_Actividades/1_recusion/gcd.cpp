

#include "header.h"

uint iterativeGCD(uint a, uint b) {
	uint aux;
	while (b != 0) {
		aux = a;
		a = b;
		b = aux % b;
	}
	return a;
}

uint recursiveGCD(uint a, uint b) {
	if (b == 0) {
		return a;
	} else {
		return recursiveGCD(b, a % b);
	}
}

int main(int argc, char* argv[]) {
	Chronometer crono;
	double ms;

	crono.start();
	std::cout << "iterative gcd(389, 271): " << iterativeGCD(389, 271) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive gcd(389, 271): " << recursiveGCD(389, 271) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n\n\n";

	crono.start();
	std::cout << "iterative gcd(97835033, 45083758): " << iterativeGCD(97835033, 45083758) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";

	crono.start();
	std::cout << "recursive gcd(97835033, 45083758): " << recursiveGCD(97835033, 45083758) << "\n";
	ms = crono.stop();
	std::cout << "time: " << ms << " ms\n";
	return 0;
}
