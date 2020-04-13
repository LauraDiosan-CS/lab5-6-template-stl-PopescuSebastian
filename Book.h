#pragma once
#include <string.h>
#include <iostream>
#include <ostream>
class Book
{
private:
	std::string title;
	std::string author;
	bool borrowed;
public:
	Book();
	Book(std::string title, std::string author, bool borrowed);
	Book(const Book& b);
	std::string getTitle();
	std::string getAuthor();
	bool getStatus();
	void setTitle(std::string newTitle);
	void setAuthor(std::string newAuthor);
	void setStatus(bool newStatus);
	Book& operator = (const Book& e);
	bool operator == (const Book& e);
	friend std::ostream& operator<<(std::ostream& os, const Book& s);
	friend std::istream& operator>>(std::istream& is, Book& s);
	~Book();
};

