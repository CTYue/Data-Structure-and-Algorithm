/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-02-21 00:43:31
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-17 00:01:19
 * @Description: 
 *   - Practice on C++ STL Containers.
 *   - Implemented Course Management.
 */

#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class course {
public:
    string name;
    int section;
    int credits;
    course() {}
    course(string n, int s, int c) { name = n; section = s; credits = c; }
    bool operator<(const course &c) { return (name < c.name); }
    bool operator==(const course &c) { return (name == c.name); }
};

void add_student(map<int, map<int, list<course *> * > *> &DB, int id);
void remove_student(map<int, map<int, list<course *> * > *> &DB, int id);
//20171 means Spring semester of 2017; 20172 means Fall semester of 2017
void add_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c); 

void drop_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c);
void print_student_semester_courses(map<int, map<int, list<course *> * > *> &DB, int semester, int id);
void print_student_all_courses(map<int, map<int, list<course *> * >  *> &DB, int id);
void print_DB(map<int, map<int, list<course *> * >  *> &DB);


int main() {
    map<int, map<int, list<course  *> *>   *> DB;
    add_student(DB, 11111);
    course C1("CIS554", 1, 3), C2("CSE674", 1, 3), C3("MAT296", 8, 4), C4("WRT205", 5, 3);
    
    add_course(DB, 20171, 11111, C1);
    add_course(DB, 20171, 11111, C4);
    add_course(DB, 20171, 11111, C3);
    add_course(DB, 20171, 11111, C2);
    print_student_semester_courses(DB, 20171, 11111);
    
    drop_course(DB, 20171, 11111, C1);
    print_student_semester_courses(DB, 20171, 11111);
    
    add_course(DB, 20172, 11111, C2);
    add_course(DB, 20172, 11111, C4);
    add_course(DB, 20172, 11111, C3);
    add_course(DB, 20172, 11111, C1);
    print_student_all_courses(DB, 11111);
    
    add_student(DB, 11112);
    add_course(DB, 20171, 11112, C2);
    add_course(DB, 20171, 11112, C4);
    add_course(DB, 20171, 11112, C3);
    add_course(DB, 20171, 11112, C1);
    print_student_semester_courses(DB, 20171, 11112);
    
    add_course(DB, 20172, 11112, C2);
    add_course(DB, 20172, 11112, C4);
    add_course(DB, 20172, 11112, C3);
    add_course(DB, 20172, 11112, C1);
    print_student_semester_courses(DB, 20172, 11112);
    
    print_student_all_courses(DB, 11112);
    
    print_DB(DB);
    remove_student(DB, 11111);
    print_DB(DB);
    getchar();
    getchar();
    return 0;
}

void add_student(map<int, map<int, list<course *> * > *> &DB, int id)
{
    auto iterator_per_student = DB.find(id);
    
    if( iterator_per_student != DB.end() )
        return;
    
    DB[id] = new map<int,list<course *> *>;
}


void remove_student(map<int, map<int, list<course *> * > *> &DB, int id)
{
    auto iterator_per_student = DB.find(id);
    
    if( iterator_per_student == DB.end() )
        return;
    
    
    for( auto sem_course_pair: (*(iterator_per_student->second)) )
    {
        auto course_list = *(sem_course_pair.second);
        
        for(auto course: course_list)
            delete course;
        
        delete sem_course_pair.second;
    }
    delete iterator_per_student->second;
    DB.erase(iterator_per_student);
    
//    auto per_student_iterator = DB.find(id);
//    if (per_student_iterator == DB.end())
//        return;
//    for (auto &sem_course_list_pair : (*(per_student_iterator->second))) {
//        auto &cl = sem_course_list_pair.second;
//        for (course* cc : *cl)
//        {
//            delete cc;//delete the course
//        }
//        delete sem_course_list_pair.second;
//    }
//    delete per_student_iterator->second;
//    DB.erase(per_student_iterator);
    
}


void add_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c) {
    //    course* copy = new course(c.name, c.section, c.credits);
    add_student(DB, id);
    auto per_student_iterator = DB.find(id);
    auto &sem_cl_map = *per_student_iterator->second;
    auto per_semester_iterator = sem_cl_map.find(semester);
    if (per_semester_iterator == sem_cl_map.end()) {
        sem_cl_map[semester] = new list<course *>;
    }
    per_semester_iterator = sem_cl_map.find(semester);
    auto &cl = per_semester_iterator->second;
    for (course* &cc : *cl) {
        if (*cc == c)  //course exists
            return;
    }
    cl->push_back(new course(c));//没有memory leak, why?
}

void drop_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c) {
    auto per_student_iterator = DB.find(id);
    if (per_student_iterator == DB.end())
        return; //no such student
    auto &sem_cl_map = *per_student_iterator->second;
    auto per_semester_iterator = sem_cl_map.find(semester);
    if (per_semester_iterator == sem_cl_map.end()) {
        return; //no such semester
    }
    auto &cl = *per_semester_iterator->second;
    auto t = cl.begin();
    while (t != cl.end()) {
        course* cc = *t;
        if (*cc == c) {
            delete cc;
            cl.erase(t++);
        }
        else
            ++t;
    }
}

void print_student_semester_courses(map<int, map<int, list<course *> * > *> &DB, int semester, int id) {
    auto per_student_iterator = DB.find(id);
    
    if (per_student_iterator == DB.end()) {
        cout << "no such student" << endl;
        return;
    }
    auto &sem_cl_map = *per_student_iterator->second;
    auto per_semester_iterator = sem_cl_map.find(semester);
    if (per_semester_iterator == sem_cl_map.end())
    {
        cout << "no such semester" << endl;
        return;
    }
    
    cout << "student id = " << (*per_student_iterator).first << endl;
    cout << "semester = " << per_semester_iterator->first << endl;
    auto &cl = *per_semester_iterator->second;
    for (course* cc : cl)
    {
        cout << cc->name << " " << cc->section << " " << cc->credits << "  ";
    }
    cout << endl << endl;
}

void print_student_all_courses(map<int, map<int, list<course *> * > *> &DB, int id) {
    auto per_student_iterator = DB.find(id);
    if (per_student_iterator == DB.end())
        return; //no such student
    auto &sem_cl_map = *per_student_iterator->second;//semester
    cout << "student id = " << id << endl;
    for (auto &per_semester_iterator : sem_cl_map) {
        //print_student_semester_courses(DB, per_semester_iterator.first, id);
        cout << "semester = " << per_semester_iterator.first << endl;
        auto &cl = *per_semester_iterator.second;
        
        for (course* cc : cl)
        {
            cout << cc->name << " " << cc->section << " " << cc->credits << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_DB(map<int, map<int, list<course *> * >  *> &DB) {
    for (auto &per_student_iterator : DB) {
        print_student_all_courses(DB, per_student_iterator.first);
    }
    cout << endl;
}

