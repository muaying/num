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
	m << 1,0,0,0,5,0,0,8,0;
	cout<<"m\n"<<m.inverse()<<endl;

	cout<<"row1\n"<<m.row(1)<<endl;
	cout<<"row\n"<<m.rows()<<endl;
}
