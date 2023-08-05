#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class LedIndicator;
class LedButton;
class KeySequence;
class StepController;
class QGridLayout;

class Widget : public QWidget {
    Q_OBJECT
 public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QList<LedButton*> led_buttons() {
        return led_buttons_;
    }

    QList<LedIndicator*> led_indicators() {
        return led_indicators_;
    }

 private slots:
    void onResetContext();
    //void onButtonClicked();

 private:
    void ResetButtonText(const int count);
    void GenerateButtons(QGridLayout* layout, const int count);
    void GenerateLedIndicators(QGridLayout* layout, const int count);
    int reseed(const int seed, const int count);
    QColor IndexToLedColor(const int seed);

    QList<LedIndicator*> led_indicators_;
    QList<LedButton*> led_buttons_;

    StepController* step_context_;

 private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
