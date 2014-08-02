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
 MERCHANSPXILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL Shaps Mohsenin OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef _ASSERTIONDEFINES_H
#define _ASSERTIONDEFINES_H


/**
 *  Asserts the specified condition on debug builds, returning an NSError on release builds
 *
 *  @param condition The condition to evaluate
 *
 *  @return An NSError
 */
#define AssertTrueOrReturnError(condition) GenericAssertTrueOrReturnError(Objc, condition)

/**
 *  Asserts the specified condition on debug builds, performing the specified action on release builds
 *
 *  @param condition The condition to evaluate
 *  @param action    The code to execute for release builds
 *
 *  @return nil
 */
#define AssertTrueOrPerformAction(condition, action) GenericAssertTrueOrPerformAction(Objc, condition, action)

/**
 *  Asserts the specified condition on debug builds, returning on release builds
 *
 *  @param condition The condition to evaluate
 */
#define AssertTrueOrReturn(condition) AssertTrueOrPerformAction(condition, return)

/**
 *  Asserts the specified condition on debug builds, returning NO on release builds
 *
 *  @param condition The condition to evaluate
 *
 *  @return NO
 */
#define AssertTrueOrReturnNo(condition) AssertTrueOrPerformAction(condition, return NO)

/**
 *  Asserts the specified condition on debug builds, returning nil on release builds
 *
 *  @param condition The condition to evaluate
 *
 *  @return nil
 */
#define AssertTrueOrReturnNil(condition) AssertTrueOrPerformAction(condition, return nil)


#pragma mark - C-based Functions


/**
 *  Asserts the specified condition on debug builds, returning an NSError on release builds
 *
 *  @param condition The condition to evaluate
 *
 *  @return An NSError
 */
#define CAssertTrueOrReturnError(condition) GenericAssertTrueOrReturnError(C, condition)

/**
 *  Asserts the specified condition on debug builds, performing the specified action on release builds
 *
 *  @param condition The condition to evaluate
 *  @param action    The code to execute for release builds
 *
 *  @return nil
 */
#define CAssertTrueOrPerformAction(condition, action) GenericAssertTrueOrPerformAction(C, condition, action)

/**
 *  Asserts the specified condition on debug builds, returning on release builds
 *
 *  @param condition The condition to evaluate
 */
#define CAssertTrueOrReturn(condition) CAssertTrueOrPerformAction(condition, return)

/**
 *  Asserts the specified condition on debug builds, returning NO on release builds
 *
 *  @param condition The condition to evaluate
 *
 *  @return NO
 */
#define CAssertTrueOrReturnNo(condition) CAssertTrueOrPerformAction(condition, return NO)

/**
 *  Asserts the specified condition on debug builds, returning nil on release builds
 *
 *  @param condition The condition to evaluate
 *
 *  @return nil
 */
#define CAssertTrueOrReturnNil(condition) CAssertTrueOrPerformAction(condition, return nil)




#pragma mark - Private Methods

/**
 *  Error status codes
 */
typedef NS_ENUM(NSInteger, SPXErrorCode) {
  /**
   *  Internal error code
   */
  SPXErrorCodeInternal = 44324344,
};



/**
 *  Constructs an NSError object
 *
 *  @param message            The message for this error
 *  @param code               The status code for this error
 *  @param aUserInfo          Any user info as an NSDictionary for this error
 *  @param methodOrFunction   The method or function that caused this error
 *
 *  @return An instance of NSError
 */
extern NSError *NSErrorMake(NSString *message, NSInteger code, NSDictionary *aUserInfo, NSString *methodOrFunction);



// The following generic macros are intended for internal-use only, for external use, see documented macros above.
#define NSObjcAssert NSAssert
#define InvalidConditionString(condition) (@"Invalid condition not satisfying: " #condition)
#define GenericAssertCondition(ctype, condition) NS ## ctype ## Assert((condition), InvalidConditionString((condition)))
#define GenericErrorMake(condition, func) NSErrorMake(InvalidConditionString((condition)), SPXErrorCodeInternal, nil, func)
#define GenericAssertTrueOrPerformAction(ctype, condition, action) ({ ctype ## AssertCondition(condition); \
if (!(condition)) { ctype ## ErrorMake(condition); action; } })
#define GenericAssertTrueOrReturnError(ctype, condition) do{ ctype ## AssertCondition(condition); \
if (!(condition)) { return ctype ## ErrorMake(condition); } } while(0)


// Intended for internal-use only.
#define ObjcAssertCondition(condition) GenericAssertCondition(Objc, condition)
// Intended for internal-use only.
#define ObjcErrorMake(condition) GenericErrorMake((condition), NSStringFromSelector(_cmd))

// Intended for internal-use only.
#define CAssertCondition(condition) GenericAssertCondition(C, condition)
// Intended for internal-use only.
#define CErrorMake(condition) GenericErrorMake((condition), [NSString stringWithUTF8String:__PRETTY_FUNCTION__])


#endif
