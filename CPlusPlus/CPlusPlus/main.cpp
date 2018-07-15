#include <iostream>
#include <>





//#include <iostream>
//using namespace std;
//int main(int argc,char **argv)
//{
//    int lenA,lenB;//变量需要初始化，否则有可能出现问题。
//    cout << "Hello world!" << endl;
//    cout << "lenA:" << lenA << " lenB:" << lenB << endl;
//
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
////    //注意新建指针和新建对象的区别！
////    int test = 8;
////    int *ptr_test = &test;
////
////    cout << "test: " << test << endl;
////    cout << "ptr_test: " << ptr_test << endl;
////
////    int *ptr_new = new int(8);
////
////    cout << "*ptr_new: " << *ptr_new << endl;
////    cout << "ptr_new: " << ptr_new << endl;
//
//    int m = 100;
//    int i = 0,j = 0;
//    while(m--)
//    {
//        i++;
//        cout << i << " ";
//    }
//    m = 100;
//    cout << endl;
//    cout << "========================================" << endl;
//    while(--m)
//    {
//        j++;
//        cout << j << " ";
//    }
//
//
//    getchar();
//    return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <utility>
//using namespace std;
//
//int main()
//{
//  string s = "Hi World";
////    string s = "";
//    int len = 0;
//    size_t length = s.length();//为什么用size_t？
//
//    if(!s.empty())
//    {
//        for(size_t i = length - 1; i > 0; i--)
//        {
//            //string是如何存储的?
//            if( s[i] != ' ' )
//                len++;
//            else if( len > 0 )//这里要注意
//                break;
//        }
//    }
//    else if(s.empty())
//        len = 0;
//
//    cout << "Length of last word in s: " << len << endl;
//}

////Mid-term, closed book
////Write your answers directly on question sheets
//
////Problem 1
////Implement the two funcitons:   DB1_to_DB2 and print_DB2
//#include <iostream>
//#include <vector>
//#include <list>
//
//using namespace std;
//
//void DB1_to_DB2(vector<list<int> *> &DB1, list< list< int *> *> &DB2);
//void DB1_print(vector<list<int> *> &DB1);
//
//void DB2_print(list<list<int *> *> &DB2);
//
//int main() {
//
//    vector<list<int> *> DB1 = { new list<int>({ 1,2,3 }), new list<int>({ 4,5 }) , new list<int>({ 8,9,10,11 }) };
//    DB1_print(DB1);
//    list< list<int *> *> DB2;
//    DB1_to_DB2(DB1, DB2);
//    DB2_print(DB2);
//    getchar();
//    getchar();
//    return 0;
//}
//
//void DB1_print(vector<list<int> *> &DB1) {
////    cout << endl;
////    for (size_t i = 0; i < DB1.size(); i++) {
////        auto it1 = DB1[i]->begin();
////        while (it1 != DB1[i]->end()) {
////            cout << *it1 << " ";
////            it1++;
////        }
////        cout << endl;
////    }
//
//    for(size_t i = 0; i < DB1.size(); i++)
//    {
//        auto it = DB1[i]->begin();
//        for(;it != DB1[i]->end(); it++)
//        {
//            cout << *it << " ";
//        }
//        cout << endl;
//    }
//
//}
//
//
//void DB2_print(list<list<int *> *> &DB2) {
////    auto it1 = DB2.begin();
////    while (it1 != DB2.end()) {
////        auto it2 = (*it1)->begin();
////        while (it2 != (*it1)->end()) {
////            cout << **it2 << " ";
////            it2++;
////        }
////        cout << endl;
////        it1++;
////    }
//
//    for(auto it = DB2.begin(); it != DB2.end(); it++)
//    {
//        //list和vector、map不同
//
//        for(auto it2 = (*it)->begin() ; it2 != (*it)->end() ; it2++)
//        {
//            ;
//        }
//    }
//
//}
//
//void DB1_to_DB2(vector<list<int> *> &DB1, list<list<int *> *> &DB2) {
//    for (size_t i = 0; i < DB1.size(); i++) {
//        auto it1 = DB1[i]->begin();
//        list<int *> * Lp = new list<int *>;
//        while (it1 != DB1[i]->end()) {
//            Lp->push_back(new int(*it1));
//            it1++;
//        }
//        DB2.push_back(Lp);
//    }
//}




//#include <iostream>
//#include <vector>
//#include <list>
//#include <map>
//
//using namespace std;
//
//void DB1_print(vector<list<int>> &DB1);
//void DB1_to_DB2(vector<list<int>> &DB1, list<vector<int>> & DB2);
//void DB2_print(list<vector<int>> &DB2);
//void DB1_to_DB3(vector<list<int>> &DB1, list< list<int> *>  &DB3);
//void DB3_print(list < list<int> * > & DB3);
//
//
//int main() {
//
//    vector<list<int>> DB1 = { {1,2,3}, {4, 5}, {6,7,8,9} };
//    DB1_print(DB1);
//    list<vector<int>> DB2;
//    DB1_to_DB2(DB1, DB2);
//    DB2_print(DB2);
//
//    list< list<int> * > DB3;
//
//    getchar();
//    getchar();
//    return 0;
//
//}
//
//void DB1_print( vector<list<int>> &DB1)
//{
////    cout << endl;
////    list<int>::iterator it1;
////
////    for (size_t i = 0; i < DB1.size(); i++) {
////        it1 = DB1[i].begin();
////
////        while (it1 != DB1[i].end()) {
////            cout << *it1 << " ";
////            it1++;
////        }
////        cout << endl;
////    }
//
//    for(size_t i = 0; i < DB1.size();i++)
//    {
//        auto it = DB1[i].begin();
//        for(; it != DB1[i].end() ; it++)
//        {
//            cout << *it << " " ;
//            it++;
//        }
//        cout << endl;
//    }
//
//}
//
//void DB1_to_DB2(vector<list<int>> &DB1, list<vector<int>> & DB2)
//{
//
////    list<int>::iterator it1;
////    for (size_t i = 0; i < DB1.size(); i++)
////    {
////        it1 = DB1[i].begin();
////        vector<int> V1;
////        while (it1 != DB1[i].end()) {
////            V1.push_back(*it1);
////            it1++;
////        }
////        DB2.push_back(V1);
////    }
//
//
//    for( size_t i = 0; i < DB1.size(); i++ )
//    {
//        auto it = DB1[i].begin();
//        vector<int> V1;
//        while( it != DB1[i].end() )
//        {
//            V1.push_back(*it);
//            it++;
//        }
//        DB2.push_back(V1);
//    }
//
//}
//
//void DB2_print(list<vector<int>> &DB2)
//{
//
////    cout << endl;
////    auto it1 = DB2.begin(); //list<vector<int>>::iterator it1 = DB2.begin();
////    while (it1 != DB2.end())
////    {
////        for (size_t i = 0; i < it1->size(); i++) {
////            cout << (*it1)[i] << " ";
////        }
////
////        it1++;
////        cout << endl;
////    }
//
//    auto it = DB2.begin();
//    while( it != DB2.end() )
//    {
//        for(size_t i = 0; i < it->size();i++)
//        {
//            cout << (*it)[i] << " ";
//        }
//        it++;
//        cout << endl;
//    }
//
//}






//#include <iostream>
//#include <map>
//#include <string>
//#include <list>
//#include <vector>
//using namespace std;
//
//class course {
//public:
//    string name;
//    int section;
//    int credits;
//    course() {}
//    course(string n, int s, int c) { name = n; section = s; credits = c; }
//    bool operator<(const course &c) { return (name < c.name); }
//    bool operator==(const course &c) { return (name == c.name); }
//};
//
//void add_student(map<int, map<int, list<course *> * > *> &DB, int id);
//void remove_student(map<int, map<int, list<course *> * > *> &DB, int id);
//void add_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c); //20171 Spring semester of 2017; 20172: Fall semester of 2017
//void drop_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c);
//void print_student_semester_courses(map<int, map<int, list<course *> * > *> &DB, int semester, int id);
//void print_student_all_courses(map<int, map<int, list<course *> * >  *> &DB, int id);
//void print_DB(map<int, map<int, list<course *> * >  *> &DB);
//
//void add_student(map<int, map<int, list<course *> * > * > &DB, int id)
//{
//    auto iterator_per_student = DB.find(id);
//    if( iterator_per_student != DB.end() )
//        return;
//
//    DB[id] = new map<int, list<course *> * >;
//}
//
//void remove_student(map<int, map<int, list<course *> * > *> &DB, int id)
//{
//    auto iterator_per_student = DB.find(id);
//    if( iterator_per_student == DB.end() )
//        return;
//
//    else
//    {
//        for(auto it2 = (*DB[id]).begin(); it2 != (*DB[id]).end() ; it2++ )
//        {
//            for(auto it3 = it2->second->begin() ; it3 != it2->second->end(); it3++)
//            {
//                delete *it3;
//            }
//        }
//
//        delete DB[id];
//        DB.erase(iterator_per_student);
//    }
//}
//
//void add_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c)
//{
//    if( DB[id] == nullptr)
//    {
//        add_student(DB, id);
//    }
//
//    if( (*DB[id])[semester] == nullptr )
//    {
//        //add semester here
//        (*DB[id])[semester] = new list<course *>;
//    }
//
//    //add course
//    (*(*DB[id])[semester]).push_back(new course(c));
//    //注意要复制c,有没有memory leak???
//    //这样没有memory leak!
//}
//
//void drop_course(map<int, map<int, list<course *> * > *> &DB, int semester, int id, course c)
//{
//    if( DB[id] == nullptr || (*DB[id])[semester] == nullptr )
//        return;
//
//    else
//    {
//        //auto iterator_per_student_semester = (*(*DB[id])[semester]).begin();
//        list<course *>::iterator iterator_per_student_semester = (*(*DB[id])[semester]).begin();
//
//        for(;iterator_per_student_semester != (*(*DB[id])[semester]).end(); iterator_per_student_semester++)
//        {
//            if( **iterator_per_student_semester == c )
//            {
//                //drop this course
//                delete *iterator_per_student_semester;
//                (*(*DB[id])[semester]).erase(iterator_per_student_semester);//
//            }
//        }
//    }
//}
//
//void print_student_semester_courses(map<int, map<int, list<course *> * > *> &DB, int semester, int id)
//{
//    if( DB[id] == nullptr || (*DB[id])[semester] == nullptr )
//        return;
//
//    cout << "student ID: " << id << endl;
//    auto it = (*(*DB[id])[semester]).end();
//    for( ; it != (*(*DB[id])[semester]).end() ; it++)
//    {
//        cout << "semester: " << semester << endl;
//        cout << "course: " << (*it)->section << " " << (*it)->name << " " << (*it)->credits << endl;
//    }
//
//}
//
//void print_student_all_courses(map<int, map<int, list<course *> * >  *> &DB, int id)
//{
//    if(DB[id] == nullptr )
//        return;
//
//    cout << "student ID: " << id << endl;
//
//    auto it = (*DB[id]);
//
////    for(  )
////    {
////
////
////        for(  )
////        {
////
////        }
////    }
//
//}
//
//void print_DB(map<int, map<int, list<course *> * >  *> &DB)
//{
//    ;
//}
//
//
//
//int main() {
//
////    cout << "===========Test Hub============" << endl;
////    map<int, map<int,int>* > map_test;
////    if( map_test.find(999) != map_test.end() )
//
////    if( map_test[888] != nullptr )
////      {
////          cout << "找到了" << endl;
////      }
////      else
////          cout << "不存在" << endl;
////
////      getchar();
////      getchar();
////      return 0;
//
//
//    //Original main
//    cout << "Original main" << endl;
//    map<int, map<int, list<course  *> *>   *> DB;
//    add_student(DB, 11111);
//    course C1("CIS554", 1, 3), C2("CSE674", 1, 3), C3("MAT296", 8, 4), C4("WRT205", 5, 3);
//
//    add_course(DB, 20171, 11111, C1);
//    add_course(DB, 20171, 11111, C4);
//    add_course(DB, 20171, 11111, C3);
//    add_course(DB, 20171, 11111, C2);
//    print_student_semester_courses(DB, 20171, 11111);
//
//    drop_course(DB, 20171, 11111, C1);
//    print_student_semester_courses(DB, 20171, 11111);
//
//    add_course(DB, 20172, 11111, C2);
//    add_course(DB, 20172, 11111, C4);
//    add_course(DB, 20172, 11111, C3);
//    add_course(DB, 20172, 11111, C1);
//    print_student_all_courses(DB, 11111);
//
//    add_student(DB, 11112);
//    add_course(DB, 20171, 11112, C2);
//    add_course(DB, 20171, 11112, C4);
//    add_course(DB, 20171, 11112, C3);
//    add_course(DB, 20171, 11112, C1);
//    print_student_semester_courses(DB, 20171, 11112);
//
//    add_course(DB, 20172, 11112, C2);
//    add_course(DB, 20172, 11112, C4);
//    add_course(DB, 20172, 11112, C3);
//    add_course(DB, 20172, 11112, C1);
//    print_student_semester_courses(DB, 20172, 11112);
//
//    print_student_all_courses(DB, 11112);
//
//    print_DB(DB);
//    remove_student(DB, 11111);
//    print_DB(DB);
//    getchar();
//    getchar();
//    return 0;
//
//}
