//
//  DocomoSdkServiceError.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <DOCOMOSDKCommon/RestApiResponse.h>
#import <DOCOMOSDKCommon/SdkError.h>

/**
 エラー情報
 
 
 @enum Docomo iOS SDK Error Codes
 */
typedef enum DocomoSdkServiceErrorType : NSInteger
{
    DocomoSdkServiceNormal = 0,
    DocomoSdkServiceErrorParam = -1
}DocomoSdkServiceErrorType;

typedef enum DocomoSdkCommonErrorType : NSInteger
{
    BAD_PARAMETER = 1,
    UNAUTHORIZED = 2,
    INTERNAL_ERROR = 3,
    CONNECTION_ERROR = 4,
    FORBIDDEN = 5,
    SERVER_ERROR =6
}DocomoSdkCommonErrorType;

/**
 */
typedef enum DocomoSdkHttpErrorType : NSInteger{
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_FORBIDDEN = 403,
}DocomoSdkHttpErrorType;

/**
 エラー情報
 
 
 パラメータチェック結果をエラー情報に設定する。
 パラメータエラーの場合、codeに DocomoSdkServiceErrorParamを設定する。
 */
@interface DocomoSdkServiceError : SdkError

/** レスポンス情報 */
@property RestApiResponse * response;

/** レスポンスボディデータ */
@property NSData * bodyData;

/** iOSエラー情報 */
//@property NSError * error;

/** 必須のエラーメッセージ。*/
extern NSString * const ERROR_MSG_PARAMETER;
/** サーバから予期しないエラーを受信しました。 */
extern NSString * const ERROR_MSG_RECV_UNEXPECTED;
/** サーバからのレスポンスデータが不正な場合のメッセージ。*/
extern NSString * const ERROR_MSG_RECV_INVALID;
/** パラメータ不正の場合 */
extern NSString * const ERROR_MSG_ILLEGALARG;
/** SDK 内部でエラーが発生 */
extern NSString * const ERROR_MSG_SDK_FAIL;

/** SDK 内部でエラーが発生 */
extern NSString * const DOMAIN_SDK_FAIL;
/** サーバでエラーが発生 */
extern NSString * const DOMAIN_SERVER_ERROR;

/**
 初期化処理
 @return id
 */
-(id)init;

/**
 レスポンスエラーチェック
 
 @param data 認識結果取得レスポンスボディ
 @param response httpレスポンス
 @param error エラー情報
 @param enablerCode SDKイネーブラーコード３桁
 
 @return エラー情報（エラーでない場合はnilを返す。各SDK固有のエラーチェックを行うこと。）
 */
+(DocomoSdkServiceError *)responseCheck:(NSData *)data
                               response:(NSURLResponse *)response
                                  error:(NSError *)error
                            enablerCode:(NSInteger)enablerCode;

@end
