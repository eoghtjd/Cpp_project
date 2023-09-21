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
	
	
	//	1) ��ǻ�Ͱ� 1~25������ �� �� �������� 6���� �� ����(�ߺ� x)

	// (find(com_space.begin(), com_space.end(), num_range) == com_space.end()) �����Ծ��� ��
	
	
	//	2) ����ڵ� 1~25������ �� �� ���ϴ� ���� 6�� �Է�(�ߺ� x)
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

	//	3) �� �迭�� ���ؼ� �� ������ ����ϱ�!
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

	//	3 - 1) �� ���� ������ ���ϸ� 7��, 1���� ���߸� 6��, 2�� ���߸� 5��...
	if (matched == 5) {
		cout << "���ϵ帳�ϴ� 2��!!!!";
	}
	if (matched == 4) {
		cout << "���ϵ帳�ϴ� 3��!!!!";
	}
	if (matched == 3) {
		cout << "���ϵ帳�ϴ� 4��!!!!";
	}
	if (matched == 2) {
		cout << "���ϵ帳�ϴ� 5��!!!!";
	}
	if (matched == 1) {
		cout << "���ϵ帳�ϴ� 6��!!!!";
	}
	if (matched == 0) {
		cout << "���ϵ帳�ϴ� 7��!!!!";
	}

	//	3 - 2) 6���� ��� ���߸� 1��
	if (matched == 6) {
		cout << "���ϵ帳�ϴ� 1��!!!!";
	}
}
