//#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

	int tape[999] = {0};
	int tape_position = 0;

	int open_bracket_pos = -1;
	int closing_bracket_pos = -1;

	string input;

	std::cout << "Enter Command : \n";
	getline(std::cin, input);
	fflush(stdin);

	for (int i = 0; i < input.size(); i++) {
		int current_cmd = input[i];
		try {
			switch (current_cmd) {
				// 43 == +
			case 43:
				tape[tape_position] += 1;
				break;
				// 45 == -
			case 45:
				tape[tape_position] -= 1;
				break;
				// 62 == >
			case 62:
				if (tape_position <= 999) {
					tape_position++;
				}
				else {
					throw 1; // Memory Corruption
				}
				break;
				// 60 == <
			case 60:
				if (tape_position >= 0) {
					tape_position--;
				}
				else {
					throw 1; // Memory Corruption
				}
				break;
				// 46 == .
			case 46:
				std::cout << (char)tape[tape_position];
				break;
				// 44 == ,
			case 44:
				char comma_input;
				std::cin >> comma_input;
				tape[tape_position] = (int)comma_input;
				break;
				// 91 == [
			case 91:
				open_bracket_pos = i;

				if (tape[tape_position] == 0){
					// Check if closing bracket pos is not set
					if (closing_bracket_pos == -1) {
						// Find Closing Bracket Pos
						int temp_i = i;
						while (true) {
							temp_i++;
							int temp_current_cmd = input[temp_i];
							if (temp_current_cmd == 93) {
								closing_bracket_pos = temp_i;
								break;
							}

							if (temp_i == input.size()) {
								break;
							}
						}
					}
					i = closing_bracket_pos;
				}
				// 93 == ]
			case 93:
				closing_bracket_pos = i;

				if (tape[tape_position]){
					if (open_bracket_pos == -1){
						throw 2; // Mismatched Paranthesis
					}
					i = open_bracket_pos;
				}
				break;
			default:
				continue;
			}
			//cout << tape[tape_position];
			//cout << (int)current_cmd;
		}
		catch (int e) {
			std::cout << "Error Num:" << e << "\n";
			//return 1;
		}


		if (tape[tape_position] < 0) {
			tape[tape_position] = 255;
		}

		if (tape[tape_position] > 255) {
			tape[tape_position] = 0;
		}

	}
	std::cin.get();
	return 0;
}

// To Do List:

// Fix the Catching Errors
// Fix the Logic
// Implement the Loops and Conditions (Done)
// Refactor Code for better readibility
// Document the code
