#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>

using namespace std;

int main() {

	srand(time(NULL));
	int randomNumber = rand();
	
	vector <int> com_space;
	vector <int> user_space;
	int input;
	
	
	//	1) 컴퓨터가 1~25까지의 수 중 랜덤으로 6개의 수 지정(중복 x)

	// (find(com_space.begin(), com_space.end(), num_range) == com_space.end()) 같은게없다 참
	
	
	//	2) 사용자도 1~25까지의 수 중 원하는 숫자 6개 입력(중복 x)
	cout << "Pick a number\n";
	for (int i = 0; i < 6; i++) {
		cout << "Number." << i + 1 << ": ";
		cin >> input;
	 if (input >= 1 && input <= 25 && find(user_space.begin(), user_space.end(), input) == user_space.end()) {
			user_space.push_back(input);
		}
		else { 
			--i;
			cout << "Please, give a number between (1~25), the last number was already used.\n";
			continue; }
		
	}
	cout << endl;
	cout << "Your's picks: ";
	for (int nums2 : user_space) {
		cout << nums2 << " ";
	}
	cout << endl<<endl;

	while (com_space.size() < 6) {
		int num_range = rand() % 25 + 1;
		if (find(com_space.begin(), com_space.end(), num_range) == com_space.end()) {
			com_space.push_back(num_range);
		}
	}
	cout << "Computer's picks: ";

	for (int nums : com_space) {
		cout << nums << " ";
	}
	cout << endl << endl;

	//	3) 두 배열을 비교해서 몇 등인지 출력하기!
	int j=0;
	int matched = 0;
	for (int nums : com_space) {
		for (int nums2: user_space) {
		
			if (nums == nums2) {
				matched++;

			}
		}

		
	}
	cout << "Matched numbers :"<< matched<<endl<<endl;

	//	3 - 1) 한 개도 맞추지 못하면 7등, 1개만 맞추면 6등, 2개 맞추면 5등...
	if (matched == 5) {
		cout << "축하드립니다 2등!!!!";
	}
	if (matched == 4) {
		cout << "축하드립니다 3등!!!!";
	}
	if (matched == 3) {
		cout << "축하드립니다 4등!!!!";
	}
	if (matched == 2) {
		cout << "축하드립니다 5등!!!!";
	}
	if (matched == 1) {
		cout << "축하드립니다 6등!!!!";
	}
	if (matched == 0) {
		cout << "축하드립니다 7등!!!!";
	}

	//	3 - 2) 6개를 모두 맞추면 1등
	if (matched == 6) {
		cout << "축하드립니다 1등!!!!";
	}
}
