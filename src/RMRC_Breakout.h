// This library creating by "iRAP Robot" from "KMUTNB" for use in RMRC competition.

#ifndef RMRC_BREAKOUT_h
#define RMRC_BREAKOUT_h

#include <Arduino.h>
#include <Wire.h>
#include <MadgwickAHRS.h>

#if defined(ARDUINO_SAMD_NANO_33_IOT)
#include <Arduino_LSM6DS3.h>
#elif defined(ARDUINO_ARCH_NRF52840)
#include <Arduino_LSM9DS1.h>
#else 
#error "This code is intended for the Arduino Nano 33 IoT or Nano 33 BLE only."
#endif

#define MAXIMUM_DUTY (int16_t)(16999) 
#define BASE_ADDR    (uint8_t)(0x12)
#define FLIPPER_ADDR (uint8_t)(0x13)
#define IMU_FEEDBACK_RATE (float)(104.0f) // Hz

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

class RMRC_IMU : public RMRC_Breakout {
  public:
    void begin(void);

    float ax = 0.0f;
    float ay = 0.0f;
    float az = 0.0f;

    float gx = 0.0f;
    float gy = 0.0f;
    float gz = 0.0f;

    float yaw = 0.0f;
    float pitch = 0.0f;
    float roll = 0.0f;

    void update(void);
  private:
    Madgwick filter_imu;
    static bool initialized_imu;
};

#endif