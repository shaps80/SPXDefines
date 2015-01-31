/*
   Copyright (c) 2015 Snippex. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY Snippex `AS IS' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL Snippex OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "Assertions.h"
#import "SPXAssertionDefines.h"

@implementation Assertions

__attribute__((constructor)) static void AssertionsConstructor(void) {
  @autoreleasepool {
    
    // this will throw an assertion when debugging since the block is nil
    Assertions *assertions = [[Assertions alloc] initWithBlock:nil];
    
    // this will throw an assertion because the length of 'name' is 0
    [assertions addSomeObject:[NSObject new] withName:@""];
  }
}

- (instancetype)initWithBlock:(void (^)())block
{
  self = [super init];
  
  // I tend to use this pattern in my own code now since its the same as writing
  //    if (!self) return nil;
  
  SPXAssertTrueOrReturnNil(self);
  SPXAssertTrueOrPerformAction(block, return self); // we'll allow the object anyway for this example
  
  return self;
}

- (void)addSomeObject:(id)object withName:(NSString *)name
{
  // If you retype these you'll understand the power of using keyPaths to get autocomplete and highlighting
  // not to mention compiler warnings if these properties are changed at a later date
  
  SPXAssertTrueOrReturn(object);
  SPXAssertTrueOrReturn(name.length);
}

@end

