//
//  AiyaCamera.h
//  AiyaCameraSDK
//
//  Created by 汪洋 on 2017/2/23.
//  Copyright © 2017年 深圳哎吖科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AiyaCameraSDK/AYGPUImageFilter.h>
#import <AiyaCameraSDK/AYGPUImageView.h>
#import <AiyaCameraSDK/AiyaGPUImageBeautifyFilter.h>
#import <AiyaCameraSDK/AiyaGPUImageEffectFilter.h>

@class AiyaCamera;
@protocol AiyaCameraDelegate <NSObject>
@optional

/**
 图像数据渲染完成后的数据回调

 @param capture AiyaCamera
 @param pixelBuffer 图像数据
 @param frameTime 图像时间信息
 @param effectStatus 特效播放状态
 */
- (void)videoCaptureOutput:(AiyaCamera *)capture pixelBuffer:(CVPixelBufferRef)pixelBuffer frameTime:(CMTime)frameTime effectStatus:(AIYA_EFFECT_STATUS)effectStatus;

/**
 音频数据的回调

 @param capture AiyaCamera
 @param audioBuffer 音频数据
 */
- (void)audioCaptureOutput:(AiyaCamera *)capture audioBuffer:(CMSampleBufferRef)audioBuffer;

@end

@interface AiyaCamera : NSObject
/** delegate */
@property (nonatomic, weak) id<AiyaCameraDelegate> delegate;

/** 设置相机预览的分辨率 默认1280x720 */
@property (nonatomic, copy) NSString *sessionPreset;

/** 设置前置相机使用镜像 默认开 */
@property (nonatomic, assign) BOOL mirror;

/** 相机 */
@property (nonatomic, strong, readonly) AVCaptureDevice *inputCamera;

/** 设置美颜等级 默认0 */
@property (nonatomic, assign) AIYA_BEAUTY_LEVEL beautyLevel;

/** 设置美颜类型 默认0 */
@property (nonatomic, assign) AIYA_BEAUTY_TYPE beautyType;

/** 设置滤镜 默认空*/
@property (nonatomic, strong) UIImage *style;

/** 设置特效文件路径 */
@property (nonatomic, copy) NSString *effectPath;

/** 设置特效播放次数 默认0 0表示一直渲染当前特效 */
@property (nonatomic, assign) NSUInteger effectPlayCount;

/** 设置是否打开音频 默认关 */
@property (nonatomic, assign) BOOL hasAudioTrack;

/** 设置相机的位置 默认前置相机 */
@property (nonatomic, assign) AVCaptureDevicePosition capturePosition;

/**
 初始化
 
 @param preview 预览的视图
 @param cameraPosition 相机的位置
 @return 对象本身
 */
- (instancetype)initWithPreview:(UIView *)preview cameraPosition:(AVCaptureDevicePosition)cameraPosition;

/**
 打开相机
 */
- (void)startCapture;

/**
 关闭相机
 */
- (void)stopCapture;

@end
