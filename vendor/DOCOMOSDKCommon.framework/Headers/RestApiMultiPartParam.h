//
//  RestApiMultiPartParam.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 マルチパート形式のリクエストパラメータに設定する情報
 */
@interface RestApiMultiPartParam : NSObject

typedef enum dataType : NSInteger
{
    /** データ種別不明 */
    DATA_TYPE_NONE = 0,
    /** データ種別文字列 */
    DATA_TYPE_STRING = 1,
    /** データ種別ファイル */
    DATA_TYPE_FILE = 2,
    /** データ種別文字列 */
    DATA_TYPE_BINARY = 3
}dataType;

/** データ種別 */
@property NSInteger type;
/** コンテンツタイプ */
@property NSString * contentType;
/** バイナリデータ */
@property NSData * binaryValue;
/** 値 */
@property NSString * value;
/** キー名 */
@property NSString * keyName;

/**
 * 初期化処理
 * @return id
 */
-(id)init;

/**
 * 文字列データで初期化
 *
 * @param value 文字列
 * @param keyName キー名
 * @return id
 */
-(id)initWithString:(NSString *)value keyName:(NSString *)keyName;

/**
 * ファイルデータで初期化
 *
 * @param filePath ファイルパス
 * @param keyName キー名
 * @param contentType コンテンツタイプ
 * @return id
 */
-(id)initWithFile:(NSString *)filePath keyName:(NSString *)keyName contentType:(NSString *)contentType;

/**
 * バイナリデータで初期化
 *
 * @param binaryValue バイナリデータ
 * @param keyName キー名
 * @param contentType コンテンツタイプ
 * @return id
 */
-(id)initWithBinary:(NSData *)binaryValue keyName:(NSString *)keyName contentType:(NSString *)contentType;


@end
