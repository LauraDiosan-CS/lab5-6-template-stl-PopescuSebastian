#include "UI.h"
#include "Book.h"
void UI::addProduct() {
	bool succes;
	Book a("A", "b", true);
	succes = this->repository.addBook(a);
}

void UI::run() {
	addProduct();
}