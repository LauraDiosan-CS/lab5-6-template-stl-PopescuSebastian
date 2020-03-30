#pragma once
#include "Repo.h"
#include "Book.h"
class UI
{
private:
	Repo<Book> repository;
	void addProduct();
public:
	void run();
};

