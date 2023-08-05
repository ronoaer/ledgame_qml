#ifndef LEDGAME_LEDGAMEUI_H_
#define LEDGAME_LEDGAMEUI_H_

#include "ledgameinterface.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>


class LedGameUI : public QWidget
{
    Q_OBJECT
 public:
    static LedGameUI* NewInstance();
    ~LedGameUI();

    void Show();

    void set_usecase(LedGameInterface *interface);
    LedGameInterface *usecase();

 signals:

 private slots:
     void onButtonClicked();

 private:
    LedGameUI();
    bool constructor();

    void ResetContext(int& press_index, const int max_count);
    void ResetButtonsText();

    // for initialize button and label
    QString IndexToText(const int index);
    QColor IndexToColor(const int index);

    void UpdateLedColor(QLabel* led, const QColor color);
    void UpdateLedsColor(const QColor color, const int press_index);

    QList<QLabel*> led_indicators_;
    QList<QPushButton*> led_buttons_;

    LedGameInterface* usecase_;

    int num_press_index_;

};

#endif // LEDGAME_LEDGAMEUI_H_
