#include "ModelView.h"
#include <QRect>
#include <QPainter>

MyTableModel::MyTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    mList << "hello" << "world" << "boys";
}

int MyTableModel::rowCount(const QModelIndex &) const 
{
    return 3;
}

int MyTableModel::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {
            return mList[0];
        }
        else if (index.column() == 1)
        {
            return mList[1];
        }
        else if (index.column() == 2)
        {
            return mList[0];
        }
    }

    return QVariant();
}

MyTableModel::~MyTableModel()
{}

MyTableView::MyTableView(QWidget *parent)
    : QTableView(parent)
{
    mModel = new MyTableModel(this); 
    mDelagate = new MyDelegate(this);
    setModel(mModel);
}

MyTableView::~MyTableView()
{}

MyDelegate::MyDelegate(QObject *parent)
    : QItemDelegate(parent)
{}

void MyDelegate::paint(QPainter *painter,
        const QStyleOptionViewItem &option,
        const QModelIndex *index)
{
    if (index->column() == 0)
    {
        QRect tmpRect = option.rect;
        
        tmpRect.setWidth(50);
        tmpRect.setHeight(50);
        painter->drawRect(tmpRect);
    }
    else if (index->column() == 1)
    {
        QRect tmpRect = option.rect;
        tmpRect.setWidth(10);
        painter->drawRect(tmpRect);
    }
    else if (index->column() == 2)
    {
        QRect tmpRect = option.rect;
        tmpRect.setHeight(100);
        painter->drawRect(tmpRect);
    }
}

MyDelegate::~MyDelegate()
{}

ModelView::ModelView(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(400, 400);

    mView = new MyTableView(this);

    mView->setGeometry(50, 50, 300, 300);
    mView->show();
}

ModelView::~ModelView()
{}
