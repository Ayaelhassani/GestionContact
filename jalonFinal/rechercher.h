#ifndef RECHERCHER_H
#define RECHERCHER_H

#include "contact.h"
#include <QWidget>

namespace Ui {
class rechercher;
}

class rechercher : public QWidget
{
    Q_OBJECT

public:
    explicit rechercher(QWidget *parent = nullptr);
    ~rechercher();
public slots:
    void receptionC(contact *c);
    void recMessage(QString m);
    void recLC(list<contact *> lcs);

private slots:


    void on_checkBoxNE_clicked();

    void on_RB_clicked();
    void on_checkBoxD_clicked();

    void on_RB1_clicked();

signals:

    void envN(QString);
    void envE(QString);
    void envD(QString);


private:
    Ui::rechercher *ui;
};

#endif // RECHERCHER_H
