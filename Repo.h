#pragma once
#include "Book.h"
#include <deque>
template <class T>
class Repo
{
protected:
	std::deque<T> elem;
public:
	Repo();
	bool addBook(T e);
	bool updateBook(T e);
	bool deleteBook(T e);
	std::deque<T> getAll();
	int getSize();
	T getElem(int index);
	int borrowBook(T e);
	int returnBook(T e);
	std::string getAuthor(T e);
	~Repo();
};

template <class T>
Repo<T>::Repo() {}

template <class T>
bool Repo<T>::addBook(T e) {
	this->elem.push_back(e);
	return 1;
}

template <class T>
bool Repo<T>::updateBook(T e) {
	int repo_size = this->elem.size();
	bool succes = false;
	for (int i = 0; i < repo_size; i++) {
		if (this->elem[i].getTitle() == e.getTitle()) {
			this->elem[i].setAuthor(e.getAuthor());
			this->elem[i].setStatus(e.getStatus());
			succes = true;
		}
	}
	return succes;
}

template <class T>
bool Repo<T>::deleteBook(T e) {
	int repo_size = this->elem.size();
	bool succes = false;
	for (int i = 0; i < repo_size; i++) {
		if (this->elem[i].getTitle() == e.getTitle()) {
			this->elem.erase(this->elem.begin() + i);
			succes = true;
			repo_size--;
		}
	}
	return succes;
}

template <class T>
int Repo<T>::borrowBook(T e) {
	int repo_size = this->elem.size();
	int succes = 0;
	for (int i = 0; i < repo_size; i++) {
		if (this->elem[i].getTitle() == e.getTitle()) {
			if (this->elem[i].getStatus() == true)
				return 1;
			if (this->elem[i].getStatus() == false) {
				this->elem[i].setStatus(true);
				return 2;
			}
		}
	}
	return succes;
}

template <class T>
int Repo<T>::returnBook(T e) {
	int repo_size = this->elem.size();
	int succes = 0;
	for (int i = 0; i < repo_size; i++) {
		if (this->elem[i].getTitle() == e.getTitle()) {
			if (this->elem[i].getStatus() == true) {
				this->elem[i].setStatus(true);
				return 2;
			}
			if (this->elem[i].getStatus() == false)
				return 1;
		}
	}
	return succes;
}

template <class T>
std::string Repo<T>::getAuthor(T e) {
	int repo_size = this->elem.size();
	std::string author = "";
	for (int i = 0; i < repo_size; i++) {
		if (this->elem[i].getTitle() == e.getTitle())
			return elem[i].getAuthor();
	}
	return author;
}

template <class T>
int Repo<T>::getSize() {
	int repo_size = this->elem.size();
	return repo_size;
}


template <class T>
std::deque<T> Repo<T>::getAll() {
	return this->elem;
}

template <class T>
T Repo<T>::getElem(int index) {
	return this->elem[index];
}

template <class T>
Repo<T>::~Repo() {}
