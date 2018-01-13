//
//  DialogueRequestParam.h
//  docomo-dialogue-ios-sdk
//  (c) 2014 NTT DOCOMO, INC. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import "DialogueError.h"

/**
 雑談対話 SDK： 質問文問い合わせリクエスト用データクラス。
 */
@interface DialogueRequestParam : NSObject

/** ユーザ発話 */
@property NSString * utt;

/** コンテキストID */
@property NSString * context;

/** ユーザのニックネーム */
@property NSString * nickname;

/** ユーザのニックネームの読み方 */
@property NSString * nickname_y;

/** ユーザの性別 */
@property NSString * sex;

/** ユーザの血液型 */
@property NSString * bloodtype;

/** ユーザの誕生日(年) */
@property NSInteger birthdateY;

/** ユーザの誕生日(月) */
@property NSInteger birthdateM;

/** ユーザの誕生日(日) */
@property NSInteger birthdateD;

/** ユーザの年齢 */
@property NSInteger age;

/** ユーザの星座 */
@property NSString * constellations;

/** ユーザの場所 */
@property NSString * place;

/** モード */
@property NSString * mode;

/** キャラクタ*/
@property NSInteger character;

/**
 初期化
 
 ＠return id
 */
-(id)init;

/**
 リクエストデータの必須パラメータチェックを行う。
 
 @return nil:正常, DialogueErrorParam：パラメータ不正
 */
-(DialogueError *)check;


/**
 リクエストデータを JSON 形式に変換する
 
 @return Json形式リクエストデータ, nil:変換失敗
 */
-(NSData *)makeJson;


@end
