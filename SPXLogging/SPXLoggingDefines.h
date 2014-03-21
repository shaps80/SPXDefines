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


#ifndef _LOGGING_H
#define _LOGGING_H


/**
 *  Returns the current date and time as a char* (formatted timestamp)
 *
 *  @return A formatted timestamp
 */
char * getTime();


/**
 *  Logs the current method to the console
 *
 *  @note Logs to the console with the format, "YYYY-MM-DD HH:MM:SS | LINE # | CLASS | SELECTOR"
 */
#define logMethod NSLog((@"%s | %d | %@ | %@ "), getTime(), __LINE__, NSStringFromClass([self class]), NSStringFromSelector(_cmd));


#ifdef LOG_VERBOSE
#define SPXLog(...) DDLogVerbose(__VA_ARGS__)

#else


/**
 *  TAB Specific logging to the console for logging messages (NSLog replacement)
 *
 *  @note Logs to the console with the format, "YYYY-MM-DD HH:MM:SS | LINE # | CLASS | SELECTOR | MESSAGE"
 */
#define SPXLog(fmt, ...) NSLog((@"%s | %d | %@ | %@ | " fmt), getTime(), __LINE__, NSStringFromClass([self class]), NSStringFromSelector(_cmd), ##__VA_ARGS__)


/**
 *  Overrides NSLog, stripping the line of all superfluous information so we can use TLog above with custom formatting.
 */
#define NSLog(FORMAT, ...) fprintf(stderr,"%s\n", [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String])

#endif



#endif
