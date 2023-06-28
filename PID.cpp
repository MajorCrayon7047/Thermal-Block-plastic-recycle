#include "PID.h"

//Constructor del objeto PID
PID::PID(float setPoint, float Kp, float Ki, float Kd){
    _setPoint = setPoint;
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;
}
//Setear constantes K del PID
void PID::set_K(float Kp, float Ki, float Kd){
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;
}
//Obtener Array de valores
float* PID::get_K(){
    float* K = new float[3];
    K[0] =_Kp;
    K[1] =_Ki;
    K[2] =_Kd;
    return K;
}
//Calculo de PID
float PID::calc_PID(float input){
    _elapsedTime = millis() - _lastTime;
    _error = _setPoint - input;
    _cumError += _error * _elapsedTime;
    if (_cumError > 255) _cumError = 255;
    else if(_cumError <= 0) _cumError = 0;
    _pendantError = (_error - _lastError) / _elapsedTime;
    float out = (_error * _Kp) + (_cumError * _Ki) + (_pendantError * _Kd);
    _lastError = _error;
    _lastTime = millis();
    return out;
}
//Calculo de PID con valores otorgados
float PID::calc_PID(float input, float Kp, float Ki, float Kd){
    _elapsedTime = millis() - _lastTime;
    _error = _setPoint - input;
    _cumError += _error * _elapsedTime;
    _pendantError = (_error - _lastError) / _elapsedTime;
    float out = (_error * Kp) + (_cumError * Ki) + (_pendantError * Kd);
    _lastError = _error;
    _lastTime = millis();
    return out;   
}
