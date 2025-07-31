#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	// Normal creation
	try {
		Bureaucrat st1("Student1", 75);
		std::cout << st1 << std::endl;

		// Increment grade
		st1.incGrade();
		std::cout << "After increment:\n" << st1 << std::endl;

		// Decrement grade
		st1.decGrade();
		std::cout << "After decrement:\n" << st1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Nothing to catch here..." << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	// Grade too high test
	try {
		Bureaucrat st2("Student2", 0);  // Should throw
		std::cout << "This should not be printed!" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Grade too low test
	try {
		Bureaucrat st3("Student3", 151);  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	// Increment beyond limit
	try {
		Bureaucrat st4("Student4", 1);
		std::cout << st4 << std::endl;
	 	st4.incGrade();  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Decrement beyond limit
	try {
		Bureaucrat st5("Student5", 150);
		std::cout << st5 << std::endl;
		st5.decGrade();  // Should throw
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
