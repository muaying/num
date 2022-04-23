#ifndef NUM_MATRIX_H
#define NUM_MATRIX_H
/**
 * @brief 矩阵
 */
#include <iostream>
template<typename T,size_t ROW,size_t COL>
class Matrix
{
	using type = T;
public:
	Matrix()
	{
		for(int i=0;i<ROW*COL;++i)
			mat[i]=0;
	}
	inline type& operator()(int i,int j)
	{
		return mat[i+ROW*j];
	}
	inline type operator()(int i,int j)const
	{
		return mat[i+ROW*j];
	}
	constexpr unsigned int row(){return ROW;}
	constexpr unsigned int column(){return COL;}
//	friend std::ostream& operator<<(std::ostream& out,const Matrix& mat)
//	{
//		for(int i<ROW)
//	}
private:
	type mat[ROW*COL];
};

/**
 * @brief 4*4 大小的矩阵
 */
class Mat4 : public Matrix<double,4,4>
{
	using Matrix = Matrix<double,4,4>;
public:
	Mat4():Matrix()//构造单位矩阵
	{
		for(int i=0;i<4;++i)
			(*this)(i,i)=1;
	}
};

#endif // NUM_MATRIX_H
