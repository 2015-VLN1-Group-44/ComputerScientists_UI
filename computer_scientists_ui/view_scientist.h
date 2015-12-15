#ifndef VIEW_SCIENTIST_H
#define VIEW_SCIENTIST_H

#include <QDialog>

namespace Ui {
class view_scientist;
}

class view_scientist : public QDialog
{
    Q_OBJECT

public:
    explicit view_scientist(QWidget *parent = 0);
    ~view_scientist();

private:
    Ui::view_scientist *ui;
};

#endif // VIEW_SCIENTIST_H
