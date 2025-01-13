#include "Test.h"
#include "XLCCircularLoadingIndicator.h"
#include <QHBoxLayout>

Test::Test(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 300);

    XLCCircularLoadingIndicator *xlcCLoadingindicator_dot = new XLCCircularLoadingIndicator(this, Pattern::Dot);
    XLCCircularLoadingIndicator *xlcCLoadingindicator_moon = new XLCCircularLoadingIndicator(this, Pattern::Moon);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
    hLayout->addWidget(xlcCLoadingindicator_dot, 0, Qt::AlignCenter);
    hLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
    hLayout->addWidget(xlcCLoadingindicator_moon, 0, Qt::AlignCenter);
    hLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
}