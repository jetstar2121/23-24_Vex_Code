#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

//Right
motor front_right(PORT1, ratio18_1);
motor mid_right(PORT2, ratio18_1);
motor back_right(PORT3, ratio18_1);

//Left
motor front_left(PORT4, ratio18_1);
motor mid_left(PORT5, ratio18_1);
motor back_left(PORT6, ratio18_1);

//Drive Groups
motor_group right_drive(front_right, mid_right, back_right);
motor_group left_drive(front_left, mid_left, back_left);

motor_group DT(front_right, mid_right, back_right, front_left, mid_left, back_left);


MiniPID drivePID_Left(0.4, 0.0007, 0.6);
MiniPID drivePID_Right(0.4, 0.0007, 0.6);

MiniPID turnPID(.5, .9, .8);




