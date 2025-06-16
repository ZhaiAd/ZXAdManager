//
//  ZXAdManager.h
//  ZXAdManager
//
//  Created by admin on 2025/4/23.
//
#define HFILENAME_USED
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZXAdSDKConfig.h"



NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSInteger, ZXAdSDKPlatform) {
    AdSDKCHUANSHANJIA   =  0,
    AdSDKKUAISHOU       =  1,
    AdSDKBAIQINGTENG    =  2,
    AdSDKYOULIANGHUI    =  3,
    AdSDKZXKJ           =  4,
    AdSDKJINGMEI           =  5,
};

typedef NS_ENUM(NSInteger, ZXAdSDKType) {
    ZXAdSDKTypeFullScreen  =  0,    //开屏
    ZXAdSDKTypeExpressFeed,         //信息流
    ZXAdSDKTypeBanner,              //banner
    ZXAdSDKTypeExpressInterstitial, //插屏
    ZXAdSDKTypeRewardVideo,         //激励
    ZXAdSDKTypeFullscreenVideo,     //竖版视频
};

@protocol ZXAdManagerDelegate <NSObject>

@optional

-(void)SDKInitSuccessWithArray:(NSArray *)resultArr;
-(void)SDKInitFail;
-(void)SDKThirdAdInitSuccessed;
-(void)SDKThirdAdFail;


-(void)zxNilAd;
-(void)zxSplashClosed:(ZXAdSDKPlatform )platType;
-(void)zxSplashShowType:(ZXAdSDKPlatform )platType;
-(void)zxBannerShowType:(ZXAdSDKPlatform )platType;
-(void)zxBannerClosed:(ZXAdSDKPlatform )platType;
-(void)zxSplashClicked;




-(void)currentAdxPrice:(double)eCpm;

@end
@interface ZXAdManager : NSObject
@property(nonatomic, weak)id<ZXAdManagerDelegate> delegate;

+(instancetype)shareInstance;

//如果有广告初始化不成功的时候，可以重新初始化
+(void)loadAllAdWithAppIdArr:(NSArray *)adArr;

+(void)initSDKWithConfig:(ZXAdSDKConfig *)config;

//加载全部广告
- (void)loadAllAdWithView:(UIView *)mainView andLogoImage:(UIImage *)logoImage andPosID:(NSString *)posID  andAdType:(ZXAdSDKType )adType;

//加载单个广告
- (void)loadAdWithView:(UIView *)mainView andPosID:(NSString *)posID andAdType:(ZXAdSDKType )adType platform:(ZXAdSDKPlatform)platform;

+(void)removeBannerOrNativeExpress;

//-(void)zxAdWithAdId:(NSString *)adId andMainView:(UIView *)mainView andAdType:(ZXAdSDKType )adType;

+(void)applicationDidBecomeActive:(UIApplication *)application;

+(void)makeToastWithText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
