#include "vex.h"

using namespace vex;

void stop(brakeType bt) {
    DT.stop(bt);
}

void drive(double dis, double speed, double timeout, double wait)
{

    DT.resetPosition();
    drivePID_Left.setOutputLimits(speed, -speed);
    drivePID_Right.setOutputLimits(speed, -speed);

    double currentPos_left = 0;
    double currentPos_right = 0;
    currentPos_left = front_left.position(deg);
    currentPos_right = front_right.position(deg);

    double output_left = drivePID_Left.getOutput(currentPos_left, dis);
    double output_right = drivePID_Right.getOutput(currentPos_right, dis);

    while (fabs(output_left) > 25 && fabs(output_right) > 25)
    {

        output_left = drivePID_Left.getOutput(currentPos_left, dis);
        output_right = drivePID_Right.getOutput(currentPos_right, dis);

        currentPos_left = front_left.position(deg);
        currentPos_right = front_right.position(deg);

        left_drive.spin(fwd, output_left, rpm);
        right_drive.spin(fwd, output_right, rpm);
    }
    stop(brake);
    
}