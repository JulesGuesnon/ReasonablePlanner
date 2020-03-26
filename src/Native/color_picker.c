#import "color_picker.h"

@implementation ColorPicker {
    NSColorPanel* _panel;
}

    - (void)initPanel 
    {
         _panel = [NSColorPanel sharedColorPanel];
        [_panel setTarget:self];
        [_panel setAction:@selector(changeColor:)];
    }

    - (void)show
    {
        [_panel orderFront:nil];
    }

    - (void)hide
    {
        if (_panel != nil) {
            [_panel orderOut:nil];
        }
    }

    - (void)changeColor:(id)sender
    {
        NSColor* color = [sender color];
        NSString* hexString = [
            NSString stringWithFormat:@"%02X%02X%02X",
            (int) (color.redComponent * 0xFF),
            (int) (color.greenComponent * 0xFF), 
            (int) (color.blueComponent * 0xFF)
        ];

        self.sendColor([hexString UTF8String]);
    }

    + (ColorPicker*)createColorPicker 
    {
        ColorPicker* colorPicker = [ColorPicker alloc];
        [colorPicker initPanel];
        return colorPicker;
    }
@end