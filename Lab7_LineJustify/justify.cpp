//formats text to be justified
//Ian Zimmerman
//March 12, 2021

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cassert>

using std::cout; using std::cin; using std::endl;
using std::string;

void justification(string&, string&, const int); //takes input and maximum length to format text

int main() {
	srand(time(nullptr)); //random number seed based on time
	const int stringLength = 75;
	string input = "Initialization goes brrrrrr"; //user input
	string punc = ",.;!?"; //the punctuation that allows 2 spaces to follow
	string quit = "y"; //used to leave a loop

	cout << "Please input a string that is less than 75 characters: ";
	getline(cin, input);

	cout << endl << "Your input line:" << endl << input << endl
		<< "It is " << input.size() << " characters long." << endl;

	justification(input, punc, stringLength);
}

//takes input and maximum length to format text to be justified
void justification(string& line, string& punct, const int stringSize) {
	const int paraEnd = 40; //if line is less than this it's the end of the paragraph and doesn't need to be formatted

	//if the line is longer than 40
	if (line.size() < paraEnd) {
		cout << line;
	}

	//if the string is longer or equal to 40
	else {

		//loops until line has 75 characters or < 40
		while (line.size() != stringSize) {

			//punctuation basedinsertion
			//adds some spaces after the punctuation marks
			//loops through both punct and line checking for punctuation
			for (int i = 0; i <= punct.size(); ++i) {
				int pos = line.find(punct[i]); //stores location of punctuation in line
				for (int j = 0; j < stringSize; ++j) {
					//while the index checked isnt the last index
					while (pos != string::npos) {
						if (pos != string::npos && pos != line.size() - 1) {
							//do insertion
							line.insert(pos + 1, " ");
						}
						pos = line.find(punct[i], pos + 1);
					}
				}
			}
			
			//random based insertion
			//adds spaces to bring the line size to 75 following punctuation based insertion
			int spaces = rand() % (75); //used to find position of spaces added to each available spot
			
			//loops through string looking for available spaces to add a space following the index set randomly
			for (int i = 0; i < stringSize; ++i) {
				if (stringSize != line.size()) {
					spaces = rand() % (stringSize - line.size()) + 1;
					if (spaces != string::npos) {
						line.insert(line.find_first_of(" ", spaces), " ");
					}
				}
				else break;
			}
		}
		//output following justification
		cout << "Your input line justified:" << endl << line << endl
			<< "It is " << line.size() << " characters long.";
	}
}
