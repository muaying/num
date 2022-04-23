//
// Created by 24100 on 2022/4/19.
//

#include "mat4Model.h"
#include <QDebug>
mat4Model::mat4Model(QObject *parent) : QAbstractTableModel(parent)
{
	mat4(0,0)=2;

}

QVariant mat4Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole) return QVariant();
	if(orientation==Qt::Horizontal)
	{
		switch (section)
		{
			case 0:
				return "x";
			case 1:
				return "y";
			case 2:
				return "z";
			case 3:
				return "w";
			default:
				break;
		}
	}
	return QString::number(section+1);
}

int mat4Model::rowCount(const QModelIndex &parent) const
{
	return 4;
}

int mat4Model::columnCount(const QModelIndex &parent) const
{
	return 4;
}

QVariant mat4Model::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();
	if( role == Qt::DisplayRole || role == Qt::EditRole)
	{
		int nRow = index.row();
		int nCol = index.column();
		if(nRow<4&&nCol<4)
			return mat4(nRow,nCol);
	}
	return QVariant();
}

bool mat4Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if( index.isValid()&&role==Qt::EditRole)
	{
		int nRow = index.row();
		int nCol = index.column();
		if(nRow<4&&nCol<4)
		{
			mat4(nRow,nCol)=value.toDouble();
			emit dataChanged(index, index, QVector<int>() << role);
			return true;
		}

	}
	return false;
}

Qt::ItemFlags mat4Model::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
}
