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

#import <UIKit/UIKit.h>

@interface UITextField (FFKit)

NS_ASSUME_NONNULL_BEGIN

/**	A handy method to add a target/action for an UIControlEventEditingDidBegin
    event instead of writing out addTarget:action:forControlEvents:.
 
    @see removeTextDidBeginEditingTarget
*/
- (void) addTextDidBeginEditingTarget: (id) target action: (SEL) action;

/**	A handy method to remove a target/action for an UIControlEventEditingDidBegin
    event instead of writing out removeTarget:action:forControlEvents:.
 
    @see addTextDidBeginEditingTarget
*/
- (void) removeTextDidBeginEditingTarget: (id) target action: (nonnull SEL) action;

/**	A handy method to add a target/action for an UIControlEventEditingChanged
    event instead of writing out addTarget:action:forControlEvents:.
 
    @see removeTextChangedTarget
*/
- (void) addTextChangedTarget: (id) target action: (SEL) action;

/**	A handy method to remove a target/action for an UIControlEventEditingChanged
    event instead of writing out removeTarget:action:forControlEvents:.
 
    @see addTextChangedTarget
*/
- (void) removeTextChangedTarget: (id) target action: (nonnull SEL) action;

/**	A handy method to add a target/action for an UIControlEventEditingDidEnd
    event instead of writing out addTarget:action:forControlEvents:.
 
    @see removeTextDidEndEditingTarget
*/
- (void) addTextDidEndEditingTarget: (id) target action: (SEL) action;

/**	A handy method to remove a target/action for an UIControlEventEditingDidEnd
    event instead of writing out removeTarget:action:forControlEvents:.
 
    @see addTextDidEndEditingTarget
*/
- (void) removeTextDidEndEditingTarget: (id) target action: (nonnull SEL) action;

/**	A handy method to add a target/action for an UIControlEventEditingDidEndOnExit
    event instead of writing out addTarget:action:forControlEvents:.
 
    @see removeTextDidEndEditingOnExitTarget
*/
- (void) addTextDidEndEditingOnExitTarget: (id) target action: (SEL) action;

/**	A handy method to remove a target/action for an UIControlEventEditingDidEndOnExit
    event instead of writing out removeTarget:action:forControlEvents:.
 
    @see addTextDidEndEditingOnExitTarget
*/
- (void) removeTextDidEndEditingOnExitTarget: (id) target action: (nonnull SEL) action;

NS_ASSUME_NONNULL_END

@end
