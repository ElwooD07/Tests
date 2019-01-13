#include "AnswerCheckBox.h"
#include <QMouseEvent>

namespace
{
    void AppendStyleSheet(QWidget* widget, const QString& styleSheet)
    {
        widget->setStyleSheet(widget->styleSheet() + "; " + styleSheet);
        widget->style()->polish(widget);
        widget->style()->unpolish(widget);
    }
}

AnswerCheckBox::AnswerCheckBox(QWidget *parent, int number, const QString& text, qreal dpiScaleFactor)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    m_ui.lblNumber->setText(QString("%1.").arg(number));
    m_ui.lblText->setText(text);
    m_ui.wgtCheck->setVisible(false);
    m_ui.wgtCheckFrame->setMinimumHeight(static_cast<int>(m_ui.wgtCheckFrame->minimumHeight() * dpiScaleFactor));
    m_ui.wgtCheckFrame->setMinimumWidth(static_cast<int>(m_ui.wgtCheckFrame->minimumWidth() * dpiScaleFactor));
    m_ui.wgtCheckFrame->layout()->setMargin(static_cast<int>(m_ui.wgtCheckFrame->layout()->margin() * dpiScaleFactor));
    setMinimumHeight(layout()->margin() * 2 + m_ui.wgtCheckFrame->minimumHeight());
}

bool AnswerCheckBox::IsChecked() const
{
    return m_ui.wgtCheck->isVisible();
}

void AnswerCheckBox::SwitchCheckedState()
{
    if (isEnabled())
    {
        m_ui.wgtCheck->setVisible(!m_ui.wgtCheck->isVisible());
    }
}

void AnswerCheckBox::EnableSummarizedView(bool wasRight)
{
    setEnabled(false);
    QString checkStyle("background-color: ");
    checkStyle += wasRight ? "#20cc20" : "#cc2020";
    AppendStyleSheet(m_ui.wgtCheckFrame, checkStyle);
    if (wasRight)
    {
        AppendStyleSheet(this, "font-weight: bold");
    }
    update();
}

void AnswerCheckBox::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        SwitchCheckedState();
    }
}
