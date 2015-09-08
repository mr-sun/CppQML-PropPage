#include "model.h"

Model::Model(QObject *parent) :
    QAbstractListModel(parent)
{
    CreateDefaultModel();
}

void Model::CreateDefaultModel(void)
{
    ModelItem itm;
    itm.sName = "Vitaly";
    itm.nAge = 34;
    itm.sAddr = "Poligraphskaya st. 4";
    itm.sPhone = "+7-909-678-67-89";
    v.push_back(itm);

    itm.sName = "Irina";
    itm.nAge = 33;
    itm.sAddr = "Poligraphskaya st. 4";
    itm.sPhone = "+7-909-123-45-67";
    v.push_back(itm);

    itm.sName = "Olga";
    itm.nAge = 55;
    itm.sAddr = "Poligraphskaya st. 4";
    itm.sPhone = "+7-909-333-55-66";
    v.push_back(itm);

    itm.sName = "Deni";
    itm.nAge = 34;
    itm.sAddr = "";
    itm.sPhone = "+7-909-333-77-88";
    v.push_back(itm);

    for (int a=0; a < 100; ++a) {
        itm.sName = "Name "+QString::number(a);
        itm.nAge = a+5;
        itm.sAddr = "";
        itm.sPhone = "";
        itm.sNote = "";
        v.push_back(itm);
    }
}

int Model::rowCount(const QModelIndex &parent) const
{
    return v.size();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    int i = index.row();
    if (i < 0 || i >= v.size()) {
        return QVariant();
    }

    if (role == name) {
        return v[i].sName;
    }
    if (role==age) {
        return v[i].nAge;
    }
    if (role==addr) {
        return v[i].sAddr;
    }
    if (role==phone) {
        return v[i].sPhone;
    }
    if (role==note) {
        return v[i].sNote;
    }
    if (role==Qt::DisplayRole) {
        return v[i].sName + " ("+ QString::number(v[i].nAge) +")";
    }
}

QHash<int, QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> r =QAbstractListModel::roleNames();
    r[name]="name";
    r[age]="age";
    r[addr]="addr";
    r[phone]="phone";
    r[note]="note";
    return r;
}

void Model::setItemData2(int index, QVariant value, QString role)
{
    if (index >=0 && index <= v.size()) {
        QVector<int> roles;

        if(role=="name") {
            v[index].sName = value.toString();
            roles.push_back(name);
        }
        if(role=="age") {
            v[index].nAge = value.toInt();
            roles.push_back(age);
        }
        if(role=="addr") {
            v[index].sAddr = value.toString();
            roles.push_back(addr);
        }
        if(role=="phone") {
            v[index].sPhone = value.toString();
            roles.push_back(phone);
        }
        if(role=="note") {
            v[index].sNote = value.toString();
            roles.push_back(note);
        }

        roles.push_back(Qt::DisplayRole);
        emit dataChanged(createIndex(0,0), createIndex(v.size()-1,0), roles);
    }
}
