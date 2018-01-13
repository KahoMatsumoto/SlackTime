//
//  RestApiRequestHeader.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <DOCOMOSDKCommon/RestApiHeader.h>

/**
 RestApiリクエストヘッダ情報。
 
 
 ヘッダに設定する情報を格納する。
 @see RestApiHeader
 */
@interface RestApiRequestHeader : RestApiHeader

/**
 リクエストURL
 
 */
@property NSURL * url;

/**
 リクエストクエリパラメータ文字列
 
 */
@property NSString * queryString;

@end
