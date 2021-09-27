#pragma once
#ifndef STUDENT_DATA_H
#define STUDENTDATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#pragma pack(1)

class StudentData
{
public:
	StudentData() : name_("None"), surname_("None"), avgMark_(0.0), attendedLessons_(0) {}
	StudentData(string name, string surname, double average_mark, unsigned attended_lessons);
	StudentData(string rawData);
	
	void writeToFile(string path);

	friend ostream& operator<<(ostream& os, const StudentData& student);


private:
	string name_, surname_;
	double avgMark_;
	unsigned attendedLessons_;
};

#endif
