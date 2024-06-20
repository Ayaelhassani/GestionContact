#ifndef AFF_H
#define AFF_H

#include <QWidget>
#include "ajouinteraction.h"
#include "basedonne1.h"
namespace Ui {
class aff;
}

class aff : public QWidget
{
    Q_OBJECT
private:
    ajouinteraction *ai;
    ajouttache *at;
    basedonne1 *bd;
    QMainWindow *mw;
public:
    explicit aff(QWidget *parent = nullptr);
    ~aff();
    void recevoirIdContact(QString idContact);


private slots:

    void on_nouvTacheB_clicked();

    void on_BQuitter_clicked();

    //void on_pushButton_clicked();
    void on_pushButton_clicked();
    void affLI(list<Interaction *> li, contact *c);
    void recMessageLI(QString m, contact *c);
    void recLIDA(map<Interaction *, list<Tache *>> it, contact *c);
    void recMessageLIDA(QString, contact *);

signals:
    void envoyer(const QString &dateDu, const QString &dateAu, const QString &id);
    void afficherButton();

    void messageLI(QString, contact *);
    void envoyerTache(Tache *);


private:
    Ui::aff *ui;
};

#endif // AFF_H
