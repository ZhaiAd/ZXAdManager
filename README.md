SDKDemo：

一、接入前期配置
1.pod导入第三方库
  
```
  pod 'GDTMobSDK','4.15.30'                     ##腾讯
  pod 'KSAdSDK','3.3.76'  ## adn
  pod 'BaiduMobAdSDK', '~> 5.390'                       ##百度
  pod 'Ads-CN-Beta','6.8.0.5', :subspecs => ['BUAdSDK', 'CSJMediation']
  pod 'AnyThinkiOS','6.4.75'
```
2.主工程---->Build Settings ---->Other Linker Flags配置
```
-ObjC，-l"c++"，-l"c++abi"，-l"sqlite3"，-l"z"
```
3.导入系统库
```
Accelerate.framework
AdSupport.framework
AppTrackingTransparency.framework
AudioToolbox.framework
AVFoundation.framework
CoreGraphics.framework
CoreImage.framework
CoreLocation.framework
CoreMedia.framework
CoreML.framework
CoreMotion.framework
CoreTelephony.framework
CoreText.framework
CoreVideo.framework
DeviceCheck.framework
EventKit.framework
EventKitUI.framework
Foundation.framework
ImageIO.framework
JavaScriptCore.framework
MapKit.framework
MediaPlayer.framework
MessageUI.framework
MobileCoreServices.framework
QuartzCore.framework
SafariServices.framework
Security.framework
StoreKit.framework
SystemConfiguration.framework
UIKit.framework
WebKit.framework
libbz2.tbd
libc++.tbd
libc++abi.tbd
libiconv.tbd
libresolv.9.tbd
libsqlite3.tbd
libxml2.tbd
libz.tbd
```
4.导入SDK文件
ZXAdManager.framework
ZXAdManager.bundle

5.info.plist文件
```
<key>NSAppTransportSecurity</key>
<dict>
  <key>NSAllowsArbitraryLoads</key>
  <true/>
</dict>
<key>SKAdNetwoorkItems</key>
<array>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>238da6jt44.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>x2jnk7ly8j.skadnetwork</string>
    </dict>
    <dict>
        <key>SKAdNetworkIdentifier</key>
        <string>cstr6suwn9.skadnetwork</string>
    </dict>
</array>
```
二、接入
1.sdk初始化
```
ZXAdSDKConfig *config = [ZXAdSDKConfig defaultConfig];
  config.appID = @"4820035";
  config.env = SDKDebug;
  config.timeout = 10.0;
  config.enableLog = YES;
 [ZXAdManager shareInstance].delegate = self;

    
 [ZXAdManager initSDKWithConfig:config];
```
sdk初始化回调
//==初始化成功==
```
-(void)SDKInitSuccessWithArray:(NSArray *)resultArr
//-(void)SDKInitSuccessWithArray:(NSArray *)resultArr
{
    NSLog(@"resultArr===%@",resultArr);

```
}
//==初始化失败==
```
-(void)SDKInitFail
{
    
}
```
2.加载同一类型所有广告源的广告
//加载全部广告
```
- (void)loadAllAdWithView:(UIView *)mainView andPosID:(NSString *)posID  andAdType:(ZXAdSDKType )adType;

示例：
 [[ZXAdManager shareInstance] loadAllAdWithView:self.mainView andPosID:@"2085643841" andAdType:ZXAdSDKTypeFullscreenVideo];
```
3.加载单一类型单个广告源的广告
 //加载单个广告
```
- (void)loadAdWithView:(UIView *)mainView andPosID:(NSString *)posID andAdType:(ZXAdSDKType )adType platform:(ZXAdSDKPlatform)platform;
```


示例：
```
 [[ZXAdManager shareInstance] loadAdWithView:self.mainView andPosID:@"2243762279" andAdType:ZXAdSDKTypeRewardVideo platform:AdSDKKUAISHOU];
```
4.移除banner或者信息流广告
```
+(void)removeBannerOrNativeExpress;

```
示例：
 
```
[ZXAdManager removeBannerOrNativeExpress];
```

5.SDK回调
5.1广告竞价失败回调  

```
-(void)zxNilAd;
```

5.2第三方广告初始化成功

```
-(void)SDKThirdAdInitSuccessed
{
    NSLog(@"第三方sdk初始化成功");
}
```
5.3第三方广告初始化失败，目前有4个第三方广告源，失败个数1-4
```
-(void)SDKThirdAdFail
{
    NSLog(@"第三方sdk初始化失败");
}
```
5.4开屏点击回调

```
-(void)zxSplashClicked
{
    NSLog(@"点击开屏广告");
}
```
5.5开屏关闭回调

```
-(void)zxSplashClosed
{
    NSLog(@"关闭开屏广告");
    //如果传了view视图，要判断view视图是否存在，如果存在要移除
    [self.mainView removeFromSuperview];
}
```