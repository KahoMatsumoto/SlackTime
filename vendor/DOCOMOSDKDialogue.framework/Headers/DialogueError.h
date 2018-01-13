//
//  DialogueError.h
//  docomo-dialogue-ios-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 */
typedef enum DialogueErrorType : NSInteger
{
    DialogueErrorParam             = 100501,  // パラメータ不正
    DialogueErrorAuth              = 100502,  // 認証失敗
    DialogueErrorSdkfail           = 100503,  // SDK内処理失敗
    DialogueErrorTimeout           = 100504,  // タイムアウト
    DialogueErrorCongestion        = 100505,  // 輻輳規制
    DialogueErrorServer            = 100506,  // その他サーバーエラー
    DialogueErrorData              = 100507,   // レスポンスデータエラー
    DialogueErrorAuthExpired       = 100508, // OAuth アクセストークン期限切れ
    DialogueErrorAuthRelationship  = 100509 // OAuth 関連エラー
    
}DialogueErrorType;

/**
 雑談対話エラー情報
 文字認識SDKのリクエスト送信の結果によりエラー定数を設定する。
 
 
 
 エラー定数
 
 
 DialogueErrorParam パラメータ不正
 
 DialogueErrorAuth  認証失敗
 
 DialogueErrorSdkfail  SDK内処理失敗
 
 DialogueErrorTimeout  タイムアウト
 
 DialogueErrorCongestion  一時利用不可
 
 DialogueErrorServer  その他サーバーエラー
 
 DialogueErrorData  レスポンスデータエラー
 
 */


@interface DialogueError : NSError

@end
