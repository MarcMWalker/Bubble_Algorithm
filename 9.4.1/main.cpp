#include <iostream>
#include <iterator>
#include <array>

int main() {

	int numbers[12]{1,2,98,66,15,98,15,32,51,66,2,11};
	int max_array{std::size(numbers)};
	bool sort_complete{};
	int max_reduce{0};
	int top_num{};
	int highest_num{};
	int iterations{};

	while (sort_complete != true) {
		int current_high{};
		sort_complete = true;

		for (int i = 0, j = i + 1; j < (max_array - max_reduce); i++, j++) {

			int right_num{};
			int left_num{};

			if (numbers[i] > numbers[j]) {
				current_high = numbers[i];
				left_num = numbers[i];
				right_num = numbers[j];
				numbers[i] = right_num;
				numbers[j] = left_num;
				sort_complete = false;
			}
			else { current_high = numbers[j]; };

			if (current_high > highest_num) {
				highest_num = current_high;
			}
		}
		iterations++;

		if (max_reduce <= 0 && numbers[max_array-1] == highest_num) {
			top_num = highest_num;
			highest_num = 0;
			max_reduce++;
		}
		else if (max_reduce >= 1 && numbers[((max_array-1) - max_reduce)] == highest_num) {
			highest_num = 0;
			max_reduce++;
		}
	}

	std::cout << "Sorting completed:";
	std::cout << "\n------------------------------------------------------\n";

	for (int k = 0; k < max_array; k++) {
		std::cout << numbers[k] << " ";
	}

	std::cout << "\n------------------------------------------------------\n";
	std::cout << "Iterations: " << iterations;
	std::cout << "\nHighest number: " << top_num << "\n";
	sort_complete = true;
	return 0;
};