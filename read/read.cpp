#include <vector>
#include <fstream>
#include "read.h"
#include "exception.cpp"

using namespace std;

string readText(string file) {
	file = homedir + path + file;

	if (fileNotFound(file)) {
		return "";
	}

	ifstream is;
	string line, text;
	is.open(file.c_str());

	while (getline(is, line)) {
		text += line;
	}

    return text;
}

void writeTextOnFile(string text, string file) {
	file = homedir + path + file;

	FILE *fp = fopen(file.c_str(), "w");
	fprintf(fp, "%s\n", text.c_str() );
	fclose(fp);
}

vector<string> readKnownWords(string file) {
	file = homedir + path + file;

	ifstream dictionary;
	string line;
	vector<string> text;

	if (fileNotFound(file)) {
		return text;
	}

	dictionary.open(file.c_str());
	while (getline(dictionary,line)){
		text.push_back(line);
	}
	dictionary.close();

    return text;
}

int readOption() {
	int option;
	do {
        cout << ">>> Choose an option: ";
        cin >> option;
    } while (invalidOption(option));

    return option;
}
