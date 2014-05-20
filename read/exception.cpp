int fileNotFound(string file) {
	FILE *fp = fopen(file.c_str(), "r");

	if (!fp) {
		cout << "The file was not found" << endl;
		return 1;
	}

	return 0;
}

int invalidOption(int option) {
    if (option < 0 || option > 4) {
        cout << ">>> Invalid option! Try again.\n";
        return -1;
    }

    return 0;
}