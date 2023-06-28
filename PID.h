#ifndef MiLibreria_h
#define MiLibreria_h
#include "Arduino.h"

class PID {
  public:
    PID(float setPoint, float Kp, float Ki, float Kd);          // Constructor
    void set_K(float Kp, float Ki, float Kd);
    float* get_K();
    float calc_PID(float input);                                // Método
    float calc_PID(float input, float Kp, float Ki, float Kd);
    float _setPoint;                                            //Set Point que dependera del sensor

  private:
    float _Kp, _Ki, _Kd;                                        //Constantes de PID
    float _error, _lastError, _cumError, _pendantError;         //Errores               
    unsigned long _lastTime, _elapsedTime;                      //Variables para almacenar valores de tiempo
};

#endif
