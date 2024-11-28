#ifndef HAL_MAX30102_H
#define HAL_MAX30102_H

void max30102_init();
bool max30102_read(float *heartRate, float *spo2);

#endif
