#include "mainwindow.h"
#include "ui_mainwindow.h"

double num1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui-> pushButton_0, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_1, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_2, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_3, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_4, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_5, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_6, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_7, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_8, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_9, SIGNAL (clicked()), this, SLOT (numbers()));
    connect(ui-> pushButton_plusminus, SIGNAL (clicked()), this, SLOT (pm()));
    connect(ui-> pushButton_plus, SIGNAL (clicked()), this, SLOT (operations()));
    connect(ui-> pushButton_minus, SIGNAL (clicked()), this, SLOT (operations()));
    connect(ui-> pushButton_slesh, SIGNAL (clicked()), this, SLOT (operations()));
    connect(ui-> pushButton_umnojenie, SIGNAL (clicked()), this, SLOT (operations()));

ui->pushButton_plus->setCheckable(true);
ui->pushButton_minus->setCheckable(true);
ui->pushButton_slesh->setCheckable(true);
ui->pushButton_umnojenie->setCheckable(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers()
{
    QPushButton *button = (QPushButton *) sender();
    double allnum;
    QString newlabel;
    allnum=(ui->label->text()+button->text()).toDouble();
    newlabel=QString::number(allnum);

          ui ->label->setText(newlabel);
}

void MainWindow::on_pushButton_dot_clicked()
{
      ui ->label->setText(ui ->label->text()+'.');
}
void MainWindow::pm()
{
    QPushButton *button = (QPushButton *) sender();
    double allnum;
    QString newlabel;

    if (button->text()=="+/-")
    {
    allnum=(ui->label->text()).toDouble();
    allnum=allnum * -1;
    newlabel=QString::number(allnum);

          ui ->label->setText(newlabel);
    }
}

void MainWindow::operations()
{
     QPushButton *button = (QPushButton *) sender();
    num1=ui->label->text().toDouble();
    ui ->label->setText(" ");
    button->setChecked(true);
}


void MainWindow::on_pushButton_ac_clicked()
{
ui ->pushButton_plus->setChecked(false);
ui ->pushButton_minus->setChecked(false);
ui ->pushButton_slesh->setChecked(false);
ui ->pushButton_umnojenie->setChecked(false);

ui->label->setText("0");
}

void MainWindow::on_pushButton_ravno_clicked()
{
    double sum, num2;
    QString newlabel;

    num2=ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {

       sum = num1 + num2;
       newlabel = QString::number(sum);

        ui ->label->setText(newlabel);
         ui ->pushButton_plus->setChecked(false);



    } else if(ui->pushButton_minus->isChecked()) {
        sum = num1 - num2;
        newlabel = QString::number(sum);

         ui ->label->setText(newlabel);
          ui ->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_slesh->isChecked()) {
        sum = num1 / num2;
        newlabel = QString::number(sum);

         ui ->label->setText(newlabel);
          ui ->pushButton_slesh->setChecked(false);
    } else if(ui->pushButton_umnojenie->isChecked()) {
        sum = num1 * num2;
        newlabel = QString::number(sum);

         ui ->label->setText(newlabel);
          ui ->pushButton_umnojenie->setChecked(false);
    }
}
