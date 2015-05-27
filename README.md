### This library is a fork of SSZipLibrary

Due to lack of mainteinance of the [SSZipLibrary](https://github.com/samsoffes/ssziparchive) repository, we decided to create this fork. 
This fork will be maintained independent from SSZipLibrary, so we don't have plans to pull changes merged in SSZipLibrary. 

Feel free to contribute to PDKTZipLibrary

---

# PDKTZipArchive

PDKTZipArchive is a simple utility class for zipping and unzipping files. 

You can do the following:

- Unzip zip files;
- Unzip password protected zip files;
- Create new zip files;
- Append to existing zip files;
- Zip files;
- Zip-up NSData instances. (with a filename)

## How to add PDKTZipArchive to your project

1. Add the `PDKTZipArchive` and `minizip` folders to your project.
2. Add the `libz` library to your target

PDKTZipArchive requires ARC.

### Usage

```objective-c
// Unzipping
NSString *zipPath = @"path_to_your_zip_file";
NSString *destinationPath = @"path_to_the_folder_where_you_want_it_unzipped";
[PDKTZipArchive unzipFileAtPath:zipPath toDestination:destinationPath];

// Zipping
NSString *zippedPath = @"path_where_you_want_the_file_created";
NSArray *inputPaths = [NSArray arrayWithObjects:
                       [[NSBundle mainBundle] pathForResource:@"photo1" ofType:@"jpg"],
                       [[NSBundle mainBundle] pathForResource:@"photo2" ofType:@"jpg"]
                       nil];
[PDKTZipArchive createZipFileAtPath:zippedPath withFilesAtPaths:inputPaths];

// Zipping directory
[PDKTZipArchive createZipFileAtPath:zippedPath withContentsOfDirectory:inputPath];
```

### License
PDKTZipArchive is protected under the [MIT license](https://github.com/produkt/pdktziparchive/raw/master/LICENSE) and our slightly modified version of [Minizip](http://www.winimage.com/zLibDll/minizip.html) 1.1 is licensed under the [Zlib license](http://www.zlib.net/zlib_license.html).

## Acknowledgments
Big thanks to [aish](http://code.google.com/p/ziparchive) for creating [ZipArchive](http://code.google.com/p/ziparchive). The project that inspired PDKTZipArchive. Thank you [@randomsequence](https://github.com/randomsequence) for implementing the creation support tech and to [@johnezang](https://github.com/johnezang) for all his amazing help along the way.