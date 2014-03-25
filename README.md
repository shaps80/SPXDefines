Purpose
--------------

Useful macro's for Objective-C projects.


Supported OS & SDK Versions
-----------------------------

* Supported build target - iOS 7.1
* Earliest supported deployment target - iOS 2.0


ARC Compatibility
------------------

The SPXDefines macro's will work correctly with or without ARC enabled.


Installation
--------------

To use the SPXDefines in an app, just drag the files into your project and import the header file into any class where you wish to make use of the SPXDefines functionality.

Macro's
-------------
 
**SPXAssertionDefines**

Provides better assertion handling in an iOS project. It will NEVER crash in a RELEASE build, but will assert and break on the offending line of code in DEBUG builds. There are equivalent `CAssertTrueOr...` methods for usage inside C functions.

The following code will assert 'condition', if it fails, write the assertion to the console and break on the offending line of code. In a release build it will simply return.

		AssertTrueOrReturnNo(condition);
		AssertTrueOrReturnNil(condition);
		AssertTrueOrReturnError(condition);
		AssertTrueOrReturn(condition);

The following code will also assert 'condition', but instead of returning, it will perform the specified action.
		
		AssertTrueOrPerformAction(condition, NSLog(@"Help!"));


**SPXEncodingDefines**

The following code will encode or decode variables using NSCoding. It uses `encode()` and `decode()` which expand to `[aEncoder encodeObject:name forKey:@"name"]` and `[aDecoder decodeObjectForKey:@"name"]` respectively.
	
	// defined in header or private interface
	@property (nonatomic, copy) NSString *name;
	@property (nonatomic, copy) NSInteger age;
	
	...
	
	- (instancetype)initWithCoder:(NSCoder *)aDecoder
	{
		self = [super init];
		if (self) {
			decode(name);	
			decode(age);
		}
		return self;
	} 
	
	- (void)encodeWithCoder:(NSCoder *)aCoder
	{
		encode(name);
		encode(age);	
	} 


**SPXLoggingDefines**

The following methods will first look for CocoaLumberjack and if it exists, use that for logging. If not it will fall back to NSLog but with much improved logging ;)

The pretty format
`YYYY-MM-DD HH:MM:SS | LINE # | CLASS | SELECTOR | MESSAGE`

Example
`2014-03-21 14:31:22 | 23 | AppDelegate | applicationDidFinishLaunchingWithOptions: | Hello World!`

	logMethod; // simply logs the current class and selector
	SPXLog(@"Hello World!");

