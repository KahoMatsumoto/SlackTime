//
//  Dialogue.h
//  docomo-dialogue-ios-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <DOCOMOSDKCommon/SdkError.h>
#import "DialogueResultData.h"
#import "DialogueError.h"
#import "DialogueRequestParam.h"

/**
 雑談対話 SDK： 雑談対話問い合わせ処理クラス。
 */
@interface Dialogue : NSObject

@property NSTimeInterval timeoutInterval;


/**
 初期化

 
 @return id
 */
-(id)init;

/**
 雑談対話の問い合わせ処理要求を行う。
 
 レスポンスの受信が完了した時に行う処理を応答受信完了時処理ハンドラ（completionHandler）に登録する。
 
 応答受信完了時処理ハンドラからはgetResultDataFromDataを呼び出し結果データを得る。
 
 @return 雑談対話SDKエラー情報
 @see DialogueError
 
 @param requestParam 雑談対話リクエスト情報
 @see DialogueRequestParam
 
 @param onComplete 応答受信完了時処理
 @param onError 応答受信エラー時処理
 @see DialogueResultData 回答データ
 */
-(DialogueError *)request:(DialogueRequestParam *)requestParam
               onComplete:(void (^)(DialogueResultData *))onComplete
                  onError:(void (^)(SdkError *))onError;

/**
 雑談対話の問い合わせ処理要求を行う。
 
 レスポンスの受信が完了した時に行う処理を応答受信完了時処理ハンドラ（completionHandler）に登録する。
 
 応答受信完了時処理ハンドラからはgetResultDataFromDataを呼び出し結果データを得る。
 
 @return 雑談対話SDKエラー情報
 @see DialogueError
 
 @param requestParam 雑談対話リクエスト情報
 @param accessToken OAuth で取得したアクセストークン
 @see DialogueRequestParam
 
 @param onComplete 応答受信完了時処理
 @param onError 応答受信エラー時処理
 @see DialogueResultData 回答データ
 */
-(DialogueError *)request:(DialogueRequestParam *)requestParam
              accessToken:(NSString *)accessToken
               onComplete:(void (^)(DialogueResultData *))onComplete
                  onError:(void (^)(SdkError *))onError;


@end

