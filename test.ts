function showTrafficCardResult () {
    if (muvision.detected(MuId.Mu00, MuVsMessageVisionType.kVisionTrafficCard)) {
        serial.writeLine("Traffic dectect")
        serial.writeValue("L", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionTrafficCardDetect, muvision.Params.Lable))
        serial.writeValue("X", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionTrafficCardDetect, muvision.Params.Horizontal))
        serial.writeValue("Y", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionTrafficCardDetect, muvision.Params.Vertical))
        serial.writeValue("W", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionTrafficCardDetect, muvision.Params.Width))
        serial.writeValue("H", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionTrafficCardDetect, muvision.Params.Height))
        if (muvision.trafficCardType(MuId.Mu00, muvision.TrafficCardType.TrafficCardForward)) {
            serial.writeLine("Forward")
        }
        if (muvision.trafficCardType(MuId.Mu00, muvision.TrafficCardType.TrafficCardLeft)) {
            serial.writeLine("Left")
        }
        if (muvision.trafficCardType(MuId.Mu00, muvision.TrafficCardType.TrafficCardRight)) {
            serial.writeLine("Right")
        }
        if (muvision.trafficCardType(MuId.Mu00, muvision.TrafficCardType.TrafficCardTURN_AROUND)) {
            serial.writeLine("Turn around")
        }
        if (muvision.trafficCardType(MuId.Mu00, muvision.TrafficCardType.TrafficCardPark)) {
            serial.writeLine("Park")
        }
    }
}
function showShapeCardResult () {
    if (muvision.detected(MuId.Mu00, MuVsMessageVisionType.kVisionShapeCard)) {
        serial.writeLine("shape dectect")
        serial.writeValue("L", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionShapeCardDetect, muvision.Params.Lable))
        serial.writeValue("X", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionShapeCardDetect, muvision.Params.Horizontal))
        serial.writeValue("Y", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionShapeCardDetect, muvision.Params.Vertical))
        serial.writeValue("W", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionShapeCardDetect, muvision.Params.Width))
        serial.writeValue("H", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionShapeCardDetect, muvision.Params.Height))
        if (muvision.shapeCardType(MuId.Mu00, muvision.ShapeCardType.ShapeCardTick)) {
            serial.writeLine("Check")
        }
        if (muvision.shapeCardType(MuId.Mu00, muvision.ShapeCardType.ShapeCardCross)) {
            serial.writeLine("Cross")
        }
        if (muvision.shapeCardType(MuId.Mu00, muvision.ShapeCardType.ShapeCardCircle)) {
            serial.writeLine("Circle")
        }
        if (muvision.shapeCardType(MuId.Mu00, muvision.ShapeCardType.ShapeCardSquare)) {
            serial.writeLine("Square")
        }
        if (muvision.shapeCardType(MuId.Mu00, muvision.ShapeCardType.ShapeCardTriangle)) {
            serial.writeLine("Triangle")
        }
    }
}
function showNumCardResult () {
    if (muvision.detected(MuId.Mu00, MuVsMessageVisionType.kVisionNumberCard)) {
        serial.writeLine("Number dectect")
        serial.writeValue("L", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionNumCardDetect, muvision.Params.Lable))
        serial.writeValue("X", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionNumCardDetect, muvision.Params.Horizontal))
        serial.writeValue("Y", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionNumCardDetect, muvision.Params.Vertical))
        serial.writeValue("W", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionNumCardDetect, muvision.Params.Width))
        serial.writeValue("H", muvision.visionValue(MuId.Mu00, muvision.VisionType.VisionNumCardDetect, muvision.Params.Height))
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard1)) {
            serial.writeLine("One")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard2)) {
            serial.writeLine("Two")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard3)) {
            serial.writeLine("Three")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard4)) {
            serial.writeLine("Four")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard5)) {
            serial.writeLine("Five")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard6)) {
            serial.writeLine("Six")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard7)) {
            serial.writeLine("Senven")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard8)) {
            serial.writeLine("Eight")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard9)) {
            serial.writeLine("Number")
        }
        if (muvision.numberCardType(MuId.Mu00, muvision.NumCardType.NumCard0)) {
            serial.writeLine("Zero")
        }
    }
}
function showLightSensorResult () {
    serial.writeValue("proximity", muvision.lsReadProximity(MuId.Mu00))
    serial.writeValue("als", muvision.lsReadAmbientLight(MuId.Mu00))
}
// Initialized MU
muvision.begin(MuId.Mu00, MuVsMode.kI2CMode)
muvision.setDefault(MuId.Mu00)
// Set LED color
muvision.ledSetColor(MuId.Mu00, MuVsLed.kLedAll, MuVsLedColor.kLedYellow, MuVsLedColor.kLedWhite)
// Enable algorithm
muvision.visionBegin(MuId.Mu00, MuStatus.Enable, MuVsMessageVisionType.kVisionTrafficCard)
muvision.visionBegin(MuId.Mu00, MuStatus.Enable, MuVsMessageVisionType.kVisionShapeCard)
muvision.visionBegin(MuId.Mu00, MuStatus.Enable, MuVsMessageVisionType.kVisionNumberCard)
// Set vision level
muvision.visionSetLevel(MuId.Mu00, MuVsMessageVisionType.kVisionShapeCard, MuVsVisionLevel.kLevelAccuracy)
muvision.visionSetLevel(MuId.Mu00, MuVsMessageVisionType.kVisionTrafficCard, MuVsVisionLevel.kLevelAccuracy)
muvision.visionSetLevel(MuId.Mu00, MuVsMessageVisionType.kVisionNumberCard, MuVsVisionLevel.kLevelAccuracy)
// Set camera digital zoom
muvision.cameraSetZoom(MuId.Mu00, MuVsCameraZoom.kZoom2)
// Set camera fps
muvision.cameraSetFPS(MuId.Mu00, true)
// Enable light sensor
muvision.lsBegin(MuId.Mu00, MuStatus.Enable, MuLsType.LsProximity)
muvision.lsBegin(MuId.Mu00, MuStatus.Enable, MuLsType.LsAmbientLight)
// Set light sensor sensitivity
muvision.lsSetSensitivity(MuId.Mu00, MuVsLsSensitivity.kSensitivity2)
basic.forever(function () {
    showShapeCardResult()
    showNumCardResult()
    showTrafficCardResult()
    showLightSensorResult()
})
