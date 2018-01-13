//
//  RestApiMultiPartBody.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <DOCOMOSDKCommon/RestApiBody.h>

/**
 マルチパート形式のリクエストパラメータボディに設定する情報
 */
@interface RestApiMultiPartBody : RestApiBody

@property NSMutableArray * paramlist;

/**
 初期化処理
 
 @return id
 */
-(id)init;

/**
 * 文字列型のリクエストパラメータを設定する
 *
 * @param value 文字列データ
 * @param keyName キー値
 */
-(void)addStringData:(NSString *)value keyName:(NSString *)keyName;

/**
 * ファイル型のリクエストパラメータを設定する
 *
 * @param filePath ファイルパス
 * @param keyName キー値
 * @param contentType コンテンツタイプ
 */
-(void)addFileData:(NSString *)filePath keyName:(NSString *)keyName contentType:(NSString *)contentType;

/**
 * バイナリ型のリクエストパラメータを設定する
 *
 * @param binaryValue バイナリデータデータ
 * @param keyName キー値
 * @param contentType コンテンツタイプ
 */
-(void)addBinaryData:(NSData *)binaryValue keyName:(NSString *)keyName contentType:(NSString *)contentType;

/**
 * 有効なボディデータが設定されているか判定する。
 *
 * Content-Typeが設定されていない場合、 またはfilePath, bodyData, bodyStringが空の場合 trueを返却する。
 * @return true：ボディデータが空の場合
 */

-(Boolean) isEmpty;

@end
