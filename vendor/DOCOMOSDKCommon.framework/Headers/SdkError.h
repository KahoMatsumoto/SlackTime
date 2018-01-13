//
//  SdkError.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 エラー情報
 
 各SDKの非同期応答受信エラー時処理ハンドラで受け取るエラー情報。
 */
@interface SdkError : NSError

/** iOSエラー情報 */
@property NSError * error;

@end
