// WaterPressure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>
#include <sstream>

// Prevent Windows from defining min and max macros
#define NOMINMAX
#include <Windows.h>

struct WaterPressurePoint {
	double x;
	double y;
	double pressure;
};

// Custom comparator for coordinates with epsilon-based comparison
struct CoordinateComparator {
	bool operator()(const std::pair<double, double>& a, const std::pair<double, double>& b) const {
		const double EPSILON = 1e-10;

		// If x values are different (accounting for epsilon)
		if (std::abs(a.first - b.first) > EPSILON) {
			return a.first < b.first;
		}

		// If x values are approximately equal, compare y values
		if (std::abs(a.second - b.second) > EPSILON) {
			return a.second < b.second;
		}

		// Coordinates are considered equal
		return false;
	}
};

// Enhanced function to return the filtered points
std::vector<WaterPressurePoint> FilterAndSaveWaterPressurePoints(
	const std::vector<WaterPressurePoint>& inputPoints,
	const std::string& outputFilePath)
{
	// Create an output file stream
	std::ofstream outputFile(outputFilePath);
	if (!outputFile.is_open()) {
		std::cerr << "Failed to open output file: " << outputFilePath << std::endl;
		return {};
	}

	// Set precision for output (3 decimal places)
	outputFile << std::fixed << std::setprecision(3);

	// Use a set to track unique coordinates
	std::set<std::pair<double, double>, CoordinateComparator> seenCoordinates;

	// Vector to store filtered points
	std::vector<WaterPressurePoint> filteredPoints;

	// Process each point in order
	for (const auto& point : inputPoints) {
		std::pair<double, double> coords(point.x, point.y);

		// Check if we've seen these coordinates before
		if (seenCoordinates.insert(coords).second) {
			// This is a new coordinate, write to file
			outputFile << point.x << " " << point.y << " " << point.pressure << std::endl;

			// Add to filtered points collection
			filteredPoints.push_back(point);
		}
	}

	outputFile.close();
	return filteredPoints;
}

// Function to read input points from console
std::vector<WaterPressurePoint> ReadPointsFromConsole() {
	std::vector<WaterPressurePoint> points;
	std::string input;

	std::cout << "Enter water pressure points (x y pressure), one per line." << std::endl;
	std::cout << "Enter an empty line when finished." << std::endl;

	while (true) {
		std::cout << "Point " << points.size() + 1 << ": ";
		std::getline(std::cin, input);

		// Exit on empty line
		if (input.empty()) {
			break;
		}

		WaterPressurePoint point;
		std::istringstream iss(input);

		// Try to parse three values
		if (iss >> point.x >> point.y >> point.pressure) {
			points.push_back(point);
		}
		else {
			std::cout << "Invalid input format. Please enter three numbers separated by spaces." << std::endl;
		}
	}

	return points;
}

// Function to print points to console
void PrintPoints(const std::vector<WaterPressurePoint>& points) {
	std::cout << "\nFiltered Points:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "      X          Y        Pressure" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// Set precision for console output (3 decimal places)
	std::cout << std::fixed << std::setprecision(3);

	for (const auto& point : points) {
		std::cout << std::setw(10) << point.x << " "
			<< std::setw(10) << point.y << " "
			<< std::setw(10) << point.pressure << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Total unique points: " << points.size() << std::endl;
}

int main() {
	// Ask user whether to use example data or input from console
	std::cout << "Choose input method:" << std::endl;
	std::cout << "1. Use example data" << std::endl;
	std::cout << "2. Input data from console" << std::endl;
	std::cout << "Enter choice (1 or 2): ";

	int choice;
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

	std::vector<WaterPressurePoint> inputPoints;

	// Process based on user choice
	if (choice == 1) {
		// Example input from the problem statement
		inputPoints = {
			{0, 0, 0},
			{0, 0, 15},
			{1e-19, 0, 0},
			{0.5, 0, 25.123},
			{0.1, 10, 25}
		};
		std::cout << "Using example data with " << inputPoints.size() << " points." << std::endl;
	}
	else {
		inputPoints = ReadPointsFromConsole();
		std::cout << "Read " << inputPoints.size() << " points from console." << std::endl;
	}

	// Define output file name
	std::string outputFileName = "water_pressure_data.txt";

	// Filter and save points, get the filtered points back
	auto filteredPoints = FilterAndSaveWaterPressurePoints(inputPoints, outputFileName);

	// Print the filtered points to console
	PrintPoints(filteredPoints);

	// Get and print the full path of the output file without using filesystem
	char fullPath[MAX_PATH];
	if (GetFullPathNameA(outputFileName.c_str(), MAX_PATH, fullPath, nullptr) != 0) {
		std::cout << "\nData successfully saved to: " << fullPath << std::endl;

		// Open the file with Notepad
		std::string command = "notepad.exe \"" + std::string(fullPath) + "\"";
		system(command.c_str());
	}
	else {
		std::cout << "\nData successfully saved to: " << outputFileName << std::endl;

		// Open the file with Notepad using relative path
		std::string command = "notepad.exe \"" + outputFileName + "\"";
		system(command.c_str());
	}

	return 0;
}