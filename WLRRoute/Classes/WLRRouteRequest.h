//
//  WLRRouteRequest.h
//  Pods
//
//  Created by Neo on 2016/12/15.
//
//

#import <Foundation/Foundation.h>

@interface WLRRouteRequest : NSObject<NSCopying>
/**
 请求的URL
 */
@property (nonatomic, copy, readonly) NSURL *URL;
@property(nonatomic,copy)NSString * routeExpression;
@property (nonatomic, copy, readonly) NSDictionary *queryParameters;
@property (nonatomic, copy, readonly) NSDictionary *routeParameters;
@property (nonatomic, copy, readonly) NSDictionary *primitiveParams;

@property (nonatomic, strong) NSURL *callbackURL;

/**
 目标预留的回调
 */
@property(nonatomic,copy)void(^targetCallBack)(NSError *error,id responseObject);


/**
 是否消费掉，一个request只能处理一次，该字段反应request是否被处理过
 */
@property(nonatomic)BOOL isConsumed;


- (id)objectForKeyedSubscript:(NSString *)key;
-(instancetype)initWithURL:(NSURL *)URL routeExpression:(NSString *)routeExpression routeParameters:(NSDictionary *)routeParameters primitiveParameters:(NSDictionary *)primitiveParameters targetCallBack:(void(^)(NSError * error,id responseObject))targetCallBack;
-(instancetype)initWithURL:(NSURL *)URL;
-(void)defaultFinishTargetCallBack;
@end
