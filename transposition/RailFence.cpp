#include <algorithm>
#include <vector>

class RailFence {
public:
	int key;
	
	RailFence(int key) {
		this->key = key;
	}

	string encrypt(string text) {
		text = deleteInvalidCharacters(text);

		int size = text.size();
		vector<int> v = railfence_id(size, key);
		string out;

		for (int i=0; i<key; i++) {
			for (int z=0; z<size; z++) {
				if (v[z] == i)
					out += text[z];
			}	
		}

		return out;
	}

	string decrypt(string text) {
		text = deleteInvalidCharacters(text);

		vector<int> v = railfence_id(text.size(), key);
		vector<int> vsorted = v;
		sort(vsorted.begin(), vsorted.end());
		
		string out;

		for (int i=0; i < text.size(); i++) {
			for (int j=0; j < text.size(); j++) {
				if (v[i] == vsorted[j] && v[i] > -1) {
					out += text[j];
					v[i] = -1;
					vsorted[j] = -1;
				}
			}
		}

		return out;
	}

private:
	string deleteInvalidCharacters(string text) {
		string in;
		for (int i=0; i<text.size(); i++) {
			if (!isalnum(text[i]) && text[i] != ' ')
				continue;

			in += text[i];
		}

		return in;
	}

	vector<int> railfence_id(int length, int key) {
		/*	Returns a vector of integers with 
		the position of the line that the character 
		of the text will occupy, range of 0 to key-1.
		*/

		vector<int> v;

		for (int i=0, j=0; i<length; i++) {
			int updown;
			if (j == key - 1)
				updown = -1;
			else if (j == 0)
				updown = 1;

			v.push_back(j);
			j += updown;
		}

		return v;
	}

};
