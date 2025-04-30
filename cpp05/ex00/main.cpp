#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	// Normal creation
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;

		// Increment grade
		bob.incGrade();
		std::cout << "After increment: " << bob << std::endl;

		// Decrement grade
		bob.decGrade();
		std::cout << "After decrement: " << bob << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Nothing to catch here..." << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	// Grade too high test
	try {
		Bureaucrat alice("Alice", 0);  // Should throw
		std::cout << "This should not be printed!" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Grade too low test
	try {
		Bureaucrat eve("Eve", 151);  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	// Increment beyond limit
	try {
		Bureaucrat topGuy("TopGuy", 1);
		std::cout << topGuy << std::endl;
		topGuy.incGrade();  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Decrement beyond limit
	try {
		Bureaucrat bottomGuy("BottomGuy", 150);
		std::cout << bottomGuy << std::endl;
		bottomGuy.decGrade();  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
