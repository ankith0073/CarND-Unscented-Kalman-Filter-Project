#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {

    VectorXd rmse(4) ;
    rmse << 0, 0, 0, 0;
    for(int i = 0; i < estimations.size(); i++)
    {
        //difference
        VectorXd diff = estimations[i] - ground_truth[i];
        diff = diff.array() * diff.array();
        rmse += diff;
    }

/* check if elements are going above 100, then make them 0 */

    rmse = rmse / estimations.size();

    rmse = rmse.array().sqrt();
    return rmse;

}
