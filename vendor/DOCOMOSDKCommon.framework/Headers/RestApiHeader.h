//
//  RestApiHeader.h
//  docomo-common-iso-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/**
 RestApiヘッダ情報。
 
 
 ヘッダに設定する情報を格納する。
 */
@interface RestApiHeader : NSObject

/**
 ヘッダ情報
 
 */
@property NSMutableDictionary * headerInfo;

@end
