#include "ledmodel.h"

#include <QDebug>

LedModel::LedModel(QObject *parent) : QAbstractListModel(parent)
{
    initilizeLedModel();
}

int LedModel::rowCount(const QModelIndex &parent) const
{
    return leds_.count();
}

bool LedModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= leds_.count()) {
        return false;
    }

    switch (role) {
    case LedNameRole: {
        break;
    }

    case LedColorRole: {
        leds_[index.row()].color_ = value.toInt();
        break;
    }

    default: {
        qDebug() << "defualt" <<Qt::endl;
        return true;
    }
    }

    Q_EMIT dataChanged(index, index);

    return true;
}

QVariant LedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= leds_.count()) {
        return QVariant();
    }

    switch (role) {
    case LedNameRole: return leds_[index.row()].name_;
    case LedColorRole: return colors_[index.row()];
    }

    return QVariant();
}

void LedModel::updateLed3Color(const QColor& color)
{
    colors_.dequeue();
    colors_.enqueue(color);

    for (int i=0; i<leds_.count(); i++) {
        leds_[i].color_ = colors_[i];
    }

    Q_EMIT dataChanged(index(0), index(rowCount({}) - 1, 0));
}

void LedModel::resetDatas()
{
    initilizeLedModel();
}

QHash<int, QByteArray> LedModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[LedNameRole] = "LedName";
    roles[LedColorRole] = "LedColor";
    return roles;
}

void LedModel::initilizeLedModel()
{
    beginResetModel();

    leds_.clear();
    colors_.clear();

    initLedDatas("Led 1", Qt::red);
    initLedDatas("Led 2", Qt::green);
    initLedDatas("Led 3", Qt::yellow);

    endResetModel();
}

void LedModel::initLedDatas(const QString &name, const QColor &color)
{
    LedModelData data;
    data.name_ = name;
    data.color_ = color;

    leds_.append(data);
    colors_.enqueue(color);
}

