#pragma once
#include "ui_AnswerCheckBox.h"

class AnswerCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit AnswerCheckBox(QWidget* parent, int number, const QString& text, qreal dpiScaleFactor = 1.0);

    bool IsChecked() const;
    void SwitchCheckedState();

    void EnableSummarizedView(bool wasRight);

protected:
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::AnswerCheckBox m_ui;
    bool m_summarized;
};

