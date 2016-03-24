//
//  SSAppDelegate.m
//  PDKTZipArchive
//
//  Created by Sam Soffes on 9/7/13.
//  Copyright (c) 2013-2014 Sam Soffes. All rights reserved.
//

#import "PDKTAppDelegate.h"

@implementation PDKTAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = [[UIViewController alloc] init];
    [self.window makeKeyAndVisible];
    return YES;
}

@end
