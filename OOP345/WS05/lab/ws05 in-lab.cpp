// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.10.10
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		// TODO: load the collection of books from the file "argv[1]".
		std::ifstream file(argv[1]);
		
		/*counting?
		int count = 0;
		do {
			std::getline(file, tempBook);
			if (file) {
				if (tempBook[0] != '#') count++;
			}
		} while (file);
		bookP = new Book*[count];
		end of counting       */
		sdds::Book **bookP = nullptr;
		std::string tempBook;

		bookP = new sdds::Book*[7];
		int i = 0;
		do{
		//       - read one line at a time, and pass it to the Book constructor
			std::getline(file, tempBook);
			bookP[i] = new sdds::Book(tempBook); // IMPORTANT: How to define a pointer to an object, A pointer = new ClassName(Object);
			//Book::Book(tempBook); -> Can't do it directly
		//       - store each book read into the array "library"
			library[i] = tempBook;
		//       - lines that start with "#" are considered comments and should be ignored
			if (file) {
				if (tempBook[0] != '#') {
					i++;
				}
			}
		} while (i < 7);
		
		file.close();
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	auto fix = [&](Book& src) {
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
		if (src.country() == "US") {
			src.price() = src.price() * usdToCadRate;
		}
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
		if (src.country() == "UK" && (src.year() >= 1990 && src.year() <= 1999)) {
			src.price() = src.price() * gbpToCadRate;
		}

	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	for (int i = 0; i < 7; i++) {
		fix(library[i]);
	}
	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
