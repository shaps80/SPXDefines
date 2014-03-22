/*
 Copyright (c) 2014 Shaps Mohsenin. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY Shaps Mohsenin `AS IS' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL Shaps Mohsenin OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef _ENCODINGDEFINES_H
#define _ENCODINGDEFINES_H


/**
 *  Converts the specified argument to a C string
 *
 *  @param x The argument to convert
 *
 *  @return A C string representation of the argument
 */
#define STRINGIFY(x) #x


/**
 *  Converts the specified C string to an Objective-C string type
 *
 *  @param x The argument to convert
 *
 *  @return An NSString instance of the argument
 */
#define OBJC_STRINGIFY(x) @#x


/**
 *  Provides encoding of objects via encode(object);
 **/
#define encodeObjectWithKey(target, key) ({if (NO){[target key];} [aCoder encodeObject:[target valueForKey:OBJC_STRINGIFY(key)] forKey:OBJC_STRINGIFY(key)];})
#define encodeT(target, value) encodeObjectWithKey(target, value)
#define encode(value) encodeT(self, value)


/**
 *  Provides decoding of objects via decode(object);
 */
#define decodeObjectWithKey(target, key) ({if (NO){[target key];} [target setValue:[aDecoder decodeObjectForKey:OBJC_STRINGIFY(key)] forKey:OBJC_STRINGIFY(key)];})
#define decodeT(target, value) decodeObjectWithKey(target, value)
#define decode(value) decodeT(self, value)


/**
 *  Provides convenient user defaults setters
 */
#define setDefaultsT(target, value) [[NSUserDefaults standardUserDefaults] setValue:getBoxedValueT(target, value) forKey:OBJC_STRINGIFY(value)]
#define setDefaults(value) setDefaultsT(self, value)


/**
 *  Provides convenient user defaults getters
 */
#define getDefaultsT(target, value) [target setValue:[[NSUserDefaults standardUserDefaults] valueForKey:OBJC_STRINGIFY(value)] forKey:OBJC_STRINGIFY(value)]
#define getDefaults(value) getDefaultsT(self, value)


/**
 *  Convenience method for synchronizing changes
 */
#define synchronize [[NSUserDefaults standardUserDefaults] synchronize]


#endif
