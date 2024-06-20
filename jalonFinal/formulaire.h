#ifndef FORMULAIRE_H
#define FORMULAIRE_H
#include "QString"
#include <QWidget>
#include "basedonne1.h"
#include "contact.h"
#include "modif.h"
namespace Ui {
class formulaire;
}

class formulaire : public QWidget
{
    Q_OBJECT
private:
    contact *nc;
    modif *m;

public:
    explicit formulaire(QWidget *parent = nullptr);
    ~formulaire();
public slots:
    void receiveContact(contact *c);
    void receiveE(QString);
    void receiveEM(QString);
    void receiveT(QString);
    void rsup();

signals:
    void envoyerE(QString);
    void envoyerEM(QString);
    void envoyerT(QString);

    void envoyerS();





    void envoyerModifC(contact *c);








private slots:
    void on_modifierB_clicked();



    void on_quitterB_clicked();

private:
    Ui::formulaire *ui;
};

#endif // FORMULAIRE_H
