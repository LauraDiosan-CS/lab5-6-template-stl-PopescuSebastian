#include "UI.h"
#include "Book.h"
#include "Read.h"
#include "Controller.h"
#include <string.h>
#include <iostream>
void menu() {
	std::cout << "Menu:\n";
	std::cout << "0 - EXIT\n";
	std::cout << "1 - ADD\n";
	std::cout << "2 - PRINT\n";
	std::cout << "3 - UPDATE\n";
	std::cout << "4 - DELETE\n";
	std::cout << "5 - Borrow a book\n";
	std::cout << "6 - Return a book\n";
	std::cout << "7 - Load from file\n";
	std::cout << "8 - Save to file\n";
	std::cout << "9 - Show Menu\n";
}
void UI::addBook() {
	std::string title, author;
	bool status, succes;
	title = title_read();
	author = author_read();
	status = status_read();
	succes = this->ctrl.addBookController(title, author, status);
	if (succes)
		std::cout << "Book succesfully added!\n";
	else
		std::cout << "There was an error in adding the book!\n";
}

void UI::updateBook() {
	std::string title, author;
	bool status, succes;
	title = title_read();
	author = author_read();
	status = status_read();
	succes = this->ctrl.updateBookController(title, author, status);
	if (succes)
		std::cout << "Book succesfully updated!\n";
	else
		std::cout << "There was an error in updating the book!\n";
}

void UI::deleteBook() {
	std::string title;
	bool succes;
	title = title_read();
	succes = this->ctrl.deleteBookController(title);
	if (succes)
		std::cout << "Book succesfully deleted!\n";
	else
		std::cout << "There was an error in deleting the book!\n";
}

void UI::borrowBook() {
	std::string title, author;
	int succes;
	bool cmd = false, found;
	title = title_read();
	succes = this->ctrl.borrowBookController(title);
	if (succes == 0) {
		std::cout << "The book doesn't exist!\n";
		cmd = command_read();
	}
	if (succes == 1) {
		std::cout << "The book is borrowed!\n";
		author = this->ctrl.getAuthorByTitleController(title);
		found = printBooksByAuthorAndStatus(author, false);
		if (found)
			cmd = command_read_2();
	}
	if (succes == 2) {
		std::cout << "You borrowed the book!\n";
	}
	if (cmd == true)
		borrowBook();
}

void UI::returnBook() {
	std::string title, author;
	int succes;
	bool cmd = false;
	title = title_read();
	succes = this->ctrl.returnBookController(title);
	if (succes == 0) {
		std::cout << "The book doesn't exist!";
		cmd = command_read();
	}
	if (succes == 1) {
		std::cout << "The book isn't borrowed!";
		cmd = command_read();
	}
	if (succes == 2) {
		std::cout << "You returned the book!\n";
	}
	if (cmd == true)
		returnBook();
}

bool UI::printBooksByAuthorAndStatus(std::string author, bool status) {
	std::deque<Book> elem;
	elem = this->ctrl.getAllController();
	int elem_size = elem.size();
	bool found = false;
	for (int i = 0; i < elem_size; i++) {
		if (elem[i].getAuthor() == author && elem[i].getStatus() == status) {
			std::cout << elem[i] << " ";
			found = true;
		}
	}
	if (found == false) {
		std::cout << "There are no more books written by " << author << "!\n";
		return false;
	}
	else
		return true;
}

void UI::loadFile() {
	std::string file_name = "repo.txt";
	bool succes;
	succes = this->ctrl.loadFromFileController(file_name);
	if (succes)
		std::cout << "Repo succesfully loaded from file!\n";
	else
		std::cout << "There was an error in loading repo from file!\n";
}

void UI::saveFile() {
	std::string file_name = "repo_out.txt";
	bool succes;
	succes = this->ctrl.saveToFileController(file_name);
	if (succes)
		std::cout << "Repo succesfully saved to file!\n";
	else
		std::cout << "There was an error in saving repo to file!\n";
}

void UI::print() {
	std::deque<Book> elem;
	elem = this->ctrl.getAllController();
	int elem_size = elem.size();
	if (elem_size == 0)
		std::cout << "There are no books in the library!\n";
	for (int i = 0; i < elem_size; i++) {
		std::cout << elem[i] << " ";
	}
}

void UI::run() {
	menu();
	int input_command;
	input_command = input_commnd_read();
	do {
		switch (input_command)
		{
		case 1:
			addBook();
			break;
		case 2:
			print();
			break;
		case 3:
			updateBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			borrowBook();
			break;
		case 6:
			returnBook();
			break;
		case 7:
			loadFile();
			break;
		case 8:
			saveFile();
			break;
		case 9:
			menu();
			break;
		default:
			break;
		}
		if (input_command != 0)
			input_command = input_commnd_read();
	} while (input_command != 0);
}