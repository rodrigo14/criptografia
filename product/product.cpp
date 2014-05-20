
void product_menu() {
	cout << "\n\t\tProduct Cipher\n";
	cout << "Options menu:\n";
	cout << "(1) Encrypt\n";
	cout << "(2) Decrypt\n";
	cout << "(3) Back\n";
}

int productCipher() {
	bool execute = true;
	int option;
	string plaintext, key1, cipher;
	const int key2 = 8;

	product_menu();
	option = readOption();

	switch (option) {
		case 0:
			system("clear");
		break;

		case 1:
			plaintext = readText("plaintext.txt");
			key1 = readText("key.txt");
			cipher = Vigenere(key1).encrypt(plaintext);
			cipher = RailFence(key2).encrypt(cipher);

			cout << "Encrypted text: " << cipher << "\n\n";
			writeTextOnFile(cipher, "prodcipher.txt");
		break;

		case 2:
			cipher = readText("prodcipher.txt");
			key1 = readText("key.txt");
			plaintext = RailFence(key2).decrypt(cipher);
			plaintext = Vigenere(key1).decrypt(plaintext);
			
			cout << "Decrypted text: " << plaintext << "\n\n";
			writeTextOnFile(plaintext, "proddecipher.txt");
		break;

		case 3:
			execute = false;
		break;
	}

	return execute;
}