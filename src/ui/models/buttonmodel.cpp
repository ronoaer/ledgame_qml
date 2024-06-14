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
    case ButtonTextRole: {
        buttons_[index.row()].button_text_ = value.toString();
        break;
    }

    case ButtonIndexRole: {
        buttons_[index.row()].button_index_ = value.toInt();
        break;
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
    case ButtonTextRole:
        return buttons_[index.row()].button_text_;

    case ButtonIndexRole:
        return buttons_[index.row()].button_index_;
    }

    return QVariant();
}

void ButtonModel::onResetDataModel()
{
//    initalizeButtonModel();
}

QHash<int, QByteArray> ButtonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ButtonTextRole] = "ButtonText";
    roles[ButtonIndexRole] = "ButtonIndex";
    return roles;
}

void ButtonModel::initalizeButtonModel()
{
    beginResetModel();

    buttons_.clear();

    initButtonDatas("A", 0);
    initButtonDatas("B", 1);
    initButtonDatas("C", 2);

    endResetModel();
}

void ButtonModel::initButtonDatas(const QString &charater, const int index)
{
    ButtonModelData data;
    data.button_text_ = charater;
    data.button_index_ = index;

    buttons_.append(data);
}
