# ptgz - Parallel Tar Gzip
The tar command line utility was first introduced in 1979 as a method of collecting many files into one archive file for distrbution and backup purposes. With the penetration of big data into every facet of the computing space datasets have grown exponentially in size. The single-threaded tar implementation is too slow to effectively archive terrabyte sized directories with millions of files. We introduce ptgz, a custom multi-threaded C++ file archiving utility to quickly compress, bundle files into an archive file, developed at the National Center for Supercomputing Applications.

## Requirements
Need at least GNU C Compiler (4.9) with OpenMP.

## Installation
### GNU C Compiler
    g++ -std=c++11 -fopenmp -o bin/ptgz src/ptgz.cpp

### GCC Makefile
    make

### Intel C Compiler
    icc -std=c++11 -openmp -O3 -o bin/ptgz src/ptgz.cpp

### ICC Makefile
    make clean
    make icc

## Usage
    If you are compressing, your current working directory should be parent directory of all directories you
    want to archive. If you are extracting, your current working directory should be the same as your archive.

### Command Syntax:
    ptgz [-c|-k|-v|-x] <archive>

### Modes:

    -c    Compression           ptgz will perform file compression. The current directory and all of it's
                                children will be archived and added to a single tarball. <archive> will be 
                                prefix of the ptgz archive created.

    -k    Keep Archive          ptgz will not delete the ptgz archive it has been passed to extract. This 
                                option must be used with "-x".

    -v    Enable Verbose        ptgz will print the commands as they are called to STDOUT

    -x    Extraction            ptgz will perform file extraction from an archive. The passed ptgz archive
                                will be unpacked and split into its component files. <archive> should be the
                                the name of the archive to extract.
