#ifndef UICOMPONENT_LEDGAMEUI_H_
#define UICOMPONENT_LEDGAMEUI_H_

#include "ledgameinterface.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class LedIndicator;


class LedGameUI : public QWidget
{
    Q_OBJECT
 public:
    static LedGameUI* NewInstance();
    ~LedGameUI();

    void Show();

    void set_usecase(LedGameInterface *interface);
    LedGameInterface* usecase() { return usecase_; }

    QList<LedIndicator*> led_indicators() { return led_indicators_; }
    QList<QPushButton*> led_buttons() { return led_buttons_; }

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

    void UpdateLedsColor(const QColor color, const int press_index);

    QList<LedIndicator*> led_indicators_;
    QList<QPushButton*> led_buttons_;

    LedGameInterface* usecase_;

    int num_press_index_;

};

#endif // UICOMPONENT_LEDGAMEUI_H_
