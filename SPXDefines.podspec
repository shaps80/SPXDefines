Pod::Spec.new do |s|

  s.name         = "SPXDefines"
  s.version      = "1.2.1"
  s.summary      = "Useful macro's for Objective-C projects"
  s.description  = <<-DESC
                   Useful macro's for Objective-C projects. All of the macros include compile-time checks where applicable.

                   * SPXAssertionDefines - Provides convenience assertions that will NOT crash on release builds
                   * SPXDescriptionDefines - Provides convenient description and keyPath macros for better and more consistent representations of your subclasses.
                   * SPXEncodingDefines - Provides cleaner encoding/decoding macros with compile-time checking
                   * SPXLoggingDefines - Provides cleaner logging, using CocoaLumberjack if available, otherwise falling gracefully back to NSLog with cleaner output.
                   DESC

  s.homepage     = "https://github.com/shaps80/SPXDefines"
  s.license      = { :type => 'MIT', :file => 'LICENSE.md' }
  s.author             = { "Shaps M" => "shaps80@me.com" }
	s.social_media_url = "http://twitter.com/shaps"
  s.platform     = :osx, '10.7'
  s.platform     = :ios, '5.0'
	
  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.7'
	
  s.source       = { :git => "https://github.com/shaps80/SPXDefines.git", :tag => s.version.to_s }
  s.source_files = 'Classes/**/*.{h,m}'
  s.requires_arc = true

end
