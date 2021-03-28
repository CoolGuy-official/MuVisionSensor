// Auto-generated. Do not edit.


    declare const enum MuVsMessageVisionType {
    //% block="🌈 Color Block"
    kVisionColorDetect = 1,
    //% block="🌈 Color Recognition"
    kVisionColorRecog = 2,
    //% block="⚽ Ball Detect"
    kVisionBall = 3,
    //% block="👥 Body Detect"
    kVisionBody = 5,
    //% block="🔳 Shape Card"
    kVisionShapeCard = 6,
    //% block="🔳 Traffic Card"
    kVisionTrafficCard = 7,
    //% block="🔳 Number Card"
    kVisionNumberCard = 8,
    }


    declare const enum MuVsLedColor {
    //% block="off"
    kLedClose = 0,
    //% block="red"
    kLedRed = 1,
    //% block="green"
    kLedGreen = 2,
    //% block="yellow"
    kLedYellow = 3,
    //% block="blue"
    kLedBlue = 4,
    //% block="purple"
    kLedPurple = 5,
    //% block="cyan"
    kLedCyan = 6,
    //% block="white"
    kLedWhite = 7,
    }


    declare const enum MuVsLed {
    //% block="all"
    kLedAll = 2,
    //% block="1"
    kLed1 = 0,
    //% block="2"
    kLed2 = 1,
    }


    declare const enum MuVsMode {
    //% block="I2C"
    kI2CMode = 1,
    //% block="Serial"
    kSerialMode = 0,
    }


    declare const enum MuVsBaudrate {
    kBaud9600 = 0x00,
    kBaud19200 = 0x01,
    kBaud38400 = 0x02,
    kBaud57600 = 0x03,
    kBaud115200 = 0x04,
    kBaud230400 = 0x05,
    kBaud460800 = 0x06,
    kBaud921600 = 0x07,
    }


    declare const enum MuVsObjectInf {
    //% block="status"
    kStatus = 0,
    //% block="x position"
    kXValue = 1,
    //% block="y position"
    kYValue = 2,
    //% block="width"
    kWidthValue = 3,
    //% block="height"
    kHeightValue = 4,
    //% block="label"
    kLabel = 5,
    //% block="red channel"
    kRValue = 6,
    //% block="green channel"
    kGValue = 7,
    //% block="blue channel"
    kBValue = 8,
    }


    declare const enum MuVsCameraZoom {
    //% block="Auto"
    kZoomDefault = 0,
    //% block="Level1"
    kZoom1 = 1,
    //% block="Level2"
    kZoom2 = 2,
    //% block="Level3"
    kZoom3 = 3,
    //% block="Level4"
    kZoom4 = 4,
    //% block="Level5"
    kZoom5 = 5,
    }


    declare const enum MuVsCameraWhiteBalance {
    //% block="auto"
    kAutoWhiteBalance = 0,
    //% block="lock"
    kLockWhiteBalance = 1,
    //% block="white"
    kWhiteLight = 2,
    //% block="yellow"
    kYellowLight = 3,
    }


    declare const enum MuVsVisionLevel {
    //% block="auto"
    kLevelDefault = 0,
    //% block="speed"
    kLevelSpeed = 1,
    //% block="balance"
    kLevelBalance = 2,
    //% block="accuracy"
    kLevelAccuracy = 3,
    }


    declare const enum MuVsLsSensitivity {
    //% block="auto"
    kSensitivityDefault = 0,
    //% block="low"
    kSensitivity1 = 1,
    //% block="middle"
    kSensitivity2 = 2,
    //% block="high"
    kSensitivity3 = 3,
    }


    declare const enum MuVsLsGesture {
    //%block="upward"
    kGestureUp = 1,
    //%block="downward"
    kGestureDown = 2,
    //%block="leftward"
    kGestureLeft = 3,
    //%block="rightward"
    kGestureRight = 4,
    //%block="push"
    kGesturePush = 5,
    //%block="pull"
    kGesturePull = 6,
    }


    declare const enum MuVsLsColorType {
    //% block="color label"
    kLsColorLabel = 0,
    //% block="red channel"
    kLsColorRed = 1,
    //% block="green channel"
    kLsColorGreen = 2,
    //% block="blue channel"
    kLsColorBlue = 3,
    //% block="hue"
    kLsColorHue = 4,
    //% block="saturation"
    kLsColorSaturation = 5,
    //% block="value"
    kLsColorValue = 6,
    }


    declare const enum MuId {
    //% block="MU00"
    Mu00 = 0,
    //% block="MU01"
    Mu01 = 1,
    //% block="MU10"
    Mu10 = 2,
    //% block="MU11"
    Mu11 = 3,
    }


    declare const enum MuStatus {
    //% block="enable"
    Enable = 1,
    //% block="disable"
    Eisable = 0,
    }


    declare const enum MuLsType {
    //% block="proximity detect"
    LsProximity = 1,
    //% block="ambient light detect"
    LsAmbientLight = 2,
    //% block="gesture detect"
    LsGesture = 8,
    }


    declare const enum MuAtMode {
    //%block="STA"
    ModeSTA = 0,
    //%block="AP"
    ModeAP = 1,
    }
declare namespace muvision {
}
declare namespace muvisionAT {
}

// Auto-generated. Do not edit. Really.
