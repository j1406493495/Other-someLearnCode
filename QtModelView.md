###Qt项视图类
QListWidget.QTableWidget,QTreeWidget为Qt提供的简便的项视图类，今天主要记录学习QListView，QTableView和QTreeView的使用.
不同与MFC的模型-视图-控制器，Qt采用了模型(model)-视图(view)的方式，不过Qt使用的不是控制器，而是委托（delegate）.
####实现自定义模型
在模型中，每个数据元素都有一个模型索引和一套属性，称为角色（role），这些角色可以保存任意值。常用的有Qt::DisplayRole,Qt::EditRole等。下面主要以QTableView来做笔记。
QTableView对于的model继承与QAvstractTableModel这个类。对于表模型，我们必须重写的函数有rowCount(),columnCount(),data().
rowCount()和columnCount()函数我们只需在其中返回自定义model的个数即可，它可支撑整个table的行列。
```
int MyTable::rowCount(const QModelIndex&) const
{
	return mRowCount;
}
int MyTable::columnCount(const QModelIndex&) const
{
	return mColumnCount;
}
```
这里需要说一下QModelIndex这个类。这个类可以理解为表格单元格的索引。可以通过QModelIndex::row()和QModelIndex::column()获得当前单元格的行号和列号。当然，在model中，我们可以通过QModelIndex index(int row, int column, QModelIndex&  parent)来获得当前单元格在parent下的索引。

data()函数为model中十分重要的函数，它返回一个项的任意角色的值。
```
QVariant MyTable::data(const QModelIndex &index, int role)
{
	if (!index.isVaild())
    {
   		return QVariant(); 
    }

    if (role == Qt::DisPlayRole)
    {}
    else if (role == Qt::TextAlignmentRole)
    {}
}
```
role的各个参数可以查询Qt文档Qt::ItemDataRole
另外，也可以用headerData()函数来实现水平表头的自定义。
对一个QTableView中进行setModel(model)即可现实信息
####自定义委托
一般我们会将自定义的委托继承于QItemDelegate，因为这样我们可以从默认的委托中获益。当然，若需要从头开始，也可继承于QAbstractItemDelegate。我们需要重新paint()，它用来改变持显示。当然，如果想要实现一个可以编辑数据的委托，则需重写createEditor(),setEditorData(),setModelData()。
```
void MyDelegate::paint(QPainter *painter
const QStyleOptionViewItem &option,
const QModelIndex *index) const
{
	if (index.column() == 1)
    {}
    else if (index.column() == 2)
    {}
    else
    {
    	QItemDelegate::paint(painter, option, index);
    }
}
```