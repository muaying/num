//
// Created by 24100 on 2022/4/25.
//

#ifndef LEARN_NUM_XYMODEL_H
#define LEARN_NUM_XYMODEL_H
#include <QAbstractTableModel>
/**
 *@brief 插值法 使用的tableview的model
 */
class XYModel :public QAbstractTableModel
{
	friend class FrameInterValue;
public:
	explicit XYModel(QObject *parent = nullptr);
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
public slots:
	void setCount(int i);

private:
	QVector<double> vec_x;
	QVector<double> vec_y;
};


#endif //LEARN_NUM_XYMODEL_H
