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

#import "Encoding.h"
#import "SPXDefines.h"

@interface Encoding ()

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger age;
@property (nonatomic, assign) BOOL isOver18;

@end

@implementation Encoding

__attribute__((constructor)) static void EncodingConstructor(void) {
  @autoreleasepool {
    NSString *docsPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).lastObject;
    NSString *file = [docsPath stringByAppendingPathComponent:@"encoded_object"];
    Encoding *object = nil;
    
    if ([[NSFileManager defaultManager] fileExistsAtPath:file]) {
      object = [NSKeyedUnarchiver unarchiveObjectWithFile:file];
      SPXCLog(@"%@ Decoded successfully. Relaunch to encode.", object);
      
      [[NSFileManager defaultManager] removeItemAtPath:file error:nil];
    } else {
      object = [Encoding new];
      
      object.name = @"Shaps";
      object.age = 35;
      object.isOver18 = (object.age > 18);
      
      if ([NSKeyedArchiver archiveRootObject:object toFile:file]) {
        SPXCLog(@"%@ Encoded successfully. Relaunch to decode.", object);
      }
    }
  }
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
  self = [super init];
  if (!self) return nil;
  
  SPXDecode(name);
  SPXDecode(age);
  SPXDecode(isOver18);
  
  return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder
{
  SPXEncode(name);
  SPXEncode(age);
  SPXEncode(isOver18);
}

- (NSString *)over18
{
  return self.isOver18 ? @"YES" : @"NO";
}

- (NSString *)description
{
  // Notice 'over18' is a custom method that allows us to print a variation of the value below
  return SPXDescription(SPXKeyPath(name), SPXKeyPath(age), SPXKeyPath(over18));
}

@end

