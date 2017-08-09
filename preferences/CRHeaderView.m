//
//  MSBHeaderView.m
//  Musubi
//
//  Created by c0ldra1n on 3/1/17.
//  Copyright © 2017 c0ldra1n. All rights reserved.
//

#import "CRHeaderView.h"

@interface CRHeaderView (){
    NSUInteger tapCount;
}

@end

@implementation CRHeaderView

/*
 // Only override drawRect: if you perform custom drawing.
 // An empty implementation adversely affects performance during animation.
 - (void)drawRect:(CGRect)rect {
 // Drawing code
 }
 */

- (instancetype)initWithBackground:(UIImage *)background overlay:(UIImage *)overlay{
    self = [super init];
    if (self) {
        backgroundImage = background;
        overlayImage = overlay;
        [self initializeImageViews];
    }
    return self;
}

-(void)layoutSubviews{
    
    [super layoutSubviews];
    
    self.backgroundView.frame = self.bounds;
    self.overlayView.frame = self.bounds;
    
    self.backgroundView.layer.masksToBounds = true;
    self.overlayView.layer.masksToBounds = true;
    
    self.backgroundView.contentMode = UIViewContentModeScaleAspectFill;
    self.overlayView.contentMode = UIViewContentModeScaleAspectFit;
    
}

-(void)initializeImageViews{
    
    if (backgroundImage) {
        if (!self.backgroundView) {
            self.backgroundView = [[UIImageView alloc] initWithFrame:self.bounds];
            self.backgroundView.image = backgroundImage;
            self.backgroundView.contentMode = UIViewContentModeScaleAspectFill;
            [self addSubview:self.backgroundView];
        }
    }
    
    if (overlayImage) {
        if (!self.overlayView) {
            self.overlayView = [[UIImageView alloc] initWithFrame:self.bounds];
            self.overlayView.image = overlayImage;
            self.overlayView.contentMode = UIViewContentModeScaleAspectFit;
            [self addSubview:self.overlayView];
        }
    }
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapped:)];
    
    [self addGestureRecognizer:tap];
    
}

-(void)tapped:(UITapGestureRecognizer *)gesture{
    
    tapCount++;
    
    if (tapCount == 10) {
        
        tapCount = 0;
        
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://www.youtube.com/watch?v=dQw4w9WgXcQ"]];
        
    }
    
}

@end
