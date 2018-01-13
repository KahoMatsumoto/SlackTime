//
//  DocomoSdkServiceBase.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <DOCOMOSDKCommon/RestApiRequest.h>
#import <DOCOMOSDKCommon/DocomoSdkServiceError.h>

/**
 DOCOMO iOS SDK サービス基底クラス
 
 
 http GET/POST/DELETEリクエスト送信
 */
@interface DocomoSdkServiceBase : NSObject

@property NSTimeInterval timeoutInterval;

/**
 getメソッド送信

 @return エラー情報（パラメータチェック結果が設定される。送信を行った場合はnilを返す。）
 @see DocomoSdkServiceError
 
 @param request リクエスト
 @see RestApiRequest
 
 @param onComplete 受信完了時処理ハンドラー
 @param onError 受信エラー時処理ハンドラー
 @param enablerCode Docomo-SDKのイネーブラコード
 */
-(DocomoSdkServiceError *)get:(RestApiRequest *)request
                   onComplete:(void(^)(NSData *, NSURLResponse *))onComplete
                      onError:(void(^)(DocomoSdkServiceError *))onError
                  enablerCode:(NSInteger)enablerCode;

/**
 postメソッド送信

 @return エラー情報（パラメータチェック結果が設定される。送信を行った場合はnilを返す。）
 @see DocomoSdkServiceError
 
 @param request リクエスト
 @see RestApiRequest
 
 @param onComplete 受信完了時処理ハンドラー
 @param onError 受信エラー時処理ハンドラー
 @param enablerCode Docomo-SDKのイネーブラコード
 */
-(DocomoSdkServiceError *)post:(RestApiRequest *)request
                    onComplete:(void(^)(NSData *, NSURLResponse *))onComplete
                       onError:(void(^)(DocomoSdkServiceError *))onError
                   enablerCode:(NSInteger)enablerCode;

/**
 deleteメソッド送信
 
 @return エラー情報（パラメータチェック結果が設定される。送信を行った場合はnilを返す。）
 @see DocomoSdkServiceError
 
 @param request リクエスト
 @see RestApiRequest
 
 @param onComplete 受信完了時処理ハンドラー
 @param onError 受信エラー時処理ハンドラー
 @param enablerCode Docomo-SDKのイネーブラコード
 */
-(DocomoSdkServiceError *)delete:(RestApiRequest *)request
                      onComplete:(void(^)(NSData *, NSURLResponse *))onComplete
                         onError:(void(^)(DocomoSdkServiceError *))onError
                     enablerCode:(NSInteger)enablerCode;

@end
