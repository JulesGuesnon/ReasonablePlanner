#import "color_picker.h"
#import <caml/alloc.h>
#import <caml/callback.h>
#import <caml/mlvalues.h>
#import <caml/memory.h>
#import <caml/threads.h>

static ColorPicker *colorPicker = nil;

void caml_callback_color(const char *color)
{
    caml_acquire_runtime_system();
    static value *closure_f = NULL;
    if (closure_f == NULL)
    {
        closure_f = caml_named_value("colorHandler");
    }

    caml_callback(*closure_f, caml_copy_string(color));
    caml_release_runtime_system();
}

void caml_create_color_picker()
{
    colorPicker = [ColorPicker createColorPicker];
    colorPicker.sendColor = caml_callback_color;
}

void caml_show_color_picker()
{
    if (colorPicker == nil)
    {
        NSLog(@"Trying to show but colorPicker is nil");
        return;
    }
    [colorPicker show];
}

void caml_hide_color_picker()
{
    if (colorPicker == nil)
    {
        NSLog(@"Trying to hide but colorPicker is nil");
        return;
    }
    [colorPicker hide];
}
