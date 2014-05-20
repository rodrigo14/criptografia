#include "../read/read.cpp"
#include "Vigenere.cpp"
#include "Breaker.cpp"

void substituition_menu() {
	//Options menu
	cout << "\n\t\tSubstituition Cipher\n";
	cout << "Options menu:\n";
	cout << "(1) Encrypt\n";
	cout << "(2) Decrypt\n";
	cout << "(3) Break Cipher\n";
	cout << "(4) Back\n";
}

int substituitionCipher() {
	int option, execute = true;
	string plaintext, key, cipher, brokenText;
	vector<string> knownWords;
	
	substituition_menu();
	option = readOption();

	switch (option) {
		case 0:
			system("clear");
		break;

		case 1:
			plaintext = readText("plaintext.txt");
			key = readText("key.txt");
			cipher = Vigenere(key).encrypt(plaintext);

			cout << "Encrypted text: " << cipher << "\n\n";
			writeTextOnFile(cipher, "subcipher.txt");
		break;

		case 2:
			cipher = readText("subcipher.txt");
			key = readText("key.txt");
			plaintext = Vigenere(key).decrypt(cipher);

			cout << "Decrypted text: " << plaintext << "\n\n";
			writeTextOnFile(plaintext, "subdecipher.txt");
		break;

		case 3:
			cipher = readText("subcipher.txt");
			knownWords = readKnownWords("dictionary.txt");
			brokenText = keyLengthFinder(cipher, knownWords);

			cout << "Broken Text: " << brokenText << "\n\n";
			writeTextOnFile(brokenText, "brokentext.txt");
		break;

		case 4:
			execute = false;
		break;
	}
  
	return execute;
}
