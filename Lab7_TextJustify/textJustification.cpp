//justifies text from a file and outputs it to another
//Ian Zimmerman
//March 12, 2021

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

//#include "justified.txt"
//#include "unjustified.txt"

using std::cout; using std::cin; using std::endl;
using std::string;
using std::ifstream; using std::ofstream;

string justification(string&, string&, const int); //takes input and maximum length to format text

int main() {
	string input = "this is a placeholder"; //input from file unjustified.txt
	string punc = ",.;!?"; //the punctuation that allows 2 spaces to follow
	srand(time(nullptr)); //random number seed based on time
	const int stringLength = 75; //maximum line length

	//opens justified.txt to be written to
	ofstream just;
	just.open("justified.txt");

	//opens and reads from unjustified.txt
	ifstream unjust; //input file
	unjust.open("unjustified.txt");
	
	//reads each line from unjustified.txt, sends it to justification() then adds it to justified.txt
	while (!unjust.eof()) {
		getline(unjust, input);
		input = justification(input, punc, stringLength);
		just << input << "\n";
	}

	//closes open files
	unjust.close();
	just.close();
}


//takes input and maximum length to format text to be justified
string justification(string& line, string& punct, const int stringSize) {
	const int paraEnd = 40; //if line is less than this it's the end of the paragraph and doesn't need to be formatted

	//opens justified.txt to be written to
	ofstream just;
	just.open("justified.txt");

	//if the line is longer than 40
	if (line.size() < paraEnd) {
		return line;
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
		return line;
	}
}
