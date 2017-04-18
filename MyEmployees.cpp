//
// Created by nadia on 26.11.16.
//

#include "MyEmployees.h"
#include <algorithm>


bool operator<(MyEmployee& info1, MyEmployee& info2)
{
  return info1.age < info2.age;
}

void MyEmployees::sortByName()
{
  for(size_t i=0;i<my_employees.size()-1;i++)
  {
    for(size_t j=0;j<my_employees.size()-i-1;j++)
    {
      if(my_employees[j].name>my_employees[j+1].name)
      {
        std::swap(my_employees[j],my_employees[j+1]);
      }
    }
  }
}

void MyEmployees::sortByAge()
{
  std::sort(my_employees.begin(),my_employees.end());
}

void MyEmployees::saveNewEmployee(MyEmployee &new_emp)
{
  my_employees.push_back(new_emp);

}

void MyEmployees::WriteAllMen()
{
  result.clear();
  for(size_t i=0;i<my_employees.size();++i)
  {
    if(my_employees[i].gender =="M")
    {
      result.push_back(my_employees[i]);
    }
  }

}

void MyEmployees::WriteAllWoman()
{
    result.clear();
    for(size_t i=0;i<my_employees.size();i++)
    {
      if(my_employees[i].gender =="W")
      {
        result.push_back(my_employees[i]);
      }
    }
}

void MyEmployees::WriteAll()
{
    result.clear();
    for(size_t i=0;i<my_employees.size();i++)
    {
        result.push_back(my_employees[i]);
    }
}

void MyEmployees::findPost(QString &post)
{
  result.clear();
   for(size_t i=0;i<my_employees.size();i++)
   {
      std::string p=post.toStdString();
      if(my_employees[i].post==p)
      {
        result.push_back(my_employees[i]);
      }
   }
}

void MyEmployees::salaryMore(unsigned int& than)
{
  result.clear();
  for(size_t i=0;i<my_employees.size();i++)
  {
    if(my_employees[i].salary>than)
    {
      result.push_back(my_employees[i]);
    }
  }
}

void MyEmployees::salaryLess(unsigned int &than)
{
    result.clear();
    for(size_t i=0;i<my_employees.size();i++)
    {
      if(my_employees[i].salary<than)
      {
        result.push_back(my_employees[i]);
      }
    }

}

bool MyEmployees::deleteEmployee(std::string &name)
{
  std::string post_deleted="";
  bool find=false,del= false;
  for(size_t i=0;i<my_employees.size();i++)
  {
    if(my_employees[i].name==name)
    {
      post_deleted=my_employees[i].post;
      my_employees.erase(my_employees.begin()+i);
      del=true;
      break;
    }
  }
  if(!del)
  {
      return false;
  }
  else
  {
   for(size_t i=0;i<my_employees.size();i++)
   {
       if(my_employees[i].post==post_deleted)
       {
            find=true;
       }
   }

  if(!find)
  {
    posts.erase(post_deleted);
  }
  return true;
  }
}

