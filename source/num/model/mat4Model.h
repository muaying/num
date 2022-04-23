//
// Created by 24100 on 2022/4/19.
//

#ifndef NUM_MAT4MODEL_H
#define NUM_MAT4MODEL_H
#include <QAbstractTableModel>
#include "Matrix/Matrix.hpp"

class mat4Model :public QAbstractTableModel
{
public:
	explicit mat4Model(QObject *parent = nullptr);

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//设置单元格数据
	bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;
	//单元格的可操作性标志位，如可编辑，可选中等
	Qt::ItemFlags flags(const QModelIndex& index) const override;
private:
	Mat4 mat4;
};


#endif //NUM_MAT4MODEL_H
