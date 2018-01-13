//
//  RestApiBody.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 RestApiボディ情報。
 
 
 ボディに設定する情報を格納する。
 */
@interface RestApiBody : NSObject

/**
 コンテントタイプ
 
 */
@property NSString * contentType;

/**
 ボディデータ
 
 */
@property NSData * bodyData;

/**
 String形式のボディデータ
 
 */
@property NSString * bodystring;

/**
 ボディデータ格納先のファイルパス
 
 */
@property NSString * filePath;

/**
 有効なボディデータが設定されているか判定する。 

 Content-Typeが設定されていない場合、 またはfilePath, bodyData, bodyStringが空の場合 trueを返却する。
 @return true：ボディデータが空の場合
 */
-(Boolean) isEmpty;

@end
