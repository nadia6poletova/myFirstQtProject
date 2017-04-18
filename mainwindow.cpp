#include "MyEmployees.h"
#include "mainwindow.h"
#include <ui_mainwindow.h>
#include <QtXlsx/QtXlsx>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string name,post;
    unsigned int age;
    std::string gender;
    unsigned int salary;

    ui->textBrowser->setText("");

    QString S1=ui->lineEdit->text();
    name=S1.toStdString();

    for(size_t i=0;i<database1.my_employees.size();++i)
    {
        if(database1.my_employees[i].name==name)
        {
            ui->textBrowser->setText("Sorry, employee with the same name already exists.");
            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            return;
        }
    }

    QString S2=ui->lineEdit_2->text();
    post=S2.toStdString();

    QString S3=ui->comboBox->currentText();
    gender=S3.toStdString();

    age=ui->spinBox->value();

    salary=ui->spinBox_2->value();

    if(S1=="" || S2=="")
    {
        ui->textBrowser->setText("Please fill in all fields.");
        return;
    }

    MyEmployee emp(name,gender,age,post,salary);
    database1.saveNewEmployee(emp);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    database1.posts.insert(post);
    ui->comboBox_3->clear();
    for(std::set<std::string>::iterator i=database1.posts.begin();i!=database1.posts.end();++i)
    {
        QString Z=QString::fromStdString(*i);
        ui->comboBox_3->addItem(Z);
    }
}

void MainWindow::addAll(const std::deque<MyEmployee>& out)
{
    ui->textBrowser->setText("");
    ui->tableView->clearMask();
    QStandardItemModel *model = new QStandardItemModel;
       QStandardItem *item;

       //Заголовки столбцов
       QStringList horizontalHeader;
       horizontalHeader.append("Key                       ");
       horizontalHeader.append("Gender");
       horizontalHeader.append("Age  ");
       horizontalHeader.append("Occupation                   ");
       horizontalHeader.append("Salary    ");

       //Заголовки строк
       QStringList verticalHeader;
       for(size_t i=1;i<=out.size();++i)
       {

           verticalHeader.append(QString::number(i));
       }


       model->setHorizontalHeaderLabels(horizontalHeader);
       model->setVerticalHeaderLabels(verticalHeader);

       for(size_t i=0;i<out.size();++i)
       {
       //Первый ряд
           QString Z;
       item = new QStandardItem(Z.fromStdString(out[i].name));
       model->setItem(i, 0, item);

       item = new QStandardItem(Z.fromStdString(out[i].gender));
       model->setItem(i, 1, item);

       item = new QStandardItem(Z.number(out[i].age));
       model->setItem(i, 2, item);

       item = new QStandardItem(Z.fromStdString(out[i].post));
       model->setItem(i, 3, item);

       item = new QStandardItem(Z.number(out[i].salary));
       model->setItem(i, 4, item);
       }

       ui->tableView->setModel(model);
       ui->tableView->resizeRowsToContents();
       ui->tableView->resizeColumnsToContents();

}



void MainWindow::on_pushButton_5_clicked()
{
   ui->textBrowser->setText("");
   if(database1.my_employees.size()==0)
   {
     ui->textBrowser->setText("Database is empty.");
   }
   else
   {
     addAll(database1.my_employees);
   }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textBrowser->setText("");
    database1.WriteAllMen();
    if(database1.result.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        if(database1.my_employees.size()==0)
        {
          ui->textBrowser->setText("Database is empty.");
        }
        else
        {
          ui->textBrowser->setText("All the company's employees are women.");
        }
        return;
    }
    addAll(database1.result);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->textBrowser->setText("");
    database1.WriteAllWoman();
    if(database1.result.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        if(database1.my_employees.size()==0)
        {
          ui->textBrowser->setText("Database is empty.");
        }
        else
        {
        ui->textBrowser->setText("All the company's employees are men.");
        }
        return;
    }
    addAll(database1.result);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->textBrowser->setText("");
    unsigned int i=ui->spinBox_3->value();
    database1.salaryMore(i);
    if(database1.result.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        if(database1.my_employees.size()==0)
        {
          ui->textBrowser->setText("Database is empty.");
        }
        else
        {
          ui->textBrowser->setText("All employees earn less than you enter.");
        }
        return;
    }
    addAll(database1.result);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->textBrowser->setText("");
    unsigned int i=ui->spinBox_4->value();
    database1.salaryLess(i);
    if(database1.result.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        if(database1.my_employees.size()==0)
        {
          ui->textBrowser->setText("Database is empty.");
        }
        else
        {
          ui->textBrowser->setText("All employees earn more than you enter.");
        }
        return;
    }
    addAll(database1.result);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->textBrowser->setText("");
    if(database1.my_employees.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        ui->textBrowser->setText("Database is empty.");
        return;
    }
    database1.sortByName();
    addAll(database1.my_employees);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->textBrowser->setText("");
    if(database1.my_employees.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        ui->textBrowser->setText("Database is empty.");
        return;
    }
    database1.sortByAge();
    addAll(database1.my_employees);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textBrowser->setText("");
    if(database1.my_employees.size()==0)
    {
      ui->textBrowser->setText("Database is empty.");
      return;
    }
    QString S1=ui->lineEdit_3->text();
    if(S1=="")
    {
        ui->textBrowser->setText("Please, enter the name.");
        return;
    }
    ui->lineEdit_3->setText("");
    std::string S11=S1.toStdString();
    bool d=database1.deleteEmployee(S11);
    if(!d)
    {
        ui->textBrowser->setText("Sorry, employee with the same name does not exist.");
    }
    ui->comboBox_3->clear();
    for(std::set<std::string>::iterator i=database1.posts.begin();i!=database1.posts.end();++i)
    {
       QString Z=QString::fromStdString(*i);
       ui->comboBox_3->addItem(Z);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->textBrowser->setText("");
    QString S1=ui->comboBox_3->currentText();
    database1.findPost(S1);
    if(database1.posts.size()==0)
    {
        ui->tableView->setModel(0);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        ui->textBrowser->setText("Database is empty.");
        return;
    }
    addAll(database1.result);
}

void MainWindow::on_pushButton_14_clicked()
{
    Form *z= new Form();
    z->setWindowTitle("Info");
    z->show();

    return;
}

void MainWindow::on_pushButton_3_clicked()
{
    QXlsx::Document xlsx("/home/nadia/data.xlsx");

    for(int i=1;i<6;i++)
    {
        QVariant a=xlsx.read(1,i);

         if((i==1 && a!="Key") || (i==2 && a!="Gender") || (i==3 && a!="Age") || (i==4 && a!="Occupation") || (i==5 && a!="Salary"))
         {
             ui->textBrowser->setText("Sorry, file is incorrect or empty.Exit on A"+QString::number(i));
         }
    }


    int j=2;
    QVariant a;
    bool k=true;

    while(k)
    {
       a=xlsx.read(j,1);
       QString z1=a.toString();
       if(z1=="")
       {
           ui->textBrowser->setText("str emp"+QString::number(j));
           k=false;
           break;
       }
       std::string name =z1.toStdString();

       a=xlsx.read(j,2);
       if(a!="M" && a!="W")
       {
           ui->textBrowser->setText("Sorry, file is incorrect gen"+QString::number(j));
           return;
       }
       z1=a.toString();
       std::string gender =z1.toStdString();

       a=xlsx.read(j,3);
       z1=a.toString();
       std::string age1=z1.toStdString();
       unsigned int age;
       if(age1.size()!=2)
       {
           ui->textBrowser->setText("Sorry, file is incorrect age");
           return;
       }
       if((age1[0]>'0' && age1[0]<'6' && age1[1]>='0' && age1[1]<='9') || (age1[0]=='6' && age1[1]=='0'))
       {
          age=z1.toUInt();
       }
       else
       {
           ui->textBrowser->setText("Sorry, file is incorrect age1");
           return;
       }

       a=xlsx.read(j,4);
       z1=a.toString();
       std::string post =z1.toStdString();

       a=xlsx.read(j,5);
       z1=a.toString();
       std::string salary1=z1.toStdString();
       unsigned int salary;
       if(salary1.size()>6 && salary1.size()<5)
       {
           ui->textBrowser->setText("Sorry, file is incorrect sal");
           return;
       }

       for (size_t i = 0; i < salary1.size(); i++)
       {
         if (salary1[i] <= '0' && salary1[i] >= '9')
          {
             ui->textBrowser->setText("Sorry, file is incorrect sal1");
             return;
          }
        }
       salary=z1.toUInt();

       bool ex=true;
       for(size_t i=0;i<database1.my_employees.size();++i)
       {
           if(database1.my_employees[i].name==name)
           {
               ex=false;
                ui->textBrowser->setText("Sorry, employee with key: \""+QString::fromStdString(name)+"\" is already exist");
               break;
           }
       }
       if(ex)
       {
         database1.posts.insert(post);
         MyEmployee emp(name,gender,age,post,salary);
         database1.my_employees.push_back(emp);
         ui->comboBox_3->clear();
         for(std::set<std::string>::iterator i=database1.posts.begin();i!=database1.posts.end();++i)
         {
             QString Z=QString::fromStdString(*i);
             ui->comboBox_3->addItem(Z);
         }
       }
       j++;
    }
   ui->textBrowser->setText("The end of reading the last saved database.");
}

void MainWindow::on_pushButton_4_clicked()
{
    QXlsx::Document xlsx;
    int row=database1.my_employees.size();

    xlsx.write(1,1,"Key");
    xlsx.write(1,2,"Gender");
    xlsx.write(1,3,"Age");
    xlsx.write(1,4,"Occupation");
    xlsx.write(1,5,"Salary");

    for(int i=2;i<=row+1;i++)
    {

        QString n=QString::fromStdString(database1.my_employees[i-2].name);
        QVariant zpn(n);
        xlsx.write(i,1,zpn);


        QString g=QString::fromStdString(database1.my_employees[i-2].gender);
        QVariant zpg(g);
        xlsx.write(i,2,zpg);


        QVariant zpa(database1.my_employees[i-2].age);
        xlsx.write(i,3,zpa);


        QString p=QString::fromStdString(database1.my_employees[i-2].post);
        QVariant zpp(p);
        xlsx.write(i,4,zpp);

        QVariant zps(database1.my_employees[i-2].salary);
        xlsx.write(i,5,zps);

    }
    xlsx.saveAs("/home/nadia/data.xlsx");
}
