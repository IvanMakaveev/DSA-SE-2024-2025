#include <iostream>
#include <string>
using namespace std;

struct Student
{
	std::string name;
	int grade;
};

void countSortForGrades(Student* arr, size_t len)
{
	const size_t GRADES_VALUES_COUNT = 5;

	size_t* countArr = new size_t[GRADES_VALUES_COUNT]{ 0 };

	for (int i = 0; i < len; i++)
		countArr[arr[i].grade - 2]++;

	for (int i = 1; i < GRADES_VALUES_COUNT; i++)
		countArr[i] += countArr[i - 1];

	Student* result = new Student[len];
	for (int i = len - 1; i >= 0; i--)
	{
		size_t index = --countArr[arr[i].grade - 2];
		result[index] = arr[i];
	}

	for (int i = 0; i < len; i++)
		arr[i] = result[i];
        
	delete[] result;
	delete[] countArr;
}

int main()
{
	Student arr[] = { { "Petur", 4 }, { "Ivan", 6 }, { "Alex", 4 }, { "Vladimir", 5 }, { "Katerina", 5 } };

	countSortForGrades(arr, sizeof(arr)/sizeof(Student));

	for (int i = 0; i < sizeof(arr) / sizeof(Student); i++)
		cout << "Name: " << arr[i].name << ", grade: " << arr[i].grade << endl;

}