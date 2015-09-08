#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QVector>

class Model : public QAbstractListModel
{
    Q_OBJECT

    struct ModelItem {
        QString sName;
        int nAge;
        QString sAddr;
        QString sPhone;
        QString sNote;
    };
    enum {name=Qt::UserRole+1, age, addr, phone, note};

public:
    explicit Model(QObject *parent = 0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

signals:

public slots:
    void setItemData2(int index, QVariant value, QString role);

private:
    QVector<ModelItem> v;

private:
    void CreateDefaultModel(void);
};

#endif // MODEL_H
