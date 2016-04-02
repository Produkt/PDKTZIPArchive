Pod::Spec.new do |s|
  s.name         = 'PDKTZipArchive'
  s.version      = '0.4.0'
  s.summary      = 'Utility class for zipping and unzipping files on iOS and Mac.'
  s.description  = 'PDKTZipArchive is a simple utility class for zipping and unzipping files on iOS and Mac.'
  s.homepage     = 'https://github.com/Produkt/PDKTZipArchive'
  s.license      = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author       = { 'Sam Soffes' => 'sam@soff.es' }
  s.source       = { :git => 'https://github.com/Produkt/PDKTZipArchive.git', :tag => "v#{s.version}" }
  s.ios.deployment_target = '8.0'
  s.osx.deployment_target = '10.6'
  s.source_files = 'PDKTZipArchive/*', 'PDKTZipArchive/minizip/*'
  s.library = 'z'
  s.requires_arc = true
end
