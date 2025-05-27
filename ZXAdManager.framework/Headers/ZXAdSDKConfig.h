//
//  ZXAdSDKConfig.h
//  ZXFramework
//
//  Created by lixiang on 2025/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, SDKEnv) {
    SDKDebug,
    SDKProduction
};

@interface ZXAdSDKConfig : NSObject


@property (nonatomic, copy) NSString *appID;
@property (nonatomic, assign) SDKEnv env;
@property (nonatomic, assign) NSTimeInterval timeout;
@property (nonatomic, assign) BOOL enableLog;
@property (nonatomic, assign) NSURLCacheStoragePolicy cachePolicy;



/**
 *  SDK版本
 */
@property (nonatomic, readonly) NSString *version;


+(NSString *)SDKVersion;

+ (instancetype)defaultConfig;
+(NSString *)getUUID;
+(NSString *)deviceSystemName;
+(NSString *)deviceSystemVersion;
+(NSString *)macAddress;
+(NSString *)getIDFA;

+ (NSString *)generateUniqueRequestID;

//时间戳
+(NSString *)getCurrentTimeString;
+ (BOOL)isEmpty:(id)object;

+ (NSString *)exchangeStringWithdict:(NSDictionary *)dict;
#pragma mark - 下载缓存图片
+ (void)downloadImageWithURL:(NSString *)urlString completion:(void (^)(UIImage *image))completion;
@end

NS_ASSUME_NONNULL_END
