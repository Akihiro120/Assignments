/*
Assignment Description :

Write a C++ program that calculates and displays the average grade of a group of students.
The program should prompt the user to enter the number of students in the class and then input each student's grades 
for a predetermined number of assignments (let's say 3 assignments for simplicity).
After entering the grades, the program should compute and display each student's average grade and the class average.

Requirements:

1. The program should use appropriate data structures to store student grades.
2. Implement functions to calculate the average grade for each student and the class average.
3. Implement proper input validation to ensure that the user enters valid grades.
4. Display clear and informative messages to guide the user through the program.
5. Use comments to explain your code logic and improve code readability.
6. Test your program with different inputs to ensure correctness.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// limit of assignments per student
#define NUMBER_OF_ASSIGNMENTS 3

int current_assignment = 0;
void gatherGrades(int current_student, std::unordered_map<int, std::vector<int>>& data)
{
	// a local variable to temporarily store the results
	std::vector<int> grades;

	// loop for each assignment - range based
	for (int j = 0; j < NUMBER_OF_ASSIGNMENTS; j++)
	{
		current_assignment = j;
		std::cout << "Enter Grade for Assignment " + std::to_string(j + 1) + ": ";

		int grade = 0;
		std::cin >> grade;
		// check if the grade is in the valid range
		if (grade < 0 || grade > 100)
		{
			std::cout << "Please Enter a Valid Grade (0 - 100)" << "\n\n";
			j--; // return to the previous assigment
		}
		else {
			// if the grade is valid store the grade
			grades.push_back(grade);
		}
	}

	// store the grades to the list
	data[current_student] = grades;
}

int main()
{
	// input the number of students in class
	int num_of_students = 0;
	std::cout << "Enter the Number of Students: ";
	std::cin >> num_of_students;
	
	// for each student store the grade for each assignment, then continue for the next student
	std::unordered_map<int, std::vector<int>> student_data;
	// unordered_map: 
	// int = student index
	// std::vector<int> = the grades of the student

	// loop for each student
	for (int i = 0; i < num_of_students; i++)
	{
		std::cout << "\n" << "Student " + std::to_string(i + 1) + ":" << "\n";

		// gather the grade for each student
		gatherGrades(i, student_data);
	}

	// after the grades have been gathered, calculate the class average and the student average
	for (int i = 0; i < num_of_students; i++)
	{
		// calculate the average for that student
		double average_grade = 0.0f;
		double total = 0.0f;
		for (auto grade : student_data[i])
		{
			// add the amount
			total += grade;
		}
		// determine the average = total / amount
		average_grade = total / static_cast<double>(NUMBER_OF_ASSIGNMENTS);

		std::cout << "\n" << "Student " + std::to_string(i + 1) << " Average Grade: " + std::to_string(average_grade);
	}

	// class average
	double class_average = 0.0f;
	for (int i = 0; i < num_of_students; i++)
	{
		for (auto grade : student_data[i])
		{
			class_average += grade;
		}
	}

	// display the average
	class_average /= num_of_students;
	std::cout << "\n" << "Class Average: " + std::to_string(class_average) << "\n";

	return 0;
}