#include <cstdlib>

const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

class Vigenere {
public:
	string key;

	Vigenere(string key) {
		for (int i = 0; i < key.size(); ++i) {
			if (isalnum(key[i])) {
				this->key += key[i];
			}
		}

	}

	string encrypt(const string text) {
		string out;

		for (int i = 0, j = 0; i < text.length(); i++) {
			int textPosition = charPosition(text[i]);
			int keyPosition = charPosition(key[j]);
	
			if (textPosition >= 0) {
				int aux = (textPosition + keyPosition) % alphabet.size();
				out += alphabet[aux];
				j = (j + 1) % key.length();
			}
		}
	 
		return out;
	}

	string decrypt(const string text) {
		string out;

		for (int i = 0, j = 0; i < text.length(); i++) {
			char c = text[i];
			int cPosition = charPosition(c);
			int keyPosition = charPosition(key[j]);
	
			if (cPosition >= 0) {
				int aux = (cPosition - keyPosition + alphabet.size()) % alphabet.size();
				out += alphabet[aux];
				j = (j + 1) % key.length();
			}
		}
	
		return out;
	}

private:
	int charPosition(char c) {
		for (int i = 0; i < alphabet.size(); i++) {
			if (c == alphabet[i])
				return i;
		}

		return -1;
	}
};
/*
int main()
{
	string plaintext = "computacao seguranca";
	string key = "key14";

	string cipher = Vigenere(key).encrypt(plaintext);
	cout << cipher << endl;
	string text = Vigenere(key).decrypt(cipher);
	cout << text << endl;

	return 0;
}
*/