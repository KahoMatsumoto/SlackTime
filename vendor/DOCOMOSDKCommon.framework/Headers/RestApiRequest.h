//
//  RestApiRequest.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <DOCOMOSDKCommon/RestApiRequestHeader.h>
#import <DOCOMOSDKCommon/RestApiBody.h>

/**
 RestApiリクエスト。
 
 
 リクエストに設定する情報を格納する。
 */
@interface RestApiRequest : NSObject

/**
 RestApiリクエストヘッダ情報
 
 @see RestApiRequestHeader
 */
@property RestApiRequestHeader * requestHeader;

/**
 RestApiリクエストボディ情報
 
 @see RestApiBody
 */
@property RestApiBody * requestBody;

@end
