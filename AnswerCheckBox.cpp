#include "AnswerCheckBox.h"
#include <QMouseEvent>
#include <QUrl>

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
    , m_summarized(false)
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
    if (!m_summarized)
    {
        m_ui.wgtCheck->setVisible(!m_ui.wgtCheck->isVisible());
    }
}

void AnswerCheckBox::EnableSummarizedView(bool wasRight)
{
    m_summarized = true;

    QString checkStyle("background-color: ");
    checkStyle += wasRight ? "#20cc20" : "#cc2020";
    AppendStyleSheet(m_ui.wgtCheckFrame, checkStyle);
    if (wasRight)
    {
        AppendStyleSheet(this, "font-weight: bold");
        auto searchLinkTemplate = QString("<a href=\"https://www.google.com/search?q=%1\">%2</a>");
        auto searchLink = searchLinkTemplate.arg(QUrl::toPercentEncoding(m_ui.lblText->text()).toStdString().c_str(), 1).arg(m_ui.lblText->text(), 2);
        m_ui.lblText->setText(searchLink);
        m_ui.lblText->setTextFormat(Qt::RichText);
        m_ui.lblText->setTextInteractionFlags(Qt::TextBrowserInteraction);
        m_ui.lblText->setOpenExternalLinks(true);
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
