#ifndef LEDMODEL_H
#define LEDMODEL_H

#include <QAbstractListModel>

#include <QColor>
#include <QQueue>

struct LedModelData {
    QString name_;
    QColor  color_;
};

class LedModel : public QAbstractListModel
{
    Q_OBJECT
    // Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    // Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged FINAL)
public:
    LedModel(QObject *parent = nullptr);

    enum Roles {
        LedNameRole = Qt::UserRole + 1,
        LedColorRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void resetDatas();

public slots:
    void updateLed3Color(const QColor& color);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<LedModelData> leds_;
    QQueue<QColor> colors_;

    void initilizeLedModel();
    void initLedDatas(const QString& name, const QColor& color);

};

#endif // LEDMODEL_H
