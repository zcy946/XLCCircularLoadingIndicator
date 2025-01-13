#include "XLCCircularLoadingIndicator.h"
#include <QFontDatabase>
#include <QFile>
#include <QDebug>
#include <QDebug>

XLCCircularLoadingIndicator::XLCCircularLoadingIndicator(QWidget *parent, Pattern pattern)
    : QLabel(parent), m_pattern(pattern)
{
    LoadFont();
    LoadStyleSheet();

    switch (m_pattern)
    {
    case Pattern::Dot:
        m_begin = 0xe052;
        m_end = 0xe0c8;
        break;
    case Pattern::Moon:
        m_begin = 0xe100;
        m_end = 0xe13b;
        break;
    default:
        m_begin = 0xe052;
        m_end = 0xe0c8;
        break;
    }
    m_currentUnicode = m_begin;

    setText(QChar(m_currentUnicode));

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &XLCCircularLoadingIndicator::UpdateText);

    Start();
}

void XLCCircularLoadingIndicator::LoadFont()
{
    int fontId = QFontDatabase::addApplicationFont("../res/font/XLCCircularLoading-Semilight.ttf");
    if (fontId != -1)
    {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        if (!fontFamilies.empty())
        {
            QString fontFamily = fontFamilies.at(0);
            setFont(QFont(fontFamily));
        }
    }
    else
    {
        qDebug() << "Failed to load font";
    }
}

void XLCCircularLoadingIndicator::LoadStyleSheet()
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setObjectName("XLCCircularLoadingIndicator");
    QString style = R"(
        #XLCCircularLoadingIndicator {
            font-family: "XLCCircularLoading Semilight";
            font-size: 40px;
        }
    )";
    setStyleSheet(style);
}

void XLCCircularLoadingIndicator::UpdateText()
{
    setText(QString(QChar(m_currentUnicode)));
    m_currentUnicode++;
    if (m_currentUnicode > m_end)
    {
        m_currentUnicode = m_begin;
    }
    // qDebug() << Qt::hex << Qt::showbase << m_currentUnicode;
}

void XLCCircularLoadingIndicator::Start()
{
    // 33 毫秒 ≈ 30 帧/秒
    m_timer->start(33);
    return;
}

void XLCCircularLoadingIndicator::Stop()
{
    m_timer->stop();
}
