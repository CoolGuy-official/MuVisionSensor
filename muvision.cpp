#include "pxt.h"
#include "MuVisionSensor3/MuVisionSensor.h"
#include "MuVisionSensor3/MuVisionSensor3_AT.h"

MuVisionSensor* MU[4]={nullptr};

enum MuId {
    //% block="MU00"
    Mu00=0,
    //% block="MU01"
    Mu01,
    //% block="MU10"
    Mu10,
    //% block="MU11"
    Mu11
};

enum MuStatus {
    //% block="enable"
    Enable=1,
    //% block="disable"
    Eisable=0
};

enum MuLsType {
    //% block="proximity detect"
    LsProximity=       1,
    //% block="ambient light detect"
    LsAmbientLight=    2,
    //% block="gesture detect"
    LsGesture=         8,
};

enum MuAtMode {
    //%block="STA"
    ModeSTA,
    //%block="AP"
    ModeAP,
};

//% color="#ff6600" weight=50 icon="\uf110"
namespace muvision {

    /**
     * Initialize MU.
     */
    //% blockId=mu3_begin block="initialize%id|port%port"
    //% group="Settings"
    void begin(MuId id, MuVsMode port) {
        if (!MU[id]) {
            MU[id] = new MuVisionSensor(0x60+id);
        }
        if (port == kSerialMode) {
            MU[id]->begin(&uBit.serial);
        } else if (port == kI2CMode) {
            MU[id]->begin(&uBit.i2c);
        }
    }

    /**
     * Reset MU.
     */
    //% blockId=mu3_set_default block="%id|restore default settings"
    //% group="Settings"
    void setDefault(MuId id){
        while(MU[id]->SensorSetDefault()!=MU_OK);
    }

    /**
     * MU vision begin.
     */
    //% blockId=mu3_vision_begin block="%id|%enable|algorithm%type"
    //% group="Settings"
    void visionBegin(MuId id, MuStatus status, MuVsMessageVisionType type){
        MuVisionSensor *mu = MU[id];
        if (status) {
            while(mu->VisionBegin((MuVisionType)visionTypeEnumToMacro(type))!=MU_OK);
        } else {
            mu->VisionEnd((MuVisionType)visionTypeEnumToMacro(type));
        }
    }

    /**
     * set led color.
     * @param id MU id
     * @param led led type.
     * @param detected_color led color while sensor detected target.
     * @param undetected_color led color while sensor undetected target.
     */
    //% blockId=mu3_led_set_color block="%id|LED %led|when detected %detected_color|when undetected %undetected_color"
    //% weight=200 inlineInputMode=inline
    //% group="Settings" advanced=true
    void ledSetColor(MuId id, MuVsLed led, MuVsLedColor detected_color, MuVsLedColor undetected_color) {
        if (detected_color == undetected_color) {
            while(MU[id]->LedSetMode(led, 1, 1) != MU_OK);
        } else {
            while(MU[id]->LedSetMode(led, 0, 0) != MU_OK);
        }
        while(MU[id]->LedSetColor(led, detected_color, undetected_color, 1) != MU_OK);
    }
    /**
     * set vision level.
     * @param id MU id
     * @param type vision type
     * @param level vision level
     */
    //% blockId=mu3_vision_set_level block="%id|algorithm%VISION_TYPE|Level%level"
    //% group="Settings" advanced=true
    void visionSetLevel(MuId id, MuVsMessageVisionType type, MuVsVisionLevel level){
        while(MU[id]->VisionSetLevel((MuVisionType)visionTypeEnumToMacro(type), level) != MU_OK);
    }
    /**
     * set camera zoom.
     * @param id MU id
     * @param zoom zoom value.
     */
    //% blockId=mu3_camera_set_zoom block="%id|digital zoom%level"
    //% group="Settings" advanced=true
    void cameraSetZoom(MuId id, MuVsCameraZoom zoom) {
        while(MU[id]->CameraSetZoom(zoom) != MU_OK);
    }

    /**
     * set camera white balance.
     * @param id MU id
     * @param wb white balance type.
     */
    //% blockId=mu3_camera_set_awb block="%id|white balance%wb"
    //% group="Settings" advanced=true
    void cameraSetAwb(MuId id, MuVsCameraWhiteBalance wb) {
        while(MU[id]->CameraSetAwb(wb) != MU_OK);
    }
    /**
     * set camera FPS.
     * @param id MU id
     * @param on FPS type.
     */
    //% blockId=mu3_camera_set_fps block="%id|high FPS mode$on"
    //% on.shadow="toggleOnOff" on.defl="true"
    //% group="Settings" advanced=true
    void cameraSetFPS(MuId id, bool on) {
        while(MU[id]->CameraSetFPS(MuVsCameraFPS(on)) != MU_OK);
    }
    /**
     * Enable/Disable light sensor function,gesture detect can not used with other functions.
     * @param id MU id
     * @param status enable/disable function
     * @param[in] ls_type Function type
     */
    //% blockId=MU3LsBegin block="%id|light sensor|%status|%ls_type"
    //% group="Light Sensor"
    void lsBegin(MuId id, MuStatus status, MuLsType ls_type) {
        if (status == Enable) {
            MU[id]->LsBegin(ls_type);
        } else {
            MU[id]->LsEnd(ls_type);
        }
    }
    /**
     * Light snesor set sensitivity.
     * @param id MU id
     * @param sensitivity sensitivity
     */
    //% blockId=MU3LsSetSensitivity block="%id|light sensor|set sensitivity%sensitivity"
    //% group="Light Sensor"
    void lsSetSensitivity(MuId id, MuVsLsSensitivity sensitivity) {
        MU[id]->LsSetSensitivity(sensitivity);
    }
    /**
     * @brief Read proximity data.
     * @param id MU id
     * @retval proximity data, 0~255.
     */
    //% blockId=MU3LsReadProximity block="%id|light sensor|read proximity"
    //% group="Light Sensor"
    uint8_t lsReadProximity(MuId id) {
        return MU[id]->LsReadProximity();
    }
    /**
     * @brief Read ambient light sensor data.
     * @param id MU id
     * @retval ambient light sensor data, 0~65536.
     */
    //% blockId=MU3LsReadAmbientLight block="%id|light sensor|read ambient light"
    //% group="Light Sensor"
    uint16_t lsReadAmbientLight(MuId id) {
        return MU[id]->LsReadAmbientLight();
    }
    // /**
    //  * Read light sensor color data.
    //  * @param id MU id
    //  * @param color_t kLsColorLabel:      get color label
    //  *                kLsColorRed:        get RGB R value(0~255)
    //  *                kLsColorGreen:      get RGB G value(0~255)
    //  *                kLsColorBlue:       get RGB B value(0~255)
    //  *                kLsColorHue:        get HSV H value(0~360)
    //  *                kLsColorSaturation: get HSV S value(0~255)
    //  *                kLsColorValue:      get HSV V value(0~255)
    //  * @retval Light sensor detected color data value
    //  */
    // //% blockId=mu3_ls_read_color block="%id|light sensor|read color%color_t"
    // //% group="Light Sensor"
    // //% deprecated=true
    // uint16_t LsReadColor(MuId id, MuVsLsColorType color_t) {
    //     return MU[id]->LsReadColor(color_t);
    // }
    /**
     * get vision result data, this function will update vision result automatically.
     * @param id MU id
     * @param vision_type: vision type.
     * @param object_inf:  object information
    */
    //% blockId=mu3_get_value
    int getValue(MuId id, MuVsMessageVisionType vision_type, MuVsObjectInf object_inf) {
        return MU[id]->GetValue((MuVisionType)visionTypeEnumToMacro(vision_type), object_inf);
    }
    /**
     * @brief  write vision parameter.
     * @param id MU id
     * @param vision_type vision type.
     * @param object_inf  object information
     * @param value  value
     */
    //% blockId=mu3_write
    void write(MuId id, MuVsMessageVisionType vision_type, MuVsObjectInf object_inf, int value) {
        MU[id]->write((MuVisionType)visionTypeEnumToMacro(vision_type), object_inf, value);
    }
    /**
     * @brief Read gesture sensor data.
     * @retval Gesture witch MU detected.
     */
    //% blockId=mu3_ls_read_gesture
    MuVsLsGesture lsReadGesture(MuId id) {
        return MU[id]->LsReadGesture();
    }
}

//% color="#11ACEF" icon="\uf1eb"
namespace muvisionAT {
    int read8() {
        uint64_t time = system_timer_current_time();  
        int c = 0;
        do {
            c = uBit.serial.read(MicroBitSerialMode::ASYNC);
        } while(c==MICROBIT_NO_DATA && system_timer_current_time()-time<1000);  
        if (system_timer_current_time()-time>=1000) {    
            return -1;  
        }
        return c;
    }
    void write8(uint8_t c) {
        uBit.serial.sendChar(c);
    }
    MuVisionSensor3_AT MU3_AT(read8, write8);

    /**
     * Read SIP 
     */
    //% blockId=mu3_at_wifi_sip block="MU|read SIP"
    //% group="MUVisionSensor3_AT"
    String wifiSIP() {
        return MU3_AT.WifiSIP();
    }
    /**
     * Read CIP 
     */
    //% blockId=mu3_at_wifi_cip block="MU|read CIP"
    //% group="MUVisionSensor3_AT"
    String wifiCIP() {
        return MU3_AT.WifiCIP();
    }
    /**
     * MU AT wifi set
     */
    //% blockId=mu3_at_wifi_set block="MU|WiFi set|ssid|%ssid|password|%password|apmode|%apmode"
    //% group="MUVisionSensor3_AT"
    void wifiSet(String ssid, String password, MuAtMode apmode) {
        switch (apmode) {
            case ModeSTA:
                MU3_AT.WifiSet(ssid->getUTF8Data(), password->getUTF8Data(), "STA");
                break;
            case ModeAP:
                MU3_AT.WifiSet(ssid->getUTF8Data(), password->getUTF8Data(), "AP");
                break;
            default:
                break;
        }
    }
    /**
     * MU AT wifi connect, return `true`=success
     */
    //% blockId=mu3_at_wifi_con block="MU|WiFi connect|%status"
    //% status.shadow="toggleOnOff" status.defl="true"
    //% group="MUVisionSensor3_AT"
    bool wifiCon(bool status) {
        if (status) {
            return !MU3_AT.WifiCon("1");
        } else {
            return !MU3_AT.WifiCon("0");
        }
    }
    /**
     * MU AT wifi set target IP&port 
     */
    //% blockId=mu3_at_wifi_udp block="MU|WiFi set target IP|%ip|port|%port"
    //% group="MUVisionSensor3_AT"
    void wifiUDP(String ip, String port) {
        MU3_AT.WifiUDP(ip->getUTF8Data(), port->getUTF8Data());
    }
    /**
     * MU AT wifi read data 
     */
    //% blockId=mu3_at_wifi_read block="MU|WiFi read"
    //% group="MUVisionSensor3_AT"
    int wifiRead() {
        if (MU3_AT.available()) {
            return MU3_AT.read8();;
        }
        return read8();
    }
}
