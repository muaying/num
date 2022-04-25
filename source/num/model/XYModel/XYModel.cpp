//
// Created by 24100 on 2022/4/25.
//

#include "XYModel.h"

XYModel::XYModel(QObject *parent) : QAbstractTableModel(parent),
vec_x({1,2,3,4,5,6,7,8,9}),vec_y({1,1,2,3,5,8,13,21,34})
{
}

QVariant XYModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole) return QVariant();
	if (orientation == Qt::Horizontal)
	{
		if(section==0)
			return QString("Xi");
		else
			return QString("Yi");
	}
	return QString::number(section + 1);
}

int XYModel::rowCount(const QModelIndex &parent) const
{
	return vec_x.size();
}

int XYModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

QVariant XYModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		int nRow = index.row();
		int nCol = index.column();
		if(nRow<vec_x.size())
			if(nCol==0)
				return vec_x[nRow];
			else
				return vec_y[nRow];
	}
	return QVariant();
}

bool XYModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && role == Qt::EditRole)
	{
		int nRow = index.row();
		int nCol = index.column();
		if(nRow<vec_x.size())
			if(nCol==0)
				return vec_x[nRow]=value.toDouble();
			else
				return vec_y[nRow]=value.toDouble();
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
}

Qt::ItemFlags XYModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

void XYModel::setCount(int i)
{
	vec_x.resize(i);
	vec_y.resize(i);
	emit emit  headerDataChanged(Qt::Vertical,0,vec_x.size()-1);
}
