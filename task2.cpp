
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <thread>
using namespace std;

// Week 11: Template Function
template <class T>
void printHeading(T heading) {
    cout << "\n" << heading << "\n";
}

// Week 7 and 8: Abstract Base Class
class Student {
protected:
    int rollNo;
    string name;

public:
    Student(int r, string n) {
        rollNo = r;
        name = n;
    }

    // Getter functions
    int getRollNo() const {
        return rollNo;
    }

    string getName() const {
        return name;
    }

    // Pure virtual functions
    virtual void display() const = 0;
    virtual float getMarks() const = 0;

    virtual ~Student() {}
};

// Week 7: Inheritance
// Week 8: Function Overriding
class Result : public Student {
private:
    float marks;

public:
    Result(int r, string n, float m) : Student(r, n) {
        if (m < 0 || m > 100) {
            throw invalid_argument("Invalid marks!");
        }

        marks = m;
    }

    float getMarks() const override {
        return marks;
    }

    void display() const override {
        cout << "\nRoll Number: " << getRollNo();
        cout << "\nName: " << getName();
        cout << "\nMarks: " << marks;

        if (marks >= 90)
            cout << "\nGrade: A";
        else if (marks >= 75)
            cout << "\nGrade: B";
        else if (marks >= 50)
            cout << "\nGrade: C";
        else
            cout << "\nGrade: F";

        cout << "\n----------------------\n";
    }
};

// Week 13: Singleton Class
// Week 10: File Handling
class FileManager {
private:
    FileManager() {}

public:
    static FileManager& getInstance() {
        static FileManager obj;
        return obj;
    }

    // Save records to file
    void saveToFile(const vector<unique_ptr<Student>>& students) {
        ofstream file("results.txt");

        if (!file) {
            cout << "File could not be opened!\n";
            return;
        }

        for (const auto& s : students) {
            file << s->getRollNo() << " "
                 << s->getName() << " "
                 << s->getMarks() << endl;
        }

        file.close();
        cout << "\nRecords saved successfully!\n";
    }

    // Read records from file
    void readFromFile() {
        ifstream file("results.txt");
        string line;

        if (!file) {
            cout << "File could not be opened!\n";
            return;
        }

        printHeading("RECORDS FROM FILE");

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

// Week 13: Multithreading
void calculateAverage(const vector<unique_ptr<Student>>& students) {
    if (students.empty()) {
        cout << "\nNo records available for average.\n";
        return;
    }

    float total = 0;

    for (const auto& s : students) {
        total += s->getMarks();
    }

    cout << "\nAverage Marks: "
         << total / students.size() << endl;
}

int main() {

    // Week 11: STL Vector
    // Week 13: Smart Pointers
    vector<unique_ptr<Student>> students;

    int n;

    printHeading("STUDENT RESULT MANAGEMENT SYSTEM");

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int roll;
        string name;
        float marks;

        cout << "\nEnter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        // Week 9: Exception Handling
        try {
            students.push_back(
                make_unique<Result>(roll, name, marks)
            );
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            cout << "Record not added.\n";
        }
    }

    // Display student results
    printHeading("STUDENT RESULTS");

    for (const auto& s : students) {
        s->display();
    }

    // Week 12: STL Algorithm and Lambda Expression
    sort(students.begin(), students.end(),
         [](const unique_ptr<Student>& a,
            const unique_ptr<Student>& b) {
             return a->getMarks() > b->getMarks();
         });

    printHeading("RESULTS SORTED BY MARKS");

    for (const auto& s : students) {
        s->display();
    }

    // Week 12: Filtering using count_if and Lambda
    int passed = count_if(
        students.begin(), students.end(),
        [](const unique_ptr<Student>& s) {
            return s->getMarks() >= 50;
        }
    );

    cout << "\nNumber of students passed: "
         << passed << endl;

    // File Handling using Singleton
    FileManager::getInstance().saveToFile(students);
    FileManager::getInstance().readFromFile();

    // Multithreading
    printHeading("CALCULATING AVERAGE");

    thread t(calculateAverage, cref(students));
    t.join();

    return 0;
}
