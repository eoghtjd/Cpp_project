#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>

using namespace std;

int main() {

	vector <int> mother_space;
	vector <int> com_space;
	vector <int> user_space;
	int input;

	srand(time(NULL));


	cout << "The given numbers" << endl;
	for (int i = 0; i < 9; i++) {
		mother_space.push_back(i + 1);
		cout << mother_space[i] << " ";
	}
	cout << endl << endl;


	int randomNumber = rand() % 9 + 1;
	com_space.push_back(randomNumber);;
	for (int k = 0; k < 2; k++) {
		int randomNumber = rand() % 9 + 1;

		//int nextnumber = randomNumber;
		if (randomNumber >= 1 && randomNumber <= 9 && find(com_space.begin(), com_space.end(), randomNumber) == com_space.end()) {
			com_space.push_back(randomNumber);;
		}
		else {
			--k;

		}
	}
	cout << "Com numbers" << endl;
	for (int com_nums : com_space) {
		cout << com_nums << " ";
	}
	cout << endl << endl;

	while (true) {



		cout << "Pick numbers (different numbers)/ If a pick number is out of the range, gonna shut it down" << endl;
		for (int j = 0; j < 3; j++) {

			cin >> input;
			
			if (input >= 1 && input <= 9 && find(user_space.begin(), user_space.end(), input) == user_space.end()) {
				user_space.push_back(input);
			}
			else if (find(user_space.begin(), user_space.end(), input) != user_space.end()) {
				cout << "all numbers sould be different" << endl;
				j--;
			}
			else {
	
				cout << "Off\n";
				return -1;
			}
		}
		cout << endl << endl;


		cout << "Your picks" << endl;
		for (int user_nums : user_space) {
		cout << user_nums << " ";
		}

		cout << endl << endl;


		int strike = 0;
		int ball = 0;

		// 이 부분 카운트 부분 틀림
		for (int i = 0; i < 3; i++) {

			if (com_space[i] == user_space[i]) {
				strike++;

				
			}
			
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (com_space[i] != user_space[i] && com_space[i] == user_space[j] && i != j) {
					ball++;


				}	
			}
		}

		cout << strike << " S, " << ball << " B" << endl << endl;
		if (strike == 3) {
			cout << "3S, out!";
			break;
		}
		//com_space.clear();
		user_space.clear();
	}
	return 0;
}
	