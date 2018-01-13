//
//  AuthApiKey.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 APIキー認証情報。 
 
 
 APIキー認証の情報を格納する。
 SDK利用者はアプリ起動時に1回だけ認証情報初期化を行う必要がある。
 */
@interface AuthApiKey : NSObject

/**
 AuthApiKeyのインスタンスを取得する。

 @return AuthApikeyインスタンス
 */
+(AuthApiKey *)getInstance;

/**
 認証情報を初期化する。

 @param  apiKey APIキー
 */
+(void)initializeAuth:(NSString *)apiKey;

/**
 APIキーを取得する。

 @return APIキー
 */
+(NSString *)getAuthApiKey;

@end
