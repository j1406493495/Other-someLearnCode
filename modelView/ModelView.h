#ifndef _MODELVIEW_H_
#define _MODELVIEW_H_

#include <QVariant>
#include <QAbstractTableModel>
#include <QWidget>
#include <QItemDelegate>
#include <QTableView>
#include <QModelIndex>

class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MyTableModel(QObject *parent = NULL);
    ~MyTableModel();

    QStringList mList;

    virtual int rowCount(const QModelIndex&) const; 
    virtual int columnCount(const QModelIndex&) const; 
    QVariant data(const QModelIndex&, int) const; 
};

class MyDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    MyDelegate(QObject *parent = NULL);
    ~MyDelegate();

    void paint(QPainter *painter,
            const QStyleOptionViewItem &option,
            const QModelIndex *index);
};

class MyTableView : public QTableView
{
    Q_OBJECT

public:
    MyTableView(QWidget *parent = NULL);
    ~MyTableView();

    MyTableModel *mModel;
    MyDelegate *mDelagate;
};

class ModelView : public QWidget 
{
    Q_OBJECT

public:
    ModelView(QWidget *parent = NULL);
    ~ModelView();

    MyTableView *mView;
};

#endif
