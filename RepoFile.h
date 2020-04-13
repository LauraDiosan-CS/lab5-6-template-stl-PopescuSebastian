#pragma once
#include "Repo.h"
#include <fstream>
#include <string>

template <class T>
class RepoFile :public Repo<T> {
public:
	bool loadFromFile(std::string file_name){
		std::fstream fileReadFrom;
		bool succes;
		fileReadFrom.open(file_name, std::ios::out | std::ios::in | std::ios::app);
		if (fileReadFrom.is_open()) {
			while (!fileReadFrom.eof()) {
				T book;
				fileReadFrom >> book;
				this->elem.push_back(book);
			}
			succes = true;
		}
		else
			succes = false;
		fileReadFrom.close();
		return succes;
	}
	bool saveToFile(std::string file_name) {
		std::fstream fileReadFrom;
		bool succes;
		fileReadFrom.open(file_name, std::ios::out | std::ios::in | std::ios::app);
		if (fileReadFrom.is_open()) {
			for (int i = 0; i<int(this->getSize()); i++) {
				fileReadFrom << this->elem[i];
			}
			succes = true;
		}
		else
			succes = false;
		fileReadFrom.close();
		return succes;
	}
};