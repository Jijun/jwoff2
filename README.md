# jwoff2
a java wrapper for woff2 to help convert ttf/otf font to woff2 or  woff2 to ttf in java

# Build

1. build [woff2](http://github.com/google/woff2)


```bash
git clone --recursive https://github.com/Jijun/jwoff2.git
#compile brotli
cd jwoff2/woff2/brotli
cmake .
make && sudo make install
cd ..
mkdir out
cd out
cmake ..
make
sudo make install

```
2. build jwoff2

```
cd jwoff2
cmake .
make
```

# Function

```java

public static native byte[] convertTTF2WOFF2Byte(byte[] inputByte);

/**
 * convert truetype font to woff2
 * 
 * @param intputFileName
 * @param outputFileName
 * @return
 */
public static native boolean convertTTF2WOFF2(String intputFileName, String outputFileName);

/**
 * convert woff2 to truetype font
 * 
 * @param inputFileName
 * @param outputFileName
 * @return
 */
public static native boolean convertWOFF2ToTTF(String inputFileName, String outputFileName);

```


# Run

```bash
java -Djava.library.path=<link to libjwoff2> -jar libjwoff2.jar inputfilename outputfilename [woff2ttf|ttf2woff2] 

```
# References

* [google woff2](http://github.com/google/woff2)

