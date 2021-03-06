//
//  TorController.h
//  OnionBrowser
//
//  Created by Mike Tigas on 9/5/12.
//
//

#import <Foundation/Foundation.h>
#import "TorWrapper.h"
#import "ULINetSocket.h"

@protocol TorControllerDelegate <NSObject>

- (void)torDidConnect;
- (void)torConnectingWithMessage:(NSString *)message;
- (void)torcontrolPortDidAuthenticate:(BOOL)didAuthenticate;

@end

@interface TorController : NSObject

@property (nonatomic,strong) id <TorControllerDelegate> delegate;
@property (nonatomic) NSUInteger controllerIsAuthenticated;
@property (nonatomic) Boolean didFirstConnect;

@property (nonatomic) TorWrapper *torThread;
@property (nonatomic) NSTimer *torCheckLoopTimer;
@property (nonatomic) NSTimer *torStatusTimeoutTimer;
@property (nonatomic) ULINetSocket	*mSocket;

@property (nonatomic) NSUInteger torSocksPort;
@property (nonatomic) NSUInteger torControlPort;


- (id)init;
- (void)startTor;
- (void)hupTor;

- (void)requestNewTorIdentity;

- (void)activateTorCheckLoop;
- (void)disableTorCheckLoop;
- (void)checkTor;
- (void)checkTorStatusTimeout;

- (void)reachabilityChanged;
- (void)appDidEnterBackground;
- (void)appDidBecomeActive;

@end
