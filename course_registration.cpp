#include<bits/stdc++.h>
using namespace std;
class Course {
public:
    string Ccode;
    string Cname;
    string time;
    unordered_set<string> prerequisites;
    unordered_set<string> enrolledstudents;
    int credits;
    int strength;
    Course(string code, string name, int cr, int cap, string slot, vector<string> prereqs) 
        : Ccode(code), Cname(name), credits(cr), strength(cap), time(slot) {
        for (const string& prereq : prereqs) {
            prerequisites.insert(prereq);
        }
    }
    bool enrollstudent(const string& id) {
        if (enrolledstudents.size() < strength) {
            enrolledstudents.insert(id);
            return true;
        }
        return false;
    }
    bool enrollable(const unordered_set<string>& coursescompleted) {
        for (const string& prereq : prerequisites) {
            if (coursescompleted.find(prereq) == coursescompleted.end()) {
                return false;
            }
        }
        return true;
    }
    void printstudent() const {
        if (enrolledstudents.empty()) {
            cout << "No students enrolled in " << Ccode << endl;
        } else {
            cout << "Enrolled students in " << Ccode << ":";
            for (const string& id : enrolledstudents) {
                cout << " " << id;
            }
            cout << endl;
        }
    }
};
class Student {
public:
    string id;
    string name;
    int studyingyear;
    unordered_set<string> coursescompleted;
    unordered_set<string> coursesenrolled;
    Student(string id, string s, int year, vector<string> completed)
        : id(id), name(s), studyingyear(year) {
        for (const string& course : completed) {
            coursescompleted.insert(course);
        }
    }
    bool enrolledincorse(Course& course) {
        if (coursesenrolled.find(course.Ccode) != coursesenrolled.end()) {
            return false;
        }
        
        if (!course.enrollable(coursescompleted)) {
            return false;
        }

        if (course.enrollstudent(id)) {
            coursesenrolled.insert(course.Ccode);
            return true;
        }

        return false;
    }
};
class courseregistration {
private:
    unordered_map<string, Student*> students;
    unordered_map<string, Course*> courses;

public:
    void add_student(const string& id, const string& name, int studyingyear, const vector<string>& coursescompleted) {
        if (students.find(id) == students.end()) {
            students[id] = new Student(id, name, studyingyear, coursescompleted);
        }
    }
    void add_course(const string& Ccode, const string& Cname, int credits, int strength, const string& time, const vector<string>& prerequisites) {
        if (courses.find(Ccode) == courses.end()) {
            courses[Ccode] = new Course(Ccode, Cname, credits, strength, time, prerequisites);
        }
    }
    void enrollstudent(const string& id, const string& Ccode) {
    if (students.find(id) != students.end() && courses.find(Ccode) != courses.end()) {
        Student* student = students[id];
        Course* course = courses[Ccode];
        if (!student->enrolledincorse(*course)) {
            cout << "Enrollment failed for " << id << " in " << Ccode << endl;
        }
    } else {
        cout << "Invalid Student ID or Course Code" << endl;
    }
}
    void print_course(const string& Ccode) {
        if (courses.find(Ccode) != courses.end()) {
            courses[Ccode]->printstudent();
        } else {
            cout << "Invalid Course " << Ccode << endl;
        }
    }
};
int main() {
    courseregistration registration;
    int n;
    cin >> n;
    string input;
    while (n--) {
        cin >> input;
        if (input == "add_student") {
            string id, name;
            int studyingyear, num_completed;
            cin >> id >> name >> studyingyear >> num_completed;
            vector<string> coursescompleted(num_completed);
            for (int i = 0; i < num_completed; ++i) {
                cin >> coursescompleted[i];
            }
            registration.add_student(id, name, studyingyear, coursescompleted);
        }
        else if (input == "add_course") {
            string Ccode, Cname, time;
            int credits, strength, num_prerequisites;
            cin >> Ccode >> Cname >> credits >> strength >> time >> num_prerequisites;
            vector<string> prerequisites(num_prerequisites);
            for (int i = 0; i < num_prerequisites; ++i) {
                cin >> prerequisites[i];
            }
            registration.add_course(Ccode, Cname, credits, strength, time, prerequisites);
        }
        else if (input == "enroll") {
            string id, Ccode;
            cin >> id >> Ccode;
            registration.enrollstudent(id, Ccode);
        }
        else if (input == "print") {
            string Ccode;
            cin >> Ccode;
            registration.print_course(Ccode);
        }
    

    }






}








