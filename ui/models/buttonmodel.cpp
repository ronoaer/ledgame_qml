#include "buttonmodel.h"


ButtonModel::ButtonModel(QObject *parent) : QAbstractListModel(parent)
{
    initalizeButtonModel();
}

int ButtonModel::rowCount(const QModelIndex &parent) const
{
    return buttons_.count();
}

bool ButtonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= buttons_.count()) {
        return false;
    }

    switch (role) {
    case ButtonCharacter: {
        buttons_[index.row()].button_character_ = value.toString();
        break;
    }

    case ButtonIndex: {
        buttons_[index.row()].button_index_ = value.toInt();
    }
    default: {
        return true;
    }
    }

    emit dataChanged(index, index);

    return true;
}

QVariant ButtonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= buttons_.count()) {
        return QVariant();
    }

    switch (role) {
    case ButtonCharacter: return buttons_[index.row()].button_character_;
    case ButtonIndex: return buttons_[index.row()].button_index_;
    }

    return QVariant();
}

QHash<int, QByteArray> ButtonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ButtonCharacter] = "buttonTexta";
    roles[ButtonIndex] = "buttonIndexa";
    return roles;
}

void ButtonModel::initalizeButtonModel()
{
    initButtonDatas("A", 0);
    initButtonDatas("B", 1);
    initButtonDatas("C", 2);
}

void ButtonModel::initButtonDatas(const QString &charater, const int index)
{
    ButtonModelData data;
    data.button_character_ = charater;
    data.button_index_ = index;

    buttons_.append(data);
}
