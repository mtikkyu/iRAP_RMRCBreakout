// This library creating by "iRAP Robot" from "KMUTNB" for use in RMRC competition.

#pragma once

#include <Arduino.h>
#include <Wire.h>

#define MAXIMUM_DUTY (int16_t)(16999)
#define BASE_ADDR    (uint8_t)(0x12)
#define FLIPPER_ADDR (uint8_t)(0x13)

typedef enum {
  SET_DUTY = 0,
  SET_RPM,
  SET_KP,
  SET_KI,
  SET_KD,
  SET_OFFSET,
  SET_MIN_K_VALUE,
  SET_MAX_K_VALUE,
  GET_OFFSET,
  GET_K_ANGLE
} CONTROL_MODE;

typedef struct {
  uint8_t buf[9];
  uint8_t buf_count = 0;
  uint32_t asUint32_t = 0;
  uint16_t asUint16_t = 0;
  float *asFloatPtr = nullptr;
} I2C_message_t;

class RMRC_Breakout {
  public:
    void begin(void);

  private:
    static bool initialized;
};

class RMRC_Base : public RMRC_Breakout {
  public:
    RMRC_Base(float _maxRpm);
    RMRC_Base(float _maxRpmL, float _maxRpmR);
    void setDuty(int16_t _dutyL, int16_t _dutyR);
    void setRpm(float _rpmL, float _rpmR);

    void setKp(float _kpL, float _kpR);
    void setKi(float _kiL, float _kiR);
    void setKd(float _kdL, float _kdR);

    struct PARAM_FEEDBACK {
      float maximum_rpm = 0.0f;
      float rpm = 0.0f;

      float kp = 0.0f;
      float ki = 0.0f;
      float kd = 0.0f;
    }ml, mr;
};

class RMRC_Flipper : public RMRC_Breakout {
  public:
    void setOffset(int16_t _offset, int16_t _k_min, int16_t _k_max);
    void setDuty(int16_t _duty);

    float position = 0.0f;

    int16_t getOffset(void);
    int16_t getKAngle(void);
};