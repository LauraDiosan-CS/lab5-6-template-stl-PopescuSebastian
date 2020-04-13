#include "Controller.h"
#include "RepoFile.h"
#include <deque>
Controller::Controller() {
}


bool Controller::addBookController(std::string title, std::string author, bool status){
	Book b(title, author, status);
	bool succes;
	succes = file_repo.addBook(b);
	return succes;
}

bool Controller::updateBookController(std::string title, std::string author, bool status) {
	Book b(title, author, status);
	bool succes;
	succes = file_repo.updateBook(b);
	return succes;
}

bool Controller::deleteBookController(std::string title) {
	Book b(title, "", NULL);
	bool succes;
	succes = file_repo.deleteBook(b);
	return succes;
}

int Controller::borrowBookController(std::string title) {
	Book b(title, "", NULL);
	int succes;
	succes = file_repo.borrowBook(b);
	return succes;
}

int Controller::returnBookController(std::string title) {
	Book b(title, "", NULL);
	int succes;
	succes = file_repo.returnBook(b);
	return succes;
}

std::string Controller::getAuthorByTitleController(std::string title) {
	Book b(title, "", NULL);
	std::string author;
	author = file_repo.getAuthor(b);
	return author;
}

bool Controller::loadFromFileController(std::string file_name) {
	bool succes;
	succes = file_repo.loadFromFile(file_name);
	return succes;
}

bool Controller::saveToFileController(std::string file_name) {
	bool succes;
	succes = file_repo.saveToFile(file_name);
	return succes;
}

int Controller::getSizeController() {
	return file_repo.getSize();
}

Book Controller::getElemController(int index) {
	return file_repo.getElem(index);
}

std::deque<Book> Controller::getAllController() {
	std::deque<Book> elem;
	elem = file_repo.getAll();
	return elem;
}