#include "StudentData.h"
#include <iomanip>

ostream& operator<<(ostream& os, const StudentData& student)
{
	string succeeded = "";
	if (student.avgMark_ >= 4 && student.attendedLessons_ >= 5)
		succeeded = "+";

	os << setw(10) << succeeded << setw(10) << student.name_ << setw(15) <<
		student.surname_ << setw(13) << student.avgMark_ << setw(13) << student.attendedLessons_;
	return os;
}

vector<StudentData> GetStudentsFromFile(string path)
{
	vector<StudentData> students;

	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		string line;

		try
		{
			while (getline(fin, line, '\n'))
				students.push_back(StudentData(line));

		}
		catch (invalid_argument& e)
		{
			e.what();
		}
	}

	fin.close();
	return students;
}

int main()
{
	StudentData s1("Grigorii", "Skivoroda", 3.56, 5);
	StudentData s2("Taras", "Shevcjenko", 4, 5);
	StudentData s3("Hose", "De San-Martin", 4.9, 9);

	s1.writeToFile("file.txt");
	s2.writeToFile("file.txt");
	s3.writeToFile("file.txt");


	vector<StudentData> students = GetStudentsFromFile("file.txt");
	cout << setw(10) << "Succeeded" << setw(10) << "Name" << setw(15) << "Surname" << setw(13) << "Avg mark" << setw(13) << "Attended" << endl;
	cout << "--------------------------------------------------------------\n";
	for (auto s : students)
		cout << s << endl;

}

