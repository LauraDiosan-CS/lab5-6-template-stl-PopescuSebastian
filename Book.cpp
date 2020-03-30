#include "Book.h"
Book::Book() {
	this->title = "";
	this->author = "";
	this->borrowed = NULL;
}

Book::Book(std::string title, std::string author, bool borrowed) {
	this->title = title;
	this->author = author;
	this->borrowed = borrowed;
}

Book::Book(const Book& b) {
	this->title = b.title;
	this->author = b.author;
	this->borrowed = b.borrowed;
}

std::string Book::getTitle() {
	return this->title;
}

std::string Book::getAuthor() {
	return this->author;
}

bool Book::getStatus() {
	return this->borrowed;
}

void Book::setTitle(std::string newTitle) {
	this->title = newTitle;
}

void Book::setAuthor(std::string newAuthor) {
	this->author = newAuthor;
}

void Book::setStatus(bool newStatus) {
	this->borrowed = newStatus;
}

Book& Book::operator = (const Book& e) {
	this->title = e.title;
	this->author = e.author;
	this->borrowed = e.borrowed;
	return *this;
}

bool Book::operator == (const Book& e) {
	if (this->title == e.title)
		if (this->author == e.author)
			if (this->borrowed == e.borrowed)
				return true;
			else
				return false;
		else
			return false;
	else
		return false;

}

Book::~Book() {};