//
// Created by 24100 on 2022/4/19.
//

#include "matModel.h"
#include <QDebug>

matModel::matModel(QObject *parent) : QAbstractTableModel(parent), mat(4, 5)
{}

QVariant matModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole) return QVariant();
	if (orientation == Qt::Horizontal)
	{
		if (section < mat.cols() - 1)
			return QString("x%1").arg(section+1);
		else
			return "b";
	}
	return QString::number(section + 1);
}

int matModel::rowCount(const QModelIndex &parent) const
{
	return mat.rows();
}

int matModel::columnCount(const QModelIndex &parent) const
{
	return mat.cols();
}

QVariant matModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		int nRow = index.row();
		int nCol = index.column();
		if (nRow < mat.rows() && nCol < mat.cols())
			return mat(nRow, nCol);
	}
	return QVariant();
}

bool matModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && role == Qt::EditRole)
	{
		int nRow = index.row();
		int nCol = index.column();
		if (nRow < mat.rows() && nCol < mat.cols())
		{
			mat(nRow, nCol) = value.toDouble();
			emit dataChanged(index, index, QVector<int>() << role);
			return true;
		}

	}
	return false;
}

Qt::ItemFlags matModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

void matModel::setXCount(int count)
{
	if(count<mat.rows()) //减少
	{
		beginRemoveColumns(QModelIndex(),mat.cols()-1,count);
		beginRemoveRows(QModelIndex(),mat.rows()-1,count-1);
		mat = Eigen::MatrixXd::Zero(count,count+1);
		endRemoveRows();
		endRemoveColumns();
	}else//增加
	{
		beginInsertColumns(QModelIndex(),mat.cols()+1,count);
		beginInsertRows(QModelIndex(),mat.rows()+1,count-1);
		mat = Eigen::MatrixXd::Zero(count,count+1);
		endInsertColumns();
		endInsertColumns();
	}
	emit  headerDataChanged(Qt::Horizontal,0,mat.cols()-1);
	emit  headerDataChanged(Qt::Vertical,0,mat.rows()-1);
}

void matModel::updateMat()
{
	emit dataChanged(index(0,0),index(mat.rows()-1,mat.cols()-1),QVector<int>());
}
