// grading2.cpp - uses C++ style object-handling (AFTER CHANGES BELOW)
// Nicholas Poob, Ishi Von Meier 4/18/2014

#include <iostream>
using namespace std;


class Record {
 public:
	Record();
	Record(double a, double b, double c, double d);
	void setGrades(double a, double b, double c, double d);
	char overallGrade() const;
	char overallGrade(double quizWt, double midtermWt, double finalWt) const;
	double getOne();
	double getTwo();
	double getMidterm();
	double getFinal();
	void setOne(double a);
	void setTwo(double a);
	void setMidterm(double a);
	void setFinal(double a);
 
private:
	double quiz1, quiz2, midterm, final;
	char letterEquiv(double grade) const;
	
};

Record::Record()
{
	quiz1=0.0;
	quiz2=0.0;
	midterm=0.0;
	final=0.0;
}

Record::Record(double a, double b, double c, double d)
{
	double a1, b1, c1, d1;
	if(a<0)
		a1 = 0.0;
	if (a>10)
		a1=10;
	if(b<0)
		b1=0.0;
	if(b>10)
		b1=10;
	if(c<0)
		c1=00;
	if(c>100)
		c1=100;
	if(d<0)
		d1=0.0;
	if(d>100)
		d1=100;
	quiz1 = a1;
	quiz2 = b1;
	midterm = c1;
	final = d1;
	if(a<0)
		a = 0.0;
	if(b<0)
		b = 0.0;
}
double Record::getOne()
{
	return quiz1;
}

double Record::getTwo()
{
	return quiz2;
}

double Record::getMidterm()
{
	return midterm;
}

double Record::getFinal()
{
	return final;
}

void Record::setOne(double a)
{
	quiz1=a;
}

void Record::setTwo(double a)
{
	quiz2=a;
}

void Record::setMidterm(double a)
{
	midterm=a;
}

void Record::setFinal(double a)
{
	final=a;
}
Record getScores();

int main() {
    Record rec = getScores();
    cout << "Grade is " << rec.overallGrade() << endl;  
    return 0;
}

Record getScores() {
    Record result;
	double a, b, c, d;
    cout << "Enter scores in this order: 2 quizzes, midterm, final: ";
    cin >> a >> b >> c >> d;
	result.setGrades(a,b,c,d);
    return result;
}


void Record::setGrades(double a, double b, double c, double d)
{
	quiz1 = a;
	quiz2 = b;
	midterm = c;
	final = d;
}
char Record::letterEquiv(double grade) const {      // FIX SIGNATURE
    if (grade >= 90) return 'A';
    if (grade >= 80) return 'B';
    if (grade >= 70) return 'C';
    if (grade >= 60) return 'D';
    return 'F';
}

char Record::overallGrade() const {  
    double quizPct = (quiz1 / 10 + quiz2 / 10) / 2;
    double overall = 25 * quizPct + 0.25 * midterm + 0.5 * final;
    return letterEquiv(overall);
}

char Record::overallGrade(double quizWt, double midtermWt, double finalWt) const
{
	double overall = 0.25*quizWt + 0.25*midtermWt + 0.5*finalWt;
	return letterEquiv(overall);
}

