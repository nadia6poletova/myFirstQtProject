//
// Created by nadia on 26.11.16.
//

#ifndef KURS_MYEMPLOYEES_H
#define KURS_MYEMPLOYEES_H

#include <QSetIterator>
#include <QList>
#include <QString>
#include <QStringList>
#include <QSet>
#include <string>
#include <iostream>
#include <ostream>
#include <deque>
#include <set>

namespace Ui {
class MyEmployees;
}

struct MyEmployee
{
    std::string name;
    std::string gender;
    unsigned int age;
    std::string post;
    unsigned int salary;
    MyEmployee(const std::string& name,const std::string& gender,
               const unsigned int& age,const std::string& post,const unsigned long int& salary): name(name),
        gender(gender),age(age),post(post),salary(salary)
    {}


};

class MyEmployees
{

public:            
  void sortByName();
  void sortByAge();
  void saveNewEmployee(MyEmployee& new_emp);
  void WriteAllMen();
  void WriteAllWoman();
  void WriteAll();
  void findPost(QString &post);
  void salaryMore(unsigned int &than);
  void salaryLess(unsigned int& than);
  bool deleteEmployee(std::string &name);
  std::deque<MyEmployee> result;
  std::deque<MyEmployee> my_employees;
  std::set<std::string> posts;
};


#endif //KURS_MYEMPLOYEES_H
