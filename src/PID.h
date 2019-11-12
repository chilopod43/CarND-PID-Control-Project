#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_, bool impluse);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte, double elapsed_time);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();
  
  /**
   * Calculate the Impluse error.
   * @output The total Impluse error
             10 iteration : 0.0
             10 iteration : 
   */
  double ImpluseError();

  /**
   * Impluse Response starttime 
   */ 
  static constexpr int start_impluse = 50;

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  double prev_error;
  double prev_time;
  int count;
  
  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
  bool impluse;
};

#endif  // PID_H