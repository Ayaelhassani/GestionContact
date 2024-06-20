#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H
#include "basedonne1.h"
#include <QWidget>
#include "contact.h"
namespace Ui {
class ajoutcontact;
}

class ajoutcontact : public QWidget
{
    QString path;
    Q_OBJECT
private:
    basedonne1 *bd;
public:
    explicit ajoutcontact(QWidget *parent = nullptr);
    ~ajoutcontact();
signals:
    void contactEnregistre(contact *);
    void majListe();
private slots:
    void on_annulerB_clicked();

    void on_enregistrerB_clicked();

    void on_photoB_clicked();

private:
    Ui::ajoutcontact *ui;
};

#endif // AJOUTCONTACT_H
