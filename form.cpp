#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_8_clicked()
{
    ui->textBrowser->setText("If you press this button - you put information from file /home/nadia/\"data.xlsx\" in database.");
}

void Form::on_pushButton_9_clicked()
{
    ui->textBrowser->setText("If you press \"Save data\" - you put information in file /home/nadia/\"data.xlsx\" from database.\n \
If you press \"Exit\" - you leave this program(Don't forget save information!).");
}

void Form::on_pushButton_3_clicked()
{
    ui->textBrowser->setText("If you press one of this buttons - you see info about all/only mens/only women employees.");
}

void Form::on_pushButton_4_clicked()
{
    ui->textBrowser->setText("If you press one of this buttons - you will have sorted info about employees.");
}

void Form::on_pushButton_5_clicked()
{
    ui->textBrowser->setText("If you press one of this buttons - you will have info about employees, whose salary more/less than \"current\".");
}

void Form::on_pushButton_6_clicked()
{
    ui->textBrowser->setText("You can delete employee by using this button - you must enter the name and press.");
}

void Form::on_pushButton_7_clicked()
{
    ui->textBrowser->setText("If you press this button - you will have info about employees whose occupation is \"current\".");
}

void Form::on_pushButton_2_clicked()
{
    ui->textBrowser->setText("You can set info about new employee and push it on database. All employees have different key. The key is issued to the employee after hiring.");
}
