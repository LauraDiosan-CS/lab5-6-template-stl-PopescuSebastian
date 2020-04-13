#pragma once
#include "Repo.h"
#include "RepoFile.h"
class Controller
{
private:
	RepoFile<Book> file_repo;
public:
	Controller();
	bool addBookController(std::string, std::string, bool);
	bool updateBookController(std::string, std::string, bool);
	bool deleteBookController(std::string);
	int getSizeController();
	Book getElemController(int index);
	int borrowBookController(std::string);
	int returnBookController(std::string);
	bool loadFromFileController(std::string);
	bool saveToFileController(std::string);
	std::string getAuthorByTitleController(std::string);
	std::deque<Book> getAllController();
};

