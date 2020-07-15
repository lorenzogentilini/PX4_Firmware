//

#pragma once

#include <matrix/matrix/math.hpp>

class IMBControl{
    public:
    // Class Constructor
    IMBControl();

    // Class Destuctor
    ~IMBControl() = default;

    // Set Parameters
    void setParams();

    // Update Control Law
    matrix::Matrix<double, 4, 1> update(matrix::Matrix<double, 12, 1> actualState,
                                        matrix::Matrix<double, 3, 1> setPoint);

    // Reset
    void reset();

    private:
    /* Attributes */
    matrix::Matrix<double, 3, 1> zRoll, zPitch;
    double zV;

    // Roll Controller
    double rollCtrl(double y, double yDot, double phi, double phiDot, double yRef);

    // Pitch Controller
    double pitchCtrl(double x, double xDot, double theta, double thetaDot, double xRef);

    // Yaw Controller
    double yawCtrl(double psi, double psiDot);

    // Vertical Dynamics Controller
    double verticalCtrl(double z, double zDot, double zRef);
};