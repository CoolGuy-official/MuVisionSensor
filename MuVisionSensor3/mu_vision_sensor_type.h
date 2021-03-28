// Copyright 2018 Morpx Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MUVISIONSENSOR_SRC_MUVISIONSENSOR_TYPE_H_
#define MUVISIONSENSOR_SRC_MUVISIONSENSOR_TYPE_H_

typedef unsigned char mu_err_t;

#ifdef BIT
#undef BIT
#endif
#define BIT(x) (0x01<<(x))

#define MU_MAX_RESULT                 1

#define MU_DEVICE_ID                  0x03
#define visionTypeEnumToMacro(v)      (BIT(v-1))

#define kVisionMaxType 9

enum MuVsMessageVisionType {
  //% block="🌈 Color Block"
  kVisionColorDetect  = 1,
  //% block="🌈 Color Recognition"
  kVisionColorRecog   = 2,
  //% block="⚽ Ball Detect"
  kVisionBall         = 3,
  //% block="👥 Body Detect"
  kVisionBody         = 5,
  //% block="🔳 Shape Card"
  kVisionShapeCard    = 6,
  //% block="🔳 Traffic Card"
  kVisionTrafficCard  = 7,
  //% block="🔳 Number Card"
  kVisionNumberCard   = 8,
};

enum MuVsLedColor {
  //% block="off"
  kLedClose           = 0,
  //% block="red"
  kLedRed             = 1,
  //% block="green"
  kLedGreen           = 2,
  //% block="yellow"
  kLedYellow          = 3,
  //% block="blue"
  kLedBlue            = 4,
  //% block="purple"
  kLedPurple          = 5,
  //% block="cyan"
  kLedCyan            = 6,
  //% block="white"
  kLedWhite           = 7,
};
//register address define
typedef enum {
  kRegDeviceId        = 0x01,
  kRegFirmwareVersion = 0x02,
  kRegRestart         = 0x03,
  kRegSensorConfig1   = 0x04,
  kRegLock            = 0x05,
  kRegLed1            = 0x06,
  kRegLed2            = 0x07,
  kRegLedLevel        = 0x08,
  kRegUart            = 0x09,
  kRegLightSensor     = 0x0A,
  kRegIO              = 0x0B,
  kRegBle             = 0x0C,
  kRegCameraConfig1   = 0x10,
  kRegFrameCount      = 0x1F,
  kRegVisionId        = 0x20,
  kRegVisionConfig1   = 0x21,
  kRegVisionConfig2   = 0x22,
  kRegParamValue1     = 0x25,
  kRegParamValue2     = 0x26,
  kRegParamValue3     = 0x27,
  kRegParamValue4     = 0x28,
  kRegParamValue5     = 0x29,
  kRegVisionStatus1   = 0x2A,
  kRegVisionStatus2   = 0x2B,
  kRegVisionDetect1   = 0x30,
  kRegVisionDetect2   = 0x31,
  kRegResultNumber    = 0x34,
  kRegResultId        = 0x35,
  kRegReadStatus1     = 0x36,
  kRegResultData1     = 0x40,
  kRegResultData2     = 0x41,
  kRegResultData3     = 0x42,
  kRegResultData4     = 0x43,
  kRegResultData5     = 0x44,
  kRegLsProximity     = 0x50,
  kRegLsAlsL          = 0x51,
  kRegLsAlsH          = 0x52,
  kRegLsRawColorRedL  = 0x53,
  kRegLsRawColorRedH  = 0x54,
  kRegLsRawColorGreenL= 0x55,
  kRegLsRawColorGreenH= 0x56,
  kRegLsRawColorBlueL = 0x57,
  kRegLsRawColorBlueH = 0x58,
  kRegLsColor         = 0x59,
  kRegLsGesture       = 0x5A,
  kRegLsColorRed      = 0x60,
  kRegLsColorGreen    = 0x61,
  kRegLsColorBlue     = 0x62,
  kRegLsColorHueL     = 0x63,
  kRegLsColorHueH     = 0x64,
  kRegLsColorSaturation  = 0x65,
  kRegLsColorValue    = 0x66,
  kRegSn              = 0xD0,
} MuVsRegAddress;

//type define
enum MuVsLed {
  //% block="all"
  kLedAll = 2,
  //% block="1"
  kLed1 = 0,
  //% block="2"
  kLed2 = 1,
};
enum MuVsMode {
  //% block="I2C"
  kI2CMode = 1,
  //% block="Serial"
  kSerialMode = 0,
};
enum MuVsBaudrate {
  kBaud9600     = 0x00,
  kBaud19200    = 0x01,
  kBaud38400    = 0x02,
  kBaud57600    = 0x03,
  kBaud115200   = 0x04,
  kBaud230400   = 0x05,
  kBaud460800   = 0x06,
  kBaud921600   = 0x07,
};
enum MuVsObjectInf {
  //% block="status"
  kStatus,        //!< whether the target is detected
  //% block="x position"
  kXValue,        //!< target horizontal position
  //% block="y position"
  kYValue,        //!< target vertical position
  //% block="width"
  kWidthValue,    //!< target width
  //% block="height"
  kHeightValue,   //!< target height
  //% block="label"
  kLabel,         //!< target label
  //% block="red channel"
  kRValue,        //!< R channel value
  //% block="green channel"
  kGValue,        //!< G channel value
  //% block="blue channel"
  kBValue,        //!< B channel value
};
typedef enum {
  //!< for UART mode only
  kCallBackMode = 0,      //!< u need send a request first, and wait for response
  kDataFlowMode = 1,      //!< MU will automatically response the result of the vision that u enabled, whether it detected or undetected
  kEventMode    = 2,      //!< MU can only automatically response the result of the vision that u enabled, which detected target
} MuVsStreamOutputMode;
enum MuVsCameraZoom {
  //% block="Auto"
  kZoomDefault  = 0,
  //% block="Level1"
  kZoom1        = 1,
  //% block="Level2"
  kZoom2        = 2,
  //% block="Level3"
  kZoom3        = 3,
  //% block="Level4"
  kZoom4        = 4,
  //% block="Level5"
  kZoom5        = 5,
};
typedef enum {
  kFPSNormal        = 0,          //!< 25FPS mode
  kFPSHigh          = 1,          //!< 50FPS mode
} MuVsCameraFPS;
enum MuVsCameraWhiteBalance {
  //% block="auto"
  kAutoWhiteBalance       = 0,    //!< auto white balance mode
  //% block="lock"
  kLockWhiteBalance       = 1,    //!< lock white balance with current value, the entire process takes about 100ms
  //% block="white"
  kWhiteLight             = 2,    //!< white light mode
  //% block="yellow"
  kYellowLight            = 3,    //!< yellow light mode
};
enum MuVsVisionLevel {
  //% block="auto"
  kLevelDefault         = 0,
  //% block="speed"
  kLevelSpeed           = 1,      //!< speed first mode
  //% block="balance"
  kLevelBalance         = 2,      //!< balance mode
  //% block="accuracy"
  kLevelAccuracy        = 3,      //!< accuracy first mode
};
enum MuVsLsSensitivity {
  //% block="auto"
  kSensitivityDefault  = 0,
  //% block="low"
  kSensitivity1,
  //% block="middle"
  kSensitivity2,
  //% block="high"
  kSensitivity3,
};
#define kGestureNone (MuVsLsGesture(0))
enum MuVsLsGesture {
  //%block="upward"
  kGestureUp = 1,
  //%block="downward"
  kGestureDown,
  //%block="leftward"
  kGestureLeft,
  //%block="rightward"
  kGestureRight,
  //%block="push"
  kGesturePush,
  //%block="pull"
  kGesturePull,
};
enum MuVsLsColorType {
  //% block="color label"
  kLsColorLabel,
  //% block="red channel"
  kLsColorRed,
  //% block="green channel"
  kLsColorGreen,
  //% block="blue channel"
  kLsColorBlue,
  //% block="hue"
  kLsColorHue,
  //% block="saturation"
  kLsColorSaturation,
  //% block="value"
  kLsColorValue,
};
typedef enum {
  kLsRawColorRed,
  kLsRawColorGreen,
  kLsRawColorBlue,
} MuVsLsRawColorType;
// register type
typedef union {
  struct {
    unsigned char reserve0 : 2;
    unsigned char default_setting :1;  //!< set 1 reset all config
  };
  unsigned char sensor_config_reg_value;
} MuVsSensorConfig1;
typedef union {
  struct {
    MuVsBaudrate baudrate :3;
  };
  unsigned char uart_reg_value;
} MuVsUartConfig;
typedef union {
  struct {
    unsigned char manual:1;
    MuVsLedColor detected_color:3;
    unsigned char hold:1;
    MuVsLedColor undetected_color:3;
  };
  unsigned char led_reg_value;
} MuVsLedConfig;
typedef union {
  struct {
    MuVsCameraZoom zoom:3;
    unsigned char rotate:1;
    MuVsCameraFPS fps:1;
    MuVsCameraWhiteBalance white_balance:2;
    unsigned char awb_locked:1;
  };
  unsigned char camera_reg_value;
} MuVsCameraConfig1;
typedef union {
  struct {
    unsigned char status :1;
    unsigned char default_setting :1;  //!< set 1 to reset vision configuration
    MuVsStreamOutputMode output_mode :2;
    MuVsVisionLevel level :2;
    unsigned char reserve6 :1;
    unsigned char output_enable :1;
  };
  unsigned char vision_config_reg_value;
} MuVsVisionConfig1;
typedef union {
  struct {
    unsigned char proximity_enable:1;
    unsigned char als_enable:1;
    unsigned char color_enable:1;
    unsigned char gesture_enable:1;
    MuVsLsSensitivity sensitivity:2;
    bool white_balance_enable:1;
  };
  unsigned char ls_reg_value;
} MuVsLightSensor;
typedef union {
  struct {
    MuVsLsGesture gesture:7;
    bool detect:1;
  };
  unsigned char ls_gesture_reg_value;
} MuVsLsGestureConfig;
typedef struct {
  unsigned char frame;
  unsigned char detect;
  struct {
    union {
      unsigned char result_data1;
      unsigned char x_value;
      unsigned char color_r_value;
      unsigned char top_x_value;
    };
    union {
      unsigned char result_data2;
      unsigned char y_value;
      unsigned char color_g_value;
      unsigned char top_y_value;
    };
    union {
      unsigned char result_data3;
      unsigned char width;
      unsigned char color_b_value;
      unsigned char bot_x_value;
    };
    union {
      unsigned char result_data4;
      unsigned char height;
      unsigned char bot_y_value;
    };
    union {
      unsigned char result_data5;
      unsigned char color;
      unsigned char label;
    };
  } vision_result[MU_MAX_RESULT];
} MuVsVisionState;

#endif /* ARDUINO_LIB_MUVISIONSENSOR_SRC_MUVISIONSENSOR_TYPE_H_ */
