#ifndef OPENAG_SOFTWARE_PWM_ACTUATOR
#define OPENAG_SOFTWARE_PWM_ACTUATOR

#include "Arduino.h"
#include <std_msgs/Float32.h>

class SoftwarePwmActuator {
  public:
    // Constuctor
    SoftwarePwmActuator(int pin, bool is_active_low, int period);

    // Public variables
    bool has_error;
    char* error_msg;

    // Public functions
    void begin();
    void update();
    void set_cmd(std_msgs::Float32 cmd);

  private:
    int _pin;
    int _period;
    bool _is_active_low;
    float _duty_cycle;
    uint32_t _last_cycle_start;
};

#endif
