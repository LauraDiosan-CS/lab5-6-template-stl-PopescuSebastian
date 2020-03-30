#include "tests.h"
#include "Book.h"
#include "Repo.h"
#include <assert.h>
void testRepo() {
	Book b("A", "B", true), b2("C", "D", false);
	Repo<Book> repos;
	Book vec[2];
	vec[0] = b;
	vec[1] = b2;
	repos.addBook(b);
	repos.addBook(b2);
	assert(repos.getAll()[0] == vec[0]);
	assert(repos.getAll()[1] == vec[1]);
}

void testBook() {
	Book b("A", "B", true), b2("C", "D", false);
	assert(b.getTitle() == "A");
	assert(b2.getTitle() == "C");
	assert(b.getAuthor() == "B");
	assert(b2.getAuthor() == "D");
	assert(b.getStatus() == true);
	assert(b2.getStatus() == false);
	b.setTitle("N");
	assert(b.getTitle() == "N");
	b.setAuthor("L");
	assert(b.getAuthor() == "L");
	b.setStatus(false);
	assert(b.getStatus() == false);
}

void runTests() {
	testBook();
	testRepo();
}