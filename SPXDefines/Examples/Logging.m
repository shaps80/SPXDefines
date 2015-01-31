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

#import "Logging.h"
#import "SPXLoggingDefines.h"

@implementation Logging

__attribute__((constructor)) static void LoggingConstructor(void) {
  @autoreleasepool {
    Logging *logging = [Logging new];
    
    [logging logThisMethodWheneverItsCalled];
    [logging manuallyLogSomeInfo];
  }
}

- (void)logThisMethodWheneverItsCalled
{
  // This is a simple, fast way of logging a method -- along with its signature, class, line, etc...
  SPXLogMethod
}

- (void)manuallyLogSomeInfo
{
  NSString *name = @"Shaps";
  SPXLog(@"%@", name);
  
  // Syntactically similar to NSLog(...) however the out of this method is cleaner and automatically removed in release builds.
  // Here's some example output: The first 2 methods are called from C functions while the last is called from this method.
  //
  // date       time      line  file        class     method/function
  // --------------------------------------------------------------------------------
  // 2015-01-31 16:13:31 | 46 | Description.m | void DescriptionConstructor()
  // 2015-01-31 16:13:31 | 43 | Logging.m | -[Logging logThisMethodWheneverItsCalled]
  // 2015-01-31 16:13:31 | 49 | Logging.m | Logging | manuallyLogSomeInfo | Shaps
  
}

@end
