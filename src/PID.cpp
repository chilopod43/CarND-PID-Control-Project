#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID()
    : p_error{0.0}, i_error{0.0}, d_error{0.0}, prev_error{0.0}, prev_time{-1.0}, count{0},
      Kp{0.0}, Ki{0.0}, Kd{0.0}, impluse{false}
{}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, bool impluse_) 
{
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    prev_error = 0.0;
    prev_time = -1.0;
    count = 0;
    
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    impluse = impluse_;
}

void PID::UpdateError(double cte, double elapsed_time)
{
    if(prev_time <  0.0)
    {
        prev_error = cte;
        prev_time = elapsed_time;
        return;
    }
  
    double diff_time = elapsed_time - prev_time;
    double error = -cte;
    p_error = error;
    i_error += error * diff_time;
    d_error = (error - prev_error) / diff_time;
  
    prev_error = error;
    prev_time = elapsed_time;
}

double PID::TotalError()
{
    double tot_err{0.0};
    if(impluse)
    {
        tot_err = count >= start_impluse ? 1.0 : 0.0;
        count++;
    } else {
        tot_err = p_error * Kp + i_error * Ki + d_error * Kd;
    }

    return tot_err;
}
