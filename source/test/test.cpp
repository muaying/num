#include <iostream>
#include<Eigen/Core>
#include<Eigen/Dense>


using namespace Eigen;
using namespace std;

int main()
{
	std::cout<< "Eigen version is:\n";
	std::cout<< EIGEN_WORLD_VERSION << "." << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;


	MatrixXd m = MatrixXd::Random(3, 3);            //初始化动态矩阵m,使用Random函数,初始化的值在[-1,1]区间内,矩阵大小3X3
	m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
	cout << "m =" << endl << m << endl;
	VectorXd v(3);
	v << 1, 2, 3;
	cout << "m * v =" << endl << m * v << endl;
}
