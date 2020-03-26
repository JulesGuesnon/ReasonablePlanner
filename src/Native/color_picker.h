#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

@interface ColorPicker : NSObject

@property (assign) NSColorPanel* panel;
@property (nonatomic) void (* sendColor)(const char*);

- (void)initPanel ;
- (void)show;
- (void)hide;

+ (ColorPicker*)createColorPicker;
@end
