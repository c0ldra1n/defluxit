//
//  Tweak.h
//  Faded
//
//  Created by c0ldra1n on 3/4/17.
//  Copyright © 2017 c0ldra1n. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <Cephei/HBPreferences.h>
#import <xctheos.h>

@interface NCNotificationListCollectionView : UICollectionView

@end

@interface SBLockScreenNotificationTableView : UITableView

@end


@interface BBServer : NSObject
- (void)publishBulletin:(id)arg1 destinations:(unsigned long long)arg2 alwaysToLockScreen:(bool)arg3;
@end

@interface BBAction : NSObject

+ (id)actionWithLaunchURL:(id)arg1;

@end

@interface BBBulletin : NSObject
@property(copy, nonatomic) NSString *sectionID; // @dynamic sectionID;
@property(copy, nonatomic) NSString *title; // @dynamic title;
@property(copy, nonatomic) NSString *message; // @dynamic title;
@property(copy, nonatomic) id defaultAction;
@property(retain, nonatomic) NSDate *date;
@property(copy, nonatomic) NSString *bulletinID;
@property(retain, nonatomic) NSDate *publicationDate;
@property(retain, nonatomic) NSDate *lastInterruptDate;
@property(nonatomic) BOOL showsMessagePreview;
@property(nonatomic) BOOL clearable;
@end


@interface SBLockScreenManager : NSObject
+ (id)sharedInstance;
- (void)lockUIFromSource:(int)source withOptions:(id)options;
@end


@protocol SBAlertingNotificationDestination;

@interface SBNotificationCenterDestination : NSObject

@end

@interface SBNCNotificationDispatcher : NSObject

@property (nonatomic,readonly) id<SBAlertingNotificationDestination> dashBoardDestination;                   //@synthesize dashBoardDestination=_dashBoardDestination - In the implementation block
@property (nonatomic,readonly) SBNotificationCenterDestination * notificationCenterDestination;              //@synthesize notificationCenterDestination=_notificationCenterDestination - In the implementation block

@end

@interface SpringBoard : UIApplication

@property (nonatomic,readonly) SBNCNotificationDispatcher * notificationDispatcher;                                  //@synthesize notificationDispatcher=_notificationDispatcher - In the implementation block

@end


@interface NCNotificationContent : NSObject
@end

@interface NCMutableNotificationContent : NCNotificationContent

@property (nonatomic,copy) NSString * header;
@property (nonatomic,copy) NSString * title;
@property (nonatomic,copy) NSString * subtitle;
@property (nonatomic,copy) NSString * message;
@property (nonatomic,copy) NSString * topic;
@property (nonatomic,retain) UIImage * icon;
@property (nonatomic,retain) UIImage * attachmentImage;
@property (nonatomic,retain) NSDate * date;

@end


@class NCNotificationAction;

@protocol NCNotificationActionRunner <NSObject>
- (void)executeAction:(NCNotificationAction *)arg1 fromOrigin:(NSString *)arg2 withParameters:(NSDictionary *)arg3;
@end


@interface NCNotificationAction : NSObject
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, retain) id<NCNotificationActionRunner> actionRunner;
@property (nonatomic,copy,readonly) NSURL * launchURL;                                         //@synthesize launchURL=_launchURL - In the implementation block
@end

@interface NCMutableNotificationAction : NCNotificationAction
-(void)setLaunchURL:(NSURL *)arg1 ;
@end

@interface NCNotificationOptions : NSObject
@end

@interface NCMutableNotificationOptions : NCNotificationOptions
@property (assign,nonatomic) BOOL dismissAutomatically;
@end

@interface NCUserAlertActionRunner : NSObject <NCNotificationActionRunner>

@end

@interface NCUserAlertDefaultActionRunner : NCUserAlertActionRunner

@end

@interface NCNotificationRequest : NSObject

@property (nonatomic,readonly) NCNotificationAction * clearAction;                          //@synthesize clearAction=_clearAction - In the implementation block
@property (nonatomic,readonly) NCNotificationAction * closeAction;                          //@synthesize closeAction=_closeAction - In the implementation block
@property (nonatomic,readonly) NCNotificationAction * defaultAction;                        //@synthesize defaultAction=_defaultAction - In the implementation block
@property (nonatomic,readonly) NCNotificationAction * silenceAction;                        //@synthesize silenceAction=_silenceAction - In the implementation block

+(id)notificationRequestWithSectionId:(id)arg1 notificationId:(id)arg2 threadId:(id)arg3 title:(id)arg4 message:(id)arg5 timestamp:(id)arg6 destination:(id)arg7 ;

@end


@interface NCMutableNotificationRequest : NCNotificationRequest

@property (nonatomic,copy) NSString * sectionIdentifier;
@property (nonatomic,copy) NSString * notificationIdentifier;
@property (nonatomic,copy) NSString * threadIdentifier;
@property (nonatomic,copy) NSString * categoryIdentifier;
@property (nonatomic,copy) NSSet * subSectionIdentifiers;
@property (nonatomic,copy) NSArray * peopleIdentifiers;
@property (nonatomic,copy) NSString * parentSectionIdentifier;
@property (nonatomic,retain) NSDate * timestamp;
@property (nonatomic,copy) NSSet * requestDestinations;
@property (nonatomic,copy) NSDictionary * context;
@property (nonatomic,copy) NSSet * settingsSections;
@property (nonatomic,retain) NCNotificationOptions * options;
@property (nonatomic,retain) NCNotificationAction * clearAction;
@property (nonatomic,retain) NCNotificationAction * closeAction;
@property (nonatomic,retain) NCNotificationAction * defaultAction;
@property (nonatomic,retain) NCNotificationAction * silenceAction;
@property (nonatomic, retain) NCNotificationContent *content;
@property (nonatomic,copy) NSDictionary * supplementaryActions;
@property (assign,nonatomic) BOOL isCollapsedNotification;
@property (assign,nonatomic) unsigned long long collapsedNotificationsCount;
@property (nonatomic,copy) NSDictionary * sourceInfo;

@end



@protocol NCNotificationDestination <NSObject>

- (void)postNotificationRequest:(NCNotificationRequest *)arg1 forCoalescedNotification:(id)arg2;

@end

@protocol SBAlertingNotificationDestination <NCNotificationDestination>

@end
