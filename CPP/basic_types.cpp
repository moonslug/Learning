#include <iostream>
#include <vector>
#include <fstream>

// basic class
class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int m_id            = 0;
    float m_avg         = 0;

public:

    // constructors
    Student() {}
    Student(std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
    {
    }

    // getters
    int getAvg() const
    {
        return m_avg;
    }

    int getID() const
    {
        return m_id;
    }

    std::string getFirst() const
   {
        return m_first;
    }

    std::string getLast() const
    {
        return m_last;
    }

    // public func
    void print() const  // s3 below is a const instance
    {
        std::cout << m_first << " " << m_last << " ";
        std::cout << m_id << " " << m_avg << "\n";
    }
};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_student;

public:

    Course() {}
    // use reference not value bc otherwise c++ will copy the whole string 
    Course(const std::string &name)
        : m_name(name)
        {
        }

        void addStudent(const Student &s)
        {
            m_student.push_back(s);
        }

        // const: begining of a function - not changing what we returning
        // const: end of a function - this function will not change the class
        // const: begining of a variable
        const std::vector<Student> getStudents() const
        {
            return m_student;
        }

        void loadFromFile(const std::string &filename)
        {
            std::ifstream fin(filename);
            std::string first, last;
            int id;
            float avg;

            while (fin >> first)
            {
                fin >> last >> id >> avg;

                addStudent(Student(first, last, id, avg));
            }

        }

        void print() const
        {
            for (const auto &s : m_student)
            {
                s.print();
            }
        }
};

int main(int argc, char *argv[])
{
    // basic int and string ops
    int age = 38;
    std::string first = "Moon";
    std::string last = "Slug";
    std::string name = first + " " + last;

    std::cout << name << std::endl;

    // basic vector ops
    std::vector<float> vec;
    vec.push_back(42.2f);
    vec.push_back(10.1f);
    vec.push_back(20.3f);
    
    // basic loops
    for (size_t i=0; i<vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }

    for (auto a : vec)
    {
        std::cout << a << "\n";
    }
    
    // class instances
    Student s1;
    Student s2("Dave", "Churchill", 1, 3.14);
    // s3 forcing print() to be a const func
    const Student s3("Moon", "Slug", 202200001, 0.01);

    s3.print();
    s3.getLast();
    /* const correctness: methods must be const funcs if any
    instances are created as const*/
    
    // create a course
    Course comp4300("COMP 4300");
    comp4300.addStudent(s1);
    comp4300.addStudent(s2);
    comp4300.addStudent(s3);
    comp4300.addStudent(Student("Bill", "Bob", 31423, 30));

    comp4300.print();

    // now create a course by loading all students from a file
    Course c("COMP 4300");
    c.loadFromFile("students.txt");
    c.print();

    return 0;
}