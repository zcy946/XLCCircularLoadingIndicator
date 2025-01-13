#ifndef XLCCIRCULARLOADINGINDICATOR_H
#define XLCCIRCULARLOADINGINDICATOR_H

#include <QLabel>
#include <QTimer>

enum Pattern
{
    Dot,
    Moon,
};

class XLCCircularLoadingIndicator : public QLabel
{
public:
    explicit XLCCircularLoadingIndicator(QWidget *parent = nullptr, Pattern pattern = Pattern::Dot);
    void Start();
    void Stop();

private:
    QTimer *m_timer;      // 定时器
    Pattern m_pattern;    // 样式
    int m_begin;          // 开始字符 Unicode 代码
    int m_end;            // 结束字符 Unicode 代码
    int m_currentUnicode; // 当前 Unicode 代码
    void LoadFont();
    void LoadStyleSheet();
    void UpdateText();
};

#endif