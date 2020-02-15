#include "main.h"

int main()
{
	cout << "Enter the number of measurements:\n";

	cin >> measurements_number;

	double* measurement = new double[measurements_number];

	for (int i = 0; i < measurements_number; i++)
	{
		cout << "Enter the measurement number " << i + 1 << ":\n";

		cin >> measurement[i];
	}

	while (true)
	{
		for (int i = 0; i < measurements_number; i++) cout << i + 1 << ": " << measurement[i] << "\n";

		cout << "Is everything right?\n 1: Yes\n 2: Change the measurement\n";

		ans = _getch();

		if (ans == '1') break;

		else if (ans == '2')
		{
			int i;

			cout << "Enter the number of measurement you want to change:\n";

			cin >> i;

			cout << "Enter the new value of measurement number " << i << "\n";

			cin >> measurement[i - 1];
		}

		else cout << "Something went wrong, try again, please...\n";
	}

	double graduation;

	cout << "Enter the graduation: ";

	cin >> graduation;

	double average_measurements_value = 0;

	for (int i = 0; i < measurements_number; i++) average_measurements_value += measurement[i] / measurements_number;

	cout << "average value of measurements equals " << average_measurements_value << "\n";

	double difference_summary = 0;

	for (int i = 0; i < measurements_number; i++) difference_summary += pow((measurement[i] - average_measurements_value), 2);

	double average_square_deviation = sqrt(difference_summary / (measurements_number - 1)) / sqrt(measurements_number);

	cout << "average square deviation equals " << average_square_deviation << "\n";

	cout << "random accuracy equals " << average_square_deviation * 2.776 << "\n";

	cout << "device accuracy equals " << graduation / 2 << "\n";

	double full_accuracy = sqrt(pow(2.776 * average_square_deviation, 2) + pow(graduation / 2, 2));

	cout << "absolute accuracy of measurements equals " << 2.776 * average_square_deviation << "\nThe result equals " << average_measurements_value << " +- " << full_accuracy << "\n";

	cout << "relative accuracy equals " << 2.776 * average_square_deviation / average_measurements_value * 100 << "%\n";

	delete[] measurement;

	return 0;
}