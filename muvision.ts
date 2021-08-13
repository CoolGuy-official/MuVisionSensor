//% color="#ff6600" weight=103 icon="\uf085"
namespace muvision {
    export enum VisionType {
        //% block="🌈 Color Block"
        VisionColorBlockDetect=1,
        //% block="⚽ Ball Detect"
        VisionBallDetect=3,
        //% block="👥 Body Detect"
        VisionBodyDetect=5,
        //% block="🔳 Shape Card"
        VisionShapeCardDetect=6,
        //% block="🔳 Traffic Card"
        VisionTrafficCardDetect=7,
        //% block="🔳 Number Card"
        VisionNumCardDetect=8
    }
    export enum CardType {
        //% block="🔳 Shape Card"
        VisionShapeCardDetect=6,
        //% block="🔳 Traffic Card"
        VisionTrafficCardDetect,
        //% block="🔳 Number Card"
        VisionNumCardDetect
    }
    export enum TrafficCardType {
        //% block="⬆ Forward"
        TrafficCardForward=1,
        //% block="⬅ Left"
        TrafficCardLeft,
        //% block="➡ Right"
        TrafficCardRight,
        //% block="🔙 Turn Around"
        TrafficCardTURN_AROUND,
        //% block="🅿️ Park"
        TrafficCardPark
    }
    export enum ShapeCardType {
        //% block="✔ Tick"
        ShapeCardTick=1,
        //% block="✖ Cross"
        ShapeCardCross,
        //% block="⭕ Circle"
        ShapeCardCircle,
        //% block="◻ Square"
        ShapeCardSquare,
        //% block="🛆 Triangle"
        ShapeCardTriangle
    }
    export enum ColorType {
        //% block="black"
        Black=1,
        //% block="white"
        White,
        //% block="red"
        Red,
        //% block="yellow"
        Yellow,
        //% block="green"
        Green,
        //% block="cyan"
        Cyan,
        //% block="blue"
        Blue,
        //% block="purple"
        Purple,
        //% block="others"
        Unkown=0
    }
    export enum NumCardType {
        //% block="1"
        NumCard1=1,
        //% block="2"
        NumCard2,
        //% block="3"
        NumCard3,
        //% block="4"
        NumCard4,
        //% block="5"
        NumCard5,
        //% block="6"
        NumCard6,
        //% block="7"
        NumCard7,
        //% block="8"
        NumCard8,
        //% block="9"
        NumCard9,
        //% block="0"
        NumCard0=0,
    }
    export enum Params {
        //% block="horizontal"
        Horizontal=1,
        //% block="vertical"
        Vertical,
        //% block="width"
        Width,
        //% block="height"
        Height,
        //% block="label"
        Lable
    }
    export enum ColorParams {
        //% block="red channel"
        RedChannal=6,
        //% block="green channel"
        GreenChannal=7,
        //% block="blue channel"
        BlueChannal=8,
        //% block="label"
        Label=5
    }

    /**
     * Set color recognition recognition area size.
     * @param id MU id
     * @param width Recognition area width
     * @param height Recognition area height
     */
    //% blockId=mu3_color_rcg_set_region block="%id|🌈 Color Recognition set recognition region|width =%width|height =%height"
    //% width.min=0 width.max=100 width.defl=5
    //% height.min=0 height.max=100 height.defl=5
    //% group="Settings" advanced=true
    export function colorRcgSetRegion(id:MuId, width: number, height: number) {
        muvision.write(id, MuVsMessageVisionType.kVisionColorRecog, MuVsObjectInf.kWidthValue, width);
        muvision.write(id, MuVsMessageVisionType.kVisionColorRecog, MuVsObjectInf.kHeightValue, height);
    }
    /**
     * Set the minimum recognition size of the color block.
     * @param id MU id
     * @param width Color block min width
     * @param height Color block min height
     */
    //% blockId=mu3_color_block_set_min_size block="%id|🌈 Color Block set min recognition size|width =%width|height =%height"
    //% width.min=0 width.max=100 width.defl=5
    //% height.min=0 height.max=100 height.defl=5
    //% group="Settings" advanced=true
    export function colorBlockSetMinRecognitionSize(id:MuId, width:number, height:number) {
        muvision.write(id, MuVsMessageVisionType.kVisionColorDetect, MuVsObjectInf.kWidthValue, width);
        muvision.write(id, MuVsMessageVisionType.kVisionColorDetect, MuVsObjectInf.kHeightValue, height);
    }
    /**
     * Get vision status
     * @param id MU id
     * @param type vision type
     */
    //% blockId=mu3_detected block="%id|detected%type" color="#2E8B57"
    //% group="Functions"
    export function detected(id:MuId, type:MuVsMessageVisionType):boolean{
        return muvision.getValue(id, type, MuVsObjectInf.kStatus) ? true:false
    }
    let x_last = -1;
    let y_last = -1;
    /**
     * Set parameters, and get vision color recognition status.
     * @param id MU id
     * @param x Horizontal recognition center(from 0~100)
     * @param y Vertical recognition center(from 0~100)
     */
    //% blockId=mu3_color_rcg_detected block="%id|recognized coordinate|x =%x|y =%y|color" color="#2E8B57"
    //% x.min=0 x.max=100 x.defl=50
    //% y.min=0 y.max=100 y.defl=50
    //% group="Functions"
    export function colorRcgDetected(id:MuId,x:number,y:number):boolean{
        x = x>100 ? 100:(x<0 ? 0:x);
        y = y>100 ? 100:(y<0 ? 0:y);
        if (x != x_last) {
            x_last = x;
            muvision.write(id, MuVsMessageVisionType.kVisionColorRecog, MuVsObjectInf.kXValue, x);
        }
        if (y != y_last) {
            y_last = y;
            muvision.write(id, MuVsMessageVisionType.kVisionColorRecog, MuVsObjectInf.kYValue, y);
        }
        return muvision.getValue(id, MuVsMessageVisionType.kVisionColorRecog, MuVsObjectInf.kStatus) ? true:false
    }
    let label_last = -1;
    /**
     * Set parameters, and get vision color block status.
     * @param id MU id
     * @param label The color label you want to detect
     */
    //% blockId=mu3_get_color_block_detect block="%id|detected%color|color block" color="#2E8B57"
    //% group="Functions"
    export function colorBlockDetected(id:MuId,label:ColorType):boolean{
        if (label_last != label) {
            label_last = label;
            muvision.write(id, MuVsMessageVisionType.kVisionColorDetect, MuVsObjectInf.kLabel, label)
        }
        return muvision.getValue(id, MuVsMessageVisionType.kVisionColorDetect, MuVsObjectInf.kStatus) ? true:false
    }
    /**
     * Get vision result
     * @param id MU id
     * @param type Vision type
     * @param item Paramters type
     */
    //% block="get%id|algorithm%type|%item|value" color="#2E8B57"
    //% group="Functions"
    export function visionValue(id: MuId, type: VisionType, item: Params): number {
        return muvision.getValue(id, <number>type, <number>item)
    }
    /**
     * Get the result of vision color recognition.
     * @param id MU id
     * @param item Paramters type
     */
    //% block="get%id|algorithm 🌈 Color Recognition|%item" color="#2E8B57"
    //% group="Functions"
    export function colorRcgValue(id:MuId,item:ColorParams):number{
        return muvision.getValue(id, MuVsMessageVisionType.kVisionColorRecog, <number>item)
    }
    /**
     * Get the card type of shape card
     * @param id MU id
     * @param type Paramters type
     */
    //% blockId=mu3_shape_card_type block="get%id|algorithm 🔳 Shape Card|type =%type" color="#2E8B57"
    //% group="Functions"
    export function shapeCardType(id:MuId,type:ShapeCardType):boolean{
        return muvision.getValue(id, MuVsMessageVisionType.kVisionShapeCard, MuVsObjectInf.kLabel) == type
    }
    /**
     * Get the card type of traffic card
     * @param id MU id
     * @param type Paramters type
     */
    //% blockId=mu3_traffic_card_type block="get%id|🔳 Traffic Card|type =%type" color="#2E8B57"
    //% group="Functions"
    export function trafficCardType(id:MuId,type:TrafficCardType):boolean{
        return muvision.getValue(id, MuVsMessageVisionType.kVisionTrafficCard, MuVsObjectInf.kLabel) == type
    }
    /**
     * Get the card type of number card
     * @param id MU id
     * @param type Paramters type
     */
    //% blockId=mu3_number_card_type block="get%id|🔳 Number Card|type =%type" color="#2E8B57"
    //% group="Functions"
    export function numberCardType(id:MuId,type:NumCardType):boolean{
        return muvision.getValue(id, MuVsMessageVisionType.kVisionNumberCard, MuVsObjectInf.kLabel) == type
    }
    /**
     * Get the color of vision color recognition
     * @param id MU id
     * @param type Paramters type
     */
    //% blockId=mu3_color_rcg_type block="get%id|🌈 Color Recognition color =%color" color="#2E8B57"
    //% group="Functions"
    export function colorRecognizeType(id:MuId,color:ColorType):boolean{
        return muvision.getValue(id, MuVsMessageVisionType.kVisionColorRecog, MuVsObjectInf.kLabel) == color;
    }
    let gesture = 0;
    /**
     * Get the status of gesture detect
     * @param id MU id
     */
    //% blockId=mu3_gesture_detect block="%id|light sensor|is detected gesture" color="#ff6600"
    //% group="Light Sensor"
    export function gestureDetect(id:MuId):boolean{
        gesture = muvision.lsReadGesture(id);
        return gesture ? true:false;
    }
    /**
     * Get the gesture type of gesture detect
     * @param id MU id
     * @param type Gesture type
     */
    //% blockId=mu3_gesture_type block="%id|light sensor|get gesture =|%MuVsLsGesture" color="#ff6600"
    //% group="Light Sensor"
    export function gestureType(id:MuId, type:MuVsLsGesture):boolean{
        return gesture == type;
    }
}
//% color="#11ACEF" icon="\uf1eb" weight=102
namespace muvisionAT {}