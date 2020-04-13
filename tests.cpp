#include "tests.h"
#include "Book.h"
#include "Repo.h"
#include "Controller.h"
#include <assert.h>
#include <iostream>


void test::testRepo() {
	Book b("A", "B", true), b2("C", "D", false), b3("A", "C", false);
	Repo<Book> repos;
	Book vec[3];
	vec[0] = b;
	vec[1] = b2;
	vec[2] = b3;
	repos.addBook(b);
	repos.addBook(b2);
	assert(repos.getAll()[0] == vec[0]);
	assert(repos.getAll()[1] == vec[1]);
	repos.updateBook(b3);
	assert(repos.getAll()[0] == vec[2]);
	repos.deleteBook(b3);
	assert(repos.getSize() == 1);
}

void test::testBook() {
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

void test::testController() {
	std::string title1 = "aaa", title2 = "bbb", title3 = "ccc", title4 = "ddd", title5 = "eee";
	std::string author1 = "a1", author2 = "a2", author3 = "a3", author4 = "a4", author5 = "a5";
	Book e1(title1, author1, true), e2(title2, author2, true), e3(title3, author3, false), e4(title4, author4, false), e5(title5, author5, true);
	Book a1(title3, author1, true), a2(title4, author4, false),a3;
	Controller ctrl;
	ctrl.addBookController(title1, author1, true);
	ctrl.addBookController(title2, author2, true);
	ctrl.addBookController(title3, author3, false);
	ctrl.addBookController(title4, author4, false);
	ctrl.addBookController(title5, author5, true);
	assert(ctrl.getSizeController() == 5);
	ctrl.updateBookController(title3, author1, true);
	assert(ctrl.getElemController(2) == a1);
	ctrl.deleteBookController(title3);
	assert(ctrl.getSizeController() == 4);
	a3 = ctrl.getElemController(3);
	assert(ctrl.getElemController(2) == a2);
}

void test::testBorrow()
{
	std::string title1 = "aaa", title2 = "bbb", title3 = "ccc", title4 = "ddd", title5 = "eee", title6 = "fff";
	std::string author1 = "a1", author2 = "a2", author3 = "a3", author4 = "a4", author5 = "a5";
	Book e1(title1, author1, true), e2(title2, author2, true), e3(title3, author3, false), e4(title4, author4, false), e5(title5, author5, true);
	Book a1(title3, author1, true), a2(title4, author4, false), a3;
	Controller ctrl;
	ctrl.addBookController(title1, author1, true);
	ctrl.addBookController(title2, author2, true);
	ctrl.addBookController(title3, author3, false);
	ctrl.addBookController(title4, author4, false);
	ctrl.addBookController(title5, author5, true);
	assert(ctrl.borrowBookController(title3) == 2);
	assert(ctrl.borrowBookController(title6) == 0);
	assert(ctrl.borrowBookController(title1) == 1);
}

void test::testReturn()
{
	std::string title1 = "aaa", title2 = "bbb", title3 = "ccc", title4 = "ddd", title5 = "eee", title6 = "fff";
	std::string author1 = "a1", author2 = "a2", author3 = "a3", author4 = "a4", author5 = "a5";
	Book e1(title1, author1, true), e2(title2, author2, true), e3(title3, author3, false), e4(title4, author4, false), e5(title5, author5, true);
	Book a1(title3, author1, true), a2(title4, author4, false), a3;
	Controller ctrl;
	ctrl.addBookController(title1, author1, true);
	ctrl.addBookController(title2, author2, true);
	ctrl.addBookController(title3, author3, false);
	ctrl.addBookController(title4, author4, false);
	ctrl.addBookController(title5, author5, true);
	assert(ctrl.returnBookController(title3) == 1);
	assert(ctrl.returnBookController(title6) == 0);
	assert(ctrl.returnBookController(title1) == 2);
}

void test::run() {
	testBook();
	testRepo();
	testController();
	testBorrow();
	testReturn();
}
