#ifndef AJOUTTACHE_H
#define AJOUTTACHE_H

#include "interaction.h"
#include "tache.h"
#include <QWidget>

namespace Ui {
class ajouttache;
}

class ajouttache : public QWidget
{
    Q_OBJECT

public:
    explicit ajouttache(QWidget *parent = nullptr);
    ~ajouttache();

private slots:
signals:


private:
    Ui::ajouttache *ui;
    Tache *T;
    Interaction *I;
};

#endif // AJOUTTACHE_H
