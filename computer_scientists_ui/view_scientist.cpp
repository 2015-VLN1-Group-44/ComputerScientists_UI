#include "view_scientist.h"
#include "ui_view_scientist.h"
#include "constants.h"

view_scientist::view_scientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_scientist)
{
    ui->setupUi(this);
}

view_scientist::~view_scientist()
{
    delete ui;
}
