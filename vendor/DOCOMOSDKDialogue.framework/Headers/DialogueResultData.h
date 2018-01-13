//
//  DialogueResultData.h
//  docomo-dialogue-ios-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
//#import "DialogueMessageData.h"

/**
 雑談対話 SDK： 回答データクラス。
 */
@interface DialogueResultData : NSObject

/** システムの返答。 */
@property NSString * utt;

/** 音声合成用読み出力。 */
@property NSString * yomi;

/** モード。 */
@property NSString * mode;

/** 対話番号。 */
@property NSInteger da;

/** コンテキストID。 */
@property NSString * context;

/**
 初期化


 @return id
 */
-(id)init;


@end
