#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>

using namespace std;

int measurements_amount = 5;

char ans;

void sort(double* measurements)
{
	int count;

	do
	{
		count = 0;

		for (int i = 1; i < measurements_amount; i++)
		{
			if (measurements[i - 1] > measurements[i])
			{
				count++;

				double temp = measurements[i];

				measurements[i] = measurements[i - 1];

				measurements[i - 1] = temp;
			}
		}
	} while (count > 0);
}

void direct_measurements()
{
	do
	{
		cout << "Enter amount of measurements:\n";

		cin >> measurements_amount;
	} while (measurements_amount < 1);

	double* measurements = new double[measurements_amount];

	cout << "Enter the measurements:\n";

	for (int i = 0; i < measurements_amount; i++)
	{
		cout << i + 1 << ": ";

		cin >> measurements[i];
	}

	do
	{
		cout << "Your measurements:\n";

		for (int i = 0; i < measurements_amount; i++) cout << i + 1 << ": " << measurements[i] << endl;

		cout << "Is everything right?\n 1: Yes\n 2: No\n";

		ans = _getch();

		if (ans == '1') break;

		else if (ans == '2')
		{
			int choice;

			do
			{
				cout << "Enter the number of measurement you want to change:\n";

				cin >> choice;

				if (choice < 1 or choice > measurements_amount) cout << "Invalid number, try again, please...\n";
			} while (choice < 1 or choice > measurements_amount);

			cout << "Enter new measurement's value:\n";

			double temp;

			cin >> temp;

			measurements[choice - 1] = temp;
		}

		else cout << "Something went wrong, try again, please...\n";
	} while (ans != '1');

	cout << "Enter Student's coefficient:\n";

	double student;

	cin >> student;

	cout << "Enter the scale value:\n";

	double scale_value = 0;

	cin >> scale_value;

	sort(measurements);

	cout << "Sorted measurements:\n";

	for (int i = 0; i < measurements_amount; i++) cout << i + 1 << ": " << measurements[i] << endl;

	cout << "Range equals:\n";

	double range = 0;

	for (int i = 0; i < measurements_amount - 1; i++)
	{
		double difference = measurements[i + 1] - measurements[i];

		cout << difference;

		if (i == measurements_amount - 2) cout << " = ";

		else cout << " + ";

		range += difference;
	}

	cout << range << endl;

	double average_measurement = 0;

	cout << "Average measurement equals:\n(";

	for (int i = 0; i < measurements_amount; i++)
	{
		cout << measurements[i];

		if (i == measurements_amount - 1) cout << ")/" << measurements_amount << " = ";

		else cout << " + ";

		average_measurement += measurements[i] / 5;
	}

	cout << average_measurement << endl;

	cout << "Average square deviation equals:\nsqrt(";

	double average_square_deviation = 0;

	for (int i = 0; i < measurements_amount; i++)
	{
		double temp = pow(measurements[i] - average_measurement, 2) / sqrt(measurements_amount * (measurements_amount - 1));

		cout << temp;

		average_square_deviation += temp;

		if (i == measurements_amount - 1) cout << ") = ";

		else cout << " + ";
	}

	average_square_deviation = sqrt(average_square_deviation);

	cout << average_square_deviation << endl;

	double random_deviation = student * average_square_deviation;

	double full_deviation = sqrt(pow(random_deviation, 2) + pow(scale_value, 2));

	cout << "Random deviation equals:\n" << student << " * " << average_square_deviation << " = " << random_deviation << "\nFull deviation equals:\nsqrt(random_deviation^2 + scale_value^2) = " << full_deviation << endl;

	double relative_deviation = random_deviation / average_measurement * 100;

	cout << "Relative deviation equals:\nrandom_deviation / average_measurement * 100% = " << relative_deviation << "%" << endl;

	cout << "The result equals " << average_measurement << " +- " << full_deviation << endl;

	delete[] measurements;
}
