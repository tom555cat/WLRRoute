//
//  WLRRouteHandler.h
//  Pods
//
//  Created by Neo on 2016/12/15.
//
//

#import <Foundation/Foundation.h>
@class WLRRouteRequest;
/**
 This is a handler object, if a WLRRouteRequest object matched, WLRRouter object will invoke shouldHandleWithRequest、handleRequest method and transitionWithWithRequest method,you can overwrite some method to complete viewcontroller transition.
 WLRRouteHandler对象与WLRRouteMatcher对象相对应，如果一个WLRRouteRequest对象匹配到该handler对象，则WLRRouter将触发 handleRequest 方法和transitionWithWithRequest方法，完成一次视图控制器的转场.
 */
@interface WLRRouteHandler : NSObject

// 即将开始处理request请求，返回值决定是否要继续相应request
- (BOOL)shouldHandleWithRequest:(WLRRouteRequest *)request;

// 根据request获取目标控制器
-(UIViewController *)targetViewControllerWithRequest:(WLRRouteRequest *)request;

// 转场一定是从一个视图控制器跳转到另外一个视图控制器，该方法用以获取转场中的源视图控制器
-(UIViewController *)sourceViewControllerForTransitionWithRequest:(WLRRouteRequest *)request;

// 开始处理request请求
-(BOOL)handleRequest:(WLRRouteRequest *)request error:(NSError *__autoreleasing *)error;

// 该方法内根据request、获取的目标和源视图控制器，完成转场逻辑
-(BOOL)transitionWithWithRequest:(WLRRouteRequest *)request sourceViewController:(UIViewController *)sourceViewController targetViewController:(UIViewController *)targetViewController isPreferModal:(BOOL)isPreferModal error:(NSError *__autoreleasing *)error;

// 根据request来返回是否是模态跳转
- (BOOL)preferModalPresentationWithRequest:(WLRRouteRequest *)request;
@end
