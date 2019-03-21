# jwoff2
a java wrapper for woff2 to help convert ttf/otf font to woff2 or  woff2 to ttf in java

# Build

1. build [woff2](http://github.com/google/woff2) and build jwoff2

```bash
git clone --recursive https://github.com/Jijun/jwoff2.git
cd jwoff2/woff2
make clean all
cd ..
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

```
 java -Djava.library.path=<link to libjwoff2> -jar jwoff2.jar inputfilename outputfilename [woff2ttf|ttf2woff2] 

```
# References

* [google woff2](http://github.com/google/woff2)

