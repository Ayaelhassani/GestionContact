#ifndef MODIF_H
#define MODIF_H

#include <QWidget>
#include "contact.h"
namespace Ui {
class modif;
}

class modif : public QWidget
{
    Q_OBJECT

public:
    explicit modif(QWidget *parent = nullptr);
    ~modif();
public slots:
    void getContact(contact *c);
signals:
    void sendEntreprise(QString);
    void sendEmail(QString);
    void sendTelephone(QString);
    void supp();

private slots:
    void on_EnregistrerButton_2_clicked();

    void on_SupprimerButton_clicked();

    void on_AnnulerButton_2_clicked();

private:
    Ui::modif *ui;
};

#endif // MODIF_H
