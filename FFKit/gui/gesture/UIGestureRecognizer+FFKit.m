/*
  ==============================================================================
 
   Copyright (C) 2016 Jacob Sologub

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
 
  ==============================================================================
*/

#import "UIGestureRecognizer+FFKit.h"
#import "../../core/NSObject+FFKit.h"
#import "FFAssociatedObject.h"
#import "FFListenerList.h"

static NSString* const kFFKitGestureRecognizerTargetKey = @"kFFKitGestureRecognizerTargetKey";
static NSString* const kFFKitGestureRecognizerListenerListKey = @"kFFKitGestureRecognizerListenerListKey";

@interface FFGestureRecognizerTarget : NSObject
@property (nonatomic, weak) FFListenerList* listenerList;
- (void) handleGesture: (UIGestureRecognizer*) recognizer;
@end

@implementation FFGestureRecognizerTarget
@synthesize listenerList;

- (void) dealloc {
    // xx
}

- (void) handleGesture: (UIGestureRecognizer*) recognizer {
    [listenerList callWithObject: recognizer];
}
@end

@implementation UIGestureRecognizer (FFKit)

- (void) addTarget: (UIGestureRecognizerBlock) block {
    FFListenerList* listenerList = [self getOrCreateAssociatedObjectForKey: kFFKitGestureRecognizerListenerListKey type: [FFListenerList class]];
    [listenerList addTarget: block];
    
    FFGestureRecognizerTarget* const gestureRecognizerTarget = [FFGestureRecognizerTarget new];
    [self setAssociatedObject: gestureRecognizerTarget forKey: kFFKitGestureRecognizerTargetKey];
    
    gestureRecognizerTarget.listenerList = listenerList;
    [self addTarget: gestureRecognizerTarget action: @selector (handleGesture:)];
}

@end
