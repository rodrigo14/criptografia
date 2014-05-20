#include <map>
#include <sstream>
#include <fstream>
#include <vector>

string breaker(string cypherText, int keySize)
{
	for (unsigned int i=0; i< cypherText.size() ; i++)
	{
		for (int j=0; j<keySize; j++)
		{
			if (cypherText[i] == '0')
			{
				cypherText[i] = 32;
				continue;
			}
			else if (cypherText[i] == 'A')
			{
				cypherText[i] = '9';
				continue;
			}
			else if (cypherText[i] == 'a')
			{
				cypherText[i] = 32;
				continue;
			}
			else if (cypherText[i] == 32)
			{
				cypherText[i] = 'z';
				continue;
			}
	
			cypherText[i]--;
		}
	}

	return cypherText;
}

int difference(char letter1, char letter2)
{
	int difference;

	if (letter1 < letter2) {
		swap(letter1 , letter2);
	}
		
	if (letter2 == 32 && (letter1 >= 'A' && letter1 <= 'Z'))
		difference = abs(letter2-letter1)-22;
	else if ((letter2 >= '0' && letter2 <= '9') && (letter1 >= 'A' && letter1 <= 'Z'))
		difference = abs(letter2-letter1)-7;
	else if ((letter2 >= '0' && letter2 <= '9') && (letter1 >= 'a' && letter1 <= 'z'))
		difference = abs(letter2-letter1)-13;
	else if (letter2 == 32 && (letter1 >= '0' && letter1 <= '9'))
		difference = abs(letter2 - letter1)-15;
	else if (letter2 == 32 && (letter1 >= 'a' && letter1 <= 'z'))
		difference= abs(letter2-letter1)-28;
	else if ((letter2 >= 'A' && letter2 <= 'Z') && (letter1 >= 'a' && letter1 <= 'z'))
		difference = abs(letter2-letter1)-6;
	else
		difference = abs(letter2-letter1);

	return difference;
}

string keyLengthFinder(string cypherText, vector<string>& knownWords)
{

	int keySize;
	unsigned int i, j, aux;
	bool found = false;

	map<string,vector<int> > sizeDifference;	
	vector<string> dictionary = knownWords;

	
	for (i=0; i < dictionary.size(); i++)
	{
		vector<int> sizes;

		for (j=1; j < dictionary[i].size(); j++)
		{	
			int temp = difference(dictionary[i][j], dictionary[i][j-1]);
			sizes.push_back(temp);
		}

		sizeDifference.insert(pair<string,vector<int> > (dictionary[i],sizes) );
		sizes.clear();
	}

	
	for (map<string,vector<int> >::iterator iterator = sizeDifference.begin(); iterator != sizeDifference.end(); iterator++ )
	{
		aux = 0;

		for (i=1 ; i< cypherText.size() ; i++)
		{
			if (aux == iterator->second.size())
			{
				found = true;
				break;
			}	
				
			int var = difference(cypherText[i], cypherText[i-1]);

			if ((var - iterator->second[aux] == 0) || ((62 - var) - iterator->second[aux] == 0))
				aux++;				
			else
				aux=0;
					
		}

		if (found || aux == iterator->second.size()) 
		{
			keySize = difference(iterator->first[iterator->first.size()-1], cypherText[i-1]);
			keySize = 62%(abs(62-keySize)) ;
			break;
		}
			
	}
		
	cout << "\n\t\tPossible Key Increment: " << keySize << endl;
	string brokenText =	breaker(cypherText,keySize);

	return brokenText;

}