/*
  ==============================================================================
 
   Copyright (C) 2014 Jacob Sologub

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

#import <UIKit/UIKit.h>

@interface UIView (FFKit)

/**	Gets or sets the x coordinate of the view.
 
    @see setX:adjustingWidth
*/
@property (nonatomic, assign) CGFloat x;

/** Sets the x coordinate of the view.
 
    @param adjustWidth      Whether or not to adjust the width of the view. If 
                            this is set to YES then the right edge of the view 
                            will remain the same.
 
    @see setX
*/
- (void) setX: (CGFloat) newX adjustingWidth: (BOOL) adjustWidth;

/**	Gets or sets the y coordinate of the view.
    
    @see setY:adjustingHeight
*/
@property (nonatomic, assign) CGFloat y;

/** Sets the y coordinate of the view.
 
    @param adjustHeight     Whether or not to adjust the height of the view. If 
                            this is set to YES then the bottom edge of the view 
                            will remain the same.
 
    @see setY
*/
- (void) setY: (CGFloat) newY adjustingHeight: (BOOL) adjustHeight;

/**	Gets or sets the width of the view. 
    
    @see setHeight
*/
@property (nonatomic, assign) CGFloat width;

/**	Gets or sets the height of the view. 
 
    @see setWidth
*/
@property (nonatomic, assign) CGFloat height;

/**	Gets or sets the size of the view.
 
    @see setWidth, setHeight
*/
@property (nonatomic, assign) CGSize size;

/**	Gets or sets the x coordinate of the view's right edge. 
    
    @see setRight:adjustingWidth
*/
@property (nonatomic, assign) CGFloat right;

/** Sets the x coordinate of the view's right edge.
 
    @param adjustWidth      Whether or not to adjust the width of the view. If
                            this is set to YES then the left edge of the view
                            will remain the same.
 
    @see setRight
*/
- (void) setRight: (CGFloat) newRight adjustingWidth: (BOOL) adjustWidth;

/**	Gets or sets the y coordinate of the view's bottom edge.
    
    @see setBottom:adjustingHeight
*/
@property (nonatomic, assign) CGFloat bottom;

/** Sets the y coordinate of the view's bottom edge.
 
    @param adjustHeight     Whether or not to adjust the height of the view. If
                            this is set to YES then the top edge of the view
                            will remain the same.
 
    @see setBottom
*/
- (void) setBottom: (CGFloat) newBottom adjustingHeight: (BOOL) adjustHeight;

/** Changes the view's size and centres it within its superview. */
- (void) centerWithSize: (CGSize) newSize;

/** Changes the view's size and centres it within its superview with an optional 
    block paramter that you can use to modify the final centered frame.
*/
- (void) centerWithSize: (CGSize) newSize block: (void (^) (CGRect* frame)) block;

/**	Gets or sets the center x of the view.
 
    @see setCenter
*/
@property (nonatomic, assign) CGFloat centerX;

/**	Gets or sets the center x of the view.
 
    @see setCenter
*/
@property (nonatomic, assign) CGFloat centerY;

/**	Gets or sets whether or not the view is visible. */
@property (nonatomic, assign) BOOL visible;

/**	Returns true if this view is currently on screen. This property checks if 
    this view's window property is not nil, this view is visible or "not hidden" 
    and this view's alpha is > 0.0f.
*/
@property (nonatomic, readonly, getter= isShowing) BOOL showing;

#ifdef FFKIT_USE_ASPECTS
/** Called when this view's size is changed.
 
    This event is called after UIView#layoutSubviews is called. To use this 
    property FFKIT_USE_ASPECTS has to be defined in FFKitConfig.h @see FFKit.h
 
    @code
    #ifndef FFKIT_USE_ASPECTS
      #include "../Pods/Aspects/Aspects.h"
      #define FFKIT_USE_ASPECTS
    #endif
    @code
 
    Aspects.h #include must be relative to the FFKitConfig.h file.
    @see FFKit.h
*/
#include "../../events/FFListenerList.h"
@property (nonatomic, readonly) FFListenerList* resized;

/** Sets a block that will be invoked after this view's layoutSubviews method 
    is invoked.
    
    @see UIView#layoutSubviews:
*/
- (void) setLayoutSubviewsBlock: (void (^) (void)) block;
#endif

//==============================================================================
/** Searches the view's subviews for a UIView of a specified class. */
- (UIView*) subviewOfClassType: (Class) classType;

/** Searches the view's subviews for a UIView of a specified class. */
- (UIView*) subviewOfClassType: (Class) classType searchRecursively: (BOOL) searchRecursively;

/** Searches the view's superviews for a UIView of a specified class. */
- (UIView*) superviewOfClassType: (Class) classType;

/** Returns the superview whose tag matches the specified value. */
- (UIView*) superviewWithTag: (NSInteger) tag;

/** Returns the UIViewController object that manages this view or nil if it does 
    not have one. 
 
    This method calls UIResponder#nextResponder and checks to see
    if the returned object is of type UIViewController and if its view property 
    is equal to this view.
 
    @see UIResponder#nextResponder
*/
@property (nonatomic, readonly) UIViewController* viewController;

//==============================================================================
/** Generates an image of this view and its its subviews. */
- (UIImage*) snapshotImage;

/** Generates an image of this view and its its subviews with the specified 
    options.
*/
- (UIImage*) snapshotImageWithOptions: (BOOL) opaque scale: (CGFloat) scale __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

//==============================================================================
/** Performs `animations` using a timing curve described by the motion of a 
    spring. When `dampingRatio` is 1, the animation will smoothly decelerate to 
    its final model values without oscillating. Damping ratios less than 1 will 
    oscillate more and more before coming to a complete stop.
 
    This is a shorthand method that calls the longer version with an 
    initialSpringVelocity of 1.0f, UIViewAnimationOptionCurveEaseInOut and  
    0.0f delay.
*/
+ (void) animateWithDuration: (NSTimeInterval) duration usingSpringWithDamping: (CGFloat) dampingRatio animations: (void (^)(void)) animations completion: (void (^)(BOOL finished)) completion;

/** Performs `animations` using a timing curve described by the motion of a
    spring. When `dampingRatio` is 1, the animation will smoothly decelerate to
    its final model values without oscillating. Damping ratios less than 1 will
    oscillate more and more before coming to a complete stop.
 
    This is a shorthand method that calls the longer version with an
    initialSpringVelocity of 1.0f, UIViewAnimationOptionCurveEaseInOut.
 */
+ (void) animateWithDuration: (NSTimeInterval) duration delay: (double) delay usingSpringWithDamping: (CGFloat) dampingRatio animations: (void (^)(void)) animations completion: (void (^)(BOOL finished)) completion;

/** Animate changes to one or more views using the specified duration, 
    delay = 0.0, options, and completion handler.
*/
+ (void) animateWithDuration: (NSTimeInterval) duration options: (UIViewAnimationOptions) options animations: (void (^)(void)) animations completion: (void (^)(BOOL finished)) completion;

/** Animate changes to one or more views using the specified duration,
    delay = 0.0, options, and completion = NULL handler.
*/
+ (void) animateWithDuration: (NSTimeInterval) duration options: (UIViewAnimationOptions) options animations: (void (^)(void)) animations;
@end
