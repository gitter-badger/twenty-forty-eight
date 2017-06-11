# twenty-forty-eight

[![Build Status](https://travis-ci.org/geeknz/twenty-forty-eight.svg)](https://travis-ci.org/geeknz/twenty-forty-eight)

## Installing Google Test

This project uses the google test framework for unit testing and will need to be installed on your system.

### Ubuntu

```bash
aptitude install libgtest-dev
cmake -DBUILD_SHARED_LIBS=ON /usr/src/gtest
make
mv libgtest.so /usr/lib
mv libgtest_main.so /usr/lib
```

## Building twenty-forty-eight

twenty-forty-eight is built using gradle with all the build artifacts being placed in the build directory.

```bash
./gradlew build
```

_Note: This will also run the unit tests and will report failure if any test fails_
