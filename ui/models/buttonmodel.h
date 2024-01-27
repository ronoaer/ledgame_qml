#ifndef BUTTONMODEL_H
#define BUTTONMODEL_H

#include <QAbstractListModel>

struct ButtonModelData {
    QString button_character_;
    int button_index_;
};

class ButtonModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ButtonModel(QObject* parent = nullptr);

    enum Roles {
        ButtonCharacter = Qt::UserRole + 1,
        ButtonIndex
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    void initalizeButtonModel();
    void initButtonDatas(const QString& charater, const int index);

    QVector<ButtonModelData> buttons_;
};

#endif // BUTTONMODEL_H
