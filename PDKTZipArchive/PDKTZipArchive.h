//
//  PDKTZipArchive.h
//  PDKTZipArchive
//
//  Forked from SSZipArchive
//  Created by Sam Soffes on 7/21/10.
//  Copyright (c) Sam Soffes 2010-2015. All rights reserved.
//

#ifndef _PDKTZipArchive_H
#define _PDKTZipArchive_H

#import <Foundation/Foundation.h>

typedef struct unz_file_info_s unz_file_info_h;
typedef struct unz_global_info_s unz_global_info_h;

typedef void(^PDKTZipProgressHandler)(NSString *entry, unz_file_info_h zipInfo, long entryNumber, long total);
typedef void(^PDKTZipCompletionHandler)(NSString *path, BOOL succeeded, NSError *error);

@protocol PDKTZipArchiveDelegate;

@interface PDKTZipArchive : NSObject

// Unzip
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination;
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination delegate:(id<PDKTZipArchiveDelegate>)delegate;

+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination overwrite:(BOOL)overwrite password:(NSString *)password error:(NSError **)error;
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination overwrite:(BOOL)overwrite password:(NSString *)password error:(NSError **)error delegate:(id<PDKTZipArchiveDelegate>)delegate;

+ (BOOL)unzipFileAtPath:(NSString *)path
          toDestination:(NSString *)destination
        progressHandler:(PDKTZipProgressHandler)progressHandler
      completionHandler:(PDKTZipCompletionHandler)completionHandler;

+ (BOOL)unzipFileAtPath:(NSString *)path
          toDestination:(NSString *)destination
              overwrite:(BOOL)overwrite
               password:(NSString *)password
        progressHandler:(PDKTZipProgressHandler)progressHandler
      completionHandler:(PDKTZipCompletionHandler)completionHandler;

// Swift compatible versions
+ (BOOL)unzipFileAtPath:(NSString *)path
          toDestination:(NSString *)destination
              overwrite:(BOOL)overwrite
               password:(NSString *)password
               delegate:(id<PDKTZipArchiveDelegate>)delegate
                  error:(NSError **)error;

// Zip
+ (BOOL)createZipFileAtPath:(NSString *)path withFilesAtPaths:(NSArray *)filenames;
+ (BOOL)createZipFileAtPath:(NSString *)path withContentsOfDirectory:(NSString *)directoryPath;
+ (BOOL)createZipFileAtPath:(NSString *)path withContentsOfDirectory:(NSString *)directoryPath keepParentDirectory:(BOOL)keepParentDirectory;

- (id)initWithPath:(NSString *)path;
- (BOOL)open;
- (BOOL)writeFile:(NSString *)path;
- (BOOL)writeFileAtPath:(NSString *)path withFileName:(NSString *)fileName;
- (BOOL)writeData:(NSData *)data filename:(NSString *)filename;
- (BOOL)close;

@end

@protocol PDKTZipArchiveDelegate <NSObject>

@optional

- (void)zipArchiveWillUnzipArchiveAtPath:(NSString *)path zipInfo:(unz_global_info_h)zipInfo;
- (void)zipArchiveDidUnzipArchiveAtPath:(NSString *)path zipInfo:(unz_global_info_h)zipInfo unzippedPath:(NSString *)unzippedPath;

- (BOOL)zipArchiveShouldUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath fileInfo:(unz_file_info_h)fileInfo;
- (void)zipArchiveWillUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath fileInfo:(unz_file_info_h)fileInfo;
- (void)zipArchiveDidUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath fileInfo:(unz_file_info_h)fileInfo;
- (void)zipArchiveDidUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath unzippedFilePath:(NSString *)unzippedFilePath;

- (void)zipArchiveProgressEvent:(NSInteger)loaded total:(NSInteger)total;
- (void)zipArchiveDidUnzipArchiveFile:(NSString *)zipFile entryPath:(NSString *)entryPath destPath:(NSString *)destPath;

@end

#endif /* _PDKTZipArchive_H */
