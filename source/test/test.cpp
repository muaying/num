#include <iostream>
#include<Eigen/Core>
#include<Eigen/Dense>


using namespace Eigen;
using namespace std;

int main()
{
	std::cout<< "Eigen version is:\n";
	std::cout<< EIGEN_WORLD_VERSION << "." << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;


	MatrixXd m(3,3);
	m << 1,2,3,4,5,6,7,8,9;
	cout<<"row1\n"<<m.row(1)<<std::endl;
	cout<<"row\n"<<m.rows();
}
