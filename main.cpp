#include <iostream>
#include <vector>//vector
#include <algorithm>//sort
using namespace std;

int main() {

	vector<int> people;

	int input = 0;
	//입력
	for (int i = 0;i < 9;i++) {
		
		cin >> input;
		people.push_back(input);

	}

	int sum = 0;

	sort(people.begin(), people.end());

	do {

		for (int i = 0; i < 7; i++) {
			 sum += people[i];
		}

		if (sum == 100) {
			break;
		}

		sum = 0;

	} while (next_permutation(people.begin(), people.end()));

	system("cls");

	//출력
	for (int i = 0; i < 7; i++) {
		cout << people[i] << endl;
	}

}