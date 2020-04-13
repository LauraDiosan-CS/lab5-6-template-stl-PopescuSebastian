#pragma once
#include "Repo.h"
#include "Book.h"
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
	void addBook();
	void updateBook();
	void deleteBook();
	void print();
	bool printBooksByAuthorAndStatus(std::string, bool);
	void borrowBook();
	void returnBook();
	void loadFile();
	void saveFile();
public:
	void run();
};

