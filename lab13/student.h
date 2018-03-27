#include <string>
using namespace std;

class Student
{
    private:
        int ID;
        string name;
        double percentage; 
        char gender;
    public:
        Student();
        Student(int I, string nam, double GP, char gende);
        void setStudent(int I, string nam, double GP, char gende);
        int getID();
        string getName();
        double getGPA();
        string getGender();
	bool operator<(const Student& b);
        friend std::ostream & operator<<(std::ostream &os, const Student& p);
		
};