#include "StudentData.h"

StudentData::StudentData(string name, string surname, double average_mark, unsigned attended_lessons)
{
	name_ = name;
	surname_ = surname;
	avgMark_ = average_mark;
	attendedLessons_ = attended_lessons;
}

StudentData::StudentData(string rawData) : StudentData()
{
	stringstream ss(rawData);
	string token;
	vector<string> tokens;

	while (getline(ss, token, ','))
		tokens.push_back(token);

	if (tokens.size() == 4)
	{
		name_ = tokens[0];
		surname_ = tokens[1];
		avgMark_ = stod(tokens[2]);
		attendedLessons_ = stoi(tokens[3]);
	}
	else
	{
		string s = "invalid input data: " + rawData;
		throw invalid_argument(s.c_str());
	}
}

void StudentData::writeToFile(string path)
{
	ofstream fout;
	fout.open(path, ios_base::app);

	if (fout.is_open())
	{
		fout << name_ << "," << surname_ << "," << avgMark_ << "," << attendedLessons_<<"\n";
	}
	else
	{
		cout << "Error opening file\n";
	}
	
	fout.close();

}



