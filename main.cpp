/* 
Trabalho de Criptografia e Segurança de Redes

Substituition Cipher - Vigenère Cipher
Transposition Cipher - RailFence
Authors: Rodrigo Gonçalves, Alessandro Caetano
Prof.: Luiz Laranjeira
*/

#include <iostream>
#include <cstdlib>
#include "substituition/substituition.cpp"
#include "transposition/transposition.cpp"
#include "product/product.cpp"

void main_menu() {
	cout << "Select the mode of cipher:\n";
	cout << "(1) Substituition cipher\n";
	cout << "(2) Transposition cipher\n";
	cout << "(3) Product cipher\n";
	cout << "(4) Exit\n";
}

int main() {
	int option, execute = true;
	main_menu();

	while (execute) {
		option = readOption();

		switch (option) {
			case 0:
				system("clear");
				main_menu();
			break;

			case 1:
				while (substituitionCipher());
			break;

			case 2:
				while (transpositionCipher());
			break;

			case 3:
				while (productCipher());
			break;

			case 4:
				execute = false;
			break;
		}
		
	}

	return 0;
}

