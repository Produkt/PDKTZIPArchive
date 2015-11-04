Pod::Spec.new do |s|
  s.name         = 'PDKTZipArchive'
  s.version      = '0.3.5'
  s.summary      = 'Utility class for zipping and unzipping files on iOS and Mac.'
  s.description  = 'PDKTZipArchive is a simple utility class for zipping and unzipping files on iOS and Mac.'
  s.homepage     = 'https://github.com/Produkt/PDKTZipArchive'
  s.license      = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author       = { 'Sam Soffes' => 'sam@soff.es' }
  s.source       = { :git => 'https://github.com/Produkt/PDKTZipArchive.git', :tag => "v#{s.version}" }
  s.ios.deployment_target = '4.0'
  s.osx.deployment_target = '10.6'
  s.tvos.deployment_target = '9.0'
  s.source_files = 'PDKTZipArchive/*.{h,m}', 'PDKTZipArchive/minizip/*.{h,c}'
  s.public_header_files = 'PDKTZipArchive/PDKTZipArchive.h'
  s.library = 'z'
  s.requires_arc = true
end
