#include "RailFence.cpp"

void transposition_menu() {
	//Options menu
	cout << "\n\t\tTransposition Cipher\n";
	cout << "Options menu:\n"; 
	cout << "(1) Encrypt\n";
	cout << "(2) Decrypt\n";
	cout << "(3) Exit\n";
}

int transpositionCipher() {
	int option , execute = true;
	string plaintext, cipher;
	const unsigned int key = 8;
	
	transposition_menu();
	option = readOption();
	
	switch (option) {
		case 0:
			system("clear");
		break;

		case 1:
			plaintext = readText("plaintext.txt");
			cout << "Key = " << key << endl;
			cipher = RailFence(key).encrypt(plaintext);

			cout << "Encrypted text: " << cipher << "\n\n";
			writeTextOnFile(cipher, "transcipher.txt");
		break;

		case 2:
			cipher = readText("transcipher.txt");
			cout << "Key = " << key << endl;
			plaintext = RailFence(key).decrypt(cipher);

			cout << "Decrypted text: " << plaintext << "\n\n";
			writeTextOnFile(plaintext, "transdecipher.txt");
		break;

		case 3:
			execute = false;
		break;
	}

	return execute;
}
