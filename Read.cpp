#include "Read.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <string>

int input_commnd_read() {
	int cmd;
	std::cout << "Command:"; std::cin >> cmd;
	if (!std::cin) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please input a number between 0 and 8!\n";
		return input_commnd_read();
	}
	if (cmd < 0 || cmd > 8) {
		std::cout << "Please input a number between 0 and 8!\n";
		return input_commnd_read();
	}
	return cmd;
}

std::string title_read() {
	std::string book_title;
	std::cout << "Book title:";
	std::cin.get();
	std::getline(std::cin, book_title);
	return book_title;
}

std::string author_read() {
	std::string book_author;
	std::cout << "Book author:";
	std::getline(std::cin, book_author);
	return book_author;
}

bool status_read() {
	bool status = NULL;
	std::string stat;
	std::cout << "Is the book borrowed?Y/N :-> "; std::cin >> stat;
	if (stat != "y" && stat != "Y" && stat != "n" && stat != "N") {
		std::cout << "Wrong input! Try again!\n";
		status = status_read();
	}
	if (stat == "Y" || stat == "y" && status != NULL)
		status = true;
	else
		status = false;
	return status;
}

bool command_read() {
	bool status = false;
	std::string stat;
	std::cout << "Do you want to try again?Y/N :-> "; std::cin >> stat;
	if (stat != "y" && stat != "Y" && stat != "n" && stat != "N") {
		std::cout << "Wrong input! Try again!\n";
		status = status_read();
	}
	if (stat == "Y" || stat == "y" && status != NULL)
		status = true;
	else
		status = false;
	return status;
}

bool command_read_2() {
	bool status = NULL;
	std::string stat;
	std::cout << "Do you want to borrow another book from this author?Y/N :-> "; std::cin >> stat;
	if (stat != "y" && stat != "Y" && stat != "n" && stat != "N") {
		std::cout << "Wrong input! Try again!\n";
		status = status_read();
	}
	if (stat == "Y" || stat == "y" && status != NULL)
		status = true;
	else
		status = false;
	return status;
}